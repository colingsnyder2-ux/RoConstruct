// from server: 83% by atomic.potato
extern "C" int sub_6aa690();
extern "C" void sub_6aa740();

volatile int global_0xb8fd60;

struct S
{
    int f();
};

int S::f()
{
    ++global_0xb8fd60;
    int value = sub_6aa690();
    *(int *)this = value;
    sub_6aa740();
    return (int)this;
}
