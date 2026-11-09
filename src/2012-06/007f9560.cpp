// from server: 24% by atomic.potato
struct S {
    char pad0[0x20];
    int f0;
    int f1;
    int f2;
    int f3;
    int f4;
    int method(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

int S::method(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15)
{
    char buf[0x38];
    *(int*)buf = 0;
    *(int*)(buf + 0x20) = a12;
    *(int*)(buf + 0x24) = a13;
    *(int*)(buf + 0x28) = a14;
    *(int*)(buf + 0x2c) = a15;
    *(int*)(buf + 0x30) = a11;
    if (a1) {
        *(int*)buf = a1;
        (*(void (__stdcall**)(int, void*, int*))a1)(0, buf + 8, (int*)(buf + 0x10));
    }
    return 0;
}
