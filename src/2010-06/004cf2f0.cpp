// from server: 93% by atomic.potato
struct S_func_004cf2f0
{
    char pad[4];
    void *field4;
    int f(int, int);
};

extern "C" int __stdcall sub_004cee80(void *, int, int);

int S_func_004cf2f0::f(int a, int b)
{
    int r = sub_004cee80(field4, a, b);
    switch (r)
    {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    }
    return 0;
}
