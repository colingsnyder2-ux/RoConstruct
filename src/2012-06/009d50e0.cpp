// roc 2012-06 009d50e0  unit: CXTPPrintingDialog  size: 31 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d50e0
//
// 009d50e0  56                   push esi
// 009d50e1  8bf1                 mov esi, ecx
// 009d50e3  56                   push esi
// 009d50e4  ff158c3ab200         call dword ptr [0xb23a8c]
// 009d50ea  8b442408             mov eax, dword ptr [esp + 8]
// 009d50ee  8b4820               mov ecx, dword ptr [eax + 0x20]
// 009d50f1  56                   push esi
// 009d50f2  51                   push ecx
// 009d50f3  ff15883ab200         call dword ptr [0xb23a88]
// 009d50f9  8bc6                 mov eax, esi
// 009d50fb  5e                   pop esi
// 009d50fc  c20400               ret 4
// copied from an identical function in another client (function ?SetPos@CXTPPrintingDialog@ns_ROCX00005e@@QAEPAXPAX@Z)

namespace ns_ROCX00005e {
struct CXTPPrintingDialog {
    void* SetPos(void* p);
};

extern "C" {
    int (__stdcall *GetCursorPos)(void*);
    int (__stdcall *ScreenToClient)(void*, void*);
}

void* CXTPPrintingDialog::SetPos(void* p) {
    GetCursorPos(this);
    ScreenToClient(*(void**)((char*)p + 0x20), this);
    return this;
}
}
