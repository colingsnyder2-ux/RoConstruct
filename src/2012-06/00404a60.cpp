// from server: 100% by auto
// roc 2012-06 00404a60  unit: RBX::Soundscape::VSoundChannel::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00404a60
//
// 00404a60  56                   push esi
// 00404a61  8bf1                 mov esi, ecx
// 00404a63  833e00               cmp dword ptr [esi], 0
// 00404a66  741a                 je 0x404a82
// 00404a68  57                   push edi
// 00404a69  8b3dc829b200         mov edi, dword ptr [0xb229c8]
// 00404a6f  90                   nop 
// 00404a70  8b06                 mov eax, dword ptr [esi]
// 00404a72  8b08                 mov ecx, dword ptr [eax]
// 00404a74  50                   push eax
// 00404a75  890e                 mov dword ptr [esi], ecx
// 00404a77  ffd7                 call edi
// 00404a79  83c404               add esp, 4
// 00404a7c  833e00               cmp dword ptr [esi], 0
// 00404a7f  75ef                 jne 0x404a70
// 00404a81  5f                   pop edi
// 00404a82  5e                   pop esi
// 00404a83  c3                   ret 
// library xtp-15.2.1-shared-mfc/Source\Chart\Diagram\Axis\XTPChartScaleTypeMap.cpp (function ??1?$CAtlSafeAllocBufferManager@VCCRTAllocator@ATL@@@_ATL_SAFE_ALLOCA_IMPL@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1-shared-mfc Source/Chart/Diagram/Axis/XTPChartScaleTypeMap.cpp
