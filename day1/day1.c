#include <stdio.h>
#include <string.h>

#define MAX_STR 8000


char * get_file( const char fileName[], char theString[] )
{
	int returnCode;
	FILE *theFile;

	theFile = fopen( fileName, "r" );
	if( theFile != NULL ) {
		returnCode = 0;
		fscanf( theFile, "%s", theString );
		fclose( theFile );
	}
	else {
		returnCode = 1;
	}
	return 0;
}


int count_this_punk( const char theString[] )
{
	int i = 0;
	int count = 0;

	while( theString[i] != '\0' ) {
		if( theString[i] == '(' ) {
			++count;
		}
		else if( theString[i] == ')' ) {
			--count;
		}
		else {
			printf( "Unexpected character: %c\n", theString[i] );
		}
		++i;
	}
	printf( "\n" );
	return count;
}


int main( const int argc, const char *argv[] )
{
	char fileName[MAX_STR];
	char theString[MAX_STR];
	int count;

	switch( argc ) {
		case 2: 
			strcpy( fileName, argv[1] );
			break;
		default:
			printf( "Enter filename: " );
			scanf( "%s", fileName );
			break;
	}

	get_file( fileName, theString );

	count = count_this_punk( theString );

	printf( "Santa ends on floor %d\n", count );

	return 0;	
}
