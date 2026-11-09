// from server: 100% by colin
struct CRobloxControlColorSelector
{
    char pad[0xf4];
    void* field_f4;
    char pad2[4];
    void* field_fc;
    void* get();
};

extern void* G_8c86d8;

extern void* __fastcall func_0067a480(void*);
extern void* __fastcall func_00643a40(void*);
extern void* __fastcall func_006321d0(void*);
extern void __cdecl func_0063dcb0(int);

void* CRobloxControlColorSelector::get()
{
    if (field_fc != 0)
        return func_00643a40(field_fc);

    if (field_f4 != 0)
    {
        void* p = func_0067a480(field_f4);
        if (p != 0)
            return func_006321d0(p);
    }

    if (G_8c86d8 == 0)
        func_0063dcb0(0);

    return G_8c86d8;
}
