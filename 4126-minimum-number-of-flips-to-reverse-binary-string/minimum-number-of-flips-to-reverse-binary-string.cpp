class Solution {
public:
    int minimumFlips(int n) {
        string s="";
        while(n>0){
            int bit=n%2;
            s=char('0' + bit) + s;
            n=n/2;
        }
        string t=s;
        reverse(t.begin(),t.end());
        int flip=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]){
                flip++;
            }
        }
            
        
     return flip;
    }
};