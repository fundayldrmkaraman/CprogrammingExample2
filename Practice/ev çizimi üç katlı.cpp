/* Ev sekli cizen program */
#include<stdio.h>
// Evin catisini cizen fonksiyon. 
void catiyi_ciz( void )
{
	printf( "    /\\   \n" );
	printf( "   /  \\  \n" );
	printf( "  /    \\ \n" );
	printf( " /      \\\n" );
	printf( "----------\n" );
}

// Evin katini cizen fonksiyon. 
void kat_ciz( void ) 
{
	printf( "|        |\n" );
	printf( "|        |\n" );
	printf( "|        |\n" );
	printf( "----------\n" );
}

// Programin calismasini saglayan 
// ana fonksiyon. 
int main( void )
{
	catiyi_ciz( );
	// 3 adet kat ciziliyor. 
	kat_ciz( );
	kat_ciz( );
	kat_ciz( );
	
	return 0;
}
