 #include "main.h"
  1
  2 /**
  3  * largest_number - returns the largest of 3 numbers
  4  * @a: first integer
  5  * @b: second integer
  6  * @c: third integer
  7  * Return: largest number
  8  */
  9
 10 int largest_number(int a, int b, int c)
 11 {
 12     int largest;
 13
 14     if ((a > b && a > c))
 15     {
 16         largest = a;
 17     }
 18     else if ((b > a && b > c))
 19     {
 20         largest = b;
 21     }
 22     else
 23     {
 24         largest = c;
 25     }
 26     return (largest);
 27 }