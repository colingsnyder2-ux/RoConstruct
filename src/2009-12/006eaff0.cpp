// from server: 79% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_6e6650(int);

int S::f()
{
    int result = sub_6e6650((int)this - 0x94);
    if (result != 0)
        result = *(int *)(*(int *)(result + 0x168) + 0xf4);
    if (result != 0)
        result = *(int *)(result + 0x2c);
    return result;
}
