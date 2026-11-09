// from server: 100% by colin
struct S_func_00461c60
{
    void base();
    S_func_00461c60();
    unsigned char pad[0xf0];
    unsigned char flag;
};

S_func_00461c60::S_func_00461c60()
{
    base();
    *(int*)this = 0x79504c;
    flag = 0;
}
