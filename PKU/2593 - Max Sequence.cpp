#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N,a[100000],dp1[100000],dp2[100000];
        
    while(true){
        scanf("%d",&N);
        if(N == 0) break;
        
        for(int i = 0;i < N;++i)
            scanf("%d",&a[i]);
        
        dp1[N-1] = a[N-1];
        
        for(int i = N-2;i >= 0;--i)
            dp1[i] = a[i] + max(0,dp1[i+1]);
        
        for(int i = N-2;i >= 0;--i)
            dp1[i] = max(dp1[i],dp1[i+1]);
        
        dp2[0] = a[0];
        
        for(int i = 1;i < N;++i)
            dp2[i] = a[i] + max(0,dp2[i-1]);
        
        for(int i = 1;i < N;++i)
            dp2[i] = max(dp2[i],dp2[i-1]);
        
        int ans = a[0] + a[1];
        
        for(int i = 0;i + 1 < N;++i)
            ans = max(ans,dp2[i] + dp1[i+1]);
        
        printf("%d\n",ans);
    }
    
    return 0;
}
