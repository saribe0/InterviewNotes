class Solution {
/*
Algorithm:
- Start with the first interval as the first "overlapping interval"
- For each next interval, determine if it can be overlapped with one or more
- If one, update the bounds
- If more, update the bounds and remove the other intervals

*/
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        
        for (int intervalIndex = 0; intervalIndex< intervals.size(); intervalIndex++) {
            
            // Search for any existing overlapping ones
            int min = intervals[intervalIndex][0];
            int max = intervals[intervalIndex][1];
            vector<int> overlappingIndices;
            for (int overlapIndex = 0; overlapIndex< merged.size(); overlapIndex++) {
                if (intervals[intervalIndex][0] <= merged[overlapIndex][1] && intervals[intervalIndex][1] >= merged[overlapIndex][0]) {
                    overlappingIndices.push_back(overlapIndex);
                    if (max < merged[overlapIndex][1])
                        max = merged[overlapIndex][1];
                    if (min > merged[overlapIndex][0])
                        min = merged[overlapIndex][0];
                }
                    
            }
            
            // If none, add it by itself
            if (overlappingIndices.size() == 0)
                merged.push_back(intervals[intervalIndex]);
            
            else {
                // Some overlap so merge into first by updating min/max
                merged[overlappingIndices[0]][0] = min;
                merged[overlappingIndices[0]][1] = max;

                // Remove the duplicates
                for (int index = 1; index<overlappingIndices.size(); index++) {
                    merged.erase(merged.begin() + overlappingIndices[index]);
                }
            }
        }
        sort(merged.begin(), merged.end());
        return merged;
    }
};