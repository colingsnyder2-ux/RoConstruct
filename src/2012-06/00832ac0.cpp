// from server: 100% by auto
// roc 2012-06 00832ac0  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00832ac0
//
// 00832ac0  56                   push esi
// 00832ac1  57                   push edi
// 00832ac2  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00832ac6  83ff02               cmp edi, 2
// 00832ac9  7c3d                 jl 0x832b08
// 00832acb  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00832acf  8b4610               mov eax, dword ptr [esi + 0x10]
// 00832ad2  8b4844               mov ecx, dword ptr [eax + 0x44]
// 00832ad5  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 00832ad8  7209                 jb 0x832ae3
// 00832ada  56                   push esi
// 00832adb  e8d0071000           call 0x9332b0
// 00832ae0  83c404               add esp, 4
// 00832ae3  8b5608               mov edx, dword ptr [esi + 8]
// 00832ae6  2b560c               sub edx, dword ptr [esi + 0xc]
// 00832ae9  c1fa04               sar edx, 4
// 00832aec  4a                   dec edx
// 00832aed  52                   push edx
// 00832aee  57                   push edi
// 00832aef  56                   push esi
// 00832af0  e84b131000           call 0x933e40
// 00832af5  c1e704               shl edi, 4
// 00832af8  83c40c               add esp, 0xc
// 00832afb  b810000000           mov eax, 0x10
// 00832b00  2bc7                 sub eax, edi
// 00832b02  014608               add dword ptr [esi + 8], eax
// 00832b05  5f                   pop edi
// 00832b06  5e                   pop esi
// 00832b07  c3                   ret 
// 00832b08  85ff                 test edi, edi
// 00832b0a  7524                 jne 0x832b30
// 00832b0c  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00832b10  8b7e08               mov edi, dword ptr [esi + 8]
// 00832b13  6a00                 push 0
// 00832b15  68e83bb400           push 0xb43be8
// 00832b1a  56                   push esi
// 00832b1b  e810381000           call 0x936330
// 00832b20  83c40c               add esp, 0xc
// 00832b23  8907                 mov dword ptr [edi], eax
// 00832b25  c7470804000000       mov dword ptr [edi + 8], 4
// 00832b2c  83460810             add dword ptr [esi + 8], 0x10
// 00832b30  5f                   pop edi
// 00832b31  5e                   pop esi
// 00832b32  c3                   ret 
// library lua-5.1/lapi.c (function _lua_concat)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
