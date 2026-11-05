// from server: 52% by atomic.potato
struct S
{
    struct T
    {
        int padding[7];
        int value;
    };

    int padding[9];
    T *field;
    int f();
};

int S::f()
{
    int value = field->value;
    if (value)
        return value - 8;
    return 0;
}
