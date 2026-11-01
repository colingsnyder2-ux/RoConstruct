// from server: 100% by auto
// roc 2007-03 005b9e80  unit: seg_005b0000  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b9e80
//
// 005b9e80  53                   push ebx
// 005b9e81  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 005b9e85  85db                 test ebx, ebx
// 005b9e87  7452                 je 0x5b9edb
// 005b9e89  55                   push ebp
// 005b9e8a  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 005b9e8e  56                   push esi
// 005b9e8f  8b742410             mov esi, dword ptr [esp + 0x10]
// 005b9e93  57                   push edi
// 005b9e94  8b06                 mov eax, dword ptr [esi]
// 005b9e96  8d8e0c020000         lea ecx, [esi + 0x20c]
// 005b9e9c  83eb01               sub ebx, 1
// 005b9e9f  3bc1                 cmp eax, ecx
// 005b9ea1  7224                 jb 0x5b9ec7
// 005b9ea3  2bc6                 sub eax, esi
// 005b9ea5  83e80c               sub eax, 0xc
// 005b9ea8  741d                 je 0x5b9ec7
// 005b9eaa  50                   push eax
// 005b9eab  8b4608               mov eax, dword ptr [esi + 8]
// 005b9eae  8d7e0c               lea edi, [esi + 0xc]
// 005b9eb1  57                   push edi
// 005b9eb2  50                   push eax
// 005b9eb3  e8c8f1ffff           call 0x5b9080
// 005b9eb8  83460401             add dword ptr [esi + 4], 1
// 005b9ebc  56                   push esi
// 005b9ebd  893e                 mov dword ptr [esi], edi
// 005b9ebf  e8fcfeffff           call 0x5b9dc0
// 005b9ec4  83c410               add esp, 0x10
// 005b9ec7  8a5500               mov dl, byte ptr [ebp]
// 005b9eca  8b0e                 mov ecx, dword ptr [esi]
// 005b9ecc  8811                 mov byte ptr [ecx], dl
// 005b9ece  830601               add dword ptr [esi], 1
// 005b9ed1  83c501               add ebp, 1
// 005b9ed4  85db                 test ebx, ebx
// 005b9ed6  75bc                 jne 0x5b9e94
// 005b9ed8  5f                   pop edi
// 005b9ed9  5e                   pop esi
// 005b9eda  5d                   pop ebp
// 005b9edb  5b                   pop ebx
// 005b9edc  c3                   ret 
// library lua-5.1.1/lauxlib.c (function _luaL_addlstring)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lauxlib.c
