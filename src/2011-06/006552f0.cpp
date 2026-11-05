// from server: 59% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Base {
    char pad[0x4c];
    int field_4c;
    long* field_50;
    Base();
};

struct Derived : Base {
    Derived(Base* other);
};

Derived::Derived(Base* other) {
    Base::Base();
    *(void**)this = (void*)0xa9a848;
    field_4c = other->field_4c;
    field_50 = other->field_50;
    if (field_50) {
        _InterlockedExchangeAdd((volatile long*)((char*)field_50 + 4), 1);
    }
}
