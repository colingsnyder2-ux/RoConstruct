// from server: 71% by atomic.potato
extern "C" void* __cdecl sub_0080B2EA(int, void*, void*, int, void*);
extern "C" void* __cdecl sub_004718B0(void*);
extern "C" void* __cdecl sub_0060A700(void*);

struct VCRobloxDoc;

struct VerbBinder {
    void* f_00472040(int);
};

void* VerbBinder::f_00472040(int arg)
{
    void* p = sub_0080B2EA(0, (void*)0x00C15DF0, (void*)0x00C15DB8, 0, this);
    if (p == 0)
        return 0;
    void* q = sub_004718B0(p);
    if (q == 0)
        return 0;
    return sub_0060A700(q);
}
