// from server: 56% by atomic.potato
extern "C" int __cdecl sub_7555C0(int*, int, int);

struct S {
    int padding[10];
    int* field28;
    int f(int, int);
};

int S::f(int a, int b)
{
    int local;
    int* p = field28;
    int* q = (int*)((char*)*p + 12);
    int result = sub_7555C0(&local, a, b);
    int (__thiscall *fn)(int*, int, int) =
        (int (__thiscall *)(int*, int, int))*(int*)q;
    return fn(p, b, result);
}
