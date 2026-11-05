// from server: 69% by atomic.potato
extern "C" void sub_679290(void *);

extern "C" double g_value;

struct S
{
    int f();
};

int S::f()
{
    char *p = reinterpret_cast<char *>(this) + 8;
    sub_679290(p);
    return static_cast<int>(*reinterpret_cast<float *>(p + 0x808) * g_value);
}
