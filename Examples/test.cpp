#include <iostream>
#include <iomanip>

using namespace std;

void letsIteratore()
{   
    int pee = 123213;
    int count;
    
    for (int i = -1; i < pee; i++)
    {
        count++;
    	break;
    }   
    cout << count << '\n'; 
}

int main()
{   
    char h;
    while ( h != 'f')
    {	
    	cin >> h;
        if(  h == 'h')
        {
    	    letsIteratore();
        }	
    }

return 0;
}

