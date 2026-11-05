// from server: 63% by atomic.potato
struct S {
    char pad[0x18];
    int (__cdecl *fn)(int, int);
    int offset1c;
    int offset20;
    int method(int a, int b);
};

int S::method(int a, int b)
{
    S* p;
    if (a != 0)
        p = (S*)((char*)a - 0x1c);
    else
        p = 0;

    int idx = *(int*)b;
    int off = *(int*)((char*)p + 0x98);
    int val = *(int*)(off + this->offset20);
    val += this->offset1c;
    int (*f)(int, int) = this->fn;
    return f(val + (int)p + 0x98, idx);
}
