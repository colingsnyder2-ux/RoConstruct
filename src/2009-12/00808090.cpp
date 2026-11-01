// from server: 100% by atomic.potato
struct S_func_00808090
{
    void* get_807bd0();

    int is_valid();
};

int S_func_00808090::is_valid()
{
    void* p = get_807bd0();
    if (p != 0 && *((int*)((char*)p + 0x68)) != 0)
        return 1;
    return 0;
}
