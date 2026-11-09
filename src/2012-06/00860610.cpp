// from server: 50% by atomic.potato
struct S {
    void f(int);
};

extern "C" void __stdcall sub_0085F5A0(void*, void*);
extern "C" void __stdcall sub_0085DE60(void*, void*);

void S::f(int a)
{
    if (a == 2) {
        void** vtbl = *((void***)this);
        ((void (__stdcall *)(void*))vtbl[0x30 / 4])(this);
        *((int*)((char*)this + 0x14)) = 0;
        *((int*)((char*)this + 0x24)) = 0;
        *((int*)((char*)this + 0x34)) = 0;
    } else if (a == 1) {
        return;
    }

    int v = *((int*)((char*)this + 0x8c));
    void* p = (char*)this + 0x40;

    if (a == 3) {
        sub_0085F5A0(p, (void*)v);
    } else {
        sub_0085DE60(&a, (void*)v);
    }
}
