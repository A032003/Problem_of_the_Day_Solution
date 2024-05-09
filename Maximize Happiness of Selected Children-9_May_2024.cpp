class Solution {
public:
   
    long long maximumHappinessSum(vector<int>& happiness, int k) {

       long long int sum = 0;

        sort(happiness.begin(), happiness.end());
        int j=0;

        while (j != k) {
            for (int i = happiness.size() - 1; i >= 0; i--) {
                if(happiness[i]-j > 0 ){
                    sum = sum + happiness[i]-j;
                }
                
                happiness.pop_back();
                cout << sum<<endl;
                break;
               
            }
           
            j++;
        }
        return sum;
    }
};
