// from server: 100% by auto
// roc 2009-06 00444ed0  unit: G3D::_WeakPtr  size: 81 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00444ed0
//
// 00444ed0  57                   push edi
// 00444ed1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00444ed5  85ff                 test edi, edi
// 00444ed7  7509                 jne 0x444ee2
// 00444ed9  b857000780           mov eax, 0x80070057
// 00444ede  5f                   pop edi
// 00444edf  c20c00               ret 0xc
// 00444ee2  56                   push esi
// 00444ee3  8b7708               mov esi, dword ptr [edi + 8]
// 00444ee6  b801000000           mov eax, 1
// 00444eeb  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00444eee  732c                 jae 0x444f1c
// 00444ef0  53                   push ebx
// 00444ef1  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00444ef5  55                   push ebp
// 00444ef6  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00444efa  8d9b00000000         lea ebx, [ebx]
// 00444f00  85c0                 test eax, eax
// 00444f02  7c16                 jl 0x444f1a
// 00444f04  8b0e                 mov ecx, dword ptr [esi]
// 00444f06  85c9                 test ecx, ecx
// 00444f08  7408                 je 0x444f12
// 00444f0a  53                   push ebx
// 00444f0b  55                   push ebp
// 00444f0c  51                   push ecx
// 00444f0d  e8aefeffff           call 0x444dc0
// 00444f12  83c604               add esi, 4
// 00444f15  3b770c               cmp esi, dword ptr [edi + 0xc]
// 00444f18  72e6                 jb 0x444f00
// 00444f1a  5d                   pop ebp
// 00444f1b  5b                   pop ebx
// 00444f1c  5e                   pop esi
// 00444f1d  5f                   pop edi
// 00444f1e  c20c00               ret 0xc
// library atl-9.0/atl.cpp (function _AtlComModuleRegisterClassObjects@12)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
