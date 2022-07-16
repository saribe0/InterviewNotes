class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> pathElems;
        
        string currentElem = "";
        int index = 0;
        while(index < path.size()) {
            
            if (path[index] == '/') {
                if (currentElem == "..") {
                    if (pathElems.size() > 0)
                        pathElems.pop_back();
                }
                else if (currentElem != "." && currentElem.size() > 0) {
                    pathElems.push_back(currentElem);
                }
                currentElem = "";
            }
            else {
                currentElem += path[index];
            }
            index++;
        }
        if (currentElem == "..") {
            if (pathElems.size() > 0)
                pathElems.pop_back();
        }
        else if (currentElem != "." && currentElem.size() > 0) {
            pathElems.push_back(currentElem);
        }
        
        string res = "/";
        for(auto elem: pathElems) {
            res += elem + "/";
        }
        if (res.size() > 1)
            res.erase(res.end()-1);
        return res;
    }
};