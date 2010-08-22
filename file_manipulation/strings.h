#include <cassert.h>

int getword(char *s, int limit, FILE *stream){
   int c;
   char *w = s;
   assert( limit > 0 && s != NULL && stream != NULL);

   /* skip to start of the word */
   while (!isalnum(c = getc(stream)) && EOF != c)
      ;
   if(EOF == c){
      return EOF;
   }else if(--limit > 0){ /* reduce limit by 1 to allow for the \0 */
      *w++ = tolower(c);
   }

   while(--limit > 0){
      if(isalnum(c = getc(stream))){
         *w++ = tolower(c);
      }else if('\'' == c){
         limit++;
      }else{
         break;
      }
   }
   *w = '\0';
   return w - s;
}

