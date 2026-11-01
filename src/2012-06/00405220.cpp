// from server: 100% by auto
// roc 2012-06 00405220  unit: VCApp::?$CComObject  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00405220
//
// 00405220  8b442404             mov eax, dword ptr [esp + 4]
// 00405224  56                   push esi
// 00405225  8bf1                 mov esi, ecx
// 00405227  83c9ff               or ecx, 0xffffffff
// 0040522a  2bc8                 sub ecx, eax
// 0040522c  83f908               cmp ecx, 8
// 0040522f  7215                 jb 0x405246
// 00405231  83c008               add eax, 8
// 00405234  50                   push eax
// 00405235  ff15f829b200         call dword ptr [0xb229f8]
// 0040523b  83c404               add esp, 4
// 0040523e  85c0                 test eax, eax
// 00405240  750e                 jne 0x405250
// 00405242  5e                   pop esi
// 00405243  c20400               ret 4
// 00405246  6857000780           push 0x80070057
// 0040524b  e860efffff           call 0x4041b0
// 00405250  8b16                 mov edx, dword ptr [esi]
// 00405252  8910                 mov dword ptr [eax], edx
// 00405254  8906                 mov dword ptr [esi], eax
// 00405256  83c008               add eax, 8
// 00405259  5e                   pop esi
// 0040525a  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Chart\Diagram\Axis\XTPChartScaleTypeMap.cpp (function ?Allocate@?$CAtlSafeAllocBufferManager@VCCRTAllocator@ATL@@@_ATL_SAFE_ALLOCA_IMPL@ATL@@QAEPAXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Chart/Diagram/Axis/XTPChartScaleTypeMap.cpp
