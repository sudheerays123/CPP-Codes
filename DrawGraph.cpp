#include <iostream>
#include <vector>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tiille(NULL); cout.tie(NULL);
typedef long long int ll;

int main() {

    ll n,mm = 0;
    cin >> n;
    vector<ll> a(n+5);
    ll sum = 0;
    for(ll i = 0; i < n; i++) {
        cin >> a[i];
        if(i%2 == 0) sum += a[i];
        else sum -= a[i];

        mm = max(mm , sum);
    }

    vector<vector<char>> grid(mm+5, vector<char>(1000));

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
        for(ll j = 0; j < 1000; j++){
            if(grid[i][j] != '/' && grid[i][j] != '\\' && grid[i][j] != '<' && grid[i][j] != '>' && grid[i][j] != '|' && grid[i][j] != 'o' ) cout << " ";
            else cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}
