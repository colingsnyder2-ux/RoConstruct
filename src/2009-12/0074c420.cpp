// from server: 69% by atomic.potato
extern "C" int __cdecl sub_74c2e0(int, int*);

struct S
{
    int* field_1c;
    int f(int, int);
};

int S::f(int a, int b)
{
    int* p = field_1c;
    int* q = (int*)((char*)*p + 0x10);
    int value = sub_74c2e0(b, &b);
    return ((int (*)(int*, int, int))(*(int**)q))(p, a, value);
}
