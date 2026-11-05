// from server: 50% by atomic.potato
struct S_func_006e3000 {
    char pad[0x98];
    int f(int arg);
};

int S_func_006e3000::f(int arg)
{
    if (arg == 0) {
        char *base = (char *)this - 0x98;
        int *obj = *(int **)base;
        int (*fn)(void *) = *(int (**)(void *))(obj + 0x40 / 4);
        return fn(base);
    }
    return 0;
}
