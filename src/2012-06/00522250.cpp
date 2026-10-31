// from server: 44% by Intel





extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    int vptr;
    long refCount1;
    long refCount2;
};

struct Variant {
    int vptr;
    int pad4;
    int pad8;
    RefCounted* ref;
    unsigned char pad10;
    unsigned char pad11;
};

struct TypeInfo {
    int vptr;
};

extern "C" int __stdcall type_info_equals(const TypeInfo*, const TypeInfo*);

int __cdecl EnumProperty_Handler(int op, void* dest, void* src) {
    if (op == 0 || op == 1) {
        if (dest) {
            Variant* d = static_cast<Variant*>(dest);
            const Variant* s = static_cast<const Variant*>(src);
            d->vptr = s->vptr;
            d->pad4 = s->pad4;
            d->pad8 = s->pad8;
            d->ref = s->ref;
            if (s->ref) {
                long old = _InterlockedExchangeAdd(&s->ref->refCount1, 1);
            }
            d->pad10 = s->pad10;
            d->pad11 = s->pad11;
        }
        if (op == 1) {
            const Variant* s = static_cast<const Variant*>(src);
            RefCounted* ref = s->ref;
            if (ref) {
                long old = _InterlockedExchangeAdd(&ref->refCount1, -1);
                if (old == 1) {
                    int vptr_val = ref->vptr;
                    typedef void (__thiscall *DtorFn)(RefCounted*);
                    DtorFn dtor = *reinterpret_cast<DtorFn*>(vptr_val + 4);
                    dtor(ref);
                    old = _InterlockedExchangeAdd(&ref->refCount2, -1);
                    if (old == 1) {
                        int vptr_val2 = ref->vptr;
                        typedef void (__thiscall *DeleteFn)(RefCounted*);
                        DeleteFn del = *reinterpret_cast<DeleteFn*>(vptr_val2 + 8);
                        del(ref);
                    }
                }
            }
        }
        return 0;
    }
    if (op == 2) {
        Variant* d = static_cast<Variant*>(dest);
        d->ref = reinterpret_cast<RefCounted*>(0xD7C110);
        d->pad10 = 0;
        d->pad11 = 0;
        return 0;
    }
    if (op == 3) {
        int* destInt = static_cast<int*>(dest);
        const TypeInfo* typeInfo = reinterpret_cast<const TypeInfo*>(0xD7C110);
        int result = type_info_equals(typeInfo, *reinterpret_cast<const TypeInfo* const*>(src));
        int val = -(result != 0);
        val &= *reinterpret_cast<int*>(reinterpret_cast<char*>(dest) + 8);
        *destInt = val;
        return 0;
    }
    return 0;
}
