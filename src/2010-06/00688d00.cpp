// from server: 7% by atomic.potato
struct S {
    void f();
};

extern "C" void __stdcall sub_686220();
extern "C" void __stdcall sub_688280();
extern "C" void __stdcall sub_7a8bea();
extern "C" void __stdcall sub_7a89b2();
extern "C" void __stdcall sub_6860b0();
extern "C" void __stdcall sub_9ea89c();

void S::f()
{
    char buf1[0x20];
    char buf2[0x20];
    char buf3[0x20];
    char buf4[0x20];
    char buf5[0x20];
    char buf6[0x20];
    char buf7[0x20];
    char buf8[0x20];
    char buf9[0x20];

    *(int*)buf1 = 0;
    *(int*)(buf1 + 4) = 1;
    *(void**)(buf1 + 8) = buf1;

    sub_686220();
    sub_688280();
    sub_7a8bea();
    sub_7a89b2();
    sub_6860b0();
    sub_9ea89c();
}
