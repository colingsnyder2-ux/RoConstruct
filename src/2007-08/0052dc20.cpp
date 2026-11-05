// from server: 100% by auto
// roc 2007-08 0052dc20  unit: RBX::VRunService::?$FactoryProduct  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0052dc20
//
// 0052dc20  83ec0c               sub esp, 0xc
// 0052dc23  55                   push ebp
// 0052dc24  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 0052dc28  56                   push esi
// 0052dc29  57                   push edi
// 0052dc2a  8bf9                 mov edi, ecx
// 0052dc2c  8b7704               mov esi, dword ptr [edi + 4]
// 0052dc2f  8b4604               mov eax, dword ptr [esi + 4]
// 0052dc32  80781500             cmp byte ptr [eax + 0x15], 0
// 0052dc36  b101                 mov cl, 1
// 0052dc38  884c240c             mov byte ptr [esp + 0xc], cl
// 0052dc3c  7520                 jne 0x52dc5e
// 0052dc3e  8b5500               mov edx, dword ptr [ebp]
// 0052dc41  3b500c               cmp edx, dword ptr [eax + 0xc]
// 0052dc44  8bf0                 mov esi, eax
// 0052dc46  0f92c1               setb cl
// 0052dc49  84c9                 test cl, cl
// 0052dc4b  884c240c             mov byte ptr [esp + 0xc], cl
// 0052dc4f  7404                 je 0x52dc55
// 0052dc51  8b00                 mov eax, dword ptr [eax]
// 0052dc53  eb03                 jmp 0x52dc58
// 0052dc55  8b4008               mov eax, dword ptr [eax + 8]
// 0052dc58  80781500             cmp byte ptr [eax + 0x15], 0
// 0052dc5c  74e3                 je 0x52dc41
// 0052dc5e  84c9                 test cl, cl
// 0052dc60  8bd6                 mov edx, esi
// 0052dc62  89542414             mov dword ptr [esp + 0x14], edx
// 0052dc66  897c2410             mov dword ptr [esp + 0x10], edi
// 0052dc6a  743d                 je 0x52dca9
// 0052dc6c  8b4704               mov eax, dword ptr [edi + 4]
// 0052dc6f  3b30                 cmp esi, dword ptr [eax]
// 0052dc71  8d4c2410             lea ecx, [esp + 0x10]
// 0052dc75  7529                 jne 0x52dca0
// 0052dc77  55                   push ebp
// 0052dc78  56                   push esi
// 0052dc79  6a01                 push 1
// 0052dc7b  51                   push ecx
// 0052dc7c  8bcf                 mov ecx, edi
// 0052dc7e  e8ad5d0500           call 0x583a30
// 0052dc83  8bc8                 mov ecx, eax
// 0052dc85  8b11                 mov edx, dword ptr [ecx]
// 0052dc87  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0052dc8b  8b4904               mov ecx, dword ptr [ecx + 4]
// 0052dc8e  5f                   pop edi
// 0052dc8f  5e                   pop esi
// 0052dc90  8910                 mov dword ptr [eax], edx
// 0052dc92  894804               mov dword ptr [eax + 4], ecx
// 0052dc95  c6400801             mov byte ptr [eax + 8], 1
// 0052dc99  5d                   pop ebp
// 0052dc9a  83c40c               add esp, 0xc
// 0052dc9d  c20800               ret 8
// 0052dca0  e88b15fcff           call 0x4ef230
// 0052dca5  8b542414             mov edx, dword ptr [esp + 0x14]
// 0052dca9  8b420c               mov eax, dword ptr [edx + 0xc]
// 0052dcac  3b4500               cmp eax, dword ptr [ebp]
// 0052dcaf  730e                 jae 0x52dcbf
// 0052dcb1  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0052dcb5  55                   push ebp
// 0052dcb6  56                   push esi
// 0052dcb7  51                   push ecx
// 0052dcb8  8d54241c             lea edx, [esp + 0x1c]
// 0052dcbc  52                   push edx
// 0052dcbd  ebbd                 jmp 0x52dc7c
// 0052dcbf  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0052dcc3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0052dcc7  5f                   pop edi
// 0052dcc8  5e                   pop esi
// 0052dcc9  8908                 mov dword ptr [eax], ecx
// 0052dccb  895004               mov dword ptr [eax + 4], edx
// 0052dcce  c6400800             mov byte ptr [eax + 8], 0
// 0052dcd2  5d                   pop ebp
// 0052dcd3  83c40c               add esp, 0xc
// 0052dcd6  c20800               ret 8
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@_N@2@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
