// from server: 68% by atomic.potato
extern "C" void __stdcall func_005c9fe8(unsigned int, const char*, int);
extern "C" void __stdcall func_006f28b0();
extern "C" void* __stdcall func_0054a920(void*);
extern "C" void __stdcall func_00531cd0();
extern "C" void __stdcall func_006856c0();

extern unsigned char g_e31aa1;

struct ClearBackpack {
    char pad[0xc];
    void* field_c;
    void method(int);
};

void ClearBackpack::method(int) {
    unsigned char al = g_e31aa1;
    if (al) {
        func_005c9fe8((unsigned int)al, (const char*)0xb9bf00, 0);
    }
    void* esi = field_c;
    func_006f28b0();
    void* eax = func_0054a920(field_c);
    if (eax) {
        func_00531cd0();
        func_006856c0();
    }
}
