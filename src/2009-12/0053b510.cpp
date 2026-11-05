// from server: 74% by atomic.potato
struct AtomicInt32 {
    int v;
    AtomicInt32(int x);
};

struct Ray {
    int a;
    int b;
    Ray(int x, int y);
};

struct Holder {
    int x;
    int y;
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct S {
    void __cdecl f(Holder* dst);
};

void S::f(Holder* dst)
{
    AtomicInt32 tmp(0);
    Ray r(*(int*)&tmp, 0);
    void* p = operator_new(8);
    if (p) {
        *(int*)p = 0x9bd1c8;
        *(int*)((char*)p + 4) = *(int*)&tmp;
    } else {
        p = 0;
    }
    int* old = (int*)dst->x;
    if (&dst->x != (int*)&tmp) {
        old = (int*)dst->x;
        dst->x = (int)p;
    }
    if (old) {
        (*(void(__thiscall**)(int*, int))(*old))(old, 1);
    }
}
