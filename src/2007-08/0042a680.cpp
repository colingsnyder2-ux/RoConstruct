// from server: 49% by colin
struct CLuaHtmlView {
    void* field0;
    CLuaHtmlView(void* arg);
};

extern "C" void* __cdecl operator_new(unsigned int size);

CLuaHtmlView::CLuaHtmlView(void* arg) {
    field0 = 0;
    void* p = operator_new(0x10);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x78a1f4;
        *(void**)((char*)p + 0xc) = arg;
    } else {
        p = 0;
    }
    field0 = p;
}
