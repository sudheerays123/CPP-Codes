#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;

int main() {

    ll n,mm = 0, sumOfElements = 0;
    cin >> n;
    vector<ll> a(n+5);
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        sumOfElements += a[i];
        if(i%2 == 0) sum += a[i];
        else sum -= a[i];

        mm = max(mm , sum);
    }

    vector<vector<char>> grid(mm+5, vector<char>(sumOfElements+5));

    ll x = mm+3;
    ll y = 0;

    ll sumnow = 0;

    for(ll i = 0; i < n; i++){
        if(i%2 == 0){
            sumnow += a[i];
            ll cnt = 0;
            while(cnt < a[i]) {
                grid[x][y] = '/';
                if(cnt != a[i]-1) x--;
                y++;
                cnt++;
            }

            if(sumnow == mm){
                grid[x-1][y-1] = '<';
                grid[x-1][y+1] = '>';
                grid[x-2][y-1] = '/';
                grid[x-2][y+1] = '\\';
                grid[x-2][y] = '|';
                grid[x-3][y] = 'o';

                y++;
            }
        }
        else{
            sumnow -= a[i];
            ll cnt = 0;
            while(cnt < a[i]) {
                grid[x][y] = '\\';
                if(cnt != a[i]-1)x++;
                y++;
                cnt++;
            }
        }
    }

    for(ll i = 0; i <= mm+3; i++){
        for(ll j = 0; j < sumOfElements+5; j++){
            if(grid[i][j] != '/' && grid[i][j] != '\\' && grid[i][j] != '<' && grid[i][j] != '>' && grid[i][j] != '|' && grid[i][j] != 'o' ) cout << " ";
            else cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}

/*

Input 1: 

52
3 1 2 3 6 2 3 6 2 3 6 3 2 3 6 2 3 4 3 2 5 4 2 1 2 1 2 3 1 2 6 2 3 6 2 3 7 3 2 3 4 5 3 2 1 2 4 2 1 8 1 2

OUTPUT 2 : 

                                                                                                                                                                     
                                                                                                   o                  o            o                                 
                                                                                                  /|\                /|\          /|\                                
                                                                                                  < >                < >          < >                                
                                                                                                  / \                / \          / \                                
                                                                                             /\  /   \              /   \  /\    /   \              /\               
                                                                                            /  \/     \            /     \/  \  /     \    /\      /  \/\            
                                                                     /\          /\        /           \          /           \/       \  /  \/\  /      \           
                                                                    /  \      /\/  \      /             \  /\    /                      \/      \/        \          
                                                       /\          /    \  /\/      \/\  /               \/  \  /                                          \         
                                                  /\  /  \    /\  /      \/            \/                     \/                                            \        
                   /\                            /  \/    \  /  \/                                                                                           \       
              /\  /  \              /\          /          \/                                                                                                 \      
             /  \/    \            /  \  /\    /                                                                                                               \/\   
            /          \          /    \/  \  /                                                                                                                   \  
     /\    /            \  /\    /          \/                                                                                                                       
  /\/  \  /              \/  \  /                                                                                                                                    
 /      \/                    \/                                                                                                                                   

INPUT 2 : 

54
10 7 12 2 4 7 2 4 1 2 6 6 3 2 1 4 7 2 7 3 1 3 11 4 2 1 5 2 3 3 3 6 1 3 9 5 2 1 2 11 9 2 3 8 2 5 1 2 7 2 4 11 2 12

OUTPUT 2 :

                                                                                                                                                                                                                                                     
                                                                                                                                                     o                                                                                               
                                                                                                                                                    /|\                                                                                              
                                                                                                                                                    < >                                                                                              
                                                                                                                                                    / \                                                                                              
                                                                                                                           /\    /\                /   \                                                                                             
                                                                                                                      /\  /  \  /  \              /     \      /\                                                                                    
                                                                                                                     /  \/    \/    \            /       \  /\/  \                      /\                                                           
                                                                                                          /\        /                \          /         \/      \                /\  /  \                                                          
                                                                                                         /  \      /                  \        /                   \              /  \/    \                                                         
                                                                                                        /    \  /\/                    \/\    /                     \            /          \                          /\                            
                                                                                                       /      \/                          \  /                       \          /            \                        /  \                           
                                                                                                      /                                    \/                         \        /              \                  /\  /    \                          
                                                                                                     /                                                                 \      /                \  /\            /  \/      \                         
                                  /\                                                    /\          /                                                                   \    /                  \/  \          /            \                        
                                 /  \                                                  /  \        /                                                                     \  /                        \        /              \                       
                            /\  /    \                                                /    \/\    /                                                                       \/                          \      /                \                      
                           /  \/      \                                              /        \  /                                                                                                     \/\  /                  \                     
                          /            \                /\                          /          \/                                                                                                         \/                    \                    
                         /              \  /\          /  \                    /\  /                                                                                                                                             \  /\               
                        /                \/  \        /    \                  /  \/                                                                                                                                               \/  \              
         /\            /                      \      /      \    /\          /                                                                                                                                                         \             
        /  \          /                        \/\  /        \  /  \/\      /                                                                                                                                                           \            
       /    \        /                            \/          \/      \    /                                                                                                                                                             \           
      /      \      /                                                  \  /                                                                                                                                                               \          
     /        \    /                                                    \/                                                                                                                                                                 \         
    /          \  /                                                                                                                                                                                                                         \        
   /            \/                                                                                                                                                                                                                           \       
  /                                                                                                                                                                                                                                           \      
 /                                                                                                                                                                                                                                             \     
/                                                                                                                                                                                                                                               \    

*/                                                                                                   
