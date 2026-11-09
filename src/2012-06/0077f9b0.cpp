// from server: 28% by atomic.potato
extern "C" int __stdcall func_004125d0(int);
extern "C" void __stdcall func_006cab60();
extern "C" void __stdcall func_009831f5(void*);

struct S {
    void f();
};

void S::f()
{
    if ((*(unsigned char*)0xe3b7a4 & 1) == 0) {
        *(unsigned int*)0xe3b7a4 |= 1;
        struct Local {
            char a;
            char b;
            int c;
            int d;
        } local;
        local.a = 0;
        local.b = 0;
        local.c = 0;
        local.d = 0x1b;
        int v = func_004125d0(*(int*)0xbc09f8);
        func_006cab60();
        func_009831f5((void*)0xb1b290);
    }
}
