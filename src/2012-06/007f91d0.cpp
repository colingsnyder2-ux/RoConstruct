// from server: 38% by atomic.potato
struct S {
    int f(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
};

struct T {
    char __thiscall sub_7f8bd0();
};

extern "C" void __stdcall sub_7de190(void*, void*);
extern "C" void __stdcall sub_7ddb10(void*);

int S::f(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
    char buf[0x50];
    int local;
    void* p;

    p = (void*)((char*)this + 8);
    *(int*)buf = 0;
    sub_7de190((void*)(buf + 8), &local);
    ((T*)0xdd57c4)->sub_7f8bd0();
    *(int*)this = 0;
    sub_7ddb10(buf);
    return 0;
}
