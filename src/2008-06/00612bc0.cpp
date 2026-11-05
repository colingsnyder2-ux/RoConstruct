// from server: 100% by auto
// roc 2008-06 00612bc0  unit: seg_00610000  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00612bc0
//
// 00612bc0  56                   push esi
// 00612bc1  57                   push edi
// 00612bc2  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00612bc6  83ff02               cmp edi, 2
// 00612bc9  7c3d                 jl 0x612c08
// 00612bcb  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00612bcf  8b4610               mov eax, dword ptr [esi + 0x10]
// 00612bd2  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00612bd5  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00612bd8  7209                 jb 0x612be3
// 00612bda  56                   push esi
// 00612bdb  e8b0970400           call 0x65c390
// 00612be0  83c404               add esp, 4
// 00612be3  8b5608               mov edx, dword ptr [esi + 8]
// 00612be6  2b560c               sub edx, dword ptr [esi + 0xc]
// 00612be9  c1fa04               sar edx, 4
// 00612bec  4a                   dec edx
// 00612bed  52                   push edx
// 00612bee  57                   push edi
// 00612bef  56                   push esi
// 00612bf0  e87ba20400           call 0x65ce70
// 00612bf5  c1e704               shl edi, 4
// 00612bf8  83c40c               add esp, 0xc
// 00612bfb  b810000000           mov eax, 0x10
// 00612c00  2bc7                 sub eax, edi
// 00612c02  014608               add dword ptr [esi + 8], eax
// 00612c05  5f                   pop edi
// 00612c06  5e                   pop esi
// 00612c07  c3                   ret 
// 00612c08  85ff                 test edi, edi
// 00612c0a  7524                 jne 0x612c30
// 00612c0c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00612c10  8b7e08               mov edi, dword ptr [esi + 8]
// 00612c13  6a00                 push 0
// 00612c15  6816b78000           push 0x80b716
// 00612c1a  56                   push esi
// 00612c1b  e8e0c60400           call 0x65f300
// 00612c20  83c40c               add esp, 0xc
// 00612c23  8907                 mov dword ptr [edi], eax
// 00612c25  c7470804000000       mov dword ptr [edi + 8], 4
// 00612c2c  83460810             add dword ptr [esi + 8], 0x10
// 00612c30  5f                   pop edi
// 00612c31  5e                   pop esi
// 00612c32  c3                   ret 
// library lua-5.1/lapi.c (function _lua_concat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
