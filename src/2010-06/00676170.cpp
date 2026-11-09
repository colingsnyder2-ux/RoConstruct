// from server: 80% by atomic.potato
struct EventDesc
{
    int f(int);
};

extern "C" int __stdcall do_global_lower(int);

int EventDesc::f(int value)
{
    int a = do_global_lower(*(int *)(value + 0x10));
    int b = do_global_lower(*(int *)(value + 0x14));
    if (a != (int)this)
        return b;
    return a;
}
