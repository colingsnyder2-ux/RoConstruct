// from server: 18% by atomic.potato
extern "C" {
    void __stdcall sub_009EA40C(void*);
    void __stdcall sub_009EA400(void*);
    void __stdcall sub_00682DE0(void*);
    void __stdcall sub_0067FD20(void*);
}

struct S {
    char pad[0x38];
    int field38;
    void method_00685A40(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

void S::method_00685A40(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15) {
    char buf1[0x1c];
    char buf2[0x1c];
    char buf3[0x1c];
    char buf4[0x1c];
    int v;
    sub_009EA40C(buf1);
    sub_009EA40C(buf2);
    int t = field38 + a1;
    sub_00682DE0((void*)t);
    int p = a1 ? a1 + 0x1c : 0;
    sub_009EA40C(buf3);
    sub_009EA40C(buf4);
    sub_0067FD20((void*)p);
    sub_009EA400(buf1);
    sub_009EA400(buf2);
}
