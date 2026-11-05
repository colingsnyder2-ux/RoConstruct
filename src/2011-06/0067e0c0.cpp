// from server: 100% by atomic.potato
struct Instance
{
    char pad[0x44];
    int field44;
};

extern "C" int __cdecl G1_func_0080b2ea(int, int, int, int, int);

int func_0067e0c0(Instance* value)
{
    if (value != 0)
    {
        int r = G1_func_0080b2ea(value->field44, 0, 0xc071f8, 0xc1a934, 0);
        if (r != 0)
            return r;
    }
    return 0;
}
