// from server: 85% by atomic.potato
extern "C" int sub_6272d0(void *, int);
extern "C" int sub_627310(void);
extern "C" void sub_4c35d0(void *, int, int, int);

struct AdornRbxGfx
{
    void f(int, int, int);
};

void AdornRbxGfx::f(int a, int b, int c)
{
    int x = sub_6272d0(this, c);
    x = sub_627310();
    sub_4c35d0(this, a, b, x);
}
