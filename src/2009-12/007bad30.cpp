// from server: 45% by atomic.potato
struct Sub {
    void f(int);
};

struct Inner {
    char pad[0x10];
    void g(char);
};

struct S {
    int (__stdcall *vf0)(int);
    char pad0[4];
    Sub *p8;
    Inner in10;
    void* dtor(char);
};

void __stdcall sub_7e6290(Inner *self, char v);
void __stdcall sub_7f385a(S *self);

void* S::dtor(char flag)
{
    this->vf0 = (int (__stdcall *)(int))0x9ee394;
    sub_7e6290(&this->in10, 0);
    Sub *p = this->p8;
    if (p) {
        (*(void (__stdcall **)(Sub *, int))p)(p, 1);
    }
    if (flag & 1) {
        sub_7f385a(this);
    }

    return this;
}
