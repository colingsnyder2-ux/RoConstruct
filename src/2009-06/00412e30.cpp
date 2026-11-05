// from server: 37% by atomic.potato
struct S {
    int f(int);
};

extern "C" int __stdcall sub_4112e0(int*, int);
extern "C" int* __stdcall sub_412cf0(int*, ...);

int S::f(int a) {
    int v;
    sub_4112e0(&v, a);
    *(int*)this = v;
    if (a == 3) {
        short s1 = 1;
        short s2 = 1;
        short s3 = 0x578;
        int* p = sub_412cf0(&v, s1, s2, s3);
        *(int*)this = *p;
        return (int)this;
    }
    if (a == 4) {
        short s1 = 0x1f;
        short s2 = 0xc;
        short s3 = 0x270f;
        int* p = sub_412cf0(&v, 1, s1, s2, s3);
        *(int*)this = *p;
    }
    return (int)this;
}
