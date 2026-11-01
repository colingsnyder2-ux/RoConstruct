// from server: 100% by colin
struct DHTMLWindow {
    char pad[0x14];
    void* field_0x14;
    void destroy();
};

extern "C" void __stdcall sub_0072538A(void*);

void DHTMLWindow::destroy()
{
    if (field_0x14 != 0)
        sub_0072538A(field_0x14);
}
