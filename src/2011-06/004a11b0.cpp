// from server: 100% by atomic.potato
struct CVideoStream_004a11b0
{
    int f(int a1, int a2, int a3, int a4, int a5, double a6);
};

int CVideoStream_004a11b0::f(int a1, int a2, int a3, int a4, int a5, double a6)
{
    *(int *)(a1 + 0x74) = a2;
    *(int *)(a1 + 0x78) = a3;
    *(int *)(a1 + 0x7c) = a4;
    *(int *)(a1 + 0x80) = a5;
    *(volatile double *)(a1 + 0x84) = a6;
    return 0;
}
