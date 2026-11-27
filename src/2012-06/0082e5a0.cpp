// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Primitive { int getGeometryType(); };
struct Target { void set(Primitive* r); };
struct S
{
    char pad[0x24];
    Target* field24;
    Primitive* field28;
    void f(Primitive* value);
};
void S::f(Primitive* value)
{
    if (value->getGeometryType() == 10)
        field28 = value;
    field24->set(value);
}
