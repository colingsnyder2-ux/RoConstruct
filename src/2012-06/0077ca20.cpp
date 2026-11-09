// from server: 31% by atomic.potato
extern "C" void __cdecl sub_4015a0(const char*, const char*);
extern "C" void* __cdecl sub_4019d0(void*);
extern "C" void* __cdecl sub_457100(void*);
extern "C" void* __cdecl sub_466420(void*);
extern "C" void* __cdecl sub_67f480();
extern "C" void* __cdecl sub_767b70();
extern "C" void __cdecl sub_972290(unsigned char, const char*);

extern unsigned char byte_E580B3;
extern void* dword_E5809C;
extern int dword_E379C8;
extern int dword_BC0BAC;

struct S {
    void f();
};

void S::f()
{
    void* p;
    void* q;
    void* r;
    unsigned char b;

    *(int*)this = 0xbb0b00;

    if (dword_BC0BAC == 0) {
        p = sub_67f480();
    } else {
        sub_4015a0((const char*)0x768140, (const char*)0xe37a70);
        p = sub_767b70();
    }

    if (byte_E580B3 != 0) {
        q = sub_4019d0(&p);
        r = *(void**)((char*)q + 4);
        void* t = sub_4019d0(&p);
        void* u = sub_466420(t);
        if (*(void**)u != r) {
            if (dword_E5809C != 0) {
                if (((unsigned char (__cdecl*)(int, const char*, const char*))dword_E5809C)(0xd7, (const char*)0xb42fa8, (const char*)0xb43284) != 0)
                    goto skip1;
            }
            b = byte_E580B3;
            sub_972290(b, (const char*)0xb431e8);
        }
    skip1:
        if (byte_E580B3 != 0) {
            if (dword_E379C8 == 0x29a) {
                if (dword_E5809C != 0) {
                    if (((unsigned char (__cdecl*)(int, const char*, const char*))dword_E5809C)(0xd8, (const char*)0xb42fa8, (const char*)0xb431d0) != 0)
                        goto skip2;
                }
                b = byte_E580B3;
                sub_972290(b, (const char*)0xb43160);
            }
        }
    skip2:
        ;
    }

    void* v = sub_4019d0(&p);
    void* w = sub_457100(v);
    *(void**)w = this;

    if (byte_E580B3 != 0) {
        q = sub_4019d0(&p);
        r = *(void**)((char*)q + 4);
        void* t = sub_4019d0(&p);
        void* u = sub_466420(t);
        if (*(void**)u == r) {
            if (dword_E5809C != 0) {
                if (((unsigned char (__cdecl*)(int, const char*, const char*))dword_E5809C)(0xdd, (const char*)0xb42fa8, (const char*)0xb4311c) != 0)
                    goto skip3;
            }
            b = byte_E580B3;
            sub_972290(b, (const char*)0xb43080);
        }
    skip3:
        if (byte_E580B3 != 0) {
            if (dword_E379C8 != 0x29a) {
                if (dword_E5809C != 0) {
                    if (((unsigned char (__cdecl*)(int, const char*, const char*))dword_E5809C)(0xde, (const char*)0xb42fa8, (const char*)0xb42f90) != 0)
                        goto skip4;
                }
                b = byte_E580B3;
                sub_972290(b, (const char*)0xb43010);
            }
        }
    skip4:
        ;
    }
}
