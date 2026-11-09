// from server: 49% by colin
struct CMainFrame {
    void* field0;
    CMainFrame(void* arg1, void* arg2);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

CMainFrame::CMainFrame(void* arg1, void* arg2)
{
    field0 = 0;
    void* p = sub_62FEF6(0x14);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)((char*)p + 0) = (void*)0x78bab0;
        *(void**)((char*)p + 0xc) = arg1;
    } else {
        p = 0;
    }
    field0 = p;
}
