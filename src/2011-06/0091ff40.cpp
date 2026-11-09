// from server: 67% by atomic.potato
extern "C" int __cdecl sub_00500ef0();

struct ViewRbxGfx_0091ff40
{
    char pad0[12];
    int m_value;
    void f();
};

extern "C" void sub_0091e460(ViewRbxGfx_0091ff40 *, int);

void ViewRbxGfx_0091ff40::f()
{
    int value;
    if (m_value)
        value = sub_00500ef0();
    else
        value = 0;
    sub_0091e460(this, value);
}
