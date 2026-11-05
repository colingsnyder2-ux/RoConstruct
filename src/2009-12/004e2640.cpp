// from server: 38% by atomic.potato
extern "C" void sub_4cd360(void*);

struct GWindow
{
    void f();
};

void GWindow::f()
{
    volatile unsigned char* flag = (volatile unsigned char*)0x00b7dc09;
    if (*flag)
        for (;;)
        {
        }
    sub_4cd360((void*)0);
}
