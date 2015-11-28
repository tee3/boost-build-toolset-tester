#include <string.h>

int
main ()
{
   char s [sizeof ("Hello, world!\n") + 1];
   strcpy ("Hello, world!\n",s);

   return 0;
}
