// from server: 75% by atomic.potato
extern "C" void sub_7479c0(void *, void *);

struct HopperBin_0068f150
{
    char pad0[332];
    void *field_14c;
    char pad1[36];
    void *field_174;
    void f(void *);
};

void HopperBin_0068f150::f(void *arg)
{
    sub_7479c0(field_14c, arg);
    sub_7479c0(field_174, arg);
}
