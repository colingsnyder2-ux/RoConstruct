// from server: 100% by tester
struct Tool {
    char pad[0x104];
    int field_bc;
    int method_5d1ae0();
    int method_5d1b60(int);
    void method_5d4650(int, int);
    void method_5d2200();
};

extern "C" bool __cdecl sub_57d570(Tool*);
extern "C" int __cdecl sub_486830(Tool*);

void Tool::method_5d2200() {
    int edi;
    if (this->method_5d1ae0() == 0) {
        edi = 0;
    } else if (sub_57d570(this) == false) {
        edi = 1;
    } else {
        edi = this->method_5d1b60(this->field_bc);
    }
    this->method_5d4650(edi, sub_486830(this));
}
