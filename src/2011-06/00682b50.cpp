// from server: 13% by atomic.potato
struct VHumanoidBoundFuncDesc {
    void* vfptr;
    char pad0[0x14];
    void* field18;
    void* field1c;
    char pad20[0x8];
    int field28;
    int field2c;
    void construct(void* a, void* b);
};

extern "C" void* __stdcall cb_005cd340();
extern "C" void* __cdecl func_00618710();
extern "C" void* __cdecl func_00592b40(void*);
extern "C" void* __cdecl func_005ba420();
extern "C" void __cdecl func_0062d1b0(void*);
extern "C" void* __cdecl func_004a7f80(void*, void*, void*);
extern "C" void __cdecl func_00722ca0(void*, int);
extern "C" void __cdecl func_006a5ab0(void*, void*);

extern int g_cca608;

void VHumanoidBoundFuncDesc::construct(void* a, void* b) {
    void* p = cb_005cd340();
    func_006a5ab0(this, p);
    this->field28 = (int)a;
    this->field2c = (int)b;
    this->vfptr = (void*)0xa9eaf0;
    void* q = func_00592b40((void*)0);
    g_cca608++;
    void* r = func_005ba420();
    func_0062d1b0(&r);
    void* ebp = this->field1c;
    void* eax = *(void**)((char*)ebp + 4);
    void* edi = (char*)this + 0x18;
    void* ebx = func_004a7f80(edi, ebp, eax);
    func_00722ca0(edi, 1);
    *(void**)((char*)ebp + 4) = ebx;
    void* t = *(void**)((char*)ebx + 4);
    *(void**)t = ebx;
    if (q) {
        void** vt = *(void***)q;
        void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
        fn(q, 1);
    }
}
