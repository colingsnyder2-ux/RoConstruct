// from server: 61% by atomic.potato
struct S
{
    int f(int, float);
};

extern "C" int __cdecl sub_008af41a(int);
extern "C" int __cdecl imported_00bec0f8(int, float);

int S::f(int a, float b)
{
    sub_008af41a(1);
    return imported_00bec0f8(a, b);
}
