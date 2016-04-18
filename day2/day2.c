#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 20
#define SUCCESS 0
#define FAIL -1


int do_the_math( int w, int l, int h )
{
	int lowest = 0;
	int sides[3] = {
		w * l,
		w * h,
		l * h
	};
	int total = 0;
	int i = 0;

	for( i = 0; i < 3; ++i ) {
		if( sides[i] < sides[lowest] ) {
			lowest = i;
		}
		total += 2 * sides[i];
	}
	
	total += sides[lowest];

	return total;
}


int get_file( const char fileName[], char * theStrings[] )
{

	char ch;
	int numLines = 0, returnCode;
	FILE *theFile;

	theFile = fopen( fileName, "r" );
	if( theFile != NULL ) {
		returnCode = SUCCESS;
	// Count the lines
		while( !feof( theFile ) ) {
			ch = fgetc( theFile );
			if( ch == '\n' ) {
				++numLines;
			}
		}
	// Allocate space
		theStrings = malloc( numLines * sizeof( char[MAX_STR] ) );
	// Populate theStrings

		fclose( theFile );
	}
	else {
		returnCode = FAIL;
	}
	// Return
	printf( "%d\n", numLines );
	return returnCode;
}


int main( const int argc, const char *argv[] )
{
	char * theStrings[MAX_STR];
	get_file( "day2.c", theStrings );
	return SUCCESS;
}
