// from server: 27% by atomic.potato
struct S
{
    void f(int);
};

void S::f(int value)
{
    volatile int result = value;
}
