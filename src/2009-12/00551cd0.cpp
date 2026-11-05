// from server: 68% by atomic.potato
extern "C" void sub_00503a70(int);

struct S_func_00551cd0
{
    int value;
    char pad[48];
    int member;
    void f(int value);
};

void S_func_00551cd0::f(int value)
{
    sub_00503a70(member + value);
}
