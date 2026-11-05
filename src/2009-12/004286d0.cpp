// from server: 46% by atomic.potato
struct CWrapperView
{
    int __cdecl Get(int);
};

int CWrapperView::Get(int value)
{
    int (**vtable)() = *(int (***)())this;
    value = 0x99fd56;
    return vtable[3]();
}
