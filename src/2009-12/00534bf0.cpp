// from server: 59% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl sub_00534780(int *);
extern "C" int __cdecl sub_00533330(int, int);

int S::f()
{
    int value;
    int result = sub_00534780(&value);
    return sub_00533330(result, value);
}
