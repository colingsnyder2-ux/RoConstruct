// from server: 45% by atomic.potato
extern "C" void sub_00983144();

struct String
{
    ~String();
};

struct AdornBillboarder
{
    void f(void*, void*, void*, void*);
};

void AdornBillboarder::f(void*, void*, void*, void*)
{
    sub_00983144();
    String s;
}
