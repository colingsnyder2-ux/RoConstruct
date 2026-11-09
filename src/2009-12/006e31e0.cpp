// from server: 97% by atomic.potato
struct Instance
{
    char pad0[76];
    int value;
};

extern "C" int __cdecl sub_007f4aaa(int, const char *, const char *, int, int);

int func_006e31e0(Instance *p)
{
    int result;

    if (p != 0)
    {
        result = sub_007f4aaa(p->value, "\x40\xfe\xaf\x00", "\x40\xab\xb0\x00", 0, 0);
        if (result != 0)
            return result;
    }

    return 0;
}
