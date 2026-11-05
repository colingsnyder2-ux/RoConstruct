// from server: 40% by atomic.potato
struct X_0055f670 {
    void* f_0;
    X_0055f670* run();
};

extern "C" void* __cdecl sub_0067f480();
extern "C" void __cdecl sub_004015a0(void*, void*);
extern "C" void* __cdecl sub_0055dee0();
extern "C" void* __cdecl sub_004019d0();
extern "C" void* __cdecl sub_00466420();
extern "C" void __cdecl sub_00972290(unsigned char, void*);
extern "C" void* __cdecl sub_00457100();

extern unsigned char byte_00e580b3;
extern void* dword_00e5809c;
extern int dword_00e23e10;

X_0055f670* X_0055f670::run() {
    f_0 = (void*)0xb73e80;
    if (*(int*)0xbc49dc == 0) {
        sub_0067f480();
    } else {
        sub_004015a0((void*)0x55e330, (void*)0xe23e20);
        sub_0055dee0();
    }
    void* edi = sub_0055dee0();
    if (byte_00e580b3 != 0) {
        void* esi = *(void**)((char*)sub_004019d0() + 4);
        void* eax = sub_004019d0();
        void* r = sub_00466420();
        if (*(void**)r != esi) {
            void* fn = dword_00e5809c;
            if (fn != 0) {
                ((char(__cdecl*)(int, void*, void*))fn)(0xd7, (void*)0xb42fa8, (void*)0xb43284);
                if (byte_00e580b3 != 0) {
                    sub_00972290(byte_00e580b3, (void*)0xb431e8);
                }
            } else {
                sub_00972290(byte_00e580b3, (void*)0xb431e8);
            }
        }
        if (byte_00e580b3 != 0 && dword_00e23e10 == 0x29a) {
            void* fn = dword_00e5809c;
            if (fn != 0) {
                ((char(__cdecl*)(int, void*, void*))fn)(0xd8, (void*)0xb42fa8, (void*)0xb431d0);
                if (byte_00e580b3 != 0) {
                    sub_00972290(byte_00e580b3, (void*)0xb43160);
                }
            } else {
                sub_00972290(byte_00e580b3, (void*)0xb43160);
            }
        }
    }
    void* eax2 = sub_004019d0();
    void* r2 = sub_00457100();
    *(void**)r2 = this;
    dword_00e23e10 = 0x29a;
    if (byte_00e580b3 != 0) {
        void* esi2 = *(void**)((char*)sub_004019d0() + 4);
        void* eax3 = sub_004019d0();
        void* r3 = sub_00466420();
        if (*(void**)r3 == esi2) {
            void* fn = dword_00e5809c;
            if (fn != 0) {
                ((char(__cdecl*)(int, void*, void*))fn)(0xdd, (void*)0xb42fa8, (void*)0xb4311c);
                if (byte_00e580b3 != 0) {
                    sub_00972290(byte_00e580b3, (void*)0xb43080);
                }
            } else {
                sub_00972290(byte_00e580b3, (void*)0xb43080);
            }
        }
        if (byte_00e580b3 != 0 && dword_00e23e10 != 0x29a) {
            void* fn = dword_00e5809c;
            if (fn != 0) {
                ((char(__cdecl*)(int, void*, void*))fn)(0xde, (void*)0xb42fa8, (void*)0xb42f90);
                if (byte_00e580b3 != 0) {
                    sub_00972290(byte_00e580b3, (void*)0xb43010);
                }
            } else {
                sub_00972290(byte_00e580b3, (void*)0xb43010);
            }
        }
    }
    return this;
}
