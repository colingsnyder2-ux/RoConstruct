// from server: 73% by atomic.potato
// roc 2009-12 0065e600  unit: RBX::VSeat::?$FactoryProduct::Creator  size: 101 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0065e600

extern "C" int __cdecl sub_401630(void*, void*);
extern "C" int __cdecl sub_6531C0();
extern "C" void* __cdecl sub_7F3860(int);

struct RefCounted {
    void** vtable;
    void Release();
};

struct Holder {
    RefCounted* ptr;
};

struct Creator {
    void* field0;
    Holder holder;
    void* Create(void* arg);
};

void RefCounted::Release() {
    void** vt = *(void***)this;
    typedef void (__thiscall *Fn)(RefCounted*, int);
    ((Fn)vt[0])(this, 1);
}

void* Creator::Create(void* arg) {
    ++*(int*)0xb8fed0;
    sub_401630((void*)0xb8fd00, (void*)0x653220);
    void* v = (void*)sub_6531C0();
    this->field0 = v;
    RefCounted* n = (RefCounted*)sub_7F3860(8);
    if (n) {
        n->vtable = (void**)0x9ccccc;
        *(void**)((char*)n + 4) = *(void**)arg;
    } else {
        n = 0;
    }
    RefCounted* old = this->holder.ptr;
    if (&arg != (void**)&this->holder) {
        old = this->holder.ptr;
        this->holder.ptr = n;
    }
    if (old) {
        old->Release();
    }
    return this;
}
