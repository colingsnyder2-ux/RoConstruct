// from server: 48% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    int pad0;
    int pad4;
    volatile long ref;
    void (__stdcall *dtor)(Inner*);
};

struct Holder {
    int* ptr;
    int* field4;
};

struct Outer {
    int pad0;
    int pad4;
    int pad8;
    int padC;
    int pad10;
    int pad14;
    int pad18;
    int pad1C;
    int pad20;
    int pad24;
    int pad28;
    int pad2C;
    int* field30;
    int* field34;
};

extern "C" void __stdcall sub_539150(void*, int*, int*);

Holder* __stdcall sub_53a530(Holder* self, int* a, int* b)
{
    int* old;
    Outer* o;
    int* prev;
    int* cur;
    long r;

    self->ptr = a;
    sub_539150(&self->field4, a, b);

    if (a != 0) {
        o = (Outer*)((char*)a + 0x2c);
        if (o != 0) {
            o->field30 = a;
            prev = (int*)self->field4;
            if (prev != o->field34) {
                if (prev != 0) {
                    _InterlockedExchangeAdd((volatile long*)((char*)prev + 8), 1);
                }
                cur = o->field34;
                if (cur != 0) {
                    r = _InterlockedExchangeAdd((volatile long*)((char*)cur + 8), -1);
                    if (r == 1) {
                        ((void (__stdcall*)(int*))*(void**)(*(int*)cur + 8))(cur);
                    }
                }
                o->field34 = prev;
            }
        }
    }

    return self;
}
