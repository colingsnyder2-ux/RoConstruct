// from server: 100% by auto
// roc 2009-12 007edc90  unit: W4_D3DFORMAT::?$EnumDesc  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007edc90
//
// 007edc90  8b542404             mov edx, dword ptr [esp + 4]
// 007edc94  83ec10               sub esp, 0x10
// 007edc97  53                   push ebx
// 007edc98  55                   push ebp
// 007edc99  57                   push edi
// 007edc9a  8bf9                 mov edi, ecx
// 007edc9c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 007edc9f  8b4104               mov eax, dword ptr [ecx + 4]
// 007edca2  80781500             cmp byte ptr [eax + 0x15], 0
// 007edca6  8bd9                 mov ebx, ecx
// 007edca8  751a                 jne 0x7edcc4
// 007edcaa  8b0a                 mov ecx, dword ptr [edx]
// 007edcac  8d642400             lea esp, [esp]
// 007edcb0  39480c               cmp dword ptr [eax + 0xc], ecx
// 007edcb3  7305                 jae 0x7edcba
// 007edcb5  8b4008               mov eax, dword ptr [eax + 8]
// 007edcb8  eb04                 jmp 0x7edcbe
// 007edcba  8bd8                 mov ebx, eax
// 007edcbc  8b00                 mov eax, dword ptr [eax]
// 007edcbe  80781500             cmp byte ptr [eax + 0x15], 0
// 007edcc2  74ec                 je 0x7edcb0
// 007edcc4  8b4718               mov eax, dword ptr [edi + 0x18]
// 007edcc7  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007edccd  56                   push esi
// 007edcce  8b37                 mov esi, dword ptr [edi]
// 007edcd0  89442414             mov dword ptr [esp + 0x14], eax
// 007edcd4  85f6                 test esi, esi
// 007edcd6  7404                 je 0x7edcdc
// 007edcd8  3bf6                 cmp esi, esi
// 007edcda  740c                 je 0x7edce8
// 007edcdc  ffd5                 call ebp
// 007edcde  8b542424             mov edx, dword ptr [esp + 0x24]
// 007edce2  8b2d60b79800         mov ebp, dword ptr [0x98b760]
// 007edce8  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 007edcec  7407                 je 0x7edcf5
// 007edcee  8b0a                 mov ecx, dword ptr [edx]
// 007edcf0  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 007edcf3  7326                 jae 0x7edd1b
// 007edcf5  8b12                 mov edx, dword ptr [edx]
// 007edcf7  8d442410             lea eax, [esp + 0x10]
// 007edcfb  50                   push eax
// 007edcfc  53                   push ebx
// 007edcfd  56                   push esi
// 007edcfe  8d4c2424             lea ecx, [esp + 0x24]
// 007edd02  51                   push ecx
// 007edd03  8bcf                 mov ecx, edi
// 007edd05  89542420             mov dword ptr [esp + 0x20], edx
// 007edd09  c744242400000000     mov dword ptr [esp + 0x24], 0
// 007edd11  e89afdffff           call 0x7edab0
// 007edd16  8b30                 mov esi, dword ptr [eax]
// 007edd18  8b5804               mov ebx, dword ptr [eax + 4]
// 007edd1b  85f6                 test esi, esi
// 007edd1d  7516                 jne 0x7edd35
// 007edd1f  ffd5                 call ebp
// 007edd21  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 007edd24  5e                   pop esi
// 007edd25  7502                 jne 0x7edd29
// 007edd27  ffd5                 call ebp
// 007edd29  5f                   pop edi
// 007edd2a  5d                   pop ebp
// 007edd2b  8d4310               lea eax, [ebx + 0x10]
// 007edd2e  5b                   pop ebx
// 007edd2f  83c410               add esp, 0x10
// 007edd32  c20400               ret 4
// 007edd35  8b36                 mov esi, dword ptr [esi]
// 007edd37  ebe8                 jmp 0x7edd21
// standard library map_ptr<ptr> (function ??A?$map@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@@std@@QAEAAPAUT@@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
