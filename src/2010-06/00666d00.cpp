// from server: 62% by atomic.potato
struct S_func_00666d00
{
    unsigned char pad[0x15];
    unsigned char enabled;
    bool f(int a1);
};

extern "C" void sub_00657740(void *, void *, void *);

bool S_func_00666d00::f(int a1)
{
    if (!enabled)
        return false;

    void *local;
    sub_00657740((char *)this - 0x98, &local, (void *)a1);
    return true;
}
