// from server: 100% by auto
// roc 2007-03 005686d0  unit: seg_00560000  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005686d0
//
// 005686d0  8b542404             mov edx, dword ptr [esp + 4]
// 005686d4  83ec08               sub esp, 8
// 005686d7  53                   push ebx
// 005686d8  8bd9                 mov ebx, ecx
// 005686da  8b4308               mov eax, dword ptr [ebx + 8]
// 005686dd  b9ffffff0f           mov ecx, 0xfffffff
// 005686e2  2bc8                 sub ecx, eax
// 005686e4  3bca                 cmp ecx, edx
// 005686e6  7305                 jae 0x5686ed
// 005686e8  e8a3e4ffff           call 0x566b90
// 005686ed  8bc8                 mov ecx, eax
// 005686ef  d1e9                 shr ecx, 1
// 005686f1  83f908               cmp ecx, 8
// 005686f4  7305                 jae 0x5686fb
// 005686f6  b908000000           mov ecx, 8
// 005686fb  3bd1                 cmp edx, ecx
// 005686fd  55                   push ebp
// 005686fe  56                   push esi
// 005686ff  57                   push edi
// 00568700  7311                 jae 0x568713
// 00568702  beffffff0f           mov esi, 0xfffffff
// 00568707  2bf1                 sub esi, ecx
// 00568709  3bc6                 cmp eax, esi
// 0056870b  7706                 ja 0x568713
// 0056870d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00568711  8bd1                 mov edx, ecx
// 00568713  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 00568716  03c2                 add eax, edx
// 00568718  6a00                 push 0
// 0056871a  50                   push eax
// 0056871b  c1ed02               shr ebp, 2
// 0056871e  e83d06ebff           call 0x418d60
// 00568723  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00568726  89442418             mov dword ptr [esp + 0x18], eax
// 0056872a  8d34ad00000000       lea esi, [ebp*4]
// 00568731  8d3c06               lea edi, [esi + eax]
// 00568734  8b4308               mov eax, dword ptr [ebx + 8]
// 00568737  03c0                 add eax, eax
// 00568739  03c0                 add eax, eax
// 0056873b  8d140e               lea edx, [esi + ecx]
// 0056873e  2bc2                 sub eax, edx
// 00568740  03c1                 add eax, ecx
// 00568742  83c408               add esp, 8
// 00568745  c1f802               sar eax, 2
// 00568748  8d048500000000       lea eax, [eax*4]
// 0056874f  8d0c38               lea ecx, [eax + edi]
// 00568752  894c2414             mov dword ptr [esp + 0x14], ecx
// 00568756  7415                 je 0x56876d
// 00568758  50                   push eax
// 00568759  52                   push edx
// 0056875a  50                   push eax
// 0056875b  57                   push edi
// 0056875c  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 00568762  ffd7                 call edi
// 00568764  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00568768  83c410               add esp, 0x10
// 0056876b  eb06                 jmp 0x568773
// 0056876d  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 00568773  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00568777  3be8                 cmp ebp, eax
// 00568779  7735                 ja 0x5687b0
// 0056877b  8b4304               mov eax, dword ptr [ebx + 4]
// 0056877e  c1fe02               sar esi, 2
// 00568781  8d14b500000000       lea edx, [esi*4]
// 00568788  8d340a               lea esi, [edx + ecx]
// 0056878b  7409                 je 0x568796
// 0056878d  52                   push edx
// 0056878e  50                   push eax
// 0056878f  52                   push edx
// 00568790  51                   push ecx
// 00568791  ffd7                 call edi
// 00568793  83c410               add esp, 0x10
// 00568796  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0056879a  2bcd                 sub ecx, ebp
// 0056879c  7406                 je 0x5687a4
// 0056879e  33c0                 xor eax, eax
// 005687a0  8bfe                 mov edi, esi
// 005687a2  f3ab                 rep stosd dword ptr es:[edi], eax
// 005687a4  85ed                 test ebp, ebp
// 005687a6  765a                 jbe 0x568802
// 005687a8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005687ac  8bcd                 mov ecx, ebp
// 005687ae  eb4e                 jmp 0x5687fe
// 005687b0  8b5304               mov edx, dword ptr [ebx + 4]
// 005687b3  8d2c8500000000       lea ebp, [eax*4]
// 005687ba  8bc5                 mov eax, ebp
// 005687bc  c1f802               sar eax, 2
// 005687bf  740d                 je 0x5687ce
// 005687c1  03c0                 add eax, eax
// 005687c3  03c0                 add eax, eax
// 005687c5  50                   push eax
// 005687c6  52                   push edx
// 005687c7  50                   push eax
// 005687c8  51                   push ecx
// 005687c9  ffd7                 call edi
// 005687cb  83c410               add esp, 0x10
// 005687ce  8b4304               mov eax, dword ptr [ebx + 4]
// 005687d1  8b542410             mov edx, dword ptr [esp + 0x10]
// 005687d5  8d0c28               lea ecx, [eax + ebp]
// 005687d8  2bf1                 sub esi, ecx
// 005687da  03f0                 add esi, eax
// 005687dc  c1fe02               sar esi, 2
// 005687df  8d04b500000000       lea eax, [esi*4]
// 005687e6  8d3410               lea esi, [eax + edx]
// 005687e9  7409                 je 0x5687f4
// 005687eb  50                   push eax
// 005687ec  51                   push ecx
// 005687ed  50                   push eax
// 005687ee  52                   push edx
// 005687ef  ffd7                 call edi
// 005687f1  83c410               add esp, 0x10
// 005687f4  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005687f8  85c9                 test ecx, ecx
// 005687fa  7606                 jbe 0x568802
// 005687fc  8bfe                 mov edi, esi
// 005687fe  33c0                 xor eax, eax
// 00568800  f3ab                 rep stosd dword ptr es:[edi], eax
// 00568802  8b4304               mov eax, dword ptr [ebx + 4]
// 00568805  85c0                 test eax, eax
// 00568807  5f                   pop edi
// 00568808  5e                   pop esi
// 00568809  5d                   pop ebp
// 0056880a  7409                 je 0x568815
// 0056880c  50                   push eax
// 0056880d  e8de580b00           call 0x61e0f0
// 00568812  83c404               add esp, 4
// 00568815  8b542404             mov edx, dword ptr [esp + 4]
// 00568819  8b442410             mov eax, dword ptr [esp + 0x10]
// 0056881d  014308               add dword ptr [ebx + 8], eax
// 00568820  895304               mov dword ptr [ebx + 4], edx
// 00568823  5b                   pop ebx
// 00568824  83c408               add esp, 8
// 00568827  c20400               ret 4
// standard library deque<ptr> (function ?_Growmap@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
