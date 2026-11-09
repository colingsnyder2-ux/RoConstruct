// from server: 32% by colin
struct Name {
    char pad[0x18];
    int len;
    char buf[4];
};

struct BoolPropertyVerb {
    char pad0[0x14];
    char sel[0x10];
    void* dataModel;
    Name* propertyName;
    void __cdecl doIt(void* dataState);
};

extern "C" void __stdcall sub_6f28b0();
extern "C" void __stdcall sub_6f8090();
extern "C" void __stdcall sub_42b340();
extern "C" void __stdcall sub_42b2e0();
extern "C" void __stdcall sub_6f4880();
extern "C" void __stdcall sub_702220();

void BoolPropertyVerb::doIt(void* dataState)
{
    void* dm = dataModel;
    sub_6f28b0();
    bool checked = ((bool (__thiscall*)(BoolPropertyVerb*))((*(void***)this)[3]))(this);
    Name* pn = propertyName;
    char flag = checked ? 0 : 1;
    void* a = ((void* (__thiscall*)(void*))sub_6f8090)(sel);
    void* b = ((void* (__thiscall*)(void*))sub_6f8090)(sel);
    void* r1;
    sub_42b340();
    void* r2;
    sub_42b2e0();
    void* v1 = *(void**)a;
    void* v2 = *(void**)b;
    char tmp[0x10];
    sub_6f4880();
    Name* pn2 = propertyName;
    char* str;
    if (pn2->len < 0x10)
        str = (char*)pn2 + 4;
    else
        str = *(char**)((char*)pn2 + 4);
    sub_702220();
    void* ds = *(void**)((char*)dataState + 0x0);
    *(int*)((char*)dataState + 4) = 1;
    void (*fn)() = *(void (**)())ds;
    fn();
}
