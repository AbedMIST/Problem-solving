//Find the Index of the First Occurrence in a String leetcode problem
class Solution {
public:
    int lps[10005];
    int strStr(string haystack, string needle) {  //O(n+m)->KMP
    
        // for(i=0;i<haystack.size();i++){
        //     if(haystack.substr(i,needle.size())==needle)
        //         return i;
        // }

        computeLPS(needle);

        int i = 0, j = 0;
        while(i<haystack.size()){
            if(haystack[i] == needle[j]){ ///matched
                i++;
                j++;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    j = lps[j-1]; ///intellectual backward
                }
            }

            if(j==needle.size()) //found first occurence
                return i-needle.size();
        }

        return -1;
    }

    //saves from comparing repeating character
    void computeLPS(string s){
        
        lps[0] = 0;
        int i = 1, prevLps = 0;
        while(i<s.size()){
            if(s[i]==s[prevLps]){ ///matched
                lps[i] = prevLps+1;
                prevLps++;
                i++;
            }
            else{
                if(prevLps == 0){
                    lps[i] = 0;
                    i++;
                }
                else{
                    prevLps = lps[prevLps-1]; ///intellectual backward
                }
            }
        }

    }
};
