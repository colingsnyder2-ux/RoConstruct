// from server: 62% by colin
struct CLuaHtmlView
{
    void sub_42C720();
};

extern int G_44ECE0;
extern void __stdcall sub_42C6F0(int, int);

void CLuaHtmlView::sub_42C720()
{
    int local[3];
    int* p = (int*)((char*)this + 4);
    int a = 0;
    int d = 0;
    int b = 0;

    if (G_44ECE0 != 0)
    {
        sub_42C6F0(a, (int)&G_44ECE0);
        b = 0x42C6E0;
        d = 0x42C6F0;
    }

    if (p != local)
    {
        int old0 = p[0];
        p[0] = d;
        int old1 = p[1];
        p[1] = a;
        p[2] = b;
        d = old0;
        a = old1;
    }

    if (d != 0)
    {
        ((void (__stdcall*)(int, int))d)(a, 1);
    }
}
