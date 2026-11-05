// from server: 100% by auto
// roc 2007-08 0060bd00  unit: CXTCaptionButtonTheme  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0060bd00
//
// 0060bd00  8b542404             mov edx, dword ptr [esp + 4]
// 0060bd04  83ec08               sub esp, 8
// 0060bd07  53                   push ebx
// 0060bd08  8bd9                 mov ebx, ecx
// 0060bd0a  8b4308               mov eax, dword ptr [ebx + 8]
// 0060bd0d  b9ffffff0f           mov ecx, 0xfffffff
// 0060bd12  2bc8                 sub ecx, eax
// 0060bd14  3bca                 cmp ecx, edx
// 0060bd16  7305                 jae 0x60bd1d
// 0060bd18  e8a3cdfeff           call 0x5f8ac0
// 0060bd1d  8bc8                 mov ecx, eax
// 0060bd1f  d1e9                 shr ecx, 1
// 0060bd21  83f908               cmp ecx, 8
// 0060bd24  7305                 jae 0x60bd2b
// 0060bd26  b908000000           mov ecx, 8
// 0060bd2b  3bd1                 cmp edx, ecx
// 0060bd2d  55                   push ebp
// 0060bd2e  56                   push esi
// 0060bd2f  57                   push edi
// 0060bd30  7311                 jae 0x60bd43
// 0060bd32  beffffff0f           mov esi, 0xfffffff
// 0060bd37  2bf1                 sub esi, ecx
// 0060bd39  3bc6                 cmp eax, esi
// 0060bd3b  7706                 ja 0x60bd43
// 0060bd3d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 0060bd41  8bd1                 mov edx, ecx
// 0060bd43  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 0060bd46  03c2                 add eax, edx
// 0060bd48  6a00                 push 0
// 0060bd4a  50                   push eax
// 0060bd4b  c1ed02               shr ebp, 2
// 0060bd4e  e80d40faff           call 0x5afd60
// 0060bd53  8b4b04               mov ecx, dword ptr [ebx + 4]
// 0060bd56  89442418             mov dword ptr [esp + 0x18], eax
// 0060bd5a  8d34ad00000000       lea esi, [ebp*4]
// 0060bd61  8d3c06               lea edi, [esi + eax]
// 0060bd64  8b4308               mov eax, dword ptr [ebx + 8]
// 0060bd67  03c0                 add eax, eax
// 0060bd69  03c0                 add eax, eax
// 0060bd6b  8d140e               lea edx, [esi + ecx]
// 0060bd6e  2bc2                 sub eax, edx
// 0060bd70  03c1                 add eax, ecx
// 0060bd72  83c408               add esp, 8
// 0060bd75  c1f802               sar eax, 2
// 0060bd78  8d048500000000       lea eax, [eax*4]
// 0060bd7f  8d0c38               lea ecx, [eax + edi]
// 0060bd82  894c2414             mov dword ptr [esp + 0x14], ecx
// 0060bd86  7415                 je 0x60bd9d
// 0060bd88  50                   push eax
// 0060bd89  52                   push edx
// 0060bd8a  50                   push eax
// 0060bd8b  57                   push edi
// 0060bd8c  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 0060bd92  ffd7                 call edi
// 0060bd94  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0060bd98  83c410               add esp, 0x10
// 0060bd9b  eb06                 jmp 0x60bda3
// 0060bd9d  8b3d48e77700         mov edi, dword ptr [0x77e748]
// 0060bda3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0060bda7  3be8                 cmp ebp, eax
// 0060bda9  7735                 ja 0x60bde0
// 0060bdab  8b4304               mov eax, dword ptr [ebx + 4]
// 0060bdae  c1fe02               sar esi, 2
// 0060bdb1  8d14b500000000       lea edx, [esi*4]
// 0060bdb8  8d340a               lea esi, [edx + ecx]
// 0060bdbb  7409                 je 0x60bdc6
// 0060bdbd  52                   push edx
// 0060bdbe  50                   push eax
// 0060bdbf  52                   push edx
// 0060bdc0  51                   push ecx
// 0060bdc1  ffd7                 call edi
// 0060bdc3  83c410               add esp, 0x10
// 0060bdc6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060bdca  2bcd                 sub ecx, ebp
// 0060bdcc  7406                 je 0x60bdd4
// 0060bdce  33c0                 xor eax, eax
// 0060bdd0  8bfe                 mov edi, esi
// 0060bdd2  f3ab                 rep stosd dword ptr es:[edi], eax
// 0060bdd4  85ed                 test ebp, ebp
// 0060bdd6  765a                 jbe 0x60be32
// 0060bdd8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0060bddc  8bcd                 mov ecx, ebp
// 0060bdde  eb4e                 jmp 0x60be2e
// 0060bde0  8b5304               mov edx, dword ptr [ebx + 4]
// 0060bde3  8d2c8500000000       lea ebp, [eax*4]
// 0060bdea  8bc5                 mov eax, ebp
// 0060bdec  c1f802               sar eax, 2
// 0060bdef  740d                 je 0x60bdfe
// 0060bdf1  03c0                 add eax, eax
// 0060bdf3  03c0                 add eax, eax
// 0060bdf5  50                   push eax
// 0060bdf6  52                   push edx
// 0060bdf7  50                   push eax
// 0060bdf8  51                   push ecx
// 0060bdf9  ffd7                 call edi
// 0060bdfb  83c410               add esp, 0x10
// 0060bdfe  8b4304               mov eax, dword ptr [ebx + 4]
// 0060be01  8b542410             mov edx, dword ptr [esp + 0x10]
// 0060be05  8d0c28               lea ecx, [eax + ebp]
// 0060be08  2bf1                 sub esi, ecx
// 0060be0a  03f0                 add esi, eax
// 0060be0c  c1fe02               sar esi, 2
// 0060be0f  8d04b500000000       lea eax, [esi*4]
// 0060be16  8d3410               lea esi, [eax + edx]
// 0060be19  7409                 je 0x60be24
// 0060be1b  50                   push eax
// 0060be1c  51                   push ecx
// 0060be1d  50                   push eax
// 0060be1e  52                   push edx
// 0060be1f  ffd7                 call edi
// 0060be21  83c410               add esp, 0x10
// 0060be24  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0060be28  85c9                 test ecx, ecx
// 0060be2a  7606                 jbe 0x60be32
// 0060be2c  8bfe                 mov edi, esi
// 0060be2e  33c0                 xor eax, eax
// 0060be30  f3ab                 rep stosd dword ptr es:[edi], eax
// 0060be32  8b4304               mov eax, dword ptr [ebx + 4]
// 0060be35  85c0                 test eax, eax
// 0060be37  5f                   pop edi
// 0060be38  5e                   pop esi
// 0060be39  5d                   pop ebp
// 0060be3a  7409                 je 0x60be45
// 0060be3c  50                   push eax
// 0060be3d  e8203e0200           call 0x62fc62
// 0060be42  83c404               add esp, 4
// 0060be45  8b542404             mov edx, dword ptr [esp + 4]
// 0060be49  8b442410             mov eax, dword ptr [esp + 0x10]
// 0060be4d  014308               add dword ptr [ebx + 8], eax
// 0060be50  895304               mov dword ptr [ebx + 4], edx
// 0060be53  5b                   pop ebx
// 0060be54  83c408               add esp, 8
// 0060be57  c20400               ret 4
// standard library deque<ptr> (function ?_Growmap@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
