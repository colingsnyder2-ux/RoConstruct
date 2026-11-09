// from server: 100% by colin
struct S {
    char pad[0x194];
    int field_194;
    void sub_444710(const char*);
    void f(int);
};

void S::f(int a) {
    if (a != this->field_194) {
        this->field_194 = a;
        this->sub_444710((const char*)0x8c2a44);
        this->sub_444710((const char*)0x8c291c);
    }
}
