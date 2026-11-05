// from server: 100% by auto
// roc 2009-12 00445250  unit: RBX::Reflection::M::?$TypedPropertyDescriptor  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00445250
//
// 00445250  83ec14               sub esp, 0x14
// 00445253  56                   push esi
// 00445254  8bf1                 mov esi, ecx
// 00445256  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0044525a  57                   push edi
// 0044525b  7521                 jne 0x44527e
// 0044525d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00445261  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00445264  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00445268  50                   push eax
// 00445269  51                   push ecx
// 0044526a  6a01                 push 1
// 0044526c  57                   push edi
// 0044526d  8bce                 mov ecx, esi
// 0044526f  e8ac802600           call 0x6ad320
// 00445274  8bc7                 mov eax, edi
// 00445276  5f                   pop edi
// 00445277  5e                   pop esi
// 00445278  83c414               add esp, 0x14
// 0044527b  c21000               ret 0x10
// 0044527e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00445282  8b5618               mov edx, dword ptr [esi + 0x18]
// 00445285  8b3a                 mov edi, dword ptr [edx]
// 00445287  8b06                 mov eax, dword ptr [esi]
// 00445289  53                   push ebx
// 0044528a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00445290  85c9                 test ecx, ecx
// 00445292  7404                 je 0x445298
// 00445294  3bc8                 cmp ecx, eax
// 00445296  7406                 je 0x44529e
// 00445298  ffd3                 call ebx
// 0044529a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044529e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004452a2  3bc7                 cmp eax, edi
// 004452a4  752a                 jne 0x4452d0
// 004452a6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004452aa  8b0f                 mov ecx, dword ptr [edi]
// 004452ac  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 004452af  0f834b010000         jae 0x445400
// 004452b5  57                   push edi
// 004452b6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004452ba  50                   push eax
// 004452bb  6a01                 push 1
// 004452bd  57                   push edi
// 004452be  8bce                 mov ecx, esi
// 004452c0  e85b802600           call 0x6ad320
// 004452c5  5b                   pop ebx
// 004452c6  8bc7                 mov eax, edi
// 004452c8  5f                   pop edi
// 004452c9  5e                   pop esi
// 004452ca  83c414               add esp, 0x14
// 004452cd  c21000               ret 0x10
// 004452d0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004452d3  8b16                 mov edx, dword ptr [esi]
// 004452d5  85c9                 test ecx, ecx
// 004452d7  7404                 je 0x4452dd
// 004452d9  3bca                 cmp ecx, edx
// 004452db  740a                 je 0x4452e7
// 004452dd  ffd3                 call ebx
// 004452df  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004452e3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004452e7  3bc7                 cmp eax, edi
// 004452e9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004452ed  752c                 jne 0x44531b
// 004452ef  8b5618               mov edx, dword ptr [esi + 0x18]
// 004452f2  8b4208               mov eax, dword ptr [edx + 8]
// 004452f5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004452f8  3b0f                 cmp ecx, dword ptr [edi]
// 004452fa  0f8300010000         jae 0x445400
// 00445300  57                   push edi
// 00445301  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00445305  50                   push eax
// 00445306  6a00                 push 0
// 00445308  57                   push edi
// 00445309  8bce                 mov ecx, esi
// 0044530b  e810802600           call 0x6ad320
// 00445310  5b                   pop ebx
// 00445311  8bc7                 mov eax, edi
// 00445313  5f                   pop edi
// 00445314  5e                   pop esi
// 00445315  83c414               add esp, 0x14
// 00445318  c21000               ret 0x10
// 0044531b  8b17                 mov edx, dword ptr [edi]
// 0044531d  39500c               cmp dword ptr [eax + 0xc], edx
// 00445320  7663                 jbe 0x445385
// 00445322  894c240c             mov dword ptr [esp + 0xc], ecx
// 00445326  8d4c240c             lea ecx, [esp + 0xc]
// 0044532a  89442410             mov dword ptr [esp + 0x10], eax
// 0044532e  e8fdeeffff           call 0x444230
// 00445333  8b17                 mov edx, dword ptr [edi]
// 00445335  8b442410             mov eax, dword ptr [esp + 0x10]
// 00445339  39500c               cmp dword ptr [eax + 0xc], edx
// 0044533c  733c                 jae 0x44537a
// 0044533e  8b5008               mov edx, dword ptr [eax + 8]
// 00445341  807a1500             cmp byte ptr [edx + 0x15], 0
// 00445345  57                   push edi
// 00445346  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0044534a  8bce                 mov ecx, esi
// 0044534c  7414                 je 0x445362
// 0044534e  50                   push eax
// 0044534f  6a00                 push 0
// 00445351  57                   push edi
// 00445352  e8c97f2600           call 0x6ad320
// 00445357  5b                   pop ebx
// 00445358  8bc7                 mov eax, edi
// 0044535a  5f                   pop edi
// 0044535b  5e                   pop esi
// 0044535c  83c414               add esp, 0x14
// 0044535f  c21000               ret 0x10
// 00445362  8b442430             mov eax, dword ptr [esp + 0x30]
// 00445366  50                   push eax
// 00445367  6a01                 push 1
// 00445369  57                   push edi
// 0044536a  e8b17f2600           call 0x6ad320
// 0044536f  5b                   pop ebx
// 00445370  8bc7                 mov eax, edi
// 00445372  5f                   pop edi
// 00445373  5e                   pop esi
// 00445374  83c414               add esp, 0x14
// 00445377  c21000               ret 0x10
// 0044537a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0044537e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00445382  39500c               cmp dword ptr [eax + 0xc], edx
// 00445385  7379                 jae 0x445400
// 00445387  8b16                 mov edx, dword ptr [esi]
// 00445389  894c240c             mov dword ptr [esp + 0xc], ecx
// 0044538d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00445390  894c2418             mov dword ptr [esp + 0x18], ecx
// 00445394  8d4c240c             lea ecx, [esp + 0xc]
// 00445398  89442410             mov dword ptr [esp + 0x10], eax
// 0044539c  89542414             mov dword ptr [esp + 0x14], edx
// 004453a0  e84b7d2600           call 0x6ad0f0
// 004453a5  8d442414             lea eax, [esp + 0x14]
// 004453a9  50                   push eax
// 004453aa  8d4c2410             lea ecx, [esp + 0x10]
// 004453ae  e8ad6f1800           call 0x5cc360
// 004453b3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004453b7  84c0                 test al, al
// 004453b9  7507                 jne 0x4453c2
// 004453bb  8b17                 mov edx, dword ptr [edi]
// 004453bd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 004453c0  733e                 jae 0x445400
// 004453c2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004453c6  8b5008               mov edx, dword ptr [eax + 8]
// 004453c9  807a1500             cmp byte ptr [edx + 0x15], 0
// 004453cd  57                   push edi
// 004453ce  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004453d2  7416                 je 0x4453ea
// 004453d4  50                   push eax
// 004453d5  6a00                 push 0
// 004453d7  57                   push edi
// 004453d8  8bce                 mov ecx, esi
// 004453da  e8417f2600           call 0x6ad320
// 004453df  5b                   pop ebx
// 004453e0  8bc7                 mov eax, edi
// 004453e2  5f                   pop edi
// 004453e3  5e                   pop esi
// 004453e4  83c414               add esp, 0x14
// 004453e7  c21000               ret 0x10
// 004453ea  51                   push ecx
// 004453eb  6a01                 push 1
// 004453ed  57                   push edi
// 004453ee  8bce                 mov ecx, esi
// 004453f0  e82b7f2600           call 0x6ad320
// 004453f5  5b                   pop ebx
// 004453f6  8bc7                 mov eax, edi
// 004453f8  5f                   pop edi
// 004453f9  5e                   pop esi
// 004453fa  83c414               add esp, 0x14
// 004453fd  c21000               ret 0x10
// 00445400  57                   push edi
// 00445401  8d442418             lea eax, [esp + 0x18]
// 00445405  50                   push eax
// 00445406  8bce                 mov ecx, esi
// 00445408  e803380500           call 0x498c10
// 0044540d  8b10                 mov edx, dword ptr [eax]
// 0044540f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00445413  5b                   pop ebx
// 00445414  8911                 mov dword ptr [ecx], edx
// 00445416  8b4004               mov eax, dword ptr [eax + 4]
// 00445419  5f                   pop edi
// 0044541a  894104               mov dword ptr [ecx + 4], eax
// 0044541d  8bc1                 mov eax, ecx
// 0044541f  5e                   pop esi
// 00445420  83c414               add esp, 0x14
// 00445423  c21000               ret 0x10
// standard library map_ptr<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@PAUT@@@2@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
