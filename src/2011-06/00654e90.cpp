// from server: 38% by atomic.potato
struct S
{
    int* field;

    int f();
};

extern "C" int __cdecl Function653CB0(int*, int*, int*);
extern "C" int __cdecl Function654D70(int);

int S::f()
{
    int* p = field;
    if (p == 0)
        return Function653CB0(0, 0, 0);

    return Function654D70(Function653CB0(p, p + 0x1c, p + 0x38));
}
