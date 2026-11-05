// from server: 27% by atomic.potato
struct S_func_00525900
{
    struct Result
    {
        char pad0[0x266e];
        unsigned char value;
    };

    Result* get();
    unsigned char f();
};

S_func_00525900::Result* S_func_00525900::get()
{
    return 0;
}

unsigned char S_func_00525900::f()
{
    Result* p = get();
    if (p)
        return p->value;
    return 0;
}
