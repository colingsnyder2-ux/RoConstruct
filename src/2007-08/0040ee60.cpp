// from server: 37% by colin
struct CChildFrame {
    void construct();
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl construct_helper(void*);

void CChildFrame::construct()
{
    CChildFrame* p = (CChildFrame*)operator_new(0xdc);
    if (p != 0)
    {
        construct_helper(p);
        *(void**)p = (void*)0x786944;
    }
}
