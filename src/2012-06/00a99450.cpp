// from server: 36% by atomic.potato
extern "C" void sub_00983144();

struct BasicString
{
    ~BasicString();
};

struct S
{
    void f();
};

void S::f()
{
    BasicString s;
    sub_00983144();
}
