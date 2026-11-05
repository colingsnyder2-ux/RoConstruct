// from server: 64% by atomic.potato
extern "C" int __stdcall sym(int);

struct S
{
    int f();
    char padding[0x138];
    int value;
};

int S::f()
{
    int eax = value;
    int edx = eax & 0x80000001;
    if (edx < 0)
        edx = (edx - 1) | ~1;
    eax = edx + eax + 1;
    return sym(eax);
}
