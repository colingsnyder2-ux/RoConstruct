// from server: 87% by atomic.potato
extern "C" int __stdcall MessageBeep(unsigned int);

struct CScintillaView
{
    char padding[0xd8];
    int state;
    void f();
};

void CScintillaView::f()
{
    state = 1;
    MessageBeep(0x10);
}
