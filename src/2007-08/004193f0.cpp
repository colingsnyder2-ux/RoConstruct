// from server: 46% by colin
struct VDHTMLWindow_SignalDesc {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
};

struct VDHTMLWindow {
    void* field0;
    VDHTMLWindow_SignalDesc* field4;
    VDHTMLWindow_SignalDesc* constructSignalDesc(VDHTMLWindow_SignalDesc* desc, void* arg);
};

extern "C" void* __cdecl operator_new(unsigned int size);

VDHTMLWindow_SignalDesc* VDHTMLWindow::constructSignalDesc(VDHTMLWindow_SignalDesc* desc, void* arg) {
    this->field0 = 0;
    VDHTMLWindow_SignalDesc* mem = (VDHTMLWindow_SignalDesc*)operator_new(0x14);
    if (mem != 0) {
        mem->field4 = (void*)1;
        mem->field8 = (void*)1;
        mem->field0 = (void*)0x787594;
        mem->fieldC = arg;
    } else {
        mem = 0;
    }
    this->field4 = mem;
    return (VDHTMLWindow_SignalDesc*)this;
}
