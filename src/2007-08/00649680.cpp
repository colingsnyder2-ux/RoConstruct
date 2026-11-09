// from server: 100% by colin
struct CXTPCommandBar {
    int f(int);
    int field0;
    int field4;
    int field8;
    int fieldC;
};

extern "C" void __fastcall sub_648640(CXTPCommandBar*);

int CXTPCommandBar::f(int arg) {
    sub_648640(this);
    field4 = arg;
    fieldC = 1;
    return (int)this;
}
