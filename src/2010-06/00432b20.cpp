// from server: 64% by atomic.potato
struct CProgressDialog
{
    int unused0;
    int unused1;
    int unused2;
    int unused3;
    void *object;
    int unused4;
    int unused5;
    int value;
    void f();
};

void CProgressDialog::f()
{
    if (object != 0)
    {
        typedef void (__thiscall *Function)(void *, void *, void *, int);
        Function function = *(Function *)object;
        if (function != 0)
            function(object, (char *)this + 0x18, (char *)this + 0x18, 2);
        object = 0;
    }
}
