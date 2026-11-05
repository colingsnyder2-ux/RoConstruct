// from server: 67% by atomic.potato
struct Value { int x; };

extern "C" int __cdecl sub_67F480();
extern "C" void __cdecl sub_4015A0(void*, void*);
extern "C" Value* __cdecl sub_8A4160();
extern "C" void __cdecl sub_6F45F0();
extern "C" void* __cdecl sub_B226C4(void*, void*, void*);

extern int g_00c00b7c;

struct ResizeTool {
    void* vtable;
    char pad[0x18];
    char flag;
    void construct(void* a, char b);
};

void ResizeTool::construct(void* a, char b)
{
    if (g_00c00b7c == 0)
        sub_67F480();
    else {
        sub_4015A0((void*)0x8a45e0, (void*)0xe52f9c);
        sub_8A4160();
    }
    char buf[0x1c];
    sub_B226C4(buf, (char*)a + 4, (void*)0xba067c);
    sub_6F45F0();
    *(void**)this = (void*)0xbdeb9c;
    this->flag = b;
}
