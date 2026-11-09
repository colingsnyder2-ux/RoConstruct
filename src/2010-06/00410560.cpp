// from server: 69% by atomic.potato
extern "C" void sub_0040FFA0(void *, void *);

struct S
{
    void *vftable;
    void *m04;
    void *m08;
    void *m0c;
    void *m10;
    void *m14;
    void *m18;
    void *m1c;
    void *m20;

    S(void *);
};

S::S(void *arg)
{
    sub_0040FFA0(this, arg);
    m20 = (void *)0xA02850;
    vftable = (void *)0xA02868;
    m0c = (void *)0xA02860;
    m20 = (void *)0xA02850;
}
