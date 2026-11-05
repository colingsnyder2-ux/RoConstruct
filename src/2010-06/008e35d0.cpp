// from server: 100% by auto
// roc 2010-06 008e35d0  unit: RBX::RbxTextureProxy  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008e35d0
//
// 008e35d0  83ec0c               sub esp, 0xc
// 008e35d3  53                   push ebx
// 008e35d4  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 008e35d8  55                   push ebp
// 008e35d9  56                   push esi
// 008e35da  57                   push edi
// 008e35db  8bf9                 mov edi, ecx
// 008e35dd  8b7718               mov esi, dword ptr [edi + 0x18]
// 008e35e0  8b4604               mov eax, dword ptr [esi + 4]
// 008e35e3  80782100             cmp byte ptr [eax + 0x21], 0
// 008e35e7  b101                 mov cl, 1
// 008e35e9  884c2410             mov byte ptr [esp + 0x10], cl
// 008e35ed  751f                 jne 0x8e360e
// 008e35ef  8b13                 mov edx, dword ptr [ebx]
// 008e35f1  3b500c               cmp edx, dword ptr [eax + 0xc]
// 008e35f4  8bf0                 mov esi, eax
// 008e35f6  0f92c1               setb cl
// 008e35f9  884c2410             mov byte ptr [esp + 0x10], cl
// 008e35fd  84c9                 test cl, cl
// 008e35ff  7404                 je 0x8e3605
// 008e3601  8b00                 mov eax, dword ptr [eax]
// 008e3603  eb03                 jmp 0x8e3608
// 008e3605  8b4008               mov eax, dword ptr [eax + 8]
// 008e3608  80782100             cmp byte ptr [eax + 0x21], 0
// 008e360c  74e3                 je 0x8e35f1
// 008e360e  8b17                 mov edx, dword ptr [edi]
// 008e3610  8bee                 mov ebp, esi
// 008e3612  896c2418             mov dword ptr [esp + 0x18], ebp
// 008e3616  89542414             mov dword ptr [esp + 0x14], edx
// 008e361a  84c9                 test cl, cl
// 008e361c  7452                 je 0x8e3670
// 008e361e  8b4718               mov eax, dword ptr [edi + 0x18]
// 008e3621  8b28                 mov ebp, dword ptr [eax]
// 008e3623  85d2                 test edx, edx
// 008e3625  7404                 je 0x8e362b
// 008e3627  3bd2                 cmp edx, edx
// 008e3629  7406                 je 0x8e3631
// 008e362b  ff150ca99e00         call dword ptr [0x9ea90c]
// 008e3631  8d4c2414             lea ecx, [esp + 0x14]
// 008e3635  3bf5                 cmp esi, ebp
// 008e3637  752a                 jne 0x8e3663
// 008e3639  53                   push ebx
// 008e363a  56                   push esi
// 008e363b  6a01                 push 1
// 008e363d  51                   push ecx
// 008e363e  8bcf                 mov ecx, edi
// 008e3640  e88bfdffff           call 0x8e33d0
// 008e3645  5f                   pop edi
// 008e3646  8bc8                 mov ecx, eax
// 008e3648  8b11                 mov edx, dword ptr [ecx]
// 008e364a  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e364e  8b4904               mov ecx, dword ptr [ecx + 4]
// 008e3651  5e                   pop esi
// 008e3652  5d                   pop ebp
// 008e3653  894804               mov dword ptr [eax + 4], ecx
// 008e3656  c6400801             mov byte ptr [eax + 8], 1
// 008e365a  8910                 mov dword ptr [eax], edx
// 008e365c  5b                   pop ebx
// 008e365d  83c40c               add esp, 0xc
// 008e3660  c20800               ret 8
// 008e3663  e8b899c4ff           call 0x52d020
// 008e3668  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 008e366c  8b542414             mov edx, dword ptr [esp + 0x14]
// 008e3670  8b450c               mov eax, dword ptr [ebp + 0xc]
// 008e3673  3b03                 cmp eax, dword ptr [ebx]
// 008e3675  7331                 jae 0x8e36a8
// 008e3677  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 008e367b  53                   push ebx
// 008e367c  56                   push esi
// 008e367d  51                   push ecx
// 008e367e  8d542420             lea edx, [esp + 0x20]
// 008e3682  52                   push edx
// 008e3683  8bcf                 mov ecx, edi
// 008e3685  e846fdffff           call 0x8e33d0
// 008e368a  5f                   pop edi
// 008e368b  8bc8                 mov ecx, eax
// 008e368d  8b11                 mov edx, dword ptr [ecx]
// 008e368f  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008e3693  8b4904               mov ecx, dword ptr [ecx + 4]
// 008e3696  5e                   pop esi
// 008e3697  5d                   pop ebp
// 008e3698  894804               mov dword ptr [eax + 4], ecx
// 008e369b  c6400801             mov byte ptr [eax + 8], 1
// 008e369f  8910                 mov dword ptr [eax], edx
// 008e36a1  5b                   pop ebx
// 008e36a2  83c40c               add esp, 0xc
// 008e36a5  c20800               ret 8
// 008e36a8  8b442420             mov eax, dword ptr [esp + 0x20]
// 008e36ac  5f                   pop edi
// 008e36ad  5e                   pop esi
// 008e36ae  896804               mov dword ptr [eax + 4], ebp
// 008e36b1  5d                   pop ebp
// 008e36b2  c6400800             mov byte ptr [eax + 8], 0
// 008e36b6  8910                 mov dword ptr [eax], edx
// 008e36b8  5b                   pop ebx
// 008e36b9  83c40c               add esp, 0xc
// 008e36bc  c20800               ret 8
// standard library map_ptr<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod16>
struct E { int v[4]; };
#include <map>
struct K; template class std::map<K*, E>;
