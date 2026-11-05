// from server: 86% by atomic.potato
extern "C" int sub_70A4D0(void);
extern "C" void sub_70ADF0(void*);

struct S
{
    int value;
    S(void* arg);
};

S::S(void* arg)
{
    value = sub_70A4D0();
    sub_70ADF0(arg);
}
