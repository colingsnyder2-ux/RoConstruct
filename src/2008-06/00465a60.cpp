// from server: 100% by colin
struct VCSecureHtmlView {
    void* vtable;
    char pad[0xf0];
    char field_f4;
    VCSecureHtmlView* construct();
};

extern "C" void __stdcall sub_6a10fa();

VCSecureHtmlView* VCSecureHtmlView::construct() {
    sub_6a10fa();
    this->vtable = (void*)0x81b864;
    this->field_f4 = 0;
    return this;
}
