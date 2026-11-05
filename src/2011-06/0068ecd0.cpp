// from server: 95% by atomic.potato
extern "C" void __cdecl G1_func_0080b1d8(void *, unsigned int, const char *, unsigned int);
extern "C" void __cdecl G1_func_0080a304(void *);

struct GuiTextButton
{
    void *value;

    void func_0068ecd0();
};

void GuiTextButton::func_0068ecd0()
{
    void *p = value;
    if (p != 0)
    {
        void *q = (char *)p - 4;
        G1_func_0080b1d8(p, 0x84, ",SUVW", *(unsigned int *)q);
        G1_func_0080a304(q);
    }
}
