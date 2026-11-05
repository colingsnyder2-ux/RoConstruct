// from server: 27% by atomic.potato
struct S
{
    int f();
};

struct V
{
    int value;
};

extern V* g_00b7e4c4;

int S::f()
{
    int* p = 0;
    return g_00b7e4c4->value;
}
