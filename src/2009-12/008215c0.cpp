// from server: 75% by atomic.potato
struct CXTPReportGroupRow_Batch {
    void *vtable;
    int f(void *);
};

int CXTPReportGroupRow_Batch::f(void *arg)
{
    typedef void (__thiscall *Callback)(void *, void *, int);
    Callback fn = *(Callback *)((char *)vtable + 0xfc);
    fn(this, arg, 0);
    return (int)arg;
}
