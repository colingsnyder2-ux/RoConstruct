// from server: 25% by colin
struct CChildFrame {
    void* field0;
    CChildFrame();
};

extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __cdecl sub_6303CA();

CChildFrame::CChildFrame()
{
    CChildFrame* p = (CChildFrame*)sub_62FEF6(0xdc);
    if (p != 0) {
        sub_6303CA();
        *(void**)p = (void*)0x786b1c;
    }
}
