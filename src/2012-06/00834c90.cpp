// from server: 51% by atomic.potato
struct S
{
    int field_0c;
    int f(int value);
};

extern "C" int __cdecl sub_56beb0(int, int *, int);

int S::f(int value)
{
    int result = sub_56beb0(field_0c + 0x78, &value, value);
    return result ? -value : 0;
}
