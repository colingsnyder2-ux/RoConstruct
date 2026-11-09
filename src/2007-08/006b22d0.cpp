// from server: 100% by colin
struct Obj {
    unsigned char pad[0xfc];
    int field;
};

void __stdcall sub_6b2170(Obj* p);

void __stdcall sub_6b22d0(Obj* p)
{
    if (p->field == 5)
        sub_6b2170(p);
}
