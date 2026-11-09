// from server: 69% by atomic.potato
struct S
{
    void f(int);
    char pad[0x170];
};

extern void g(void*, int);

void S::f(int value)
{
    char* p = reinterpret_cast<char*>(this) + 0x170;
    g(p, value);
}
