// from server: 66% by atomic.potato
struct S
{
    char padding_0[148];
    int field_94;
    char padding_98[4];
    int field_9c;
    char field_a0;
    int f();
};

int S::f()
{
    if (field_9c != 0 || field_a0 != 0)
        return field_94;
    return 0;
}
