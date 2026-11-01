// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Base {
    Base();
    virtual ~Base();
    char pad[0x3bc - 4];
};
struct Derived : Base {
    virtual ~Derived();
    static Base* __stdcall CreateObject();
};
Base* __stdcall Derived::CreateObject()
{
    return new Derived;
}
