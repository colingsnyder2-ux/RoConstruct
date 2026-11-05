// from server: 100% by auto
// roc 2007-08 00433770  unit: RBX::CMarshalWindow  size: 446 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00433770
//
// 00433770  83ec0c               sub esp, 0xc
// 00433773  56                   push esi
// 00433774  8bf1                 mov esi, ecx
// 00433776  837e0800             cmp dword ptr [esi + 8], 0
// 0043377a  57                   push edi
// 0043377b  7521                 jne 0x43379e
// 0043377d  8b442424             mov eax, dword ptr [esp + 0x24]
// 00433781  8b4e04               mov ecx, dword ptr [esi + 4]
// 00433784  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 00433788  50                   push eax
// 00433789  51                   push ecx
// 0043378a  6a01                 push 1
// 0043378c  57                   push edi
// 0043378d  8bce                 mov ecx, esi
// 0043378f  e81cfcffff           call 0x4333b0
// 00433794  8bc7                 mov eax, edi
// 00433796  5f                   pop edi
// 00433797  5e                   pop esi
// 00433798  83c40c               add esp, 0xc
// 0043379b  c21000               ret 0x10
// 0043379e  8b5604               mov edx, dword ptr [esi + 4]
// 004337a1  8b3a                 mov edi, dword ptr [edx]
// 004337a3  55                   push ebp
// 004337a4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 004337a8  85ed                 test ebp, ebp
// 004337aa  7404                 je 0x4337b0
// 004337ac  3bee                 cmp ebp, esi
// 004337ae  7406                 je 0x4337b6
// 004337b0  ff15d8e67700         call dword ptr [0x77e6d8]
// 004337b6  53                   push ebx
// 004337b7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 004337bb  3bdf                 cmp ebx, edi
// 004337bd  752b                 jne 0x4337ea
// 004337bf  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 004337c3  8b07                 mov eax, dword ptr [edi]
// 004337c5  3b430c               cmp eax, dword ptr [ebx + 0xc]
// 004337c8  0f8339010000         jae 0x433907
// 004337ce  57                   push edi
// 004337cf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004337d3  53                   push ebx
// 004337d4  6a01                 push 1
// 004337d6  57                   push edi
// 004337d7  8bce                 mov ecx, esi
// 004337d9  e8d2fbffff           call 0x4333b0
// 004337de  5b                   pop ebx
// 004337df  5d                   pop ebp
// 004337e0  8bc7                 mov eax, edi
// 004337e2  5f                   pop edi
// 004337e3  5e                   pop esi
// 004337e4  83c40c               add esp, 0xc
// 004337e7  c21000               ret 0x10
// 004337ea  85ed                 test ebp, ebp
// 004337ec  8b7e04               mov edi, dword ptr [esi + 4]
// 004337ef  7404                 je 0x4337f5
// 004337f1  3bee                 cmp ebp, esi
// 004337f3  7406                 je 0x4337fb
// 004337f5  ff15d8e67700         call dword ptr [0x77e6d8]
// 004337fb  3bdf                 cmp ebx, edi
// 004337fd  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00433801  752d                 jne 0x433830
// 00433803  8b4e04               mov ecx, dword ptr [esi + 4]
// 00433806  8b4108               mov eax, dword ptr [ecx + 8]
// 00433809  8b500c               mov edx, dword ptr [eax + 0xc]
// 0043380c  3b17                 cmp edx, dword ptr [edi]
// 0043380e  0f83f3000000         jae 0x433907
// 00433814  57                   push edi
// 00433815  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00433819  50                   push eax
// 0043381a  6a00                 push 0
// 0043381c  57                   push edi
// 0043381d  8bce                 mov ecx, esi
// 0043381f  e88cfbffff           call 0x4333b0
// 00433824  5b                   pop ebx
// 00433825  5d                   pop ebp
// 00433826  8bc7                 mov eax, edi
// 00433828  5f                   pop edi
// 00433829  5e                   pop esi
// 0043382a  83c40c               add esp, 0xc
// 0043382d  c21000               ret 0x10
// 00433830  8b07                 mov eax, dword ptr [edi]
// 00433832  39430c               cmp dword ptr [ebx + 0xc], eax
// 00433835  765b                 jbe 0x433892
// 00433837  8d4c2424             lea ecx, [esp + 0x24]
// 0043383b  896c2424             mov dword ptr [esp + 0x24], ebp
// 0043383f  895c2428             mov dword ptr [esp + 0x28], ebx
// 00433843  e8e8b90b00           call 0x4ef230
// 00433848  8b07                 mov eax, dword ptr [edi]
// 0043384a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0043384e  39410c               cmp dword ptr [ecx + 0xc], eax
// 00433851  733c                 jae 0x43388f
// 00433853  8b4108               mov eax, dword ptr [ecx + 8]
// 00433856  80781500             cmp byte ptr [eax + 0x15], 0
// 0043385a  57                   push edi
// 0043385b  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043385f  7417                 je 0x433878
// 00433861  51                   push ecx
// 00433862  6a00                 push 0
// 00433864  57                   push edi
// 00433865  8bce                 mov ecx, esi
// 00433867  e844fbffff           call 0x4333b0
// 0043386c  5b                   pop ebx
// 0043386d  5d                   pop ebp
// 0043386e  8bc7                 mov eax, edi
// 00433870  5f                   pop edi
// 00433871  5e                   pop esi
// 00433872  83c40c               add esp, 0xc
// 00433875  c21000               ret 0x10
// 00433878  53                   push ebx
// 00433879  6a01                 push 1
// 0043387b  57                   push edi
// 0043387c  8bce                 mov ecx, esi
// 0043387e  e82dfbffff           call 0x4333b0
// 00433883  5b                   pop ebx
// 00433884  5d                   pop ebp
// 00433885  8bc7                 mov eax, edi
// 00433887  5f                   pop edi
// 00433888  5e                   pop esi
// 00433889  83c40c               add esp, 0xc
// 0043388c  c21000               ret 0x10
// 0043388f  39430c               cmp dword ptr [ebx + 0xc], eax
// 00433892  7373                 jae 0x433907
// 00433894  8b4e04               mov ecx, dword ptr [esi + 4]
// 00433897  894c2414             mov dword ptr [esp + 0x14], ecx
// 0043389b  8d4c2424             lea ecx, [esp + 0x24]
// 0043389f  896c2424             mov dword ptr [esp + 0x24], ebp
// 004338a3  895c2428             mov dword ptr [esp + 0x28], ebx
// 004338a7  89742410             mov dword ptr [esp + 0x10], esi
// 004338ab  e800560000           call 0x438eb0
// 004338b0  8d542410             lea edx, [esp + 0x10]
// 004338b4  52                   push edx
// 004338b5  8d4c2428             lea ecx, [esp + 0x28]
// 004338b9  e8f2310300           call 0x466ab0
// 004338be  84c0                 test al, al
// 004338c0  8b442428             mov eax, dword ptr [esp + 0x28]
// 004338c4  7507                 jne 0x4338cd
// 004338c6  8b0f                 mov ecx, dword ptr [edi]
// 004338c8  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004338cb  733a                 jae 0x433907
// 004338cd  8b5308               mov edx, dword ptr [ebx + 8]
// 004338d0  807a1500             cmp byte ptr [edx + 0x15], 0
// 004338d4  57                   push edi
// 004338d5  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004338d9  8bce                 mov ecx, esi
// 004338db  7415                 je 0x4338f2
// 004338dd  53                   push ebx
// 004338de  6a00                 push 0
// 004338e0  57                   push edi
// 004338e1  e8cafaffff           call 0x4333b0
// 004338e6  5b                   pop ebx
// 004338e7  5d                   pop ebp
// 004338e8  8bc7                 mov eax, edi
// 004338ea  5f                   pop edi
// 004338eb  5e                   pop esi
// 004338ec  83c40c               add esp, 0xc
// 004338ef  c21000               ret 0x10
// 004338f2  50                   push eax
// 004338f3  6a01                 push 1
// 004338f5  57                   push edi
// 004338f6  e8b5faffff           call 0x4333b0
// 004338fb  5b                   pop ebx
// 004338fc  5d                   pop ebp
// 004338fd  8bc7                 mov eax, edi
// 004338ff  5f                   pop edi
// 00433900  5e                   pop esi
// 00433901  83c40c               add esp, 0xc
// 00433904  c21000               ret 0x10
// 00433907  57                   push edi
// 00433908  8d442414             lea eax, [esp + 0x14]
// 0043390c  50                   push eax
// 0043390d  8bce                 mov ecx, esi
// 0043390f  e88cfcffff           call 0x4335a0
// 00433914  8b10                 mov edx, dword ptr [eax]
// 00433916  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0043391a  5b                   pop ebx
// 0043391b  5d                   pop ebp
// 0043391c  8911                 mov dword ptr [ecx], edx
// 0043391e  8b4004               mov eax, dword ptr [eax + 4]
// 00433921  5f                   pop edi
// 00433922  894104               mov dword ptr [ecx + 4], eax
// 00433925  8bc1                 mov eax, ecx
// 00433927  5e                   pop esi
// 00433928  83c40c               add esp, 0xc
// 0043392b  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
