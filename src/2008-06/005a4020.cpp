// from server: 100% by tester
struct D { double get(); };
struct S {
    void f();
    void set(double*);
    char data[0x158];
    D d;
};
void S::f() {
    double value = d.get();
    set(&value);
}
