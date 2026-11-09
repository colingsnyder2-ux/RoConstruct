// from server: 76% by colin
struct S {
    char pad[0x10];
    int* m10;
    int* m14;
    int* m20;
    int* m24;
    int* m30;
    int* m34;
    char pad2[0x8];
    int m40;
    int* m4c;
    int f(int a, int b, int c, int d, int e, int f);
};

extern "C" int __stdcall pubsync(void*);

int S::f(int a, int b, int c, int d, int e, int f)
{
    if (*m24 != 0)
        pubsync(0);
    if (a == 1 && *m20 != 0) {
        int v = *m30;
        c -= v;
        d -= (v >> 31);
    }
    *m10 = 0;
    *m20 = 0;
    *m30 = 0;
    *m14 = 0;
    *m24 = 0;
    *m34 = 0;
    return ((int (__thiscall*)(void*, int, int, int, int, int, int*))0x54f600)(&m40, c, d, a, e, f, m4c);
}
