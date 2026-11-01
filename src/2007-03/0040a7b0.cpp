// from server: 100% by auto
// roc 2007-03 0040a7b0  unit: seg_00400000  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0040a7b0
//
// 0040a7b0  8b542404             mov edx, dword ptr [esp + 4]
// 0040a7b4  83ec08               sub esp, 8
// 0040a7b7  53                   push ebx
// 0040a7b8  8bd9                 mov ebx, ecx
// 0040a7ba  8b4308               mov eax, dword ptr [ebx + 8]
// 0040a7bd  b949922409           mov ecx, 0x9249249
// 0040a7c2  2bc8                 sub ecx, eax
// 0040a7c4  3bca                 cmp ecx, edx
// 0040a7c6  7305                 jae 0x40a7cd
// 0040a7c8  e8c3e4ffff           call 0x408c90
// 0040a7cd  8bc8                 mov ecx, eax
// 0040a7cf  d1e9                 shr ecx, 1
// 0040a7d1  83f908               cmp ecx, 8
// 0040a7d4  7305                 jae 0x40a7db
// 0040a7d6  b908000000           mov ecx, 8
// 0040a7db  3bd1                 cmp edx, ecx
// 0040a7dd  55                   push ebp
// 0040a7de  56                   push esi
// 0040a7df  57                   push edi
// 0040a7e0  7311                 jae 0x40a7f3
// 0040a7e2  be49922409           mov esi, 0x9249249
// 0040a7e7  2bf1                 sub esi, ecx
// 0040a7e9  3bc6                 cmp eax, esi
// 0040a7eb  7706                 ja 0x40a7f3
// 0040a7ed  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0040a7f1  8bd1                 mov edx, ecx
// 0040a7f3  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 0040a7f6  03c2                 add eax, edx
// 0040a7f8  6a00                 push 0
// 0040a7fa  50                   push eax
// 0040a7fb  e860e50000           call 0x418d60
// 0040a800  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0040a803  89442418             mov dword ptr [esp + 0x18], eax
// 0040a807  8d34ad00000000       lea esi, [ebp*4]
// 0040a80e  8d3c06               lea edi, [esi + eax]
// 0040a811  8b4308               mov eax, dword ptr [ebx + 8]
// 0040a814  03c0                 add eax, eax
// 0040a816  03c0                 add eax, eax
// 0040a818  8d140e               lea edx, [esi + ecx]
// 0040a81b  2bc2                 sub eax, edx
// 0040a81d  03c1                 add eax, ecx
// 0040a81f  83c408               add esp, 8
// 0040a822  c1f802               sar eax, 2
// 0040a825  8d048500000000       lea eax, [eax*4]
// 0040a82c  8d0c38               lea ecx, [eax + edi]
// 0040a82f  894c2414             mov dword ptr [esp + 0x14], ecx
// 0040a833  7415                 je 0x40a84a
// 0040a835  50                   push eax
// 0040a836  52                   push edx
// 0040a837  50                   push eax
// 0040a838  57                   push edi
// 0040a839  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 0040a83f  ffd7                 call edi
// 0040a841  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0040a845  83c410               add esp, 0x10
// 0040a848  eb06                 jmp 0x40a850
// 0040a84a  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 0040a850  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0040a854  3be8                 cmp ebp, eax
// 0040a856  7735                 ja 0x40a88d
// 0040a858  8b4304               mov eax, dword ptr [ebx + 4]
// 0040a85b  c1fe02               sar esi, 2
// 0040a85e  8d14b500000000       lea edx, [esi*4]
// 0040a865  8d340a               lea esi, [edx + ecx]
// 0040a868  7409                 je 0x40a873
// 0040a86a  52                   push edx
// 0040a86b  50                   push eax
// 0040a86c  52                   push edx
// 0040a86d  51                   push ecx
// 0040a86e  ffd7                 call edi
// 0040a870  83c410               add esp, 0x10
// 0040a873  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0040a877  2bcd                 sub ecx, ebp
// 0040a879  7406                 je 0x40a881
// 0040a87b  33c0                 xor eax, eax
// 0040a87d  8bfe                 mov edi, esi
// 0040a87f  f3ab                 rep stosd dword ptr es:[edi], eax
// 0040a881  85ed                 test ebp, ebp
// 0040a883  765a                 jbe 0x40a8df
// 0040a885  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0040a889  8bcd                 mov ecx, ebp
// 0040a88b  eb4e                 jmp 0x40a8db
// 0040a88d  8b5304               mov edx, dword ptr [ebx + 4]
// 0040a890  8d2c8500000000       lea ebp, [eax*4]
// 0040a897  8bc5                 mov eax, ebp
// 0040a899  c1f802               sar eax, 2
// 0040a89c  740d                 je 0x40a8ab
// 0040a89e  03c0                 add eax, eax
// 0040a8a0  03c0                 add eax, eax
// 0040a8a2  50                   push eax
// 0040a8a3  52                   push edx
// 0040a8a4  50                   push eax
// 0040a8a5  51                   push ecx
// 0040a8a6  ffd7                 call edi
// 0040a8a8  83c410               add esp, 0x10
// 0040a8ab  8b4304               mov eax, dword ptr [ebx + 4]
// 0040a8ae  8b542410             mov edx, dword ptr [esp + 0x10]
// 0040a8b2  8d0c28               lea ecx, [eax + ebp]
// 0040a8b5  2bf1                 sub esi, ecx
// 0040a8b7  03f0                 add esi, eax
// 0040a8b9  c1fe02               sar esi, 2
// 0040a8bc  8d04b500000000       lea eax, [esi*4]
// 0040a8c3  8d3410               lea esi, [eax + edx]
// 0040a8c6  7409                 je 0x40a8d1
// 0040a8c8  50                   push eax
// 0040a8c9  51                   push ecx
// 0040a8ca  50                   push eax
// 0040a8cb  52                   push edx
// 0040a8cc  ffd7                 call edi
// 0040a8ce  83c410               add esp, 0x10
// 0040a8d1  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0040a8d5  85c9                 test ecx, ecx
// 0040a8d7  7606                 jbe 0x40a8df
// 0040a8d9  8bfe                 mov edi, esi
// 0040a8db  33c0                 xor eax, eax
// 0040a8dd  f3ab                 rep stosd dword ptr es:[edi], eax
// 0040a8df  8b4304               mov eax, dword ptr [ebx + 4]
// 0040a8e2  85c0                 test eax, eax
// 0040a8e4  5f                   pop edi
// 0040a8e5  5e                   pop esi
// 0040a8e6  5d                   pop ebp
// 0040a8e7  7409                 je 0x40a8f2
// 0040a8e9  50                   push eax
// 0040a8ea  e801382100           call 0x61e0f0
// 0040a8ef  83c404               add esp, 4
// 0040a8f2  8b542404             mov edx, dword ptr [esp + 4]
// 0040a8f6  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040a8fa  014308               add dword ptr [ebx + 8], eax
// 0040a8fd  895304               mov dword ptr [ebx + 4], edx
// 0040a900  5b                   pop ebx
// 0040a901  83c408               add esp, 8
// 0040a904  c20400               ret 4
// standard library deque<string> (function ?_Growmap@?$deque@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@IAEXI@Z)

// stl: deque<string>
#include <string>
typedef std::string E;
#include <deque>
template class std::deque<E>;
