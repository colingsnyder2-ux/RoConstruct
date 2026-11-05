// from server: 64% by atomic.potato
struct S
{
    void f(int);
    int padding[59];
};

void S::f(int value)
{
    if (this->padding[58] != value)
    {
        this->padding[58] = value;
        ((void (__thiscall *)(int *, int))0x414da0)(&this->padding[58], 0xe490c0);
    }
}
