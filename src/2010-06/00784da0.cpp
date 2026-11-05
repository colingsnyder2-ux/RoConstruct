// from server: 100% by atomic.potato
struct Base {
    void construct(int, int);
};

struct Dead : Base {
    void* vfptr0;
    void* vfptr1;
    Dead(int, int);
};

Dead::Dead(int a, int b)
{
    construct(a, b);
    vfptr0 = (void*)0xa538b8;
    vfptr1 = (void*)0xa538b0;
}
