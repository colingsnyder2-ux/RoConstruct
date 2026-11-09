// from server: 62% by atomic.potato
struct S {
    char pad0[0x18];
    int (__stdcall *fn)(int, int);
    char pad1[0x4];
    int offset;
    char pad2[0x4];
    int index;
    int method(int, int);
};

int S::method(int a, int b)
{
    char* p = (char*)a;
    if (p != 0)
        p -= 0x1c;
    else
        p = 0;
    int idx = *(unsigned char*)b;
    int off = *(int*)(p + 0x148);
    int val = *(int*)(off + this->index);
    val += this->offset;
    int (__stdcall *f)(int, int) = this->fn;
    return f(val + (int)p + 0x148, idx);
}
