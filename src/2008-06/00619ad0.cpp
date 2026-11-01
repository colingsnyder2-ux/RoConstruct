// from server: 100% by colin
struct S {
    void f(int* p);
};

extern "C" void __fastcall sub_598C70(int);
extern "C" void __fastcall sub_598C90(int);
extern "C" void __fastcall sub_5F1690(int);

void S::f(int* p) {
    sub_598C70(*p);
    sub_5F1690((int)p);
    sub_598C90(*p);
}
