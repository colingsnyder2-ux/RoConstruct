// from server: 46% by atomic.potato
struct S
{
    int f();
    int m_a8;
};

extern "C" int sub_499fe0(int *);
extern "C" int sub_759ef0(S *, int *);

int S::f()
{
    int value = sub_499fe0(&m_a8);
    return sub_759ef0(this, &value);
}
