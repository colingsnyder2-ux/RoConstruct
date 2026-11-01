// from server: 100% by atomic.potato
struct S
{
    int f(int);
    int value8;
    int valueC;
};

int S::f(int p)
{
    int* base = (int*)p;
    if (base)
        base = (int*)((char*)base - 20);
    else
        base = 0;

    int index = *(int*)((char*)base + 0x134);
    int offset = *(int*)((char*)this + 0xC);
    int entry = *(int*)((char*)index + offset);
    entry += *(int*)((char*)this + 8);

    return *(int*)((char*)entry + (int)base + 0x134);
}
