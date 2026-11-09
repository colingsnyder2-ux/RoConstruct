// from server: 48% by tester
extern "C" void* __cdecl sub_98211a(unsigned int size);
extern "C" void __fastcall sub_8aa140(void* self, void* unused, void* arg);

struct WeldTool {
    char pad[0x20];
    void* field20;
    void* construct();
};

void* WeldTool::construct()
{
    void* mem = sub_98211a(0x60);
    void* result = 0;
    if (mem != 0) {
        sub_8aa140(mem, 0, field20);
        *(void**)mem = (void*)0xbdf25c;
        *(void**)((char*)mem + 4) = (void*)0xbdf230;
        result = mem;
    }
    return result;
}
