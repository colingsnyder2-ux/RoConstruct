// from server: 100% by atomic.potato
extern "C" int __cdecl sub_0080b2ea(int, int, int, int, int);

struct Configuration_00696010
{
    int f(int);
};

int Configuration_00696010::f(int value)
{
    return sub_0080b2ea(value, 0, 0x00c071f8, 0x00c223b8, 0) == 0;
}
