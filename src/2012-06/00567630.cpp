// from server: 44% by 41k
extern "C" void __stdcall some_function(void*);

struct S_func_00567630 {
    void f(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6);
};

void S_func_00567630::f(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6) {
    unsigned char* esi = (unsigned char*)a1;
    unsigned char cl = *(unsigned char*)((unsigned char*)a1 + 16);
    void* edi = a2;
    unsigned long edx = 0;
    unsigned long eax = (unsigned long)edi * 8;
    *(unsigned long*)esi = eax;
    *(unsigned long*)((unsigned char*)esi + 8) = edx;
    *(unsigned char*)((unsigned char*)esi + 16) = cl;
    *(unsigned long*)((unsigned char*)esi + 4) = eax;
    if (cl == *(unsigned char*)((unsigned char*)a1 + 17)) {
        return;
    }
    if ((unsigned long)edi <= edx) {
        if ((unsigned long)edi < 0x100) {
            esi += 17;
            *(unsigned long*)((unsigned char*)esi + 4) = 0x800;
            return;
        }
        some_function((void*)0x6c);
        some_function((void*)0xb74820);
        edi = a2;
        some_function(edi);
        some_function((void*)a3);
        some_function((void*)a4);
        some_function((void*)a5);
        some_function((void*)a6);
        return;
    }
    *(unsigned long*)((unsigned char*)esi + 12) = edx;
    return;
}
