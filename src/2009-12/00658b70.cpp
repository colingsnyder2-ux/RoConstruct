// from server: 66% by atomic.potato
struct S
{
    char pad[168];
    int value;
    int f(int);
};

extern "C" int __stdcall sub_7b7e50(int *, int);

int S::f(int a)
{
    return sub_7b7e50(&a, value);
}
