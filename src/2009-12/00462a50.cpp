// from server: 79% by atomic.potato
extern "C" __declspec(dllimport) unsigned long __stdcall SetClassLongA(void*, int, long);

struct Sub {
    char pad0[0xd8];
    void* field_d8;
    char pad1[0x28];
    long field_104;
    char pad2[0x18];
    void* field_20;
};

struct CRobloxWnd_PartDropTarget {
    char pad0[0x38];
    Sub* field_38;
    int method(int, int, int, int, int);
};

extern "C" void func_00473c30();

int CRobloxWnd_PartDropTarget::method(int a, int b, int c, int d, int e)
{
    Sub* s = this->field_38;
    void* p = s->field_d8;
    if (p) {
        func_00473c30();
        SetClassLongA(s->field_20, -0xc, s->field_104);
    }
    return (e == 1) ? 1 : 0;
}
