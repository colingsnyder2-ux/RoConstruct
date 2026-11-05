// from server: 54% by atomic.potato
struct P8GuiTextButton_GetImpl {
    char pad0[8];
    int (__stdcall *fn)(void *, void *);
    char padC[4];
    void GetImpl(void *out, void *arg);
};

void P8GuiTextButton_GetImpl::GetImpl(void *out, void *arg)
{
    void *p;
    if (arg != 0)
        p = (char *)arg - 0x1c;
    else
        p = 0;

    float tmp[2];
    int (__stdcall *f)(void *, void *) = this->fn;
    f((char *)this + 0xc + (int)p, tmp);

    *(float *)out = tmp[0];
    *(float *)((char *)out + 4) = tmp[1];
}
