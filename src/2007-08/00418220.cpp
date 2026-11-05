// from server: 43% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SlotImpl {
    void* vptr0;
    void* vptr1;
    void* vptr2;
    void* vptr3;
    void* vptr4;
    void* vptr5;
};

struct SlotBase {
    void* vptr;
    SlotImpl* impl;
    void* fn;
    void construct(void* a, void* b, void* c, void* d, void* e, void* f, void* g);
};

extern "C" int __cdecl sub_4879D0(void*);
extern "C" void* __cdecl sub_62FEF6(unsigned int);

void SlotBase::construct(void* a, void* b, void* c, void* d, void* e, void* f, void* g)
{
    void* local[7];
    local[0] = a;
    local[1] = b;
    local[2] = c;
    local[3] = d;
    local[4] = e;
    local[5] = f;
    local[6] = g;

    if (!sub_4879D0(&local[0])) {
        this->fn = (void*)0x416a40;
        this->vptr = (void*)0x417530;
        SlotImpl* p = (SlotImpl*)sub_62FEF6(0x18);
        if (p) {
            p->vptr0 = local[0];
            p->vptr1 = local[1];
            p->vptr2 = local[2];
            p->vptr3 = local[3];
            if (local[4]) {
                _InterlockedExchangeAdd((volatile long*)((char*)local[4] + 4), 1);
            }
            p->vptr4 = local[5];
            p->vptr5 = local[6];
        }
        this->impl = p;
    }

    if (local[4]) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local[4] + 4), -1) == 1) {
            (*(void(__thiscall**)(void*))((*(void***)local[4])[1]))(local[4]);
            if (_InterlockedExchangeAdd((volatile long*)((char*)local[4] + 8), -1) == 1) {
                (*(void(__thiscall**)(void*))((*(void***)local[4])[2]))(local[4]);
            }
        }
    }
}
