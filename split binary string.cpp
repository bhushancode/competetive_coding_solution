int maxSubStr(string S, int n)
{

	
    int maxnum=0;
    int noofzero=0;
    int noofone=0;
    for(int i=0;i<n;i++){
        if(S[i]=='0'){
            noofzero++;
            if((noofzero==noofone) & (2*noofone>maxnum)){
                maxnum=2*noofone;
                noofone=0;
                noofzero=0;
            }
        }
         else if(S[i]=='1'){
            noofone++;
            if((noofzero==noofone) & (2*noofone>maxnum)){
                maxnum=2*noofone;
                noofone=0;
                noofzero=0;
            }
        }
      cout<<maxnum;
    }
