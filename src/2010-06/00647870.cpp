// from server: 51% by atomic.potato
struct VRightMotorTool {
    char pad[0xc];
    void* p;
    void* f();
};

struct Sub720660 {
    void g(void*);
};

extern "C" void* __cdecl sub_7A79A0(unsigned int);

void* VRightMotorTool::f() {
    void* mem = sub_7A79A0(0x48);
    void* result = 0;
    if (mem) {
        void* q = *(void**)((char*)p + 0xaa0);
        ((Sub720660*)mem)->g(q);
        *(void**)mem = (void*)0xa37e74;
        *(void**)((char*)mem + 4) = (void*)0xa37e58;
        result = mem;
    }
    return result;
}
