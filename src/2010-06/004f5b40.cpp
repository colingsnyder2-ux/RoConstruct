// from server: 40% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_9EA37C(int);

struct Inner {
    void** vtbl;
    char pad[0x40];
};

struct Outer {
    void** vtbl;
    char pad0[0x14];
    void* field18;
    char pad1[0x4];
    void* field20;
    char pad2[0x18];
    Inner* field3c;
    Inner* field44;
};

void Outer_dtor(Outer* self)
{
    self->vtbl = (void**)0xa1b6a8;

    Inner* p44 = self->field44;
    if (p44) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p44 + 4), -1) == 1) {
            ((void (__thiscall*)(Inner*))p44->vtbl[1])(p44);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p44 + 8), -1) == 1) {
                ((void (__thiscall*)(Inner*))p44->vtbl[2])(p44);
            }
        }
    }

    Inner* p3c = self->field3c;
    if (p3c) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p3c + 4), -1) == 1) {
            ((void (__thiscall*)(Inner*))p3c->vtbl[1])(p3c);
            if (_InterlockedExchangeAdd((volatile long*)((char*)p3c + 8), -1) == 1) {
                ((void (__thiscall*)(Inner*))p3c->vtbl[2])(p3c);
            }
        }
    }

    void* f18 = self->field18;
    if (f18) {
        void* fn = *(void**)f18;
        void* arg = (char*)self + 0x20;
        if (fn) {
            ((void (__cdecl*)(void*, void*, int))fn)(arg, arg, 2);
        }
        self->field18 = 0;
    }

    sub_9EA37C(0xc007ac);
    self->vtbl = (void**)0xa0399c;
}
