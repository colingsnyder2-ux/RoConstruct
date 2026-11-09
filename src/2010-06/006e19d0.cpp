// from server: 97% by atomic.potato
extern "C" unsigned char __cdecl Function7655D0(int, int);

struct S {
    int f();
    int field0;
    int field8;
    int fieldC;
};

int S::f()
{
    if (field0 == 10)
        if (Function7655D0(fieldC, field8))
            return 1;
    return 0;
}
