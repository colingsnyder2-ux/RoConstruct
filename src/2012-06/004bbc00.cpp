// from server: 69% by atomic.potato
extern "C" void sub_004bad30(void *, void *);

struct S
{
    int f(void *);
    int v0;
    char pad0[36];
    int v1;
    char pad1[16];
    int v2;
};

int S::f(void *arg)
{
    sub_004bad30(this, arg);
    v1 = 0x00b43c34;
    v0 = 0x00b64c0c;
    v2 = 0x00b64c04;
    v1 = 0x00b64bf4;
    return (int)this;
}
