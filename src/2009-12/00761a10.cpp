// from server: 100% by auto
// roc 2009-12 00761a10  unit: RBX::VInstance::?$NonFactoryProduct  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00761a10
//
// 00761a10  8b542404             mov edx, dword ptr [esp + 4]
// 00761a14  83ec10               sub esp, 0x10
// 00761a17  53                   push ebx
// 00761a18  55                   push ebp
// 00761a19  57                   push edi
// 00761a1a  8bf9                 mov edi, ecx
// 00761a1c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00761a1f  8b4104               mov eax, dword ptr [ecx + 4]
// 00761a22  80781500             cmp byte ptr [eax + 0x15], 0
// 00761a26  8bd9                 mov ebx, ecx
// 00761a28  751a                 jne 0x761a44
// 00761a2a  8b0a                 mov ecx, dword ptr [edx]
// 00761a2c  8d642400             lea esp, [esp]
// 00761a30  39480c               cmp dword ptr [eax + 0xc], ecx
// 00761a33  7d05                 jge 0x761a3a
// 00761a35  8b4008               mov eax, dword ptr [eax + 8]
// 00761a38  eb04                 jmp 0x761a3e
// 00761a3a  8bd8                 mov ebx, eax
// 00761a3c  8b00                 mov eax, dword ptr [eax]
// 00761a3e  80781500             cmp byte ptr [eax + 0x15], 0
// 00761a42  74ec                 je 0x761a30
// 00761a44  8b4718               mov eax, dword ptr [edi + 0x18]
// 00761a47  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 00761a4d  56                   push esi
// 00761a4e  8b37                 mov esi, dword ptr [edi]
// 00761a50  89442414             mov dword ptr [esp + 0x14], eax
// 00761a54  85f6                 test esi, esi
// 00761a56  7404                 je 0x761a5c
// 00761a58  3bf6                 cmp esi, esi
// 00761a5a  740c                 je 0x761a68
// 00761a5c  ffd5                 call ebp
// 00761a5e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00761a62  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 00761a68  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 00761a6c  7407                 je 0x761a75
// 00761a6e  8b0a                 mov ecx, dword ptr [edx]
// 00761a70  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 00761a73  7d23                 jge 0x761a98
// 00761a75  8b12                 mov edx, dword ptr [edx]
// 00761a77  8d442410             lea eax, [esp + 0x10]
// 00761a7b  50                   push eax
// 00761a7c  53                   push ebx
// 00761a7d  56                   push esi
// 00761a7e  8d4c2424             lea ecx, [esp + 0x24]
// 00761a82  51                   push ecx
// 00761a83  8bcf                 mov ecx, edi
// 00761a85  89542420             mov dword ptr [esp + 0x20], edx
// 00761a89  c644242400           mov byte ptr [esp + 0x24], 0
// 00761a8e  e8ed48f9ff           call 0x6f6380
// 00761a93  8b30                 mov esi, dword ptr [eax]
// 00761a95  8b5804               mov ebx, dword ptr [eax + 4]
// 00761a98  85f6                 test esi, esi
// 00761a9a  7516                 jne 0x761ab2
// 00761a9c  ffd5                 call ebp
// 00761a9e  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00761aa1  5e                   pop esi
// 00761aa2  7502                 jne 0x761aa6
// 00761aa4  ffd5                 call ebp
// 00761aa6  5f                   pop edi
// 00761aa7  5d                   pop ebp
// 00761aa8  8d4310               lea eax, [ebx + 0x10]
// 00761aab  5b                   pop ebx
// 00761aac  83c410               add esp, 0x10
// 00761aaf  c20400               ret 4
// 00761ab2  8b36                 mov esi, dword ptr [esi]
// 00761ab4  ebe8                 jmp 0x761a9e
// standard library map_int<char> (function ??A?$map@HDU?$less@H@std@@V?$allocator@U?$pair@$$CBHD@std@@@2@@std@@QAEAADABH@Z)

// stl: map_int<char>
typedef char E;
#include <map>
template class std::map<int, E>;
