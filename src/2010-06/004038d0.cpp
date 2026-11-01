// from server: 100% by auto
// roc 2010-06 004038d0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 004038d0
//
// 004038d0  56                   push esi
// 004038d1  8bf1                 mov esi, ecx
// 004038d3  833e00               cmp dword ptr [esi], 0
// 004038d6  741a                 je 0x4038f2
// 004038d8  57                   push edi
// 004038d9  8b3d08aa9e00         mov edi, dword ptr [0x9eaa08]
// 004038df  90                   nop 
// 004038e0  8b06                 mov eax, dword ptr [esi]
// 004038e2  8b08                 mov ecx, dword ptr [eax]
// 004038e4  50                   push eax
// 004038e5  890e                 mov dword ptr [esi], ecx
// 004038e7  ffd7                 call edi
// 004038e9  83c404               add esp, 4
// 004038ec  833e00               cmp dword ptr [esi], 0
// 004038ef  75ef                 jne 0x4038e0
// 004038f1  5f                   pop edi
// 004038f2  5e                   pop esi
// 004038f3  c3                   ret 
// library xtp-13.2.1-shared-mfc/Source\Common\XTPPropExchange.cpp (function ??1?$CAtlSafeAllocBufferManager@VCCRTAllocator@ATL@@@_ATL_SAFE_ALLOCA_IMPL@ATL@@QAE@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/Common/XTPPropExchange.cpp
