class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        /*string res1="";
        string res2="";
        for(int i=0;i < word1.size();i++){
            res1+=word1[i];
        }
        for(int j=0;j<word2.size();j++){
            res2+=word2[j];
        }
        if(res1==res2){
            return 1;
        }
        return 0;*/
        int m=word1.size();
        int n=word2.size();
        int w1i=0; int i=0; 
        int w2i=0; int j=0;
        while(w1i<m && w2i<n){
            if(word1[w1i][i]!=word2[w2i][j])
            return 0;
            i++;
            j++;
            if(i==word1[w1i].length()){
            i=0;
            w1i++;
            }
            if(j==word2[w2i].length()){
            j=0;
            w2i++;
            }
        }
        if(w1i==word1.size() && w2i==word2.size())
        return 1;

        return 0;
    }
};