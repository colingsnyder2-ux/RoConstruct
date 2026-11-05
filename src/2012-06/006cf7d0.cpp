// from server: 25% by Intel
struct ExceptionFrame {
    ExceptionFrame* prev;
    void* handler;
};

extern "C" void __stdcall __SEH_prolog4(ExceptionFrame* frame, int cookie, void* handler);
extern "C" void __stdcall __SEH_epilog4(ExceptionFrame* frame);

struct TooManyArgs {
    int field_0;
    int field_4;
    TooManyArgs* ctor();
};

TooManyArgs* TooManyArgs::ctor() {
    ExceptionFrame frame;
    __SEH_prolog4(&frame, -1, (void*)0x00ABA8C8);
    this->field_0 = 0;
    __SEH_prolog4(&frame, 0, (void*)0x0097BDC0);
    this->field_4 = 0;
    __SEH_epilog4(&frame);
    return this;
}
