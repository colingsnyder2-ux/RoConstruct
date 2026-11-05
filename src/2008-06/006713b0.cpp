// from server: 100% by auto
// roc 2008-06 006713b0  unit: RBX::AdornRbxGfx  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006713b0
//
// 006713b0  83ec14               sub esp, 0x14
// 006713b3  56                   push esi
// 006713b4  8bf1                 mov esi, ecx
// 006713b6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006713ba  57                   push edi
// 006713bb  7521                 jne 0x6713de
// 006713bd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006713c1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 006713c4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 006713c8  50                   push eax
// 006713c9  51                   push ecx
// 006713ca  6a01                 push 1
// 006713cc  57                   push edi
// 006713cd  8bce                 mov ecx, esi
// 006713cf  e8bc090200           call 0x691d90
// 006713d4  8bc7                 mov eax, edi
// 006713d6  5f                   pop edi
// 006713d7  5e                   pop esi
// 006713d8  83c414               add esp, 0x14
// 006713db  c21000               ret 0x10
// 006713de  8b442424             mov eax, dword ptr [esp + 0x24]
// 006713e2  8b5618               mov edx, dword ptr [esi + 0x18]
// 006713e5  8b3a                 mov edi, dword ptr [edx]
// 006713e7  8b0e                 mov ecx, dword ptr [esi]
// 006713e9  53                   push ebx
// 006713ea  8b1d90288000         mov ebx, dword ptr [0x802890]
// 006713f0  85c0                 test eax, eax
// 006713f2  7404                 je 0x6713f8
// 006713f4  3bc1                 cmp eax, ecx
// 006713f6  7406                 je 0x6713fe
// 006713f8  ffd3                 call ebx
// 006713fa  8b442428             mov eax, dword ptr [esp + 0x28]
// 006713fe  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00671402  55                   push ebp
// 00671403  3bd7                 cmp edx, edi
// 00671405  753a                 jne 0x671441
// 00671407  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0067140b  83c20c               add edx, 0xc
// 0067140e  52                   push edx
// 0067140f  57                   push edi
// 00671410  ff155c238000         call dword ptr [0x80235c]
// 00671416  83c408               add esp, 8
// 00671419  84c0                 test al, al
// 0067141b  0f849a010000         je 0x6715bb
// 00671421  8b442430             mov eax, dword ptr [esp + 0x30]
// 00671425  57                   push edi
// 00671426  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0067142a  50                   push eax
// 0067142b  6a01                 push 1
// 0067142d  57                   push edi
// 0067142e  8bce                 mov ecx, esi
// 00671430  e85b090200           call 0x691d90
// 00671435  5d                   pop ebp
// 00671436  5b                   pop ebx
// 00671437  8bc7                 mov eax, edi
// 00671439  5f                   pop edi
// 0067143a  5e                   pop esi
// 0067143b  83c414               add esp, 0x14
// 0067143e  c21000               ret 0x10
// 00671441  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00671444  8b0e                 mov ecx, dword ptr [esi]
// 00671446  85c0                 test eax, eax
// 00671448  7404                 je 0x67144e
// 0067144a  3bc1                 cmp eax, ecx
// 0067144c  7406                 je 0x671454
// 0067144e  ffd3                 call ebx
// 00671450  8b542430             mov edx, dword ptr [esp + 0x30]
// 00671454  3bd7                 cmp edx, edi
// 00671456  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0067145a  753e                 jne 0x67149a
// 0067145c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0067145f  8b4108               mov eax, dword ptr [ecx + 8]
// 00671462  83c00c               add eax, 0xc
// 00671465  57                   push edi
// 00671466  50                   push eax
// 00671467  ff155c238000         call dword ptr [0x80235c]
// 0067146d  83c408               add esp, 8
// 00671470  84c0                 test al, al
// 00671472  0f8443010000         je 0x6715bb
// 00671478  8b5618               mov edx, dword ptr [esi + 0x18]
// 0067147b  8b4208               mov eax, dword ptr [edx + 8]
// 0067147e  57                   push edi
// 0067147f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00671483  50                   push eax
// 00671484  6a00                 push 0
// 00671486  57                   push edi
// 00671487  8bce                 mov ecx, esi
// 00671489  e802090200           call 0x691d90
// 0067148e  5d                   pop ebp
// 0067148f  5b                   pop ebx
// 00671490  8bc7                 mov eax, edi
// 00671492  5f                   pop edi
// 00671493  5e                   pop esi
// 00671494  83c414               add esp, 0x14
// 00671497  c21000               ret 0x10
// 0067149a  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 006714a0  83c20c               add edx, 0xc
// 006714a3  52                   push edx
// 006714a4  57                   push edi
// 006714a5  ffd5                 call ebp
// 006714a7  83c408               add esp, 8
// 006714aa  84c0                 test al, al
// 006714ac  746c                 je 0x67151a
// 006714ae  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006714b2  8b542430             mov edx, dword ptr [esp + 0x30]
// 006714b6  894c2410             mov dword ptr [esp + 0x10], ecx
// 006714ba  8d4c2410             lea ecx, [esp + 0x10]
// 006714be  89542414             mov dword ptr [esp + 0x14], edx
// 006714c2  e889be0100           call 0x68d350
// 006714c7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 006714cb  57                   push edi
// 006714cc  8d430c               lea eax, [ebx + 0xc]
// 006714cf  50                   push eax
// 006714d0  8d4e08               lea ecx, [esi + 8]
// 006714d3  e828abeeff           call 0x55c000
// 006714d8  84c0                 test al, al
// 006714da  743e                 je 0x67151a
// 006714dc  8b4b08               mov ecx, dword ptr [ebx + 8]
// 006714df  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 006714e3  57                   push edi
// 006714e4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 006714e8  8bce                 mov ecx, esi
// 006714ea  7415                 je 0x671501
// 006714ec  53                   push ebx
// 006714ed  6a00                 push 0
// 006714ef  57                   push edi
// 006714f0  e89b080200           call 0x691d90
// 006714f5  5d                   pop ebp
// 006714f6  5b                   pop ebx
// 006714f7  8bc7                 mov eax, edi
// 006714f9  5f                   pop edi
// 006714fa  5e                   pop esi
// 006714fb  83c414               add esp, 0x14
// 006714fe  c21000               ret 0x10
// 00671501  8b542434             mov edx, dword ptr [esp + 0x34]
// 00671505  52                   push edx
// 00671506  6a01                 push 1
// 00671508  57                   push edi
// 00671509  e882080200           call 0x691d90
// 0067150e  5d                   pop ebp
// 0067150f  5b                   pop ebx
// 00671510  8bc7                 mov eax, edi
// 00671512  5f                   pop edi
// 00671513  5e                   pop esi
// 00671514  83c414               add esp, 0x14
// 00671517  c21000               ret 0x10
// 0067151a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0067151e  83c00c               add eax, 0xc
// 00671521  57                   push edi
// 00671522  50                   push eax
// 00671523  ffd5                 call ebp
// 00671525  83c408               add esp, 8
// 00671528  84c0                 test al, al
// 0067152a  0f848b000000         je 0x6715bb
// 00671530  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00671534  8b542430             mov edx, dword ptr [esp + 0x30]
// 00671538  8b4618               mov eax, dword ptr [esi + 0x18]
// 0067153b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0067153f  8b0e                 mov ecx, dword ptr [esi]
// 00671541  894c2418             mov dword ptr [esp + 0x18], ecx
// 00671545  8d4c2410             lea ecx, [esp + 0x10]
// 00671549  89542414             mov dword ptr [esp + 0x14], edx
// 0067154d  8944241c             mov dword ptr [esp + 0x1c], eax
// 00671551  e84abc0100           call 0x68d1a0
// 00671556  8d542418             lea edx, [esp + 0x18]
// 0067155a  52                   push edx
// 0067155b  8d4c2414             lea ecx, [esp + 0x14]
// 0067155f  e83cb7f7ff           call 0x5ecca0
// 00671564  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00671568  84c0                 test al, al
// 0067156a  7511                 jne 0x67157d
// 0067156c  8d430c               lea eax, [ebx + 0xc]
// 0067156f  50                   push eax
// 00671570  57                   push edi
// 00671571  8d4e08               lea ecx, [esi + 8]
// 00671574  e887aaeeff           call 0x55c000
// 00671579  84c0                 test al, al
// 0067157b  743e                 je 0x6715bb
// 0067157d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00671581  8b4808               mov ecx, dword ptr [eax + 8]
// 00671584  80792d00             cmp byte ptr [ecx + 0x2d], 0
// 00671588  57                   push edi
// 00671589  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0067158d  8bce                 mov ecx, esi
// 0067158f  7415                 je 0x6715a6
// 00671591  50                   push eax
// 00671592  6a00                 push 0
// 00671594  57                   push edi
// 00671595  e8f6070200           call 0x691d90
// 0067159a  5d                   pop ebp
// 0067159b  5b                   pop ebx
// 0067159c  8bc7                 mov eax, edi
// 0067159e  5f                   pop edi
// 0067159f  5e                   pop esi
// 006715a0  83c414               add esp, 0x14
// 006715a3  c21000               ret 0x10
// 006715a6  53                   push ebx
// 006715a7  6a01                 push 1
// 006715a9  57                   push edi
// 006715aa  e8e1070200           call 0x691d90
// 006715af  5d                   pop ebp
// 006715b0  5b                   pop ebx
// 006715b1  8bc7                 mov eax, edi
// 006715b3  5f                   pop edi
// 006715b4  5e                   pop esi
// 006715b5  83c414               add esp, 0x14
// 006715b8  c21000               ret 0x10
// 006715bb  57                   push edi
// 006715bc  8d54241c             lea edx, [esp + 0x1c]
// 006715c0  52                   push edx
// 006715c1  8bce                 mov ecx, esi
// 006715c3  e808270200           call 0x693cd0
// 006715c8  8b10                 mov edx, dword ptr [eax]
// 006715ca  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006715ce  5d                   pop ebp
// 006715cf  5b                   pop ebx
// 006715d0  8911                 mov dword ptr [ecx], edx
// 006715d2  8b4004               mov eax, dword ptr [eax + 4]
// 006715d5  5f                   pop edi
// 006715d6  894104               mov dword ptr [ecx + 4], eax
// 006715d9  8bc1                 mov eax, ecx
// 006715db  5e                   pop esi
// 006715dc  83c414               add esp, 0x14
// 006715df  c21000               ret 0x10
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
