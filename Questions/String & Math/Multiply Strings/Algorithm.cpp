class Solution {
    /*
     by-hand multiplication of strings
    
    -> 'carry' starts as 0
    -> multiply ones digit of num2 by num1
    -> continue until 
    
    12
    537
    894
    ---
   2148
      0
    */
    
private:
    
public:
    string multiply(string num1, string num2) {
        
        if (num1[0] == '0' || num2[0] == '0')
            return "0";
        
        // Find the products for each digit
        int maxDigits = 0;
        vector<string> intermediateProducts;
        for(int digitIndex = 1; digitIndex <= num2.size(); digitIndex++) {
            
            int carry = 0;
            string currentProduct (digitIndex-1, '0');
            
            for(int num1Index = 1; num1Index <= num1.size(); num1Index++) {
                // Get the product of the digits and add the carry
                int digitProduct = (num1[num1.size() - num1Index] - '0') * (num2[num2.size() - digitIndex] - '0') + carry;
                // Peal off the last value and update the carry
                currentProduct.insert(currentProduct.begin(), (digitProduct%10)+'0');
                carry = digitProduct/10;
            }
            
            if (carry > 0)
                currentProduct.insert(currentProduct.begin(), carry+'0');
            intermediateProducts.push_back(currentProduct);
            
            if (currentProduct.size() > maxDigits)
                maxDigits = currentProduct.size();
        }
        
        // Add up all the digits in the intermediate products
        string product;
        int carry = 0;
        for(int digitIndex = 1; digitIndex <= maxDigits; digitIndex++) {
            int currentSum = carry;
            for(string intProd: intermediateProducts) {
                if (digitIndex <= intProd.size())
                    currentSum += (intProd[intProd.size()-digitIndex] - '0');
            }
            
            // Peal off the last value and update the carry
            product.insert(product.begin(), (currentSum%10)+'0');
            carry = currentSum/10;
        }
        if (carry > 0)
            product.insert(product.begin(), carry+'0');
        
        return product;
    }
};