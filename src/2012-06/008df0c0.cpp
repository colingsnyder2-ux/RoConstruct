// from server: 28% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl free(void*);

struct Inner {
    void** vptr;
    long refcount;
};

struct Obj {
    Inner* p;
};

struct S {
    Obj* field0;
    void dtor();
};

void S::dtor()
{
    Obj* o = this->field0;
    this->field0 = 0;
    if (o) {
        Inner* in = o->p;
        if (in) {
            char* base = (char*)in - 8;
            if (_InterlockedExchangeAdd((volatile long*)base, -1) == 1) {
                void** vt = *(void***)in;
                ((void (__stdcall*)(void*))vt[0])(0);
                if (_InterlockedExchangeAdd((volatile long*)(base + 4), -1) == 1) {
                    free(base);
                }
            }
        }
    }
}
