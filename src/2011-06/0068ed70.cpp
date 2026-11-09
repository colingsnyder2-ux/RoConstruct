// from server: 37% by atomic.potato
extern "C" void __stdcall fn_0080b15d(void*);
extern "C" void __cdecl fn_0040ddc0(void*);
extern "C" void __cdecl fn_006b6f40(void*, void*);

extern "C" void __fastcall fn_0040b300(void*, void*, void*);
extern "C" void __fastcall fn_00410900(void*, void*);
extern "C" void __fastcall fn_0040ac80(void*);

struct S_0068ed70 {
    void func();
};

void S_0068ed70::func()
{
    char buf[0x40];
    void* p;
    void* q;
    int i;

    if (*(unsigned char*)0xccf3bc == 0) {
        *(unsigned int*)0xccf3bc |= 1;
        *(void**)0xccf3b4 = 0;
        *(void**)0xccf3b8 = 0;
        fn_0080b15d((void*)0xa3ba20);
    }

    fn_0040b300((void*)0xccf3b4, buf, &p);
    fn_00410900((void*)0xccf3b4, buf);
    *(unsigned char*)(buf + 0x18) = 1;

    fn_006b6f40(buf + 0x14, &q);
    i = 10;
    while (q != 0) {
        *(void**)((char*)q + 0x10) = 0;
        if (i == 0) break;
        i--;
        q = (char*)q + 0xc;
        fn_006b6f40(buf + 0x14, &q);
    }

    fn_0040ac80(buf + 0x28);
    *(unsigned char*)(buf + 0x18) = 1;
    fn_006b6f40(buf + 0x14, &p);
    *(unsigned char*)(buf + 0x18) = 0;
    if (q != 0) {
        fn_0040ddc0((char*)q + 5);
    }
    if (*(void**)buf != 0) {
        fn_0040ddc0((char*)*(void**)buf + 5);
    }
}
