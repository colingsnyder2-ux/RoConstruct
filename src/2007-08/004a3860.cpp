// from server: 100% by auto
// roc 2007-08 004a3860  unit: boost::Vmutex::?$sp_counted_impl_p  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004a3860
//
// 004a3860  83ec0c               sub esp, 0xc
// 004a3863  55                   push ebp
// 004a3864  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004a3868  56                   push esi
// 004a3869  57                   push edi
// 004a386a  8bf9                 mov edi, ecx
// 004a386c  8b7704               mov esi, dword ptr [edi + 4]
// 004a386f  8b4604               mov eax, dword ptr [esi + 4]
// 004a3872  80781500             cmp byte ptr [eax + 0x15], 0
// 004a3876  b101                 mov cl, 1
// 004a3878  884c240c             mov byte ptr [esp + 0xc], cl
// 004a387c  7520                 jne 0x4a389e
// 004a387e  8b5500               mov edx, dword ptr [ebp]
// 004a3881  3b500c               cmp edx, dword ptr [eax + 0xc]
// 004a3884  8bf0                 mov esi, eax
// 004a3886  0f9cc1               setl cl
// 004a3889  84c9                 test cl, cl
// 004a388b  884c240c             mov byte ptr [esp + 0xc], cl
// 004a388f  7404                 je 0x4a3895
// 004a3891  8b00                 mov eax, dword ptr [eax]
// 004a3893  eb03                 jmp 0x4a3898
// 004a3895  8b4008               mov eax, dword ptr [eax + 8]
// 004a3898  80781500             cmp byte ptr [eax + 0x15], 0
// 004a389c  74e3                 je 0x4a3881
// 004a389e  84c9                 test cl, cl
// 004a38a0  8bd6                 mov edx, esi
// 004a38a2  89542414             mov dword ptr [esp + 0x14], edx
// 004a38a6  897c2410             mov dword ptr [esp + 0x10], edi
// 004a38aa  743d                 je 0x4a38e9
// 004a38ac  8b4704               mov eax, dword ptr [edi + 4]
// 004a38af  3b30                 cmp esi, dword ptr [eax]
// 004a38b1  8d4c2410             lea ecx, [esp + 0x10]
// 004a38b5  7529                 jne 0x4a38e0
// 004a38b7  55                   push ebp
// 004a38b8  56                   push esi
// 004a38b9  6a01                 push 1
// 004a38bb  51                   push ecx
// 004a38bc  8bcf                 mov ecx, edi
// 004a38be  e8edfaf8ff           call 0x4333b0
// 004a38c3  8bc8                 mov ecx, eax
// 004a38c5  8b11                 mov edx, dword ptr [ecx]
// 004a38c7  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a38cb  8b4904               mov ecx, dword ptr [ecx + 4]
// 004a38ce  5f                   pop edi
// 004a38cf  5e                   pop esi
// 004a38d0  8910                 mov dword ptr [eax], edx
// 004a38d2  894804               mov dword ptr [eax + 4], ecx
// 004a38d5  c6400801             mov byte ptr [eax + 8], 1
// 004a38d9  5d                   pop ebp
// 004a38da  83c40c               add esp, 0xc
// 004a38dd  c20800               ret 8
// 004a38e0  e84bb90400           call 0x4ef230
// 004a38e5  8b542414             mov edx, dword ptr [esp + 0x14]
// 004a38e9  8b420c               mov eax, dword ptr [edx + 0xc]
// 004a38ec  3b4500               cmp eax, dword ptr [ebp]
// 004a38ef  7d0e                 jge 0x4a38ff
// 004a38f1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004a38f5  55                   push ebp
// 004a38f6  56                   push esi
// 004a38f7  51                   push ecx
// 004a38f8  8d54241c             lea edx, [esp + 0x1c]
// 004a38fc  52                   push edx
// 004a38fd  ebbd                 jmp 0x4a38bc
// 004a38ff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 004a3903  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004a3907  5f                   pop edi
// 004a3908  5e                   pop esi
// 004a3909  8908                 mov dword ptr [eax], ecx
// 004a390b  895004               mov dword ptr [eax + 4], edx
// 004a390e  c6400800             mov byte ptr [eax + 8], 0
// 004a3912  5d                   pop ebp
// 004a3913  83c40c               add esp, 0xc
// 004a3916  c20800               ret 8
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
