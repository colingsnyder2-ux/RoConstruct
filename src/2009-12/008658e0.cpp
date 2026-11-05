// from server: 73% by atomic.potato
struct S
{
    int SetValue(int value);
    char padding[144];
    int field_90;
};

int S::SetValue(int value)
{
    if (field_90 != value)
    {
        field_90 = value;
        value = 1;
        goto done;
    }
    return 0;

done:
    return value;
}
