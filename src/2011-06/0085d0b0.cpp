// from server: 100% by atomic.potato
extern "C" void* (__stdcall *SelectObject)(void*, void*);

struct CXTPPrintingDialog {
    void* vftable;
    void* field_4;
    void* field_8;
    CXTPPrintingDialog* sub_85D0B0(void*, void*);
};

CXTPPrintingDialog* CXTPPrintingDialog::sub_85D0B0(void* param1, void* param2) {
    this->vftable = (void*)0xaca538;
    void* v = param1;
    if (v != 0) {
        v = *(void**)((char*)v + 4);
    }
    this->field_4 = v;
    void* h = param2;
    if (h == 0) {
        this->field_8 = SelectObject(v, h);
        return this;
    }
    h = *(void**)((char*)h + 4);
    this->field_8 = SelectObject(v, h);
    return this;
}
