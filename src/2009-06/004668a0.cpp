// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00465a60  unit: VCSecureHtmlView::?$CXTPCommandBarsSiteBase  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00465a60
//
// 00465a60  56                   push esi
// 00465a61  8bf1                 mov esi, ecx
// 00465a63  e892b62300           call 0x6a10fa
// 00465a68  c70664b88100         mov dword ptr [esi], 0x81b864
// 00465a6e  c686f400000000       mov byte ptr [esi + 0xf4], 0
// 00465a75  8bc6                 mov eax, esi
// 00465a77  5e                   pop esi
// 00465a78  c3                   ret 

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
