#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 20
#define SUCCESS 0
#define FAIL -1
#define NUM_DIMENSIONS 3 // LOL


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


int break_it_down( char *theStrings[], int numLines )
{

	char thisNum[MAX_STR];
	int row = 0, character = 0, dimension, digit = 0, lineNums[NUM_DIMENSIONS];

	for( row = 0; row < numLines; ++row ) {
		dimension = 0;
		for( character = 0; character < MAX_STR; ++character ) {
			if( theStrings[row][character] != 'x' ) {
				thisNum[digit] = theStrings[row][character];
				++digit;
			}
			else {
				digit = 0;
				lineNums[dimension] = atoi( thisNum );
				++dimension;
			}
		}
	}

}


int get_file( const char fileName[], char *theStrings[] )
{

	char ch;
	int numLines = 0, returnCode, i = 0, j = 0;
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
		while( !feof( theFile ) ) {
			theStrings[i][j] = fgetc( theFile );
			if( theStrings[i][j] == '\n' ) {
				theStrings[i][j] = '\0';
				++i;
				j = -1; // No need for an else, just always increment!
			}
			++j;
		}

		/* This function will call some other functions that will actually do
		 * everything I want to happen to these strings.
		 */
		break_it_down( theStrings, numLines );

		free( theStrings );
		fclose( theFile );
	}
	else {
		returnCode = FAIL;
	}
	// Return
	return returnCode;
}


int main( const int argc, const char *argv[] )
{
	char * theStrings[MAX_STR];
	get_file( "day2.c", theStrings );
	return SUCCESS;
}
