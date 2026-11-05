// from server: 46% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)



struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
    virtual void destroy1();
    virtual void destroy2();
};

struct Iter {
    RefCounted** first;
    RefCounted** last;
    RefCounted** end;
};

struct Outer {
    void func(int a, int b, int c);
    void _invalid_parameter_noinfo();
};

extern "C" void __cdecl sub_4178F0(Iter* out);
extern "C" void __cdecl sub_4D0950(void* self, int val);

void Outer::func(int a, int b, int c)
{
    char* base = (char*)this + 0xc0;
    if (*(void**)base == 0)
        return;

    Iter it;
    sub_4178F0(&it);

    RefCounted** cur = it.first;
    RefCounted** last = it.last;

    if (cur > last)
        _invalid_parameter_noinfo();

    RefCounted** end = it.end;
    if (cur > end)
        _invalid_parameter_noinfo();

    while (cur != last) {
        if (cur >= end)
            _invalid_parameter_noinfo();

        RefCounted* obj = *cur;
        if (obj != 0) {
            _InterlockedExchangeAdd(&obj->ref1, 1);
        }

        sub_4D0950(&it, c);

        if (cur >= end)
            _invalid_parameter_noinfo();
        cur++;
    }

    RefCounted* obj = (RefCounted*)it.first;
    if (obj != 0) {
        if (_InterlockedExchangeAdd(&obj->ref1, -1) == 1) {
            obj->destroy1();
            if (_InterlockedExchangeAdd(&obj->ref2, -1) == 1) {
                obj->destroy2();
            }
        }
    }
}
