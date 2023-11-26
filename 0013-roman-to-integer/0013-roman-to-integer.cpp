class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanNumberals = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };

        int strSize = s.size();
        int result = 0;
        for (int i = 0; i < strSize; i++){
            int currentChar = romanNumberals[s[i]];
            int nextChar = i+1 > strSize ? currentChar : romanNumberals[s[i+1]];
            if (currentChar < nextChar){
                result += nextChar - currentChar;
                ++i;
            }else{
                result += currentChar;
            }
        }

        return result;
    }
};