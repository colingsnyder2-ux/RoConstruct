// from server: 36% by tester
struct SurfaceTool {
    char pad[0x20];
    void* workspace;
};

struct StudsTool : SurfaceTool {
    StudsTool(void* workspace);
};

extern "C" void* __cdecl sub_98211a(unsigned int size);
extern "C" void __cdecl sub_8aa140(void* self, void* workspace);

StudsTool::StudsTool(void* workspace)
{
    void* mem = sub_98211a(0x60);
    if (mem != 0) {
        sub_8aa140(mem, this->workspace);
        *(void**)mem = (void*)0xbdf314;
        *(void**)((char*)mem + 4) = (void*)0xbdf2e8;
    }
}
