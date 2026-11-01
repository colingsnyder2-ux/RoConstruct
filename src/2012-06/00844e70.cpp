// from server: 18% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void AddRef();
    void Release();
};

struct Inner {
    char pad0[4];
    RefCounted* ptr;
};

struct Outer {
    char pad0[4];
    Inner inner;
};

struct Slot {
    void* vptr;
    char pad0[4];
    RefCounted* ptr;
    void Release();
};

struct Wrapper {
    void* field0;
    char pad0[4];
    RefCounted* field8;
    bool Equals(Wrapper* other);
};

bool Wrapper::Equals(Wrapper* other) {
    if (this->field0 != other->field0)
        return false;

    RefCounted* a = 0;
    RefCounted* b = 0;

    {
        Slot* s = (Slot*)((char*)this + 4);
        a = s->ptr;
        if (a) {
            _InterlockedExchangeAdd((volatile long*)((char*)a + 4), 1);
        }
    }

    if (a != 0) {
        if (b) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
                b->Release();
            }
        }
        return false;
    }

    {
        Slot* s = (Slot*)((char*)other + 4);
        b = s->ptr;
        if (b) {
            _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
        }
    }

    bool result;
    if (a == 0) {
        if (b) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
                b->Release();
            }
        }
        result = false;
    } else {
        result = (a == b);
        if (b) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
                b->Release();
            }
        }
    }

    if (a) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)a + 4), -1) == 1) {
            a->Release();
        }
    }

    return result;
}
