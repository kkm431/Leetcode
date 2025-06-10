class Solution {
public:
    int maxDifference(string s) {
        int freq[26];
        
        
        for(char ch: s){
            freq[ch - 'a']++;
        }

        int oddMax = INT_MIN;
        int evenMin = INT_MAX;

        for(int i=0; i < 26; i++){
            if(freq[i] == 0){
                continue;
            }
            if(freq[i] % 2 == 0){
                evenMin = min(evenMin, freq[i]);
            }
            else{
                oddMax= max(oddMax, freq[i]);
            }

        }


        // int res= (evenMax - oddMin);

        return -evenMin + oddMax;

    }
};