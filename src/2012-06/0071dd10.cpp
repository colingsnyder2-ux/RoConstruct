// from server: 100% by atomic.potato
typedef int* P;

struct S
{
    int f(P, P);
    int pad[12];
    int m30;
    int m34;
};

extern "C" int __cdecl sub_71dca0(int, int, int, int);

int S::f(P a, P b)
{
    int x = a ? (int)((char*)a - 28) : 0;
    return sub_71dca0(x, m30, m34, (int)((char*)b + 4));
}
