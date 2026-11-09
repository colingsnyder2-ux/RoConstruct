// from server: 47% by atomic.potato
struct BodyColors
{
    int f();
};

int BodyColors::f()
{
    return *reinterpret_cast<volatile int *>(0);
}
