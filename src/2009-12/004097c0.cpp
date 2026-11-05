// from server: 54% by atomic.potato
extern "C" void __stdcall sub_409420(void*);

struct Inner {
    char pad0[4];
    void* p4;
    int c;
    int d;
    int e;
};

struct Outer {
    void* vtbl;
    char pad4[0x24];
    void* vtbl28;
    void* p2c;
    int p30;
    int p34;
    int p38;
    void* ctor(Inner*);
};

void* Outer::ctor(Inner* arg)
{
    sub_409420(this);
    this->vtbl = (void*)0x99fdac;
    this->vtbl28 = (void*)0x99fdd8;
    Inner* p = arg ? (Inner*)((char*)arg + 0x28) : 0;
    this->p2c = p->p4;
    if (this->p2c) {
        void** vt = *(void***)this->p2c;
        ((void(__thiscall*)(void*))vt[3])(this->p2c);
    }
    this->p30 = p->c;
    this->p34 = p->d;
    this->p38 = p->e;
    this->vtbl = (void*)0x99ff04;
    this->vtbl28 = (void*)0x99fefc;

    return this;
}
