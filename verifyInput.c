// verifyInput.c
// This program will verify scanf user inputs

#include <stdio.h>

int main(){

  int num1;
  double num2;
  char ch;

  int keepGoing = 1;
  int errdetect = 0;

  // This implimentation does not detect input "1abc" to "10abc" as invalid
  // because scanf() using %d reads input left to right, storing the number
  // and "abc" will be lingering in the input buffer
  // this behavior allows scanf() to read arbitrarily formated data input
  // such as (int)(char)(double) with scanf("%d%c%lf",&num,&ch,&dec)

  printf("Enter an integer 1-10\n"); 
  while(keepGoing){
    scanf("%d",&num1);
    printf("num1 = %d  (NOTE: num1 might not be initialized)\n", num1);
    if(num1 >= 1 && num1 <= 10 ){
      keepGoing = 0;
    }
    else{
      // call getchar() till newline character is found
      // this helps clear input buffer of invalid data
      while((getchar()) != '\n');
      printf("Invalid, input must be an integer 1-10\n");
    }
  }// end while loop

  printf("num1 value verified\n");

  // num1 has satisfied previous "if" condition 
  // but this does not mean the input was exactly what was ask for
  // remember printf("%c", num1) will read "5abc" just fine
  // and write "5" to num1 but we want the "abc" part to invalidate
  // the entire input "5abc" or any character input that is not a number
   
    
  // This implementation below will do just that

  printf("Enter an int 11-20\n");
  keepGoing = 1;
  while(keepGoing){
    scanf("%d",&num1);
    printf("num1 = %d\n", num1);

    // check input buffer and set errdetect if a non-numeric character is found
    while((ch = getchar()) != '\n'){
      if( ch < 48 || ch > 57){
      printf("detected non-numeric character %c, ascii code %d\n", ch, ch);
      errdetect = 1;
      }
    }

    // if non-numeric character was found in buffer
    // then restart while loop from begining
    if(errdetect == 1){
    printf("Invalid input, try again\n");
    errdetect = 0;
    continue;
    }

    if(num1 >= 11 && num1 <= 20 ){
      keepGoing = 0;
    }
    else{
    printf("Input must be 11-20\n");
    }
  }
  printf("num1 value and input format verified\n");

  return 0;
}
