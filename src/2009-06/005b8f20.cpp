// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
void copyField(int& dst, const int& src);
struct Data {
    void assign(Data* src);
};
struct X {
    int a;
    int b;
    Data* get() const;
    void assign(const X& other);
};
void X::assign(const X& other)
{
    if (this != &other) {
        copyField(a, other.a);
        copyField(b, other.b);
        get()->assign(other.get());
    }
}
