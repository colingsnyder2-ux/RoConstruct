// from server: 18% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

bool func_00759970();

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
    void Release();
};

struct NewInstanceItem {
    char pad[0x18];
    RefCounted* ptr;
    bool method(RefCounted* a, int b, int c, int d, int e, int f);
};

bool NewInstanceItem::method(RefCounted* a, int b, int c, int d, int e, int f)
{
    RefCounted* local = 0;
    if (func_00759970())
    {
        if (local)
        {
            if (_InterlockedExchangeAdd(&local->ref1, -1) == 1)
            {
                local->Release();
                if (_InterlockedExchangeAdd(&local->ref2, -1) == 1)
                    local->Release();
            }
        }
        return false;
    }

    RefCounted* tmp = this->ptr;
    if (tmp)
        _InterlockedExchangeAdd(&tmp->ref1, 1);

    bool result = true;

    if (tmp)
    {
        if (_InterlockedExchangeAdd(&tmp->ref1, -1) == 1)
        {
            tmp->Release();
            if (_InterlockedExchangeAdd(&tmp->ref2, -1) == 1)
                tmp->Release();
        }
    }

    return result;
}
