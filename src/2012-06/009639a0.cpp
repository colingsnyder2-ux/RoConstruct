// from server: 100% by atomic.potato
int func_009639a0(void *p)
{
    if (!p)
        return 0;
    if (!*(void **)((char *)p + 4))
        return 1;
    return func_009639a0(*(void **)((char *)p + 4)) + 1;
}
