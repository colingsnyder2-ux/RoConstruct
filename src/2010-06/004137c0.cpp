// from server: 60% by atomic.potato
struct CutVerb {
    char pad0[0xc];
    void* field_c;
    char field_10;
    CutVerb(const char* name, void* arg, bool flag);
};

extern "C" void* __stdcall sub_009ea410_ctor(void*, const char*);
extern "C" void __fastcall sub_005e6d20(void*, void*);

CutVerb::CutVerb(const char* name, void* arg, bool flag)
{
    const char* s = flag ? (const char*)0xa02f30 : (const char*)0xa02f28;
    void* p = arg ? (char*)arg + 0xd8 : 0;
    char buf[0x1c];
    sub_009ea410_ctor(buf, s);
    sub_005e6d20(this, p);
    field_c = arg;
    field_10 = flag;
    *(void**)this = (void*)0xa02f14;
}
