// from server: 68% by atomic.potato
struct S
{
    char pad0[12];
    struct T
    {
        char pad0[8];
        int (*call)(T *);
        char pad1[328];
        int value;
    } *member;
    int f();
};

int S::f()
{
    T *p = member;
    int (*fn)(T *) = *(int (**)(T *))((char *)p + 8);
    int result = fn((T *)((char *)this->member + 336));
    return *((int *)((char *)result + 328)) == 1;
}
