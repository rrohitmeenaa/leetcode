class Solution {
public:
    int smallestIndex(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        
        
        for(int i=0;i<n;i++){
            int num = arr[i];
            int sum = 0;
            if((num==0)&&(i==0)){return i;}
            if(num<0){num = -num;}
            while(num>0){
                int y = num % 10;
                num = num/10;
                sum = sum + y;

            }
            if(sum == i){return i;}
        }
        return -1;
    }
};