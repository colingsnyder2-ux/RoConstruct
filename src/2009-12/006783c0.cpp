// from server: 76% by atomic.potato
struct S
{
    int pad0;
    int pad1;
    int pad2;
    void *value;
    void f(int);
};

extern "C" void sub_677e50(void *);
extern "C" void sub_69c200(void *);

void S::f(int)
{
    void *p = value;
    sub_677e50(p);
    sub_69c200(*(void **)((char *)value + 0xA90));
}
