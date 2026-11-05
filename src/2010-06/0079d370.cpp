// from server: 53% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl boost_get_tss_data(const void*);
extern "C" void __cdecl boost_set_tss_data(const void*, void*, void*, int);

struct CleanupFunction
{
    void* vtable;
    void* data;
    volatile long shared_count;
    volatile long weak_count;
};

extern "C" void* __cdecl allocate_cleanup(unsigned int);

struct S
{
    void* key;
    void* cleanup;
    void* f();
};

void* S::f()
{
    CleanupFunction* created;
    CleanupFunction* old;
    CleanupFunction* current;

    created = (CleanupFunction*)allocate_cleanup(8);
    if (created != 0)
    {
        created->vtable = *(void**)this;
        created->data = *(void**)((char*)this + 4);
        if (created->data != 0)
            _InterlockedExchangeAdd(&((CleanupFunction*)created->data)->shared_count, 1);
        old = created;
    }
    else
        old = 0;

    current = (CleanupFunction*)boost_get_tss_data(this);
    if (current != old)
    {
        CleanupFunction value;

        value.vtable = *(void**)this;
        value.data = *(void**)((char*)this + 4);
        if (value.data != 0)
            _InterlockedExchangeAdd(&((CleanupFunction*)value.data)->shared_count, 1);

        boost_set_tss_data(this, old, &value, 1);
    }

    if (old != 0 &&
        _InterlockedExchangeAdd(&old->shared_count, -1) == 1)
    {
        typedef void (__thiscall *Destroy)(CleanupFunction*);
        typedef void (__thiscall *Deallocate)(CleanupFunction*);

        Destroy destroy = *(Destroy*)((char*)*(void**)old + 4);
        destroy(old);

        if (_InterlockedExchangeAdd(&old->weak_count, -1) == 1)
        {
            Deallocate deallocate = *(Deallocate*)((char*)*(void**)old + 8);
            deallocate(old);
        }
    }

    return 0;
}
