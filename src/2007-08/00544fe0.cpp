// from server: 42% by colin
struct S {
    void f();
};

extern "C" {
    int __stdcall sub_77E57C(const char*, int, int);
    void __stdcall sub_77E698(void*, const char*);
    void __stdcall sub_77E568(void*, void*, void*);
    void __stdcall sub_77E6AC(void*);
}

void __stdcall sub_44CF10(void*);

void S::f() {
    char buf1[16];
    char buf2[16];
    char buf3[16];
    void* p;

    if (sub_77E57C("file://", 0, 7) == 0) {
        sub_44CF10(this);
        return;
    }

    sub_77E698(buf1, "file://");
    sub_77E568(buf3, buf1, this);
    sub_44CF10(buf3);
    sub_77E6AC(buf2);
    sub_77E6AC(buf1);
}
