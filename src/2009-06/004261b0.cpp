// from server: 62% by colin
// roc 2009-06 004261b0  unit: boost::any::H::?$holder  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004261b0

struct AnyHolder {
    void* vptr;
    void* data;
};

struct AnyValue {
    void* type;
    AnyHolder* holder;
};

struct AnyOps {
    void* unknown0;
    void* unknown1;
    void (*destroy)(AnyHolder*, int);
};

struct AnyHolderVtbl {
    void* unknown0;
    void* unknown1;
    AnyHolder* (__thiscall *clone)(AnyHolder*);
};

void __cdecl copy_range(AnyValue* first, AnyValue* last, AnyValue* dest) {
    if (first != last) {
        do {
            dest->type = first->type;
            AnyHolder* src = first->holder;
            AnyHolder* cloned;
            if (src) {
                AnyHolderVtbl* vt = *(AnyHolderVtbl**)src;
                cloned = vt->clone(src);
            } else {
                cloned = 0;
            }
            AnyHolder* old = dest->holder;
            if (&dest->holder != &first->holder) {
                old = first->holder;
                first->holder = cloned;
            }
            if (old) {
                AnyOps* ops = *(AnyOps**)old;
                ops->destroy(old, 1);
            }
            first = (AnyValue*)((char*)first + 8);
            dest = (AnyValue*)((char*)dest + 8);
        } while (first != last);
    }
}
