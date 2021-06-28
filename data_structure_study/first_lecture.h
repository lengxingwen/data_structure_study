/*
循环打印1到N
*/
void Loop_PrintN(int N);
/*
递归打印1到N
*/
void Recursion_PrintN(int N);
/*
计算给定多项式在给定点x处的值
*/
double f1(int n, double a[], double x);
double f2(int n, double a[], double x);
/*
给定N个整数的序列{ A1, A2, …, AN}，求子列的最大值。暴力算法t(n)=o(n3)
*/
int MaxSubseqSum1(int A[], int N);
/*
给定N个整数的序列{ A1, A2, …, AN}，求子列的最大值。双指针算法t(n)=o(n2)
*/
int MaxSubseqSum2(int A[], int N);
/* 返回3个整数中的最大值 */
int Max3(int A, int B, int C);
/* 分治法求List[left]到List[right]的最大子列和 */
int DivideAndConquer(int List[], int left, int right);
/*
给定N个整数的序列{ A1, A2, …, AN}，求子列的最大值。分治算法t(n)=o(nlogn)
*/
int MaxSubseqSum3(int List[], int N);
/*
给定N个整数的序列{ A1, A2, …, AN}，求子列的最大值。在线处理算法t(n)=o(n)
*/
int MaxSubseqSum4(int List[], int N);
