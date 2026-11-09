// from server: 100% by auto
// roc 2009-06 00447660  unit: CBrowserDocManager  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00447660
//
// 00447660  55                   push ebp
// 00447661  8b6c2408             mov ebp, dword ptr [esp + 8]
// 00447665  85ed                 test ebp, ebp
// 00447667  7509                 jne 0x447672
// 00447669  b857000780           mov eax, 0x80070057
// 0044766e  5d                   pop ebp
// 0044766f  c20c00               ret 0xc
// 00447672  53                   push ebx
// 00447673  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00447676  56                   push esi
// 00447677  57                   push edi
// 00447678  33ff                 xor edi, edi
// 0044767a  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 0044767d  734e                 jae 0x4476cd
// 0044767f  90                   nop 
// 00447680  8b33                 mov esi, dword ptr [ebx]
// 00447682  85f6                 test esi, esi
// 00447684  743b                 je 0x4476c1
// 00447686  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044768a  85c0                 test eax, eax
// 0044768c  7410                 je 0x44769e
// 0044768e  8b0e                 mov ecx, dword ptr [esi]
// 00447690  51                   push ecx
// 00447691  50                   push eax
// 00447692  e89917fdff           call 0x418e30
// 00447697  83c408               add esp, 8
// 0044769a  85c0                 test eax, eax
// 0044769c  7423                 je 0x4476c1
// 0044769e  8b561c               mov edx, dword ptr [esi + 0x1c]
// 004476a1  6a00                 push 0
// 004476a3  ffd2                 call edx
// 004476a5  50                   push eax
// 004476a6  8b06                 mov eax, dword ptr [esi]
// 004476a8  50                   push eax
// 004476a9  e822faffff           call 0x4470d0
// 004476ae  8bf8                 mov edi, eax
// 004476b0  85ff                 test edi, edi
// 004476b2  7c2d                 jl 0x4476e1
// 004476b4  8b4e04               mov ecx, dword ptr [esi + 4]
// 004476b7  6a00                 push 0
// 004476b9  ffd1                 call ecx
// 004476bb  8bf8                 mov edi, eax
// 004476bd  85ff                 test edi, edi
// 004476bf  7c20                 jl 0x4476e1
// 004476c1  83c304               add ebx, 4
// 004476c4  3b5d0c               cmp ebx, dword ptr [ebp + 0xc]
// 004476c7  72b7                 jb 0x447680
// 004476c9  85ff                 test edi, edi
// 004476cb  7c14                 jl 0x4476e1
// 004476cd  837c241800           cmp dword ptr [esp + 0x18], 0
// 004476d2  740d                 je 0x4476e1
// 004476d4  8b5504               mov edx, dword ptr [ebp + 4]
// 004476d7  6a00                 push 0
// 004476d9  52                   push edx
// 004476da  e801fdffff           call 0x4473e0
// 004476df  8bf8                 mov edi, eax
// 004476e1  8bc7                 mov eax, edi
// 004476e3  5f                   pop edi
// 004476e4  5e                   pop esi
// 004476e5  5b                   pop ebx
// 004476e6  5d                   pop ebp
// 004476e7  c20c00               ret 0xc
// library atl-8.0/atl.cpp (function _AtlComModuleUnregisterServer@12)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
