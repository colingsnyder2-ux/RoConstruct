// from server: 23% by atomic.potato
extern "C" void* __stdcall sub_9EA410();

struct RBX_ButtonBindingWidget {
    void* __cdecl construct(char* s);
};

void* RBX_ButtonBindingWidget::construct(char* s) {
    if (s == (char*)0x1b) {
        sub_9EA410();
        return (void*)0xa38b60;
    } else {
        sub_9EA410();
        return (void*)0xa008fe;
    }
}
