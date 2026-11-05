// from server: 100% by why2
struct MegaTextureProxy {
    void func(int a, int b, int c);
};

void MegaTextureProxy::func(int a, int b, int c)
{
    volatile int local = 0;
    int *p = (int *)a;
    *p = 0;
}
