// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S
{
    int (**vtable)();

    void XItem(unsigned char *value);
};

void S::XItem(unsigned char *value)
{
    value = (unsigned char *)(*value);
    ((void (__thiscall *)(S *, unsigned char *))vtable[0x39])(this, value);
}