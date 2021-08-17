//find max contigious sum and elements forming max sum

int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int sum_max=0;
        int local_max_sum=0;
        int index_start=0;
        int index_end=0;
        for(int i=0;i<n;i++){
            local_max_sum=local_max_sum+arr[i];
            if(local_max_sum>sum_max){
                sum_max=local_max_sum;
                index_end=i;
            }
            if(local_max_sum<0)
        {local_max_sum=0;
            index_start=i;}
        }
        cout<<index_start<<" "<<index_end;
        return sum_max;
    }
