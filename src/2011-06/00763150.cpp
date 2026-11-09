// from server: 100% by auto
// roc 2011-06 00763150  unit: seg_00760000  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00763150
//
// 00763150  83ec14               sub esp, 0x14
// 00763153  56                   push esi
// 00763154  57                   push edi
// 00763155  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00763159  85ff                 test edi, edi
// 0076315b  7505                 jne 0x763162
// 0076315d  bfd0bca700           mov edi, 0xa7bcd0
// 00763162  8b442428             mov eax, dword ptr [esp + 0x28]
// 00763166  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0076316a  8b742420             mov esi, dword ptr [esp + 0x20]
// 0076316e  50                   push eax
// 0076316f  51                   push ecx
// 00763170  8d542410             lea edx, [esp + 0x10]
// 00763174  52                   push edx
// 00763175  56                   push esi
// 00763176  e885760700           call 0x7da800
// 0076317b  57                   push edi
// 0076317c  8d44241c             lea eax, [esp + 0x1c]
// 00763180  50                   push eax
// 00763181  56                   push esi
// 00763182  e8c9bb0100           call 0x77ed50
// 00763187  83c41c               add esp, 0x1c
// 0076318a  5f                   pop edi
// 0076318b  5e                   pop esi
// 0076318c  83c414               add esp, 0x14
// 0076318f  c3                   ret 
// library lua-5.1/lapi.c (function _lua_load)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
