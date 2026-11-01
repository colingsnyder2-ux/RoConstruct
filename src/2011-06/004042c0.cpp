// from server: 100% by auto
// roc 2011-06 004042c0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004042c0
//
// 004042c0  56                   push esi
// 004042c1  8bf1                 mov esi, ecx
// 004042c3  833e00               cmp dword ptr [esi], 0
// 004042c6  741a                 je 0x4042e2
// 004042c8  57                   push edi
// 004042c9  8b3d740aa400         mov edi, dword ptr [0xa40a74]
// 004042cf  90                   nop 
// 004042d0  8b06                 mov eax, dword ptr [esi]
// 004042d2  8b08                 mov ecx, dword ptr [eax]
// 004042d4  50                   push eax
// 004042d5  890e                 mov dword ptr [esi], ecx
// 004042d7  ffd7                 call edi
// 004042d9  83c404               add esp, 4
// 004042dc  833e00               cmp dword ptr [esi], 0
// 004042df  75ef                 jne 0x4042d0
// 004042e1  5f                   pop edi
// 004042e2  5e                   pop esi
// 004042e3  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Chart\Diagram\Axis\XTPChartScaleTypeMap.cpp (function ??1?$CAtlSafeAllocBufferManager@VCCRTAllocator@ATL@@@_ATL_SAFE_ALLOCA_IMPL@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Chart/Diagram/Axis/XTPChartScaleTypeMap.cpp
