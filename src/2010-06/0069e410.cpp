// from server: 41% by atomic.potato
extern "C" int sub_69e070(int);

struct S
{
    int field20;
    int f(int value);
};

int S::f(int value)
{
    int result = sub_69e070(value);
    int *object = *(int **)((char *)field20);
    return ((int (__thiscall *)(int *, int, int))(*(int **)((char *)object) + 0x10))(object, result, result);
}
