// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Primitive { char pad[0xf0]; bool a; bool b; bool c; };
struct PartInstance {
    char pad[0x118];
    Primitive* primitive;
    int f() const;
};
int PartInstance::f() const
{
    const Primitive* p = primitive;
    return !p->a && !p->c;
}
