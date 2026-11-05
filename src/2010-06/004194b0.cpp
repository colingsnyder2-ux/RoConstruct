// from server: 28% by atomic.potato
struct S
{
    void f(int);
};

void S::f(int value)
{
    char *p = reinterpret_cast<char *>(this) + value;
    (void)p;
}
