class Solution {
public:
    int isWinner(vector<int>& v1, vector<int>& v2) {
        int x = v1[0], y = v2[0];//for size 1 score = index 0 score
        i = 0, n = v1.size();
        
        for(i = 1; i < n; i++){
            if(i==1){//for index 1 check for index 0
                if(v1[i-1]==10)
                {
                    x += v1[i]*2;
                }
                else 
                {
                    x += v1[i];
                }
                ///////////////////
                if(v2[i-1]==10)
                {
                    y += v2[i]*2;
                }
                else 
                {
                    y += v2[i];
                }
            }
            else{//for other indexs check for i-1 || i-2
                
                //this is for v1
                if(v1[i-1]==10||v1[i-2]==10)
                x += v1[i]*2;
                
                else
                x += v1[i];

                //this is for v2
                if(v2[i-1]==10||v2[i-2]==10)
                y += v2[i]*2;

                else y += v2[i];

            }
        }
        if(x>y)return 1;
        if(y>x)return 2;
        return 0;
    }
};