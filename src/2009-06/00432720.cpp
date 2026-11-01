// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
typedef unsigned int size_t;
void* __cdecl operator new(size_t);
inline void* __cdecl operator new(size_t, void* p) throw() { return p; }
struct Arg4 { int a, b; void* c; };
struct Obj {
    char data[0x1c];
    Obj(int a, int b, int c, const Arg4& d, bool e) throw();
};
Obj* __stdcall create_00432720(int a, int b, int c, const Arg4& d, bool e)
{
    Obj* p = static_cast<Obj*>(operator new(sizeof(Obj)));
    new (p) Obj(a, b, c, d, e);
    return p;
}
