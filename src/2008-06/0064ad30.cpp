// from server: 100% by auto
// roc 2008-06 0064ad30  unit: RBX::SleepStage  size: 220 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064ad30
//
// 0064ad30  83ec08               sub esp, 8
// 0064ad33  53                   push ebx
// 0064ad34  55                   push ebp
// 0064ad35  8b2d90288000         mov ebp, dword ptr [0x802890]
// 0064ad3b  56                   push esi
// 0064ad3c  8bf1                 mov esi, ecx
// 0064ad3e  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064ad41  8b18                 mov ebx, dword ptr [eax]
// 0064ad43  8b06                 mov eax, dword ptr [esi]
// 0064ad45  57                   push edi
// 0064ad46  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0064ad4a  85ff                 test edi, edi
// 0064ad4c  7404                 je 0x64ad52
// 0064ad4e  3bf8                 cmp edi, eax
// 0064ad50  7406                 je 0x64ad58
// 0064ad52  ffd5                 call ebp
// 0064ad54  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0064ad58  395c2424             cmp dword ptr [esp + 0x24], ebx
// 0064ad5c  7562                 jne 0x64adc0
// 0064ad5e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0064ad62  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0064ad65  8b06                 mov eax, dword ptr [esi]
// 0064ad67  85c9                 test ecx, ecx
// 0064ad69  7404                 je 0x64ad6f
// 0064ad6b  3bc8                 cmp ecx, eax
// 0064ad6d  7406                 je 0x64ad75
// 0064ad6f  ffd5                 call ebp
// 0064ad71  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0064ad75  395c242c             cmp dword ptr [esp + 0x2c], ebx
// 0064ad79  7545                 jne 0x64adc0
// 0064ad7b  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0064ad7e  8b5104               mov edx, dword ptr [ecx + 4]
// 0064ad81  52                   push edx
// 0064ad82  8bce                 mov ecx, esi
// 0064ad84  e8c7e20100           call 0x669050
// 0064ad89  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064ad8c  894004               mov dword ptr [eax + 4], eax
// 0064ad8f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064ad92  c7461c00000000       mov dword ptr [esi + 0x1c], 0
// 0064ad99  8900                 mov dword ptr [eax], eax
// 0064ad9b  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064ad9e  894008               mov dword ptr [eax + 8], eax
// 0064ada1  8b4618               mov eax, dword ptr [esi + 0x18]
// 0064ada4  8b16                 mov edx, dword ptr [esi]
// 0064ada6  8b08                 mov ecx, dword ptr [eax]
// 0064ada8  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0064adac  5f                   pop edi
// 0064adad  5e                   pop esi
// 0064adae  5d                   pop ebp
// 0064adaf  894804               mov dword ptr [eax + 4], ecx
// 0064adb2  8910                 mov dword ptr [eax], edx
// 0064adb4  5b                   pop ebx
// 0064adb5  83c408               add esp, 8
// 0064adb8  c21400               ret 0x14
// 0064adbb  eb03                 jmp 0x64adc0
// 0064adbd  8d4900               lea ecx, [ecx]
// 0064adc0  85ff                 test edi, edi
// 0064adc2  7406                 je 0x64adca
// 0064adc4  3b7c2428             cmp edi, dword ptr [esp + 0x28]
// 0064adc8  7406                 je 0x64add0
// 0064adca  ffd5                 call ebp
// 0064adcc  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0064add0  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0064add4  3b5c242c             cmp ebx, dword ptr [esp + 0x2c]
// 0064add8  741d                 je 0x64adf7
// 0064adda  8d4c2420             lea ecx, [esp + 0x20]
// 0064adde  e85de5f9ff           call 0x5e9340
// 0064ade3  53                   push ebx
// 0064ade4  57                   push edi
// 0064ade5  8d442418             lea eax, [esp + 0x18]
// 0064ade9  50                   push eax
// 0064adea  8bce                 mov ecx, esi
// 0064adec  e82ffcffff           call 0x64aa20
// 0064adf1  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0064adf5  ebc9                 jmp 0x64adc0
// 0064adf7  8b36                 mov esi, dword ptr [esi]
// 0064adf9  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0064adfd  5f                   pop edi
// 0064adfe  8930                 mov dword ptr [eax], esi
// 0064ae00  5e                   pop esi
// 0064ae01  5d                   pop ebp
// 0064ae02  895804               mov dword ptr [eax + 4], ebx
// 0064ae05  5b                   pop ebx
// 0064ae06  83c408               add esp, 8
// 0064ae09  c21400               ret 0x14
// standard library set<ptr> (function ?erase@?$_Tree@V?$_Tset_traits@PAUT@@U?$less@PAUT@@@std@@V?$allocator@PAUT@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@0@Z)

// stl: set<ptr>
struct T; typedef T* E;
#include <set>
template class std::set<E>;
