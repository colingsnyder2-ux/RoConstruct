// from server: 100% by auto
// roc 2008-06 006976f0  unit: Ogre::RbxSceneManager  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006976f0
//
// 006976f0  83ec14               sub esp, 0x14
// 006976f3  56                   push esi
// 006976f4  8bf1                 mov esi, ecx
// 006976f6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 006976fa  57                   push edi
// 006976fb  7521                 jne 0x69771e
// 006976fd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00697701  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00697704  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00697708  50                   push eax
// 00697709  51                   push ecx
// 0069770a  6a01                 push 1
// 0069770c  57                   push edi
// 0069770d  8bce                 mov ecx, esi
// 0069770f  e8dcabffff           call 0x6922f0
// 00697714  8bc7                 mov eax, edi
// 00697716  5f                   pop edi
// 00697717  5e                   pop esi
// 00697718  83c414               add esp, 0x14
// 0069771b  c21000               ret 0x10
// 0069771e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00697722  8b5618               mov edx, dword ptr [esi + 0x18]
// 00697725  8b3a                 mov edi, dword ptr [edx]
// 00697727  8b06                 mov eax, dword ptr [esi]
// 00697729  53                   push ebx
// 0069772a  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00697730  85c9                 test ecx, ecx
// 00697732  7404                 je 0x697738
// 00697734  3bc8                 cmp ecx, eax
// 00697736  7406                 je 0x69773e
// 00697738  ffd3                 call ebx
// 0069773a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0069773e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00697742  3bc7                 cmp eax, edi
// 00697744  752a                 jne 0x697770
// 00697746  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0069774a  8b0f                 mov ecx, dword ptr [edi]
// 0069774c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0069774f  0f834b010000         jae 0x6978a0
// 00697755  57                   push edi
// 00697756  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0069775a  50                   push eax
// 0069775b  6a01                 push 1
// 0069775d  57                   push edi
// 0069775e  8bce                 mov ecx, esi
// 00697760  e88babffff           call 0x6922f0
// 00697765  5b                   pop ebx
// 00697766  8bc7                 mov eax, edi
// 00697768  5f                   pop edi
// 00697769  5e                   pop esi
// 0069776a  83c414               add esp, 0x14
// 0069776d  c21000               ret 0x10
// 00697770  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00697773  8b16                 mov edx, dword ptr [esi]
// 00697775  85c9                 test ecx, ecx
// 00697777  7404                 je 0x69777d
// 00697779  3bca                 cmp ecx, edx
// 0069777b  740a                 je 0x697787
// 0069777d  ffd3                 call ebx
// 0069777f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00697783  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00697787  3bc7                 cmp eax, edi
// 00697789  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0069778d  752c                 jne 0x6977bb
// 0069778f  8b5618               mov edx, dword ptr [esi + 0x18]
// 00697792  8b4208               mov eax, dword ptr [edx + 8]
// 00697795  8b480c               mov ecx, dword ptr [eax + 0xc]
// 00697798  3b0f                 cmp ecx, dword ptr [edi]
// 0069779a  0f8300010000         jae 0x6978a0
// 006977a0  57                   push edi
// 006977a1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006977a5  50                   push eax
// 006977a6  6a00                 push 0
// 006977a8  57                   push edi
// 006977a9  8bce                 mov ecx, esi
// 006977ab  e840abffff           call 0x6922f0
// 006977b0  5b                   pop ebx
// 006977b1  8bc7                 mov eax, edi
// 006977b3  5f                   pop edi
// 006977b4  5e                   pop esi
// 006977b5  83c414               add esp, 0x14
// 006977b8  c21000               ret 0x10
// 006977bb  8b17                 mov edx, dword ptr [edi]
// 006977bd  39500c               cmp dword ptr [eax + 0xc], edx
// 006977c0  7663                 jbe 0x697825
// 006977c2  894c240c             mov dword ptr [esp + 0xc], ecx
// 006977c6  8d4c240c             lea ecx, [esp + 0xc]
// 006977ca  89442410             mov dword ptr [esp + 0x10], eax
// 006977ce  e8ed5affff           call 0x68d2c0
// 006977d3  8b17                 mov edx, dword ptr [edi]
// 006977d5  8b442410             mov eax, dword ptr [esp + 0x10]
// 006977d9  39500c               cmp dword ptr [eax + 0xc], edx
// 006977dc  733c                 jae 0x69781a
// 006977de  8b5008               mov edx, dword ptr [eax + 8]
// 006977e1  807a3900             cmp byte ptr [edx + 0x39], 0
// 006977e5  57                   push edi
// 006977e6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 006977ea  8bce                 mov ecx, esi
// 006977ec  7414                 je 0x697802
// 006977ee  50                   push eax
// 006977ef  6a00                 push 0
// 006977f1  57                   push edi
// 006977f2  e8f9aaffff           call 0x6922f0
// 006977f7  5b                   pop ebx
// 006977f8  8bc7                 mov eax, edi
// 006977fa  5f                   pop edi
// 006977fb  5e                   pop esi
// 006977fc  83c414               add esp, 0x14
// 006977ff  c21000               ret 0x10
// 00697802  8b442430             mov eax, dword ptr [esp + 0x30]
// 00697806  50                   push eax
// 00697807  6a01                 push 1
// 00697809  57                   push edi
// 0069780a  e8e1aaffff           call 0x6922f0
// 0069780f  5b                   pop ebx
// 00697810  8bc7                 mov eax, edi
// 00697812  5f                   pop edi
// 00697813  5e                   pop esi
// 00697814  83c414               add esp, 0x14
// 00697817  c21000               ret 0x10
// 0069781a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0069781e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00697822  39500c               cmp dword ptr [eax + 0xc], edx
// 00697825  7379                 jae 0x6978a0
// 00697827  8b16                 mov edx, dword ptr [esi]
// 00697829  894c240c             mov dword ptr [esp + 0xc], ecx
// 0069782d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00697830  894c2418             mov dword ptr [esp + 0x18], ecx
// 00697834  8d4c240c             lea ecx, [esp + 0xc]
// 00697838  89442410             mov dword ptr [esp + 0x10], eax
// 0069783c  89542414             mov dword ptr [esp + 0x14], edx
// 00697840  e8cb59ffff           call 0x68d210
// 00697845  8d442414             lea eax, [esp + 0x14]
// 00697849  50                   push eax
// 0069784a  8d4c2410             lea ecx, [esp + 0x10]
// 0069784e  e84d54f5ff           call 0x5ecca0
// 00697853  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00697857  84c0                 test al, al
// 00697859  7507                 jne 0x697862
// 0069785b  8b17                 mov edx, dword ptr [edi]
// 0069785d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00697860  733e                 jae 0x6978a0
// 00697862  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00697866  8b5008               mov edx, dword ptr [eax + 8]
// 00697869  807a3900             cmp byte ptr [edx + 0x39], 0
// 0069786d  57                   push edi
// 0069786e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00697872  7416                 je 0x69788a
// 00697874  50                   push eax
// 00697875  6a00                 push 0
// 00697877  57                   push edi
// 00697878  8bce                 mov ecx, esi
// 0069787a  e871aaffff           call 0x6922f0
// 0069787f  5b                   pop ebx
// 00697880  8bc7                 mov eax, edi
// 00697882  5f                   pop edi
// 00697883  5e                   pop esi
// 00697884  83c414               add esp, 0x14
// 00697887  c21000               ret 0x10
// 0069788a  51                   push ecx
// 0069788b  6a01                 push 1
// 0069788d  57                   push edi
// 0069788e  8bce                 mov ecx, esi
// 00697890  e85baaffff           call 0x6922f0
// 00697895  5b                   pop ebx
// 00697896  8bc7                 mov eax, edi
// 00697898  5f                   pop edi
// 00697899  5e                   pop esi
// 0069789a  83c414               add esp, 0x14
// 0069789d  c21000               ret 0x10
// 006978a0  57                   push edi
// 006978a1  8d442418             lea eax, [esp + 0x18]
// 006978a5  50                   push eax
// 006978a6  8bce                 mov ecx, esi
// 006978a8  e813c5ffff           call 0x693dc0
// 006978ad  8b10                 mov edx, dword ptr [eax]
// 006978af  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 006978b3  5b                   pop ebx
// 006978b4  8911                 mov dword ptr [ecx], edx
// 006978b6  8b4004               mov eax, dword ptr [eax + 4]
// 006978b9  5f                   pop edi
// 006978ba  894104               mov dword ptr [ecx + 4], eax
// 006978bd  8bc1                 mov eax, ecx
// 006978bf  5e                   pop esi
// 006978c0  83c414               add esp, 0x14
// 006978c3  c21000               ret 0x10
// standard library map_ptr<pod40> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod40>
struct E { int v[10]; };
#include <map>
struct K; template class std::map<K*, E>;
