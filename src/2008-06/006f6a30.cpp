// from server: 100% by tester
struct CXTPControlSelector {
    void* field0;
    void* field4;
    void* field8;
    void Release();
};

extern "C" void* (__stdcall *SelectObject)(void*, void*);

void CXTPControlSelector::Release()
{
    void* p8 = field8;
    field0 = (void*)0x7ceae0;
    void* p4 = field4;
    SelectObject(p4, p8);
}
