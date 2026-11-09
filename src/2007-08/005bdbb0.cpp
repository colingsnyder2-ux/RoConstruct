// from server: 100% by auto
// roc 2007-08 005bdbb0  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bdbb0
//
// 005bdbb0  56                   push esi
// 005bdbb1  8b742408             mov esi, dword ptr [esp + 8]
// 005bdbb5  8b4610               mov eax, dword ptr [esi + 0x10]
// 005bdbb8  8b4844               mov ecx, dword ptr [eax + 0x44]
// 005bdbbb  3b4840               cmp ecx, dword ptr [eax + 0x40]
// 005bdbbe  57                   push edi
// 005bdbbf  7209                 jb 0x5bdbca
// 005bdbc1  56                   push esi
// 005bdbc2  e839220500           call 0x60fe00
// 005bdbc7  83c404               add esp, 4
// 005bdbca  8b542414             mov edx, dword ptr [esp + 0x14]
// 005bdbce  8b442410             mov eax, dword ptr [esp + 0x10]
// 005bdbd2  8b7e08               mov edi, dword ptr [esi + 8]
// 005bdbd5  52                   push edx
// 005bdbd6  50                   push eax
// 005bdbd7  56                   push esi
// 005bdbd8  e893510500           call 0x612d70
// 005bdbdd  83c40c               add esp, 0xc
// 005bdbe0  8907                 mov dword ptr [edi], eax
// 005bdbe2  c7470804000000       mov dword ptr [edi + 8], 4
// 005bdbe9  83460810             add dword ptr [esi + 8], 0x10
// 005bdbed  5f                   pop edi
// 005bdbee  5e                   pop esi
// 005bdbef  c3                   ret 
// library lua-5.1/lapi.c (function _lua_pushlstring)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
