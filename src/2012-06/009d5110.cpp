// roc 2012-06 009d5110  unit: CXTPPrintingDialog  size: 47 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d5110
//
// 009d5110  56                   push esi
// 009d5111  57                   push edi
// 009d5112  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 009d5116  57                   push edi
// 009d5117  8bf1                 mov esi, ecx
// 009d5119  ff15143bb200         call dword ptr [0xb23b14]
// 009d511f  56                   push esi
// 009d5120  85c0                 test eax, eax
// 009d5122  740e                 je 0x9d5132
// 009d5124  57                   push edi
// 009d5125  ff15f83ab200         call dword ptr [0xb23af8]
// 009d512b  5f                   pop edi
// 009d512c  8bc6                 mov eax, esi
// 009d512e  5e                   pop esi
// 009d512f  c20400               ret 4
// 009d5132  ff15903ab200         call dword ptr [0xb23a90]
// 009d5138  5f                   pop edi
// 009d5139  8bc6                 mov eax, esi
// 009d513b  5e                   pop esi
// 009d513c  c20400               ret 4
// copied from an identical function in another client (function ?sub_67FF70@CXTPPrintingDialog@ns_ROCX00005f@@QAEPAXPAX@Z)

namespace ns_ROCX00005f {
extern "C" int (__stdcall *IsWindow)(void*);
extern "C" int (__stdcall *GetWindowRect)(void*, void*);
extern "C" int (__stdcall *SetRectEmpty)(void*);

struct CXTPPrintingDialog {
    void* sub_67FF70(void*);
};

void* CXTPPrintingDialog::sub_67FF70(void* param) {
    if (IsWindow(param)) {
        GetWindowRect(param, this);
    } else {
        SetRectEmpty(this);
    }
    return this;
}
}
