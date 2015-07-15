/**************************************************************************************************
// file:	recursion.h
//
// summary:	Declares the recursion class
 **************************************************************************************************/
#ifndef RECURSION_H_
#define RECURSION_H_

/**************************************************************************************************
 * <summary>	Factorials. </summary>
 *
 * <remarks>	Mr Li, 2014/4/2. </remarks>
 *
 *       							1			n = 0;	
 *		definition:			n = 
 *									n(n - 1)!   n > 0;
 *						
 * <param name="para">	The para. </param>
 *
 * <returns>	An int. </returns>
 **************************************************************************************************/

long int factorial(int para);

/**************************************************************************************************
 * <summary>	Fibonaccis. </summary>
 *
 * <remarks>	Mr Li, 2014/4/2. </remarks>
 *									1						n = 0;
 *		definition:		F(n) =		1						n = 1;
 *									F(n - 1) + F(n - 2)		n > 1;
 * <param name="para">	The para. </param>
 *
 * <returns>	A long. </returns>
 **************************************************************************************************/

long int Fibonacci(int para);

/**************************************************************************************************
 * <summary>	Ackermans. </summary>
 *
 * <remarks>	Mr Li, 2014/4/2. </remarks>
 * 
 *									F(1,0) = 2										n = 1,	m = 0;			
 *		definition:		F(n, m)=	F(0,m) = 1										n = 0,	m >= 0;		
 *									F(n,0) = n + 2									n >= 2,	m = 0;
 *									F(n,m) = F(F(para - 1, para1), para1 - 1)		n,m >= 1;
 *									
 * <param name="para"> 	The para. </param>
 * <param name="para1">	The first para. </param>
 *
 * <returns>	A long. </returns>
 **************************************************************************************************/

long int Ackerman(int para, int para1);

/**************************************************************************************************
 * <summary>	È«ÅÅÁÐ. </summary>
 *
 * <remarks>	Mr Li, 2014/4/2. </remarks>
 * 
 *									r									n = 1;						
 *		definition:		Perm(n)
 *									(r1)Perm(R1)...(rn)Perm(Rn)			n > 1;
 *									
 * <param name="arr">  	[in,out] If non-null, the array. </param>
 * <param name="start">	The start. </param>
 * <param name="end">  	The end. </param>
 **************************************************************************************************/

void Perm(int * arr,   int start,   int end);

/**************************************************************************************************
 * <summary>	Integer division. </summary>
 *
 * <remarks>	Mr Li, 2014/4/2. </remarks>
 * 
 *									1						n = 1,m = 1;		
 *		definition:		F(n,m) =	F(n,n)					n < m;
 *									1 + F(n,n-1)			n = m;
 *									F(n,m-1)+q(n-m,m)		n > m > 1;
 *									
 * <param name="num">	Number of. </param>
 * <param name="max">	The maximum. </param>
 *
 * <returns>	An int. </returns>
 **************************************************************************************************/

int IntegerDivision(int num, int max);

/**************************************************************************************************
 * <summary>	Binary search. </summary>
 *
 * <remarks>	Mr Li, 2014/4/2. </remarks>
 *
 * <param name="arr"> 	[in,out] If non-null, the array. </param>
 * <param name="key"> 	The key. </param>
 * <param name="size">	The size. </param>
 *
 * <returns>	An int. </returns>
 **************************************************************************************************/

int BinarySearch(int * arr, const int key,   int size);

/**************************************************************************************************
 * <summary>	Merge sort. </summary>
 *
 * <remarks>	Mr Li, 2014/4/2. </remarks>
 *
 * <param name="arr">  	[in,out] If non-null, the array. </param>
 * <param name="left"> 	The left. </param>
 * <param name="right">	The right. </param>
 * <param name="temp">	The temp. </param>
 **************************************************************************************************/

void MergeSort(int * arr, int left, int right, int * temp);

/**************************************************************************************************
 * <summary>	Quick sort. </summary>
 *
 * <remarks>	Mr Li, 2014/4/2. </remarks>
 *
 * <param name="arr">  	[in,out] If non-null, the array. </param>
 * <param name="start">	The start. </param>
 * <param name="end">  	The end. </param>
 **************************************************************************************************/

void QuickSort(int * arr,   int start,   int end);

#endif
/**************************************************************************************************
// End of recursion.h
 **************************************************************************************************/
