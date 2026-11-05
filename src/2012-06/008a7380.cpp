// from server: 51% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int size);

struct Alloc {
    void init(int arg);
};

struct VMaterialTool {
    char pad[0xc];
    void* field_c;
    void* method();
};

void* VMaterialTool::method() {
    Alloc* mem = (Alloc*)sub_98211a(0x3c);
    void* result = 0;
    if (mem != 0) {
        int arg = *(int*)((char*)field_c + 0xac4);
        mem->init(arg);
        *(void**)mem = (void*)0xbdfadc;
        *(void**)((char*)mem + 4) = (void*)0xbdfaac;
        result = mem;
    }
    return result;
}
