// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void*, const void*, int);

struct CXTPPropertyGrid
{
    char pad[0x20];
    void* field20;
    char pad2[0x54 - 0x24];
    int field54;
    int field58;
    int field5c;
    char pad3[0x64 - 0x60];
    int field64;
    char field68[0x130 - 0x68];
    void* field130;
    int field134;
    char pad5[0x148 - 0x138];
    int field148;

    CXTPPropertyGrid* sub_682a20();
    void sub_630034(int, int, int, int, int);
    void func(int, int);
};

void CXTPPropertyGrid::func(int a, int b)
{
    CXTPPropertyGrid* p = sub_682a20();
    if (p->field148 > 0)
        return;
    if (this == 0)
        return;
    if (field20 == 0)
        return;

    int ebx = 0;
    int edi = b;
    if (field5c != 0)
        edi = edi - field54 - 3;

    void* eax = *(void**)((char*)field130 + 0x28);
    if (eax != 0)
        edi = edi + (-3 - field58);

    int edx = (eax != 0) ? 1 : 0;
    field134 = edx;

    if (field64 != 0)
    {
        ((CXTPPropertyGrid*)((char*)this + 0x68))->sub_630034(1, 1, a - 2, 0x17, 1);
        ebx = 0x19;
    }

    CXTPPropertyGrid* q = sub_682a20();
    q->sub_630034(0, ebx, a, edi - ebx, 1);

    CXTPPropertyGrid* r = sub_682a20();
    void* h1 = r->field20;
    void (__stdcall *fn)(void*, int, int) = *(void (__stdcall **)(void*, int, int))0x77ecdc;
    fn(h1, 0, 0);
    fn(field20, 0, 0);
}
