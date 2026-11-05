// from server: 68% by atomic.potato
struct Value { int x; };

extern "C" int __cdecl sub_67F480();
extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" int __cdecl sub_8A3A60();
extern "C" void __cdecl sub_6F45F0();
extern "C" void* __cdecl sub_B226C4(void*, const char*, void*);

extern int g_be0420;
extern void* g_ba067c;
extern void* g_bdf2c4;

struct WeldTool {
    void* vfptr;
    char pad[0x18];
    char flag;
    void construct(void* a, char b);
};

void WeldTool::construct(void* a, char b)
{
    if (g_be0420 == 0)
        sub_67F480();
    else {
        sub_4015A0((void*)0x8A44E0, (void*)0xE52F5C);
        sub_8A3A60();
    }
    char buf[0x1c];
    sub_B226C4(buf, (const char*)0xBA067C, (char*)a + 4);
    sub_6F45F0();
    *(void**)this = (void*)0xBDF2C4;
    this->flag = b;
}
