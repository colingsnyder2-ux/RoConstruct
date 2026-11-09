// from server: 45% by atomic.potato


extern "C" void* __cdecl sub_004019d0(void*);
extern "C" void __cdecl sub_004015a0(const char*, const char*);
extern "C" void* __cdecl sub_00457100(void*);
extern "C" void* __cdecl sub_00466420(void*);
extern "C" void __cdecl sub_0067f480();
extern "C" void* __cdecl sub_00766d00();
extern "C" void __cdecl sub_00972290(unsigned char, const char*);

struct X_00771e70 {
    void* f_0;
    void* run();
};

void* X_00771e70::run() {
    void* edi;
    void* esi;
    void* eax;
    void* ecx;
    void* edx;
    void* tmp;

    f_0 = (void*)0xbaf94c;

    if (*(int*)0xbe62f8 == 0) {
        sub_0067f480();
    } else {
        sub_004015a0((const char*)0x767f30, (const char*)0xe379ec);
        sub_00766d00();
    }
    edi = eax;

    if (*(unsigned char*)0xe580b3 != 0) {
        tmp = edi;
        eax = sub_004019d0(&tmp);
        esi = *(void**)((char*)eax + 4);
        eax = sub_004019d0(&tmp);
        ecx = eax;
        eax = sub_00466420(ecx);
        if (*(void**)eax != esi) {
            eax = *(void**)0xe5809c;
            if (eax != 0) {
                ((void(__cdecl*)(int, const char*, const char*))eax)(0xd7, (const char*)0xb42fa8, (const char*)0xb43284);
                if ((char)eax != 0) goto skip1;
            }
            edx = (void*)(unsigned int)*(unsigned char*)0xe580b3;
            sub_00972290((unsigned char)(unsigned int)edx, (const char*)0xb431e8);
        }
    skip1:
        if (*(unsigned char*)0xe580b3 != 0) {
            if (*(int*)0xe37944 == 0x29a) {
                eax = *(void**)0xe5809c;
                if (eax != 0) {
                    ((void(__cdecl*)(int, const char*, const char*))eax)(0xd8, (const char*)0xb42fa8, (const char*)0xb431d0);
                    if ((char)eax != 0) goto skip2;
                }
                eax = (void*)(unsigned int)*(unsigned char*)0xe580b3;
                sub_00972290((unsigned char)(unsigned int)eax, (const char*)0xb43160);
            }
        }
    }
skip2:
    tmp = edi;
    eax = sub_004019d0(&tmp);
    ecx = eax;
    eax = sub_00457100(ecx);
    *(void**)eax = this;

    if (*(unsigned char*)0xe580b3 != 0) {
        tmp = edi;
        eax = sub_004019d0(&tmp);
        esi = *(void**)((char*)eax + 4);
        eax = sub_004019d0(&tmp);
        ecx = eax;
        eax = sub_00466420(ecx);
        if (*(void**)eax == esi) {
            eax = *(void**)0xe5809c;
            if (eax != 0) {
                ((void(__cdecl*)(int, const char*, const char*))eax)(0xdd, (const char*)0xb42fa8, (const char*)0xb4311c);
                if ((char)eax != 0) goto skip3;
            }
            ecx = (void*)(unsigned int)*(unsigned char*)0xe580b3;
            sub_00972290((unsigned char)(unsigned int)ecx, (const char*)0xb43080);
        }
    skip3:
        if (*(unsigned char*)0xe580b3 != 0) {
            if (*(int*)0xe37944 != 0x29a) {
                eax = *(void**)0xe5809c;
                if (eax != 0) {
                    ((void(__cdecl*)(int, const char*, const char*))eax)(0xde, (const char*)0xb42fa8, (const char*)0xb42f90);
                    if ((char)eax != 0) goto skip4;
                }
                edx = (void*)(unsigned int)*(unsigned char*)0xe580b3;
                sub_00972290((unsigned char)(unsigned int)edx, (const char*)0xb43010);
            }
        }
    }
skip4:
    *(int*)0xe37944 = 0x29a;
    return this;
}

void* func_00771e70(X_00771e70* x) { return x->run(); }
