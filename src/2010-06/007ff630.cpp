// from server: 100% by atomic.potato
extern "C" void* (__stdcall *SelectObject)(void*, void*);

struct CXTPPrintingDialog {
    void* vtable;
    void* field_4;
    void* field_8;
    CXTPPrintingDialog(void* a, void* b);
};

CXTPPrintingDialog::CXTPPrintingDialog(void* a, void* b) {
    vtable = (void*)0xa5fc48;
    void* p = a;
    if (p != 0)
        p = *(void**)((char*)p + 4);
    field_4 = p;
    void* q = b;
    if (q == 0) {
        field_8 = SelectObject(p, q);
    } else {
        q = *(void**)((char*)q + 4);
        field_8 = SelectObject(p, q);
    }
}
