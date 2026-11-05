// from server: 26% by atomic.potato
struct S {
    char pad0[0x38];
    void (__stdcall *fn38)(int);
    char pad3c[4];
    int field40;
    int field44;
    void f(int, int);
};

extern "C" void* __stdcall sub_7a8bea(int, int, int, int, int);
extern "C" void __stdcall sub_7a89b2(void*, void*);
extern "C" void __stdcall sub_5a8a70(void*);
extern "C" void* __stdcall sub_9ea89c(void*, void*);

void S::f(int a, int b)
{
    int v8;
    int vc;
    int v2c;
    void* p;

    v8 = field40;
    if (field44) {
        vc = (*(int (__stdcall**)(void*))(*((int*)field44) + 8))((void*)field44);
    } else {
        vc = 0;
    }
    v2c = 0;
    (*(void (__stdcall**)(int*, int, int*))(*((int*)a) + 4))((int*)a, 1, &v8);
    p = sub_7a8bea(v2c, 0, (int)0xb79040, (int)0xbb2578, 0);
    if (!p) {
        sub_9ea89c(&v8, (void*)0xa00a54);
        sub_7a89b2(&v8, (void*)0xb12290);
    }
    sub_5a8a70(&v8);
    fn38(*(int*)p + (int)p);
    if (vc) {
        (*(void (__stdcall**)(int, int))(*((int*)vc)))(vc, 1);
    }
}
