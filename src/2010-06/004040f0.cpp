// from server: 100% by auto
// roc 2010-06 004040f0  unit: ATL::CRegObject  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004040f0
//
// 004040f0  8b442404             mov eax, dword ptr [esp + 4]
// 004040f4  56                   push esi
// 004040f5  8bf1                 mov esi, ecx
// 004040f7  83c9ff               or ecx, 0xffffffff
// 004040fa  2bc8                 sub ecx, eax
// 004040fc  83f908               cmp ecx, 8
// 004040ff  7215                 jb 0x404116
// 00404101  83c008               add eax, 8
// 00404104  50                   push eax
// 00404105  ff15c8a89e00         call dword ptr [0x9ea8c8]
// 0040410b  83c404               add esp, 4
// 0040410e  85c0                 test eax, eax
// 00404110  750e                 jne 0x404120
// 00404112  5e                   pop esi
// 00404113  c20400               ret 4
// 00404116  6857000780           push 0x80070057
// 0040411b  e8b0eaffff           call 0x402bd0
// 00404120  8b16                 mov edx, dword ptr [esi]
// 00404122  8910                 mov dword ptr [eax], edx
// 00404124  8906                 mov dword ptr [esi], eax
// 00404126  83c008               add eax, 8
// 00404129  5e                   pop esi
// 0040412a  c20400               ret 4
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ?Allocate@?$CAtlSafeAllocBufferManager@VCCRTAllocator@ATL@@@_ATL_SAFE_ALLOCA_IMPL@ATL@@QAEPAXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
