// from server: 42% by atomic.potato
struct LDrawCommand
{
    char pad0[4];
    int field4;
    char pad8[4];
    int fieldC;
    bool f(int);
};

extern "C" int __stdcall sub_47AE40(int);
extern "C" void* __stdcall sub_44C920(void*, const char*);
extern "C" void* __cdecl sub_98B3CC(void*, int);

bool LDrawCommand::f(int arg)
{
    int a = fieldC;
    int b = field4;
    void* p = sub_44C920((void*)b, (const char*)0x9b1f7c);
    void* q = sub_44C920(p, (const char*)0x9b1f58);
    void* r = sub_98B3CC(q, a);
    void* s = sub_44C920(r, (const char*)0x9b203c);
    (void)s;
    return true;
}
