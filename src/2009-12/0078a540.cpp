// from server: 100% by auto
// roc 2009-12 0078a540  unit: RBX::UniversalTool  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0078a540
//
// 0078a540  8b542408             mov edx, dword ptr [esp + 8]
// 0078a544  83ec08               sub esp, 8
// 0078a547  8bc2                 mov eax, edx
// 0078a549  56                   push esi
// 0078a54a  8d7001               lea esi, [eax + 1]
// 0078a54d  8d4900               lea ecx, [ecx]
// 0078a550  8a08                 mov cl, byte ptr [eax]
// 0078a552  40                   inc eax
// 0078a553  84c9                 test cl, cl
// 0078a555  75f9                 jne 0x78a550
// 0078a557  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0078a55b  2bc6                 sub eax, esi
// 0078a55d  52                   push edx
// 0078a55e  8944240c             mov dword ptr [esp + 0xc], eax
// 0078a562  8d442408             lea eax, [esp + 8]
// 0078a566  50                   push eax
// 0078a567  68f0a47800           push 0x78a4f0
// 0078a56c  51                   push ecx
// 0078a56d  89542414             mov dword ptr [esp + 0x14], edx
// 0078a571  e81af0ffff           call 0x789590
// 0078a576  83c410               add esp, 0x10
// 0078a579  5e                   pop esi
// 0078a57a  83c408               add esp, 8
// 0078a57d  c3                   ret 
// library lua-5.1/lauxlib.c (function _luaL_loadstring)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lauxlib.c
