// from server: 23% by atomic.potato
extern "C" {
    void __stdcall sub_98B480(void*);
    void __stdcall sub_98B484(void*);
    void __stdcall sub_98B7A4(void*);
}

struct S {
    char pad0[0x14];
    unsigned int len;
    unsigned int cap;
    char pad2[0x44];
    char buf[4];

    unsigned short f(S* arg);
};

struct T {
    char pad0[0x14];
    char data[0x60];
};

extern "C" void __stdcall sub_5DC3A0(void*);
extern "C" int __stdcall sub_713640(void*, void*);

unsigned short S::f(S* arg)
{
    char local[0x58];
    sub_98B480(local);
    *(void**)(local + 0) = (void*)0x9d6a34;
    *(int*)(local + 0x4c) = 0;
    unsigned int n = arg->len;
    char* p;
    if (arg->cap < 0x10)
        p = (char*)arg + 4;
    else
        p = *(char**)((char*)arg + 4);
    char* end = p + n;
    *(char**)(local + 0x3c) = p;
    *(char**)(local + 0x40) = end;
    if (sub_713640(local, &arg)) {
        unsigned short r = *(unsigned short*)((char*)&arg + 4);
        *(int*)(local + 0x4c) = -1;
        sub_98B484(local);
        return r;
    }
    sub_98B7A4((void*)0x99fe9c);
    *(void**)(local + 0) = (void*)0x9c1364;
    *(void**)(local + 0xc) = (void*)0xb033e8;
    *(void**)(local + 0x10) = (void*)0xb4b96c;
    sub_5DC3A0(local);
    return 0;
}
