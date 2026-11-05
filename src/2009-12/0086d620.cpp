// roc 2009-12 0086d620  unit: CXTCaption  size: 65 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086d620
//
// 0086d620  53                   push ebx
// 0086d621  56                   push esi
// 0086d622  57                   push edi
// 0086d623  8bf9                 mov edi, ecx
// 0086d625  e84682c6ff           call 0x4d5870
// 0086d62a  8bd8                 mov ebx, eax
// 0086d62c  33f6                 xor esi, esi
// 0086d62e  85db                 test ebx, ebx
// 0086d630  7e29                 jle 0x86d65b
// 0086d632  55                   push ebp
// 0086d633  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 0086d637  56                   push esi
// 0086d638  8bcf                 mov ecx, edi
// 0086d63a  e871ffffff           call 0x86d5b0
// 0086d63f  3bc5                 cmp eax, ebp
// 0086d641  740c                 je 0x86d64f
// 0086d643  46                   inc esi
// 0086d644  3bf3                 cmp esi, ebx
// 0086d646  7cef                 jl 0x86d637
// 0086d648  5d                   pop ebp
// 0086d649  5f                   pop edi
// 0086d64a  5e                   pop esi
// 0086d64b  5b                   pop ebx
// 0086d64c  c20400               ret 4
// 0086d64f  6a01                 push 1
// 0086d651  56                   push esi
// 0086d652  8d4f24               lea ecx, [edi + 0x24]
// 0086d655  e826fcfbff           call 0x82d280
// 0086d65a  5d                   pop ebp
// 0086d65b  5f                   pop edi
// 0086d65c  5e                   pop esi
// 0086d65d  5b                   pop ebx
// 0086d65e  c20400               ret 4
// copied from an identical function in another client (function ?FindRow@CXTPReportRow_Batch@ns_ROCX00004b@ns_ROCX0000e6@@QAEXH@Z)

namespace ns_ROCX00004b {
namespace ns_ROCX00005d {
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
}
