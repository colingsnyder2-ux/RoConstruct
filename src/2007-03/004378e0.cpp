// from server: 100% by auto
// roc 2007-03 004378e0  unit: seg_00430000  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 004378e0
//
// 004378e0  8b542404             mov edx, dword ptr [esp + 4]
// 004378e4  83ec08               sub esp, 8
// 004378e7  53                   push ebx
// 004378e8  8bd9                 mov ebx, ecx
// 004378ea  8b4308               mov eax, dword ptr [ebx + 8]
// 004378ed  b9ffffff0f           mov ecx, 0xfffffff
// 004378f2  2bc8                 sub ecx, eax
// 004378f4  3bca                 cmp ecx, edx
// 004378f6  7305                 jae 0x4378fd
// 004378f8  e89313fdff           call 0x408c90
// 004378fd  8bc8                 mov ecx, eax
// 004378ff  d1e9                 shr ecx, 1
// 00437901  83f908               cmp ecx, 8
// 00437904  7305                 jae 0x43790b
// 00437906  b908000000           mov ecx, 8
// 0043790b  3bd1                 cmp edx, ecx
// 0043790d  55                   push ebp
// 0043790e  56                   push esi
// 0043790f  57                   push edi
// 00437910  7311                 jae 0x437923
// 00437912  beffffff0f           mov esi, 0xfffffff
// 00437917  2bf1                 sub esi, ecx
// 00437919  3bc6                 cmp eax, esi
// 0043791b  7706                 ja 0x437923
// 0043791d  894c241c             mov dword ptr [esp + 0x1c], ecx
// 00437921  8bd1                 mov edx, ecx
// 00437923  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 00437926  03c2                 add eax, edx
// 00437928  6a00                 push 0
// 0043792a  50                   push eax
// 0043792b  c1ed02               shr ebp, 2
// 0043792e  e82d14feff           call 0x418d60
// 00437933  8b4b04               mov ecx, dword ptr [ebx + 4]
// 00437936  89442418             mov dword ptr [esp + 0x18], eax
// 0043793a  8d34ad00000000       lea esi, [ebp*4]
// 00437941  8d3c06               lea edi, [esi + eax]
// 00437944  8b4308               mov eax, dword ptr [ebx + 8]
// 00437947  03c0                 add eax, eax
// 00437949  03c0                 add eax, eax
// 0043794b  8d140e               lea edx, [esi + ecx]
// 0043794e  2bc2                 sub eax, edx
// 00437950  03c1                 add eax, ecx
// 00437952  83c408               add esp, 8
// 00437955  c1f802               sar eax, 2
// 00437958  8d048500000000       lea eax, [eax*4]
// 0043795f  8d0c38               lea ecx, [eax + edi]
// 00437962  894c2414             mov dword ptr [esp + 0x14], ecx
// 00437966  7415                 je 0x43797d
// 00437968  50                   push eax
// 00437969  52                   push edx
// 0043796a  50                   push eax
// 0043796b  57                   push edi
// 0043796c  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 00437972  ffd7                 call edi
// 00437974  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00437978  83c410               add esp, 0x10
// 0043797b  eb06                 jmp 0x437983
// 0043797d  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 00437983  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00437987  3be8                 cmp ebp, eax
// 00437989  7735                 ja 0x4379c0
// 0043798b  8b4304               mov eax, dword ptr [ebx + 4]
// 0043798e  c1fe02               sar esi, 2
// 00437991  8d14b500000000       lea edx, [esi*4]
// 00437998  8d340a               lea esi, [edx + ecx]
// 0043799b  7409                 je 0x4379a6
// 0043799d  52                   push edx
// 0043799e  50                   push eax
// 0043799f  52                   push edx
// 004379a0  51                   push ecx
// 004379a1  ffd7                 call edi
// 004379a3  83c410               add esp, 0x10
// 004379a6  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 004379aa  2bcd                 sub ecx, ebp
// 004379ac  7406                 je 0x4379b4
// 004379ae  33c0                 xor eax, eax
// 004379b0  8bfe                 mov edi, esi
// 004379b2  f3ab                 rep stosd dword ptr es:[edi], eax
// 004379b4  85ed                 test ebp, ebp
// 004379b6  765a                 jbe 0x437a12
// 004379b8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004379bc  8bcd                 mov ecx, ebp
// 004379be  eb4e                 jmp 0x437a0e
// 004379c0  8b5304               mov edx, dword ptr [ebx + 4]
// 004379c3  8d2c8500000000       lea ebp, [eax*4]
// 004379ca  8bc5                 mov eax, ebp
// 004379cc  c1f802               sar eax, 2
// 004379cf  740d                 je 0x4379de
// 004379d1  03c0                 add eax, eax
// 004379d3  03c0                 add eax, eax
// 004379d5  50                   push eax
// 004379d6  52                   push edx
// 004379d7  50                   push eax
// 004379d8  51                   push ecx
// 004379d9  ffd7                 call edi
// 004379db  83c410               add esp, 0x10
// 004379de  8b4304               mov eax, dword ptr [ebx + 4]
// 004379e1  8b542410             mov edx, dword ptr [esp + 0x10]
// 004379e5  8d0c28               lea ecx, [eax + ebp]
// 004379e8  2bf1                 sub esi, ecx
// 004379ea  03f0                 add esi, eax
// 004379ec  c1fe02               sar esi, 2
// 004379ef  8d04b500000000       lea eax, [esi*4]
// 004379f6  8d3410               lea esi, [eax + edx]
// 004379f9  7409                 je 0x437a04
// 004379fb  50                   push eax
// 004379fc  51                   push ecx
// 004379fd  50                   push eax
// 004379fe  52                   push edx
// 004379ff  ffd7                 call edi
// 00437a01  83c410               add esp, 0x10
// 00437a04  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00437a08  85c9                 test ecx, ecx
// 00437a0a  7606                 jbe 0x437a12
// 00437a0c  8bfe                 mov edi, esi
// 00437a0e  33c0                 xor eax, eax
// 00437a10  f3ab                 rep stosd dword ptr es:[edi], eax
// 00437a12  8b4304               mov eax, dword ptr [ebx + 4]
// 00437a15  85c0                 test eax, eax
// 00437a17  5f                   pop edi
// 00437a18  5e                   pop esi
// 00437a19  5d                   pop ebp
// 00437a1a  7409                 je 0x437a25
// 00437a1c  50                   push eax
// 00437a1d  e8ce661e00           call 0x61e0f0
// 00437a22  83c404               add esp, 4
// 00437a25  8b542404             mov edx, dword ptr [esp + 4]
// 00437a29  8b442410             mov eax, dword ptr [esp + 0x10]
// 00437a2d  014308               add dword ptr [ebx + 8], eax
// 00437a30  895304               mov dword ptr [ebx + 4], edx
// 00437a33  5b                   pop ebx
// 00437a34  83c408               add esp, 8
// 00437a37  c20400               ret 4
// standard library deque<ptr> (function ?_Growmap@?$deque@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEXI@Z)

// stl: deque<ptr>
struct T; typedef T* E;
#include <deque>
template class std::deque<E>;
