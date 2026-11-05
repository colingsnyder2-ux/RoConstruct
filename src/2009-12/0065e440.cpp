// from server: 74% by atomic.potato
extern "C" void __cdecl sub_401630(int, int);
extern "C" int __cdecl sub_652f90();
extern "C" void* __cdecl sub_7f3860(int);

struct Inner {
    void** vtable;
    int value;
};

struct S {
    void* field0;
    Inner* field4;
    S* ctor(int*);
};

S* S::ctor(int* arg) {
    ++*(int*)0xb8ffa8;
    sub_401630(0xb8fcec, 0x652ff0);
    field0 = (void*)sub_652f90();
    Inner* tmp = (Inner*)sub_7f3860(8);
    if (tmp) {
        tmp->vtable = (void**)0x9ccc0c;
        tmp->value = *arg;
    } else {
        tmp = 0;
    }
    Inner** slot = &field4;
    Inner* old = *slot;
    if (slot != (Inner**)&arg) {
        old = *slot;
        *slot = tmp;
    }
    if (old) {
        ((void (__thiscall*)(Inner*, int))old->vtable[0])(old, 1);
    }
    return this;
}
