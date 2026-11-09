// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct D {
    char s[0x18];
    ~D();
};
struct Inner {
    D a;
    D b;
};
struct Outer {
    char pad[0x10];
    Inner in;
    ~Outer();
};
Outer::~Outer()
{
}
