// from server: 27% by colin
struct CInstanceExplorer {
    void* field0;
    CInstanceExplorer();
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl func_0041e690();

CInstanceExplorer::CInstanceExplorer()
{
    void* p = operator_new(0x310);
    if (p != 0) {
        func_0041e690();
    }
}
