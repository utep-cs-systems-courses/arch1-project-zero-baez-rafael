#include <stdio.h>
#include "draw.h"

int main() 
{
  puts("Welcome!");
  int font_ind = 0;
  while (1) { // Infinite while loop
    printf("Current font is '%d'.",font_ind);
    fputs("Select which shape you want to print (Triangle = t, Square = s, Chars = c, Arrow = a, Change font = f) or 'q' to quit\n> ", stdout);
    fflush(stdout);		/* stdout only flushes automatically on \n */
    int c;
    while ((c = getchar()) == '\n'); /* ignore newlines */
    if (c == EOF)		     /* terminate on end-of-file */
      goto done;

    // Given the user answer, select which method to call
    switch (c) {
    case 't':
      puts("You selected triangle:");
      print_triangle(5, 7);
      break;
    case 's':
      puts("You selected square:");
      print_square(5, 5);
      break;
    case 'c':
      puts("You selected chars:");
      for (char c = 'A'; c < 'D'; c++){
	if(font_ind == 0)
	  print_char_11x16(c);
	if(font_ind == 1)
	  print_char_8x12(c);
	if(font_ind == 2)
	  print_char_5x7(c);
      }
      break;
    case 'a':
      puts("You selected a for arrow:");
      print_triangle(0,7);
      print_square(5,5);
      break;
    case 'f':
      fputs("Choose the number for the font:\n0 = 11x16\n1 = 8x12\n2 = 5x7\n",stdout);
      fflush(stdout);
      int font;
      while((font = getchar()) == '\n');
      if (font == EOF)
	goto done;
      switch(font){
       case '0':
	 font_ind = 0;
	 break;
       case '1':
	 font_ind = 1;
	 break;
       case '2':
	 font_ind = 2;
	 break;
       case '\n':
	 break;
       default:
	 printf("Invalid option '%c', please try again!\n", font);
      }
      break;
    case 'q':
      puts("Bye!");
      goto done; 		/* terminate */
    case '\n':
      break;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

 done: // To exit from program
  return 0;
}
