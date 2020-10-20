n = int(input("Enter the number of Elements : "))
a = list(map(int,input().split()))
summ = 0
sumOfAllElements = sum(a)

maxx = 0
for i in range(len(a)) :
    if i%2 == 0 :
        summ = summ + a[i]
    else :
        summ = summ - a[i]

    maxx = max(maxx ,summ)

x = maxx + 3
y = 0
sumnow = 0

grid = [[''] * (1000) for _ in range(1000)]

for i in range(len(a)) :
    if i%2 == 0 :
        sumnow = sumnow + a[i]
        cnt = 0
        while cnt < a[i] :
            grid[x][y] = '/'
            if cnt != a[i]-1 :
                x = x - 1
            y = y + 1
            cnt = cnt + 1

        if sumnow == maxx :
            grid[x-1][y-1] = '<'
            grid[x-1][y+1] = '>'
            grid[x-2][y-1] = '/'
            grid[x-2][y+1] = '\\'
            grid[x-2][y]  = '|'
            grid[x-3][y] = 'o'

            y = y + 1
    else :
        sumnow = sumnow - a[i]
        cnt = 0
        while cnt < a[i] :
            grid[x][y] = '\\'
            if cnt != a[i]-1 :
                x = x+1
            y = y+1
            cnt = cnt + 1

for i in range(maxx+3) :
    for j in range(sumOfAllElements+1) :
            if grid[i][j] != '/' and grid[i][j] != '\\' and grid[i][j] != '<' and grid[i][j] != '>' and grid[i][j] != '|' and grid[i][j] != 'o' :
                print(' ' , end = "")
            else :
                print(grid[i][j],end="")
    print("\n",end="")

"""
    
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
/


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


"""
