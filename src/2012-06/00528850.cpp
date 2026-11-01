// from server: 61% by Intel
struct VTimerServiceFactoryProductCreator {
    void Initialize();
};

extern "C" {
    extern unsigned char byte_E580B3;
    extern unsigned int dword_E1E0C8;
    extern int (__cdecl *dword_E5809C)(int, int, int);
    extern int (__cdecl *sub_972290)(int, int);
    extern int (__stdcall *sub_4019D0)(int*);
    extern int (__thiscall *sub_4A11D0)(void*, int);
    extern int (__thiscall *sub_51FAA0)(VTimerServiceFactoryProductCreator*);
}

void VTimerServiceFactoryProductCreator::Initialize() {
    int vtable = 0xB6FAC8;
    *(int*)this = vtable;

    if (byte_E580B3) {
        if (dword_E1E0C8 != 0x29A) {
            int (__cdecl *callback)(int, int, int) = dword_E5809C;
            if (callback) {
                int result = callback(0xB42F90, 0xB42FA8, 0xE2);
                if (result) {
                    goto CallBaseConstructor;
                }
            }
            unsigned char flag = byte_E580B3;
            sub_972290(0xB43368, flag);
        }
    }

CallBaseConstructor:
    int baseResult = sub_51FAA0(this);
    int stackVar;
    int* ptr = &stackVar;
    *(int*)((char*)&stackVar + 4) = baseResult;
    int sehResult = sub_4019D0(ptr);
    sub_4A11D0(this, sehResult);
}
