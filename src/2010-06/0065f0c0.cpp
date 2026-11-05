// from server: 69% by atomic.potato
extern "C" void __fastcall Copy9(void *, void *);

struct Backpack
{
    char pad0[252];
    char data[36];
    void f(void *);
};

void Backpack::f(void *p)
{
    Copy9(p, this->pad0 + 252);
    *(float *)((char *)p + 36) = *(float *)(this->pad0 + 288);
    *(float *)((char *)p + 40) = *(float *)(this->pad0 + 292);
    *(float *)((char *)p + 44) = *(float *)(this->pad0 + 296);
}
