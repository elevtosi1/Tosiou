#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{ char	seq[100000];
  char	compl[100000];
  int	length, x, y, a, b, start, start2, len, len2, z, k, n, m;

   

  while(scanf("%s", seq) == 1)
   { length = strlen(seq);
     a = 0;
     for (b = 0 ; b < length ; b++)
     {if (seq[b] ==  'A' || seq[b] == 'a' || seq[b] == 'T' || seq[b] == 't' || seq[b] == 'G' || seq[b] == 'g' || seq[b] == 'C' || seq[b] == 'c')
       { 
       }
      else 
         {a = 1;
         printf("There are invalid characters in the sequence.\n");
         break; }
     }
     if (a == 1)
     { printf("Please, give another sequence.\n");
       continue;}

     x = 0;
     len = 0;
     while(x < length - 5)
     {if ((seq[x] == 'A' || seq[x] == 'a') && (seq[x+1] == 'T' || seq[x+1] == 't') && (seq[x+2] == 'G' || seq[x+2] == 'g'))
        {x++;
         for (y = x + 2 ; y <= length - 3 ; y += 3)
           {if (((seq[y] == 'T' || seq[y] == 't') && (seq[y+1] == 'G'|| seq[y+1] == 'g') && (seq[y+2] == 'A' || seq[y+2] == 'a')) || ((seq[y] == 'T'  || seq[y] == 't') && (seq[y+1] == 'A' || seq[y+1] == 'a') && (seq[y+2] == 'A' || seq[y+2] == 'a')) || ((seq[y] == 'T' || seq[y] == 't') && (seq[y+1] == 'A' || seq[y+1] == 'a') && (seq[y+2] == 'G' || seq[y+2] == 'g')))
              { start = x - 1;
                len = y + 4 - x;
                printf("A possible coding region of the sequence has length %d bp and it is: %.*s \n", len, len, seq + start); 
                x = y + 3;
                break ;
              }

            }
          }
      else
      { x++; }
      }
    n = 0;
    for (z = length - 1 ; z>=0 ; z--)
     {if (seq[z] == 'A')
     {compl[n] = 'T'; }
     else if (seq[z] == 'a')
     {compl[n] = 't'; }
     else if (seq[z] == 'T')
     {compl[n] = 'A'; }
     else if (seq[z] == 't')
     {compl[n] = 'a'; }
     else if (seq[z] == 'G')
     {compl[n] = 'C'; }
     else if (seq[z] == 'g')
     {compl[n] = 'c'; }
     else if (seq[z] == 'C')
     {compl[n] = 'G'; }
     else if (seq[z] == 'c')
     {compl[n] = 'g'; }
      n++; }
    
    k = 0;
    len2 = 0;
    while(k < length - 5 )
     {if ((compl[k] == 'A' || compl[k] == 'a') && (compl[k+1] == 'T' || compl[k+1] == 't') && (compl[k+2] == 'G' || compl[k+2] == 'g'))
        {k++;
         for (m = k + 2 ; m <= length - 3 ; m += 3)
           {if (((compl[m] == 'T' || compl[m] == 't') && (compl[m+1] == 'G'|| compl[m+1] == 'g') && (compl[m+2] == 'A' || compl[m+2] == 'a')) || ((compl[m] == 'T'  || compl[m] == 't') && (compl[m+1] == 'A' || compl[m+1] == 'a') && (compl[m+2] == 'A' || compl[m+2] == 'a')) || ((compl[m] == 'T' || compl[m] == 't') && (compl[m+1] == 'A' || compl[m+1] == 'a') && (compl[m+2] == 'G' || compl[m+2] == 'g')))
              { start2 = k - 1;
                len2 = m + 4 - k;
                printf("A possible coding region of the complementary strand has length %d bp and it is: %.*s \n", len2, len2, compl + start2);
                k = m + 3;
                break ;
              }

            }
          }
      else
      { k++; }
      }

   if (len == 0)
     { printf("The sequence has not coding regions. \n"); }
   if (len2 == 0)
     { printf("The complementary strand of the sequence has not coding regions. \n"); }
 }

}
