// from server: 100% by colin
struct CXTPPropertyGridDelphiTheme {
    void Init();
    char pad[0x30];
    void* field_34;
};

struct Helper {
    void* method(int);
};

extern "C" void __stdcall sub_6f9380();
extern "C" void* __stdcall sub_668f70();

void CXTPPropertyGridDelphiTheme::Init()
{
    sub_6f9380();
    Helper* p = (Helper*)sub_668f70();
    void* q = p->method(0xf);
    void* r = *(void**)((char*)this + 0x34);
    *(void**)((char*)r + 0x74) = q;
    void* s = *(void**)((char*)this + 0x34);
    *(int*)((char*)s + 0x5c) = 0x800000;
}
