// from server: 86% by atomic.potato
extern "C" void sub_694b70(void*, int);
extern "C" void sub_40c080(void*, const char*);

struct S
{
    int value;
    int f(int);
};

int S::f(int a)
{
    if (a != *(int*)((char*)this + 0x134))
    {
        sub_694b70(this, a);
        sub_40c080(this, "d$0P");
    }
    return 0;
}
