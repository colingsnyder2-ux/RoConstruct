// from server: 100% by colin
struct T_func_0052d250 {
    char pad[0xbc];
    int field_bc;
    char pad2[0x158 - 0xc0];
    unsigned char field_158;
    char pad3[0x174 - 0x159];
    char field_174[0x190 - 0x174];
    int field_190;
    void m(int);
};

extern void __fastcall func_00726950(char*);
extern void __fastcall func_00726440(void*);
extern void __cdecl func_0062fc62(void*);

void T_func_0052d250::m(int)
{
    if (field_bc != 0)
        return;
    field_158 = 1;
    func_00726950(field_174);
    int* p = (int*)field_190;
    field_190 = 0;
    if (p != 0)
    {
        func_00726440(p);
        func_0062fc62(p);
    }
}
