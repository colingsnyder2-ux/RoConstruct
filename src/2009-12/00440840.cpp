// from server: 100% by auto
// roc 2009-12 00440840  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00440840
//
// 00440840  83ec14               sub esp, 0x14
// 00440843  56                   push esi
// 00440844  8bf1                 mov esi, ecx
// 00440846  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0044084a  57                   push edi
// 0044084b  7521                 jne 0x44086e
// 0044084d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00440851  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00440854  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00440858  50                   push eax
// 00440859  51                   push ecx
// 0044085a  6a01                 push 1
// 0044085c  57                   push edi
// 0044085d  8bce                 mov ecx, esi
// 0044085f  e82ce7ffff           call 0x43ef90
// 00440864  8bc7                 mov eax, edi
// 00440866  5f                   pop edi
// 00440867  5e                   pop esi
// 00440868  83c414               add esp, 0x14
// 0044086b  c21000               ret 0x10
// 0044086e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00440872  8b5618               mov edx, dword ptr [esi + 0x18]
// 00440875  8b3a                 mov edi, dword ptr [edx]
// 00440877  8b06                 mov eax, dword ptr [esi]
// 00440879  53                   push ebx
// 0044087a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00440880  85c9                 test ecx, ecx
// 00440882  7404                 je 0x440888
// 00440884  3bc8                 cmp ecx, eax
// 00440886  7406                 je 0x44088e
// 00440888  ffd3                 call ebx
// 0044088a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0044088e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00440892  3bc7                 cmp eax, edi
// 00440894  752a                 jne 0x4408c0
// 00440896  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0044089a  8b0f                 mov ecx, dword ptr [edi]
// 0044089c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0044089f  0f834b010000         jae 0x4409f0
// 004408a5  57                   push edi
// 004408a6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004408aa  50                   push eax
// 004408ab  6a01                 push 1
// 004408ad  57                   push edi
// 004408ae  8bce                 mov ecx, esi
// 004408b0  e8dbe6ffff           call 0x43ef90
// 004408b5  5b                   pop ebx
// 004408b6  8bc7                 mov eax, edi
// 004408b8  5f                   pop edi
// 004408b9  5e                   pop esi
// 004408ba  83c414               add esp, 0x14
// 004408bd  c21000               ret 0x10
// 004408c0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 004408c3  8b16                 mov edx, dword ptr [esi]
// 004408c5  85c9                 test ecx, ecx
// 004408c7  7404                 je 0x4408cd
// 004408c9  3bca                 cmp ecx, edx
// 004408cb  740a                 je 0x4408d7
// 004408cd  ffd3                 call ebx
// 004408cf  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004408d3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004408d7  3bc7                 cmp eax, edi
// 004408d9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 004408dd  752c                 jne 0x44090b
// 004408df  8b5618               mov edx, dword ptr [esi + 0x18]
// 004408e2  8b4208               mov eax, dword ptr [edx + 8]
// 004408e5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004408e8  3b0f                 cmp ecx, dword ptr [edi]
// 004408ea  0f8300010000         jae 0x4409f0
// 004408f0  57                   push edi
// 004408f1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004408f5  50                   push eax
// 004408f6  6a00                 push 0
// 004408f8  57                   push edi
// 004408f9  8bce                 mov ecx, esi
// 004408fb  e890e6ffff           call 0x43ef90
// 00440900  5b                   pop ebx
// 00440901  8bc7                 mov eax, edi
// 00440903  5f                   pop edi
// 00440904  5e                   pop esi
// 00440905  83c414               add esp, 0x14
// 00440908  c21000               ret 0x10
// 0044090b  8b17                 mov edx, dword ptr [edi]
// 0044090d  39500c               cmp dword ptr [eax + 0xc], edx
// 00440910  7663                 jbe 0x440975
// 00440912  894c240c             mov dword ptr [esp + 0xc], ecx
// 00440916  8d4c240c             lea ecx, [esp + 0xc]
// 0044091a  89442410             mov dword ptr [esp + 0x10], eax
// 0044091e  e8adc81800           call 0x5cd1d0
// 00440923  8b17                 mov edx, dword ptr [edi]
// 00440925  8b442410             mov eax, dword ptr [esp + 0x10]
// 00440929  39500c               cmp dword ptr [eax + 0xc], edx
// 0044092c  733c                 jae 0x44096a
// 0044092e  8b5008               mov edx, dword ptr [eax + 8]
// 00440931  807a2900             cmp byte ptr [edx + 0x29], 0
// 00440935  57                   push edi
// 00440936  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0044093a  8bce                 mov ecx, esi
// 0044093c  7414                 je 0x440952
// 0044093e  50                   push eax
// 0044093f  6a00                 push 0
// 00440941  57                   push edi
// 00440942  e849e6ffff           call 0x43ef90
// 00440947  5b                   pop ebx
// 00440948  8bc7                 mov eax, edi
// 0044094a  5f                   pop edi
// 0044094b  5e                   pop esi
// 0044094c  83c414               add esp, 0x14
// 0044094f  c21000               ret 0x10
// 00440952  8b442430             mov eax, dword ptr [esp + 0x30]
// 00440956  50                   push eax
// 00440957  6a01                 push 1
// 00440959  57                   push edi
// 0044095a  e831e6ffff           call 0x43ef90
// 0044095f  5b                   pop ebx
// 00440960  8bc7                 mov eax, edi
// 00440962  5f                   pop edi
// 00440963  5e                   pop esi
// 00440964  83c414               add esp, 0x14
// 00440967  c21000               ret 0x10
// 0044096a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0044096e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00440972  39500c               cmp dword ptr [eax + 0xc], edx
// 00440975  7379                 jae 0x4409f0
// 00440977  8b16                 mov edx, dword ptr [esi]
// 00440979  894c240c             mov dword ptr [esp + 0xc], ecx
// 0044097d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00440980  894c2418             mov dword ptr [esp + 0x18], ecx
// 00440984  8d4c240c             lea ecx, [esp + 0xc]
// 00440988  89442410             mov dword ptr [esp + 0x10], eax
// 0044098c  89542414             mov dword ptr [esp + 0x14], edx
// 00440990  e8cbc81800           call 0x5cd260
// 00440995  8d442414             lea eax, [esp + 0x14]
// 00440999  50                   push eax
// 0044099a  8d4c2410             lea ecx, [esp + 0x10]
// 0044099e  e8bdb91800           call 0x5cc360
// 004409a3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004409a7  84c0                 test al, al
// 004409a9  7507                 jne 0x4409b2
// 004409ab  8b17                 mov edx, dword ptr [edi]
// 004409ad  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 004409b0  733e                 jae 0x4409f0
// 004409b2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004409b6  8b5008               mov edx, dword ptr [eax + 8]
// 004409b9  807a2900             cmp byte ptr [edx + 0x29], 0
// 004409bd  57                   push edi
// 004409be  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004409c2  7416                 je 0x4409da
// 004409c4  50                   push eax
// 004409c5  6a00                 push 0
// 004409c7  57                   push edi
// 004409c8  8bce                 mov ecx, esi
// 004409ca  e8c1e5ffff           call 0x43ef90
// 004409cf  5b                   pop ebx
// 004409d0  8bc7                 mov eax, edi
// 004409d2  5f                   pop edi
// 004409d3  5e                   pop esi
// 004409d4  83c414               add esp, 0x14
// 004409d7  c21000               ret 0x10
// 004409da  51                   push ecx
// 004409db  6a01                 push 1
// 004409dd  57                   push edi
// 004409de  8bce                 mov ecx, esi
// 004409e0  e8abe5ffff           call 0x43ef90
// 004409e5  5b                   pop ebx
// 004409e6  8bc7                 mov eax, edi
// 004409e8  5f                   pop edi
// 004409e9  5e                   pop esi
// 004409ea  83c414               add esp, 0x14
// 004409ed  c21000               ret 0x10
// 004409f0  57                   push edi
// 004409f1  8d442418             lea eax, [esp + 0x18]
// 004409f5  50                   push eax
// 004409f6  8bce                 mov ecx, esi
// 004409f8  e873faffff           call 0x440470
// 004409fd  8b10                 mov edx, dword ptr [eax]
// 004409ff  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00440a03  5b                   pop ebx
// 00440a04  8911                 mov dword ptr [ecx], edx
// 00440a06  8b4004               mov eax, dword ptr [eax + 4]
// 00440a09  5f                   pop edi
// 00440a0a  894104               mov dword ptr [ecx + 4], eax
// 00440a0d  8bc1                 mov eax, ecx
// 00440a0f  5e                   pop esi
// 00440a10  83c414               add esp, 0x14
// 00440a13  c21000               ret 0x10
// standard library map_ptr<pod24> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod24>
struct E { int v[6]; };
#include <map>
struct K; template class std::map<K*, E>;
