// from server: 78% by Intel
struct CProgressDialog
{
    void f();
};

void CProgressDialog::f()
{
    typedef void (__thiscall *Callback)(void *, int, void *);
    Callback cb = *reinterpret_cast<Callback *>(this + 0x10);
    if (cb)
    {
        void *context = reinterpret_cast<void *>(reinterpret_cast<char *>(this) + 0x18);
        cb(context, 2, context);
        *reinterpret_cast<int *>(this + 0x10) = 0;
    }
}
