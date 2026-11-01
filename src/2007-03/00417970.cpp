// from server: 100% by auto
// roc 2007-03 00417970  unit: seg_00410000  size: 343 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00417970
//
// 00417970  8b542404             mov edx, dword ptr [esp + 4]
// 00417974  83ec08               sub esp, 8
// 00417977  53                   push ebx
// 00417978  8bd9                 mov ebx, ecx
// 0041797a  8b4308               mov eax, dword ptr [ebx + 8]
// 0041797d  b955555515           mov ecx, 0x15555555
// 00417982  2bc8                 sub ecx, eax
// 00417984  3bca                 cmp ecx, edx
// 00417986  7305                 jae 0x41798d
// 00417988  e80313ffff           call 0x408c90
// 0041798d  8bc8                 mov ecx, eax
// 0041798f  d1e9                 shr ecx, 1
// 00417991  83f908               cmp ecx, 8
// 00417994  7305                 jae 0x41799b
// 00417996  b908000000           mov ecx, 8
// 0041799b  3bd1                 cmp edx, ecx
// 0041799d  55                   push ebp
// 0041799e  56                   push esi
// 0041799f  57                   push edi
// 004179a0  7311                 jae 0x4179b3
// 004179a2  be55555515           mov esi, 0x15555555
// 004179a7  2bf1                 sub esi, ecx
// 004179a9  3bc6                 cmp eax, esi
// 004179ab  7706                 ja 0x4179b3
// 004179ad  894c241c             mov dword ptr [esp + 0x1c], ecx
// 004179b1  8bd1                 mov edx, ecx
// 004179b3  8b6b0c               mov ebp, dword ptr [ebx + 0xc]
// 004179b6  03c2                 add eax, edx
// 004179b8  6a00                 push 0
// 004179ba  50                   push eax
// 004179bb  e8a0130000           call 0x418d60
// 004179c0  8b4b04               mov ecx, dword ptr [ebx + 4]
// 004179c3  89442418             mov dword ptr [esp + 0x18], eax
// 004179c7  8d34ad00000000       lea esi, [ebp*4]
// 004179ce  8d3c06               lea edi, [esi + eax]
// 004179d1  8b4308               mov eax, dword ptr [ebx + 8]
// 004179d4  03c0                 add eax, eax
// 004179d6  03c0                 add eax, eax
// 004179d8  8d140e               lea edx, [esi + ecx]
// 004179db  2bc2                 sub eax, edx
// 004179dd  03c1                 add eax, ecx
// 004179df  83c408               add esp, 8
// 004179e2  c1f802               sar eax, 2
// 004179e5  8d048500000000       lea eax, [eax*4]
// 004179ec  8d0c38               lea ecx, [eax + edi]
// 004179ef  894c2414             mov dword ptr [esp + 0x14], ecx
// 004179f3  7415                 je 0x417a0a
// 004179f5  50                   push eax
// 004179f6  52                   push edx
// 004179f7  50                   push eax
// 004179f8  57                   push edi
// 004179f9  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 004179ff  ffd7                 call edi
// 00417a01  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00417a05  83c410               add esp, 0x10
// 00417a08  eb06                 jmp 0x417a10
// 00417a0a  8b3d78e97700         mov edi, dword ptr [0x77e978]
// 00417a10  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00417a14  3be8                 cmp ebp, eax
// 00417a16  7735                 ja 0x417a4d
// 00417a18  8b4304               mov eax, dword ptr [ebx + 4]
// 00417a1b  c1fe02               sar esi, 2
// 00417a1e  8d14b500000000       lea edx, [esi*4]
// 00417a25  8d340a               lea esi, [edx + ecx]
// 00417a28  7409                 je 0x417a33
// 00417a2a  52                   push edx
// 00417a2b  50                   push eax
// 00417a2c  52                   push edx
// 00417a2d  51                   push ecx
// 00417a2e  ffd7                 call edi
// 00417a30  83c410               add esp, 0x10
// 00417a33  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00417a37  2bcd                 sub ecx, ebp
// 00417a39  7406                 je 0x417a41
// 00417a3b  33c0                 xor eax, eax
// 00417a3d  8bfe                 mov edi, esi
// 00417a3f  f3ab                 rep stosd dword ptr es:[edi], eax
// 00417a41  85ed                 test ebp, ebp
// 00417a43  765a                 jbe 0x417a9f
// 00417a45  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00417a49  8bcd                 mov ecx, ebp
// 00417a4b  eb4e                 jmp 0x417a9b
// 00417a4d  8b5304               mov edx, dword ptr [ebx + 4]
// 00417a50  8d2c8500000000       lea ebp, [eax*4]
// 00417a57  8bc5                 mov eax, ebp
// 00417a59  c1f802               sar eax, 2
// 00417a5c  740d                 je 0x417a6b
// 00417a5e  03c0                 add eax, eax
// 00417a60  03c0                 add eax, eax
// 00417a62  50                   push eax
// 00417a63  52                   push edx
// 00417a64  50                   push eax
// 00417a65  51                   push ecx
// 00417a66  ffd7                 call edi
// 00417a68  83c410               add esp, 0x10
// 00417a6b  8b4304               mov eax, dword ptr [ebx + 4]
// 00417a6e  8b542410             mov edx, dword ptr [esp + 0x10]
// 00417a72  8d0c28               lea ecx, [eax + ebp]
// 00417a75  2bf1                 sub esi, ecx
// 00417a77  03f0                 add esi, eax
// 00417a79  c1fe02               sar esi, 2
// 00417a7c  8d04b500000000       lea eax, [esi*4]
// 00417a83  8d3410               lea esi, [eax + edx]
// 00417a86  7409                 je 0x417a91
// 00417a88  50                   push eax
// 00417a89  51                   push ecx
// 00417a8a  50                   push eax
// 00417a8b  52                   push edx
// 00417a8c  ffd7                 call edi
// 00417a8e  83c410               add esp, 0x10
// 00417a91  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00417a95  85c9                 test ecx, ecx
// 00417a97  7606                 jbe 0x417a9f
// 00417a99  8bfe                 mov edi, esi
// 00417a9b  33c0                 xor eax, eax
// 00417a9d  f3ab                 rep stosd dword ptr es:[edi], eax
// 00417a9f  8b4304               mov eax, dword ptr [ebx + 4]
// 00417aa2  85c0                 test eax, eax
// 00417aa4  5f                   pop edi
// 00417aa5  5e                   pop esi
// 00417aa6  5d                   pop ebp
// 00417aa7  7409                 je 0x417ab2
// 00417aa9  50                   push eax
// 00417aaa  e841662000           call 0x61e0f0
// 00417aaf  83c404               add esp, 4
// 00417ab2  8b542404             mov edx, dword ptr [esp + 4]
// 00417ab6  8b442410             mov eax, dword ptr [esp + 0x10]
// 00417aba  014308               add dword ptr [ebx + 8], eax
// 00417abd  895304               mov dword ptr [ebx + 4], edx
// 00417ac0  5b                   pop ebx
// 00417ac1  83c408               add esp, 8
// 00417ac4  c20400               ret 4
// standard library deque<pod12> (function ?_Growmap@?$deque@UE@@V?$allocator@UE@@@std@@@std@@IAEXI@Z)

// stl: deque<pod12>
struct E { int v[3]; };
#include <deque>
template class std::deque<E>;
