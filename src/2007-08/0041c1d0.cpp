// from server: 42% by colin
struct VDHTMLWindow_SignalDesc {
    void* p;
    void* f(int, int);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int);

void* VDHTMLWindow_SignalDesc::f(int a, int b) {
    void* result = 0;
    void* mem = sub_62FEF6(0x14);
    if (mem) {
        *(int*)((char*)mem + 4) = 1;
        *(int*)((char*)mem + 8) = 1;
        *(int*)mem = 0x787a7c;
        *(int*)((char*)mem + 0xc) = a;
        result = mem;
    }
    *(void**)this = result;
    return this;
}
