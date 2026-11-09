// from server: 62% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl Call_009831f5(void*);

struct Inner
{
    int* ptr;
    int field4;
    void assign(int*);
};

struct S
{
    void* vptr;
    int field4;
    Inner inner;
    void ctor(int*);
};

void Inner::assign(int* p)
{
    int* q = p;
    ptr = (int*)*q;
    field4 = q[1];
    if (field4)
    {
        _InterlockedExchangeAdd((volatile long*)(field4 + 4), 1);
    }
}

void S::ctor(int* arg)
{
    if (!(*(volatile unsigned char*)0xe21d94 & 1))
    {
        *(volatile unsigned int*)0xe21d94 |= 1;
        *(volatile unsigned int*)0xe21d88 = 0xd858d0;
        *(volatile unsigned int*)0xe21d90 = 0x54ed50;
        *(volatile unsigned int*)0xe21d8c = 0x41b810;
        Call_009831f5((void*)0xb13940);
    }

    if (vptr == (void*)0xe21d88)
    {
        int* p = arg;
        field4 = *p;
        p++;
        inner.assign(p);
        return;
    }

    if (vptr)
    {
        void (*fn)(int*) = *(void (**)(int*))((char*)vptr + 4);
        fn(&field4);
        vptr = 0;
    }

    Inner* ip = &inner;
    if (ip)
    {
        int* p = arg;
        ip->ptr = (int*)*p;
        ip->field4 = p[1];
        if (ip->field4)
        {
            _InterlockedExchangeAdd((volatile long*)(ip->field4 + 4), 1);
        }
    }

    vptr = (void*)0xe21d88;
}
