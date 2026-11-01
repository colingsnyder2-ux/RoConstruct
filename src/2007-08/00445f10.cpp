// from server: 100% by auto
// roc 2007-08 00445f10  unit: VCRenderSettings::?$FactoryProduct  size: 199 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00445f10
//
// 00445f10  6aff                 push -1
// 00445f12  6858f67300           push 0x73f658
// 00445f17  64a100000000         mov eax, dword ptr fs:[0]
// 00445f1d  50                   push eax
// 00445f1e  83ec28               sub esp, 0x28
// 00445f21  53                   push ebx
// 00445f22  56                   push esi
// 00445f23  57                   push edi
// 00445f24  a188518b00           mov eax, dword ptr [0x8b5188]
// 00445f29  33c4                 xor eax, esp
// 00445f2b  50                   push eax
// 00445f2c  8d442438             lea eax, [esp + 0x38]
// 00445f30  64a300000000         mov dword ptr fs:[0], eax
// 00445f36  8bf1                 mov esi, ecx
// 00445f38  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 00445f3c  53                   push ebx
// 00445f3d  e81ecd0f00           call 0x542c60
// 00445f42  85f6                 test esi, esi
// 00445f44  8bf8                 mov edi, eax
// 00445f46  7506                 jne 0x445f4e
// 00445f48  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445f4e  3b7e04               cmp edi, dword ptr [esi + 4]
// 00445f51  7412                 je 0x445f65
// 00445f53  8d470c               lea eax, [edi + 0xc]
// 00445f56  50                   push eax
// 00445f57  53                   push ebx
// 00445f58  ff1520e67700         call dword ptr [0x77e620]
// 00445f5e  83c408               add esp, 8
// 00445f61  84c0                 test al, al
// 00445f63  7445                 je 0x445faa
// 00445f65  53                   push ebx
// 00445f66  8d4c241c             lea ecx, [esp + 0x1c]
// 00445f6a  ff159ce67700         call dword ptr [0x77e69c]
// 00445f70  c744243400000000     mov dword ptr [esp + 0x34], 0
// 00445f78  8d4c2418             lea ecx, [esp + 0x18]
// 00445f7c  51                   push ecx
// 00445f7d  57                   push edi
// 00445f7e  56                   push esi
// 00445f7f  8d54241c             lea edx, [esp + 0x1c]
// 00445f83  52                   push edx
// 00445f84  8bce                 mov ecx, esi
// 00445f86  c744245000000000     mov dword ptr [esp + 0x50], 0
// 00445f8e  e81dfaffff           call 0x4459b0
// 00445f93  8b30                 mov esi, dword ptr [eax]
// 00445f95  8b7804               mov edi, dword ptr [eax + 4]
// 00445f98  8d4c2418             lea ecx, [esp + 0x18]
// 00445f9c  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 00445fa4  ff15ace67700         call dword ptr [0x77e6ac]
// 00445faa  85f6                 test esi, esi
// 00445fac  7506                 jne 0x445fb4
// 00445fae  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445fb4  3b7e04               cmp edi, dword ptr [esi + 4]
// 00445fb7  7506                 jne 0x445fbf
// 00445fb9  ff15d8e67700         call dword ptr [0x77e6d8]
// 00445fbf  8d4728               lea eax, [edi + 0x28]
// 00445fc2  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00445fc6  64890d00000000       mov dword ptr fs:[0], ecx
// 00445fcd  59                   pop ecx
// 00445fce  5f                   pop edi
// 00445fcf  5e                   pop esi
// 00445fd0  5b                   pop ebx
// 00445fd1  83c434               add esp, 0x34
// 00445fd4  c20400               ret 4
// standard library map_str<ptr> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@@std@@QAEAAPAUT@@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
