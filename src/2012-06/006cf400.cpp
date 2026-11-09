// from server: 100% by atomic.potato
struct S_func_006cf400 {
    int kind;
    char pad4[12];
    int value;
    unsigned char flags[4];
    int f(int other);
};

int S_func_006cf400::f(int other)
{
    if (kind == 10 && (flags[0] & 3) != 0 && value == other)
        return 1;
    return 0;
}
