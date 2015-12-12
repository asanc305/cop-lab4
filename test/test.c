#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] )
{
  unsigned char buffer1 ;
  FILE* input_file ;
  FILE* output_file ;

	//open files
	input_file = fopen( "/test/war-and-peace.txt", "rb" ) ; 
	output_file = fopen( "/test/output", "wb" ) ;

	//check files
	if(input_file == NULL || output_file == NULL)
	{
		if( input_file == NULL )
			printf("Error opening input file\n") ;
		else
			printf("Error opening output file\n") ;
		return -1 ;
	}

	//read first byte
	fread( &buffer1, 1, 1, input_file ) ;  

	while( !feof(input_file) )
	{
		fwrite( &buffer1, 1, 1, output_file ) ;

		//fwrite( " !!MORE!! ", 1, 10, output_file ) ; 

		fread( &buffer1, 1, 1, input_file ) ;   
	}
	fclose( input_file ) ;
	fclose( output_file ) ; 
  
}
