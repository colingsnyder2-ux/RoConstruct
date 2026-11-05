// from server: 100% by atomic.potato
extern "C" int __cdecl sub_007f4aaa(int, int, int, int, int);

struct Teams
{
    int teamExists(int);
};

int Teams::teamExists(int value)
{
    return !!sub_007f4aaa(value, 0, 0xaffe40, 0xb2b298, 0);
}
