// from server: 97% by atomic.potato
struct S
{
};

extern "C" int __cdecl sub_4e1260(int, int);
extern "C" int __cdecl sub_4e1050(int, void *);

int __cdecl f(int a, int b)
{
    int value;
    sub_4e1260(a, b);
    sub_4e1050(a, &value);
    *(short *)((char *)b + 4) = *(short *)((char *)&value + 8);
    return a;
}
