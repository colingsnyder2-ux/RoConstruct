// from server: 77% by atomic.potato
extern "C" void * __cdecl sub_7b2f50(void *);
extern "C" void __cdecl sub_775820(void *);
extern "C" void __cdecl sub_7b2f60(void *);

struct S_007aa9c0
{
    char pad[152];
    void *f();
};

void *S_007aa9c0::f()
{
    void *p = this ? (void *)(this->pad + 152) : 0;
    sub_775820(sub_7b2f50(p));
    sub_7b2f60(this);
    return 0;
}
