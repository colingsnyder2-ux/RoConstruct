// from server: 37% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    void** vptr;
    long refcount;
};

struct Inner
{
    void** vptr;
    long refcount;
};

struct Holder
{
    void* ptr;
    Inner* inner;
};

struct S
{
    char pad0[8];
    Holder holder;
    char pad1[0x24 - 0x10];
    int* field24;
    void clear();
};

int* __cdecl f(int* p);
void __cdecl g(void* p, void* q, void* r);

void S::clear()
{
    if (field24 != 0)
    {
        int* a = f(field24);
        g(&holder, a, 0);
        if (holder.ptr != 0)
        {
            RefCounted* rc = (RefCounted*)holder.ptr;
            if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1)
            {
                ((void (__thiscall*)(RefCounted*))rc->vptr[1])(rc);
                if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1)
                {
                    ((void (__thiscall*)(RefCounted*))rc->vptr[2])(rc);
                }
            }
        }
    }
    else
    {
        Inner* old = holder.inner;
        holder.inner = 0;
        if (old != 0)
        {
            if (_InterlockedExchangeAdd(&old->refcount, -1) == 1)
            {
                ((void (__thiscall*)(Inner*))old->vptr[2])(old);
            }
        }
    }
}
