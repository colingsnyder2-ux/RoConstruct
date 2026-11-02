// from server: 67% by tajop
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_6a2870(volatile long*);

struct Counted
{
    int vtbl;
    volatile long refs;
};

struct Item
{
    Counted* p;
    int pad;
    int a;
    int b;
    int c;
    int d;
};

inline void add_ref(volatile long* r)
{
    _InterlockedExchangeAdd(r, 1);
}

inline void release(Counted* o)
{
    volatile long* r = &o->refs;
    sub_6a2870(r);
}

void func_00852470(Item* first, Item* last, Item& val)
{
    if (first != last)
    {
        int* q = &first->c;
        do
        {
            Counted* n = val.p;
            if (n)
                add_ref(&n->refs);
            Counted* old = first->p;
            first->p = n;
            if (old)
                release(old);
            q[-2] = val.a;
            q[-1] = val.b;
            q[0] = val.c;
            q[1] = val.d;
            ++first;
            q += 6;
        } while (first != last);
    }
}
