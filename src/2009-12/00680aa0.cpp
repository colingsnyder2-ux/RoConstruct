// from server: 95% by atomic.potato
struct S {
    void* f();
    char padding[208];
    int field_d0;
    char field_a0[4];
};

void* S::f()
{
    if (field_d0 == 0)
        return field_a0;
    return (void*)0x00b90edc;
}
