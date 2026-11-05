// from server: 100% by auto
// roc 2007-03 00594fe0  unit: seg_00590000  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00594fe0
//
// 00594fe0  8b542404             mov edx, dword ptr [esp + 4]
// 00594fe4  83ec08               sub esp, 8
// 00594fe7  53                   push ebx
// 00594fe8  8bd9                 mov ebx, ecx
// 00594fea  8b4308               mov eax, dword ptr [ebx + 8]
// 00594fed  b9ffffff0f           mov ecx, 0xfffffff
// 00594ff2  2bc8                 sub ecx, eax
// 00594ff4  3bca                 cmp ecx, edx
// 00594ff6  7305                 jae 0x594ffd
// 00594ff8  e8931bfdff           call 0x566b90
// 00594ffd  8bc8                 mov ecx, eax
// 00594fff  d1e9                 shr ecx, 1
// 00595001  83f908               cmp ecx, 8
// 00595004  7305                 jae 0x59500b
// 00595006  b908000000           mov ecx, 8
// 0059500b  3bd1                 cmp edx, ecx
// 0059500d  55                   push ebp
// 0059500e  56                   push esi
// 0059500f  57                   push edi
// 00595010  7311                 jae 0x595023
// 00595012  beffffff0f           mov esi, 0xfffffff
// 00595017  2bf1                 sub esi, ecx
// 00595019  3bc6                 cmp eax, esi
// 0059501b  7706                 ja 0x595023
// 0059501d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00595021  8bd1                 mov edx, ecx
// 00595023  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 00595026  03c2                 add eax, edx
// 00595028  6a00                 push 0
// 0059502a  50                   push eax
// 0059502b  c1ed04               shr ebp, 4
// 0059502e  e82d3de8ff           call 0x418d60
// 00595033  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00595036  89442418             mov dword ptr [esp + 0x18], eax
// 0059503a  8d34ad00000000       lea esi, [ebp*4]
// 00595041  8d3c06               lea edi, [esi + eax]
// 00595044  8b4308               mov eax, dword ptr [ebx + 8]
// 00595047  03c0                 add eax, eax
// 00595049  03c0                 add eax, eax
// 0059504b  8d140e               lea edx, [esi + ecx]
// 0059504e  2bc2                 sub eax, edx
// 00595050  03c1                 add eax, ecx
// 00595052  83c408               add esp, 8
// 00595055  c1f802               sar eax, 2
// 00595058  8d048500000000       lea eax, [eax*4]
// 0059505f  8d0c38               lea ecx, [eax + edi]
// 00595062  894c2414             mov dword ptr [esp + 0x14], ecx
// 00595066  7415                 je 0x59507d
// 00595068  50                   push eax
// 00595069  52                   push edx
// 0059506a  50                   push eax
// 0059506b  57                   push edi
// 0059506c  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 00595072  ffd7                 call edi
// 00595074  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00595078  83c410               add esp, 0x10
// 0059507b  eb06                 jmp 0x595083
// 0059507d  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 00595083  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00595087  3be8                 cmp ebp, eax
// 00595089  7735                 ja 0x5950c0
// 0059508b  8b4304               mov eax, dword ptr [ebx + 4]
// 0059508e  c1fe02               sar esi, 2
// 00595091  8d14b500000000       lea edx, [esi*4]
// 00595098  8d340a               lea esi, [edx + ecx]
// 0059509b  7409                 je 0x5950a6
// 0059509d  52                   push edx
// 0059509e  50                   push eax
// 0059509f  52                   push edx
// 005950a0  51                   push ecx
// 005950a1  ffd7                 call edi
// 005950a3  83c410               add esp, 0x10
// 005950a6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005950aa  2bcd                 sub ecx, ebp
// 005950ac  7406                 je 0x5950b4
// 005950ae  33c0                 xor eax, eax
// 005950b0  8bfe                 mov edi, esi
// 005950b2  f3ab                 rep stosd dword ptr es:[edi], eax
// 005950b4  85ed                 test ebp, ebp
// 005950b6  765a                 jbe 0x595112
// 005950b8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005950bc  8bcd                 mov ecx, ebp
// 005950be  eb4e                 jmp 0x59510e
// 005950c0  8b5304               mov edx, dword ptr [ebx + 4]
// 005950c3  8d2c8500000000       lea ebp, [eax*4]
// 005950ca  8bc5                 mov eax, ebp
// 005950cc  c1f802               sar eax, 2
// 005950cf  740d                 je 0x5950de
// 005950d1  03c0                 add eax, eax
// 005950d3  03c0                 add eax, eax
// 005950d5  50                   push eax
// 005950d6  52                   push edx
// 005950d7  50                   push eax
// 005950d8  51                   push ecx
// 005950d9  ffd7                 call edi
// 005950db  83c410               add esp, 0x10
// 005950de  8b4304               mov eax, dword ptr [ebx + 4]
// 005950e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 005950e5  8d0c28               lea ecx, [eax + ebp]
// 005950e8  2bf1                 sub esi, ecx
// 005950ea  03f0                 add esi, eax
// 005950ec  c1fe02               sar esi, 2
// 005950ef  8d04b500000000       lea eax, [esi*4]
// 005950f6  8d3410               lea esi, [eax + edx]
// 005950f9  7409                 je 0x595104
// 005950fb  50                   push eax
// 005950fc  51                   push ecx
// 005950fd  50                   push eax
// 005950fe  52                   push edx
// 005950ff  ffd7                 call edi
// 00595101  83c410               add esp, 0x10
// 00595104  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00595108  85c9                 test ecx, ecx
// 0059510a  7606                 jbe 0x595112
// 0059510c  8bfe                 mov edi, esi
// 0059510e  33c0                 xor eax, eax
// 00595110  f3ab                 rep stosd dword ptr es:[edi], eax
// 00595112  8b4304               mov eax, dword ptr [ebx + 4]
// 00595115  85c0                 test eax, eax
// 00595117  5f                   pop edi
// 00595118  5e                   pop esi
// 00595119  5d                   pop ebp
// 0059511a  7409                 je 0x595125
// 0059511c  50                   push eax
// 0059511d  e8ce8f0800           call 0x61e0f0
// 00595122  83c404               add esp, 4
// 00595125  8b542404             mov edx, dword ptr [esp + 4]
// 00595129  8b442410             mov eax, dword ptr [esp + 0x10]
// 0059512d  014308               add dword ptr [ebx + 8], eax
// 00595130  895304               mov dword ptr [ebx + 4], edx
// 00595133  5b                   pop ebx
// 00595134  83c408               add esp, 8
// 00595137  c20400               ret 4
// standard library deque<char> (function ?_Growmap@?$deque@DV?$allocator@D@std@@@std@@IAEXI@Z)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
