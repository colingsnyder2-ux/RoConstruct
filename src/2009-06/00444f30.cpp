// from server: 100% by auto
// roc 2009-06 00444f30  unit: G3D::_WeakPtr  size: 70 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00444f30
//
// 00444f30  57                   push edi
// 00444f31  8b7c2408             mov edi, dword ptr [esp + 8]
// 00444f35  85ff                 test edi, edi
// 00444f37  7509                 jne 0x444f42
// 00444f39  b857000780           mov eax, 0x80070057
// 00444f3e  5f                   pop edi
// 00444f3f  c20400               ret 4
// 00444f42  56                   push esi
// 00444f43  8b7708               mov esi, dword ptr [edi + 8]
// 00444f46  33c0                 xor eax, eax
// 00444f48  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00444f4b  7324                 jae 0x444f71
// 00444f4d  53                   push ebx
// 00444f4e  8b1df8028a00         mov ebx, dword ptr [0x8a02f8]
// 00444f54  85c0                 test eax, eax
// 00444f56  7518                 jne 0x444f70
// 00444f58  8b0e                 mov ecx, dword ptr [esi]
// 00444f5a  85c9                 test ecx, ecx
// 00444f5c  740a                 je 0x444f68
// 00444f5e  8b4114               mov eax, dword ptr [ecx + 0x14]
// 00444f61  85c0                 test eax, eax
// 00444f63  7403                 je 0x444f68
// 00444f65  50                   push eax
// 00444f66  ffd3                 call ebx
// 00444f68  83c604               add esi, 4
// 00444f6b  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00444f6e  72e4                 jb 0x444f54
// 00444f70  5b                   pop ebx
// 00444f71  5e                   pop esi
// 00444f72  5f                   pop edi
// 00444f73  c20400               ret 4
// library atl-8.0/atl.cpp (function _AtlComModuleRevokeClassObjects@4)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
