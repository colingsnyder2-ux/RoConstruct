// from server: 100% by atomic.potato
struct S {
    void f(char value);
};

void S::f(char value)
{
    *(char*)((char*)this + 0x9f0) = value;
}
