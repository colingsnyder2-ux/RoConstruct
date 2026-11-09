// from server: 48% by colin
struct S {
    void f();
};

extern "C" void __stdcall sub_77E698(void*);
extern "C" void __fastcall sub_58C6C0(void*, int, void*);

void S::f() {
    char buf[28];
    sub_77E698(buf);
    sub_58C6C0(this, 1, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 2, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 3, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 4, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 5, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 6, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 7, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 8, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 9, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 10, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 11, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 12, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 13, buf);
    sub_77E698(buf);
    sub_58C6C0(this, 14, buf);
}
