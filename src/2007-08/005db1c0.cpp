// from server: 100% by auto
// roc 2007-08 005db1c0  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005db1c0
//
// 005db1c0  8b5104               mov edx, dword ptr [ecx + 4]
// 005db1c3  8b4204               mov eax, dword ptr [edx + 4]
// 005db1c6  83ec10               sub esp, 0x10
// 005db1c9  80781500             cmp byte ptr [eax + 0x15], 0
// 005db1cd  53                   push ebx
// 005db1ce  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 005db1d2  56                   push esi
// 005db1d3  57                   push edi
// 005db1d4  7516                 jne 0x5db1ec
// 005db1d6  8b33                 mov esi, dword ptr [ebx]
// 005db1d8  39700c               cmp dword ptr [eax + 0xc], esi
// 005db1db  7305                 jae 0x5db1e2
// 005db1dd  8b4008               mov eax, dword ptr [eax + 8]
// 005db1e0  eb04                 jmp 0x5db1e6
// 005db1e2  8bd0                 mov edx, eax
// 005db1e4  8b00                 mov eax, dword ptr [eax]
// 005db1e6  80781500             cmp byte ptr [eax + 0x15], 0
// 005db1ea  74ec                 je 0x5db1d8
// 005db1ec  3b5104               cmp edx, dword ptr [ecx + 4]
// 005db1ef  8bfa                 mov edi, edx
// 005db1f1  8bf1                 mov esi, ecx
// 005db1f3  7407                 je 0x5db1fc
// 005db1f5  8b03                 mov eax, dword ptr [ebx]
// 005db1f7  3b420c               cmp eax, dword ptr [edx + 0xc]
// 005db1fa  7324                 jae 0x5db220
// 005db1fc  8b13                 mov edx, dword ptr [ebx]
// 005db1fe  8d44240c             lea eax, [esp + 0xc]
// 005db202  50                   push eax
// 005db203  57                   push edi
// 005db204  89542414             mov dword ptr [esp + 0x14], edx
// 005db208  56                   push esi
// 005db209  8d542420             lea edx, [esp + 0x20]
// 005db20d  52                   push edx
// 005db20e  c744242000000000     mov dword ptr [esp + 0x20], 0
// 005db216  e855fdffff           call 0x5daf70
// 005db21b  8b30                 mov esi, dword ptr [eax]
// 005db21d  8b7804               mov edi, dword ptr [eax + 4]
// 005db220  85f6                 test esi, esi
// 005db222  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 005db228  7502                 jne 0x5db22c
// 005db22a  ffd3                 call ebx
// 005db22c  3b7e04               cmp edi, dword ptr [esi + 4]
// 005db22f  7502                 jne 0x5db233
// 005db231  ffd3                 call ebx
// 005db233  8d4710               lea eax, [edi + 0x10]
// 005db236  5f                   pop edi
// 005db237  5e                   pop esi
// 005db238  5b                   pop ebx
// 005db239  83c410               add esp, 0x10
// 005db23c  c20400               ret 4
// standard library map_ptr<ptr> (function ??A?$map@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@@std@@QAEAAPAUT@@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
