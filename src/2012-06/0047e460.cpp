// from server: 92% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Base {
    char pad[0x4c];
    void* field_4c;
    volatile long* field_50;
};

struct Derived : Base {
    Derived(Base* other);
};

extern "C" void __cdecl sub_47aed0(Base* other);

Derived::Derived(Base* other)
{
    sub_47aed0(other);
    *(void**)this = (void*)0xb5c60c;
    field_4c = other->field_4c;
    field_50 = other->field_50;
    if (field_50 != 0)
    {
        _InterlockedExchangeAdd(field_50 + 1, 1);
    }
}
