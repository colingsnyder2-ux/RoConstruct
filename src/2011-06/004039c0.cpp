// from server: 100% by auto
// roc 2011-06 004039c0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004039c0
//
// 004039c0  8b442404             mov eax, dword ptr [esp + 4]
// 004039c4  83f864               cmp eax, 0x64
// 004039c7  56                   push esi
// 004039c8  8bf1                 mov esi, ecx
// 004039ca  7d05                 jge 0x4039d1
// 004039cc  b8e8030000           mov eax, 0x3e8
// 004039d1  33c9                 xor ecx, ecx
// 004039d3  c70600000000         mov dword ptr [esi], 0
// 004039d9  894604               mov dword ptr [esi + 4], eax
// 004039dc  7705                 ja 0x4039e3
// 004039de  83f8ff               cmp eax, -1
// 004039e1  7604                 jbe 0x4039e7
// 004039e3  33c0                 xor eax, eax
// 004039e5  eb07                 jmp 0x4039ee
// 004039e7  50                   push eax
// 004039e8  ff157430a400         call dword ptr [0xa43074]
// 004039ee  894608               mov dword ptr [esi + 8], eax
// 004039f1  85c0                 test eax, eax
// 004039f3  7403                 je 0x4039f8
// 004039f5  c60000               mov byte ptr [eax], 0
// 004039f8  8bc6                 mov eax, esi
// 004039fa  5e                   pop esi
// 004039fb  c20400               ret 4
// library atl-9.0/atl.cpp (function ??0CParseBuffer@CRegParser@ATL@@QAE@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
