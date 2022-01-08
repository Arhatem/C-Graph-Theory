#include <iostream>

using namespace std;

int main()
{
    int n , m ;
    cin>> n >> m ;
    int x[m*3] , y[m*2] , j=0 ;
    for (int i = 0 ; i < m*3 ; i++)
    {
       cin >> x[i];
    }

    for (int i = 1 ; i < m*3 ; i++)
    {
      if (i%3 != 0)
      {
          y[j] = x [i-1] ;
          j++;
      }

    }

        for(int i=0; i<m*2-1; i++)
    {
        for(int j=i+1; j<m*2; j++)
        {
            if(y[j] < y[i])
            {
                int temp = y[i];
                y[i] = y[j];
                y[j] = temp;
            }
        }
    }

    int z[m];
    for (int i = 0 ; i < n ; i++)
    {
      z[i] = 1 ;
    }
    int k = 0 ;
    for (int i = 0 ; i < m*2-1 ; i++)
    {
     for(int j=i+1; j<m*2; j++)
     {
         if (y[i]==y[j])
         {
             z[k]++ ;
         }
         else
         {
         j = m*2 ;
         i = i + z[k] - 1 ;
         k ++ ;
         }
     }
    }

  for (int i = 0 ; i < n ; i++)
        cout << z[i] << "\n' ;

}
