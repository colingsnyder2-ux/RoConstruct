// from server: 69% by atomic.potato
extern "C" void __cdecl sub_401630(int, int);
extern "C" int __cdecl sub_653620();
extern "C" void* __cdecl sub_7F3860(int);

struct Inner {
    void** vtbl;
    int field4;
};

struct S {
    int field0;
    Inner* field4;
    int f(S* arg);
};

int S::f(S* arg) {
    ++*(int*)0xb900bc;
    sub_401630(0xb8fd28, 0x653680);
    int v = sub_653620();
    this->field0 = v;
    Inner* p = (Inner*)sub_7F3860(8);
    if (p) {
        p->vtbl = (void**)0x9cce7c;
        p->field4 = arg->field0;
    } else {
        p = 0;
    }
    Inner* old = this->field4;
    if ((void*)&arg != (void*)&this->field4) {
        this->field4 = p;
    }
    if (old) {
        ((void (__stdcall*)(int))old->vtbl[0])(1);
    }
    return (int)this;
}
