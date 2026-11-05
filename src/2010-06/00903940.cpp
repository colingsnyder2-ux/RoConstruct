// from server: 97% by atomic.potato
typedef int (__thiscall *Method)(void *);

extern "C" int __cdecl sub_8df4c0(int, int);

struct S
{
    int f(int);
};

int S::f(int value)
{
    void *object = *(void **)((char *)this - 0x238);
    Method method = *(Method *)((char *)object + 0x168);
    method((char *)this - 0x238);
    sub_8df4c0(value, value);
    return value;
}
