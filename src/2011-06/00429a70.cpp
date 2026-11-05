// from server: 34% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_401610();
extern "C" void __cdecl sub_80B15D();
extern "C" void __cdecl sub_411500();
extern "C" void __cdecl sub_6D7090();
extern "C" void __cdecl sub_6B6F40();
extern "C" void __cdecl sub_40DE50(void*);
extern "C" void __cdecl sub_40DDC0(void*);
extern "C" void* __cdecl sub_40A2B0();
extern "C" void __stdcall SetEvent(void*);

struct RefCounted {
    void* vptr;
    volatile long refcount;
};

struct S {
    void* field0;
    void assign(void* arg);
};

void S::assign(void* arg)
{
    sub_401610();
    if (!(*(volatile unsigned char*)0x00CB25A4 & 1)) {
        *(volatile unsigned long*)0x00CB25A4 |= 1;
        *(void**)0x00CB259C = 0;
        *(void**)0x00CB25A0 = 0;
        sub_80B15D();
    }

    RefCounted* rc = (RefCounted*)0x00CB259C;
    char flag = 0;
    sub_411500();

    void* local = 0;
    if (this->field0 == 0) {
        void* p = arg;
        if (p != 0) {
            sub_40DE50((char*)p + 5);
        }
        void* old = this->field0;
        this->field0 = p;
        (void)old;
    } else {
        sub_6D7090();
        local = 0;
        void* p = arg;
        sub_6B6F40();
        if (p != 0) {
            sub_40DE50((char*)p + 5);
        }
        void* old = this->field0;
        this->field0 = p;
        if (old != 0) {
            sub_40DDC0((char*)old + 5);
        }
        void* tmp = local;
        flag = 0;
        if (tmp != 0) {
            sub_40DDC0((char*)tmp + 5);
        }
    }

    if (flag) {
        long old = _InterlockedExchangeAdd(&rc->refcount, (long)0x80000000);
        if (!(old & 0x40000000) && old > (long)0x80000000) {
            long prev = _InterlockedExchangeAdd((volatile long*)rc, 0x40000000);
            if (!(prev & 0x40000000)) {
                SetEvent(sub_40A2B0());
            }
        }
    }
}
