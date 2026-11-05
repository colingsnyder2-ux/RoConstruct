// from server: 50% by atomic.potato
struct CInsertObjectDialog
{
    int f(int);
};

extern "C" int __stdcall sub_664540(CInsertObjectDialog *);
extern "C" void sub_664370(CInsertObjectDialog *);
extern "C" void sub_57ba80(CInsertObjectDialog *, int);

int CInsertObjectDialog::f(int value)
{
    if (sub_664540(this))
    {
        sub_664370(this);
        sub_57ba80(this, value);
    }
    return 0;
}
