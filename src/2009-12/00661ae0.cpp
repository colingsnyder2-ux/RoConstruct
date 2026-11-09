// from server: 36% by atomic.potato
extern "C" int __cdecl sub_6322E0(int);
extern "C" void __cdecl sub_7E1DF0();

struct S {
    void* vtbl;
    int field4;
    int field8;
    int fieldC;
    char field10;
    char field11;
    char pad12[2];
    S(int a, int b, char c, char d);
};

S::S(int a, int b, char c, char d)
{
    this->vtbl = (void*)0x99fd70;
    this->field4 = sub_6322E0(a);
    if (*(volatile char*)0xb901e4 != 0)
        sub_7E1DF0();
    this->vtbl = (void*)0x9ba0a4;
    this->field8 = b;
    this->fieldC = sub_6322E0(a);
    this->field11 = c;
    this->field10 = d;
}
