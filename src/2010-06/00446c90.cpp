// from server: 100% by auto
// roc 2010-06 00446c90  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00446c90
//
// 00446c90  8b542404             mov edx, dword ptr [esp + 4]
// 00446c94  83ec10               sub esp, 0x10
// 00446c97  53                   push ebx
// 00446c98  55                   push ebp
// 00446c99  57                   push edi
// 00446c9a  8bf9                 mov edi, ecx
// 00446c9c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 00446c9f  8b4104               mov eax, dword ptr [ecx + 4]
// 00446ca2  80781500             cmp byte ptr [eax + 0x15], 0
// 00446ca6  8bd9                 mov ebx, ecx
// 00446ca8  751a                 jne 0x446cc4
// 00446caa  8b0a                 mov ecx, dword ptr [edx]
// 00446cac  8d642400             lea esp, [esp]
// 00446cb0  39480c               cmp dword ptr [eax + 0xc], ecx
// 00446cb3  7305                 jae 0x446cba
// 00446cb5  8b4008               mov eax, dword ptr [eax + 8]
// 00446cb8  eb04                 jmp 0x446cbe
// 00446cba  8bd8                 mov ebx, eax
// 00446cbc  8b00                 mov eax, dword ptr [eax]
// 00446cbe  80781500             cmp byte ptr [eax + 0x15], 0
// 00446cc2  74ec                 je 0x446cb0
// 00446cc4  8b4718               mov eax, dword ptr [edi + 0x18]
// 00446cc7  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00446ccd  56                   push esi
// 00446cce  8b37                 mov esi, dword ptr [edi]
// 00446cd0  89442414             mov dword ptr [esp + 0x14], eax
// 00446cd4  85f6                 test esi, esi
// 00446cd6  7404                 je 0x446cdc
// 00446cd8  3bf6                 cmp esi, esi
// 00446cda  740c                 je 0x446ce8
// 00446cdc  ffd5                 call ebp
// 00446cde  8b542424             mov edx, dword ptr [esp + 0x24]
// 00446ce2  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 00446ce8  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 00446cec  7407                 je 0x446cf5
// 00446cee  8b0a                 mov ecx, dword ptr [edx]
// 00446cf0  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 00446cf3  7326                 jae 0x446d1b
// 00446cf5  8b12                 mov edx, dword ptr [edx]
// 00446cf7  8d442410             lea eax, [esp + 0x10]
// 00446cfb  50                   push eax
// 00446cfc  53                   push ebx
// 00446cfd  56                   push esi
// 00446cfe  8d4c2424             lea ecx, [esp + 0x24]
// 00446d02  51                   push ecx
// 00446d03  8bcf                 mov ecx, edi
// 00446d05  89542420             mov dword ptr [esp + 0x20], edx
// 00446d09  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00446d11  e8eafbffff           call 0x446900
// 00446d16  8b30                 mov esi, dword ptr [eax]
// 00446d18  8b5804               mov ebx, dword ptr [eax + 4]
// 00446d1b  85f6                 test esi, esi
// 00446d1d  7516                 jne 0x446d35
// 00446d1f  ffd5                 call ebp
// 00446d21  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00446d24  5e                   pop esi
// 00446d25  7502                 jne 0x446d29
// 00446d27  ffd5                 call ebp
// 00446d29  5f                   pop edi
// 00446d2a  5d                   pop ebp
// 00446d2b  8d4310               lea eax, [ebx + 0x10]
// 00446d2e  5b                   pop ebx
// 00446d2f  83c410               add esp, 0x10
// 00446d32  c20400               ret 4
// 00446d35  8b36                 mov esi, dword ptr [esi]
// 00446d37  ebe8                 jmp 0x446d21
// standard library map_ptr<ptr> (function ??A?$map@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@@std@@QAEAAPAUT@@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
