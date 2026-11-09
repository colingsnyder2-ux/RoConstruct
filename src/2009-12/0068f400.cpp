// from server: 99% by atomic.potato
extern "C" int __cdecl CallTarget(int, const void *, const void *, int, int);

struct S {
    int f();
    int padding[19];
    void *field4c;
};

int S::f()
{
    if (field4c != 0 &&
        CallTarget((int)field4c, 0, (const void *)0xaffe40,
                   (int)".?AVInstance@RBX@@", 0) != 0)
        return 1;
    return 0;
}
