// from server: 26% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);

struct Inner {
    char pad0[4];
    char flag4;
    char pad5[3];
    char pad8[0x24];
};

struct PoolData {
    void* vptr;
    char pad4[8];
    void* begin;
    void* end;
    void* cap;
    int mode;
    void* ptr2c;
    void* ptr30;
};

extern "C" void __cdecl sub_411500(void*);
extern "C" void __cdecl sub_6ed760(void*);
extern "C" char __cdecl sub_4215f0(void*);
extern "C" void __cdecl sub_6ed2a0(void*, void*);
extern "C" void __cdecl sub_6ec190(void*, void*, void*);
extern "C" void __cdecl sub_6eb330(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_7fc430(void*, void*, void*, void*);
extern "C" void __cdecl sub_80a058(void*);
extern "C" void* __cdecl sub_40a2b0();

void PoolData_dtor(PoolData* self)
{
    self->vptr = (void*)0xaa8b5c;

    Inner* inner = (Inner*)self->ptr2c;
    void* p = (char*)inner + 0x2c;
    char local18 = 0;
    void* local14 = p;
    sub_411500(&local14);
    ((Inner*)self->ptr2c)->flag4 = 1;
    sub_6ed760((char*)self->ptr2c + 8);

    if (local18) {
        volatile long* rc = (volatile long*)local14;
        long old = _InterlockedExchangeAdd(rc, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            volatile long* b = (volatile long*)local14;
            if (!_InterlockedExchangeAdd(b, 0)) {
                void* ev = sub_40a2b0();
                SetEvent(ev);
            }
        }
    }

    int m = self->mode;
    if (m == 0) {
        void* a = self->end;
        void* b = self->begin;
        sub_6eb330(&a, b, a, (void*)0x6eb070, 0);
    } else if (m == 1) {
        void* a = self->end;
        void* b = self->begin;
        void* fn = (void*)0x6ed300;
        int c = 0x186a0;
        int d = 0;
        sub_6ec190(&fn, b, a);
    } else if (m == 2) {
        int count = (int)(((char*)self->end - (char*)self->begin) >> 3);
        if (count > 0) {
            int i = 0;
            do {
                void* e = *(void**)((char*)self->begin + i * 8);
                char local28 = sub_4215f0(e);
                void* local24 = e;
                void* ecx = *(void**)((char*)self->begin + i * 8);
                sub_6ed2a0(ecx, &local24);
                if (e) *(char*)e = local28;
                i++;
                count = (int)(((char*)self->end - (char*)self->begin) >> 3);
            } while (i < count);
        }
    }

    void* p30 = self->ptr30;
    if (p30 != 0) {
        volatile long* rc = (volatile long*)((char*)p30 + 4);
        if (_InterlockedExchangeAdd(rc, -1) == 1) {
            void** vt = *(void***)p30;
            void (*f)(void*) = (void (*)(void*))vt[1];
            f(p30);
            volatile long* rc2 = (volatile long*)((char*)p30 + 8);
            if (_InterlockedExchangeAdd(rc2, -1) == 1) {
                void** vt2 = *(void***)p30;
                void (*f2)(void*) = (void (*)(void*))vt2[2];
                f2(p30);
            }
        }
    }

    void* e = self->begin;
    if (e != 0) {
        sub_7fc430(e, self->cap, self->begin, local14);
        sub_80a058(self->begin);
    }
    self->begin = 0;
    self->end = 0;
    self->cap = 0;

    void* e2 = self->ptr2c;
    if (e2 != 0) {
        sub_7fc430(e2, self->ptr30, self->ptr2c, local14);
        sub_80a058(self->ptr2c);
    }
    self->ptr2c = 0;
    self->ptr30 = 0;
}
