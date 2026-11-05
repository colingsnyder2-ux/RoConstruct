// from server: 25% by atomic.potato
extern "C" void sub_005ea3e0(void*);

struct S_00781f60
{
    char pad0[8];
    float value;
    void f(float value);
};

void S_00781f60::f(float value)
{
    this->value = value;
    sub_005ea3e0(this);
}
