// from server: 25% by colin
struct S {
    void f();
};

extern "C" {
    void __stdcall sub_77ddac();
    void __stdcall sub_77d59c();
    void __stdcall sub_77dd98();
    void __stdcall sub_77ddbc();
    void __stdcall sub_77e658();
    void __stdcall sub_77e69c();
    void __stdcall sub_77e6ac();
    void __stdcall sub_77e65c();
}

void __stdcall sub_6303f4();
int __stdcall sub_6303ee();
void __stdcall sub_6303e8();
void __stdcall sub_6303dc();
void __stdcall sub_630a1e();
void __stdcall sub_52c940();
void __stdcall sub_408740();
void __stdcall sub_547ca0();
void __stdcall sub_440440();

void S::f() {
    char buf[0x2a0];
    sub_77ddac();
    sub_77d59c();
    sub_77dd98();
    sub_6303f4();
    if (sub_6303ee() == 1) {
        sub_6303e8();
        sub_77dd98();
        sub_77e658();
        sub_52c940();
        sub_408740();
        sub_547ca0();
        sub_77e69c();
        sub_77e6ac();
        sub_77e65c();
        sub_77ddbc();
        sub_440440();
        sub_77e6ac();
    }
    sub_6303dc();
    sub_77ddbc();
    sub_630a1e();
}
