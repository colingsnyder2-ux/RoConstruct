// from server: 74% by atomic.potato
struct CInsertObjectDialog
{
    int f();
};

extern "C" void func_007f4184(void*);
extern "C" void func_007f3c02(void*);

int CInsertObjectDialog::f()
{
    func_007f4184(this);
    func_007f3c02((char*)this + 0xa8);
    return 0;
}
