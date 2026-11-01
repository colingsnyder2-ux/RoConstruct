// from server: 100% by auto
// roc 2011-06 00404bd0  unit: ATL::CRegObject  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00404bd0
//
// 00404bd0  8b442404             mov eax, dword ptr [esp + 4]
// 00404bd4  56                   push esi
// 00404bd5  8bf1                 mov esi, ecx
// 00404bd7  83c9ff               or ecx, 0xffffffff
// 00404bda  2bc8                 sub ecx, eax
// 00404bdc  83f908               cmp ecx, 8
// 00404bdf  7215                 jb 0x404bf6
// 00404be1  83c008               add eax, 8
// 00404be4  50                   push eax
// 00404be5  ff15400aa400         call dword ptr [0xa40a40]
// 00404beb  83c404               add esp, 4
// 00404bee  85c0                 test eax, eax
// 00404bf0  750e                 jne 0x404c00
// 00404bf2  5e                   pop esi
// 00404bf3  c20400               ret 4
// 00404bf6  6857000780           push 0x80070057
// 00404bfb  e8a0e9ffff           call 0x4035a0
// 00404c00  8b16                 mov edx, dword ptr [esi]
// 00404c02  8910                 mov dword ptr [eax], edx
// 00404c04  8906                 mov dword ptr [esi], eax
// 00404c06  83c008               add eax, 8
// 00404c09  5e                   pop esi
// 00404c0a  c20400               ret 4
// library xtp-15.2.1-shared-mfc/Source\Chart\Diagram\Axis\XTPChartScaleTypeMap.cpp (function ?Allocate@?$CAtlSafeAllocBufferManager@VCCRTAllocator@ATL@@@_ATL_SAFE_ALLOCA_IMPL@ATL@@QAEPAXK@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Chart/Diagram/Axis/XTPChartScaleTypeMap.cpp
