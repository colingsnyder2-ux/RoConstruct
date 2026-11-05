// from server: 100% by auto
// roc 2009-12 007ebd30  unit: RBX::TaskScheduler::VThread::?$sp_counted_impl_p  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007ebd30
//
// 007ebd30  8b44240c             mov eax, dword ptr [esp + 0xc]
// 007ebd34  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007ebd38  8b542404             mov edx, dword ptr [esp + 4]
// 007ebd3c  6a00                 push 0
// 007ebd3e  50                   push eax
// 007ebd3f  51                   push ecx
// 007ebd40  52                   push edx
// 007ebd41  e88afcffff           call 0x7eb9d0
// 007ebd46  83c410               add esp, 0x10
// 007ebd49  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_register)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
