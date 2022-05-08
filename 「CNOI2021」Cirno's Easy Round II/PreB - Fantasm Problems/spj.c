#include <stdio.h>

#define AC 0
#define WA 1

int n;
int main(int argc,char *args[])
{
    FILE * f_in   = fopen( args[1], "r" );
    FILE * f_out  = fopen( args[2], "r" );
    FILE * f_user = fopen( args[3], "r" );
    
    int ret = AC;
    
    //fscanf( f_in, "%d", &n );
    //fscanf( f_in, "%d", &n );
    
    int x, y;
    
    while( ~fscanf( f_out , "%d", &x ) )
      { y = fscanf( f_user, "%d", &y );
	  	if( x ^ y ) ret = WA; }
	
	printf( "%d\n", ret );
	
    fclose(f_in);
    fclose(f_out);
    fclose(f_user);
    return ret;
}

