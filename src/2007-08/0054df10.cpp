// from server: 53% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Allocator {
    char* allocate(unsigned int, const void*);
    void deallocate(char*, unsigned int);
};

struct RefCounted {
    long refcount;
    long weakcount;
    virtual void destroy();
    virtual void destroy2();
};

struct Inner {
    void* ptr;
    RefCounted* ctrl;
};

struct Outer {
    char pad0[0x3c];
    char flag3c;
    char pad3d[3];
    Inner inner40;
    char* data50;
    unsigned int size54;
    unsigned int cap58;
    unsigned int flags5c;
    void set_capacity(unsigned int, unsigned int, unsigned int);
    void set_capacity_inner(Inner*);
};

void Outer::set_capacity(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int n = a;
    if (n == 0xffffffff)
        n = 0x80;
    unsigned int m = b;
    if (m == 0xffffffff)
        m = 4;
    unsigned int local = 2;
    unsigned int* psel;
    if ((int)m > 2)
        psel = &m;
    else
        psel = &local;
    unsigned int chosen = *psel;
    this->cap58 = chosen;
    if (n == 0)
        n = 1;
    unsigned int total = chosen + n;
    if (this->size54 != total)
    {
        char* newbuf = ((Allocator*)0)->allocate(total, 0);
        unsigned int oldsize = this->size54;
        this->size54 = total;
        char* oldbuf = this->data50;
        this->data50 = newbuf;
        if (oldbuf)
            ((Allocator*)0)->deallocate(oldbuf, oldsize);
    }
    void** vt = *(void***)this;
    void (*fn)(Outer*) = (void (*)(Outer*))vt[0x54/4];
    fn(this);

    Inner tmp;
    tmp.ptr = this->inner40.ptr;
    tmp.ctrl = this->inner40.ctrl;
    if (tmp.ctrl)
    {
        _InterlockedExchangeAdd(&tmp.ctrl->refcount, 1);
    }
    this->set_capacity_inner(&tmp);
    if (tmp.ctrl)
    {
        if (_InterlockedExchangeAdd(&tmp.ctrl->refcount, -1) == 1)
        {
            tmp.ctrl->destroy();
            if (_InterlockedExchangeAdd(&tmp.ctrl->weakcount, -1) == 1)
                tmp.ctrl->destroy2();
        }
    }
    this->flags5c |= 1;
    this->flag3c = 0;
}
