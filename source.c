/*
lets find the square root of any number!

how does this work
	if input value is >= 1,
	increase value slightly and compare value*value and input number
	if value is greater than input number, finish loop
	(differences are absolute value, if smaller than previous difference, keep number of that session)
	if input value is < 1,
	same but start increasing at num, and ends loop when it's 1

problems
	too slow!
	theoritically we can improve accuracy by just using smaller units when increasing (ex. 0.1 -> 0.0001)
	however this will be much slower than now.

	unnecessary calculations!
	no square root value is as small as its original number.
	no square root of 0.x is big as 1.
	however i couldn't set lower limit because there are examples like 1.0000x and 0.99999x.
	*/

#include <stdio.h>
#pragma warning (disable:4996)

void main()
{
	long double rootnum = 0;
	long double num;
	long double difference;
	long double prev_difference;
	int B_differenceN = 0;

	printf("prints square root of input number\n");
	printf("type in number: ");
	scanf("%Lf", &num);
	if (num >= 1.0) //if sqrt(num) is smaller than num
	{
		prev_difference = 0.1;
		for (long double cnt = 0.0; cnt < num; cnt += 0.00000001)
		{
			difference = (cnt * cnt - num);
			if (difference < 0)
			{
				difference *= -1; //abs value
				B_differenceN = 1;
			}
			if (difference < prev_difference)
			{
				prev_difference = difference;
				rootnum = cnt;
			}
		}
	}
	else //when num is 0.x, sqrt(num) is bigger than num
	{
		prev_difference = 0.1;
		for (long double cnt = num; cnt < 1.0; cnt += 0.00000001)
		{
			difference = (cnt * cnt - num);
			if (difference < 0)
			{
				difference *= -1; //abs value
				B_differenceN = 1;
			}
			if (difference < prev_difference)
			{
				prev_difference = difference;
				rootnum = cnt;
			}
		}
	}
	
	printf("\n\nroot is %Lf", rootnum);

}