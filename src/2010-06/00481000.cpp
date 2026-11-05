// from server: 100% by auto
// roc 2010-06 00481000  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00481000
//
// 00481000  83ec14               sub esp, 0x14
// 00481003  56                   push esi
// 00481004  8bf1                 mov esi, ecx
// 00481006  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0048100a  57                   push edi
// 0048100b  7521                 jne 0x48102e
// 0048100d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00481011  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00481014  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00481018  50                   push eax
// 00481019  51                   push ecx
// 0048101a  6a01                 push 1
// 0048101c  57                   push edi
// 0048101d  8bce                 mov ecx, esi
// 0048101f  e80ca03000           call 0x78b030
// 00481024  8bc7                 mov eax, edi
// 00481026  5f                   pop edi
// 00481027  5e                   pop esi
// 00481028  83c414               add esp, 0x14
// 0048102b  c21000               ret 0x10
// 0048102e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00481032  8b5618               mov edx, dword ptr [esi + 0x18]
// 00481035  8b3a                 mov edi, dword ptr [edx]
// 00481037  8b06                 mov eax, dword ptr [esi]
// 00481039  53                   push ebx
// 0048103a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00481040  85c9                 test ecx, ecx
// 00481042  7404                 je 0x481048
// 00481044  3bc8                 cmp ecx, eax
// 00481046  7406                 je 0x48104e
// 00481048  ffd3                 call ebx
// 0048104a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0048104e  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00481052  3bc7                 cmp eax, edi
// 00481054  752a                 jne 0x481080
// 00481056  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0048105a  8b0f                 mov ecx, dword ptr [edi]
// 0048105c  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 0048105f  0f8d4b010000         jge 0x4811b0
// 00481065  57                   push edi
// 00481066  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 0048106a  50                   push eax
// 0048106b  6a01                 push 1
// 0048106d  57                   push edi
// 0048106e  8bce                 mov ecx, esi
// 00481070  e8bb9f3000           call 0x78b030
// 00481075  5b                   pop ebx
// 00481076  8bc7                 mov eax, edi
// 00481078  5f                   pop edi
// 00481079  5e                   pop esi
// 0048107a  83c414               add esp, 0x14
// 0048107d  c21000               ret 0x10
// 00481080  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00481083  8b16                 mov edx, dword ptr [esi]
// 00481085  85c9                 test ecx, ecx
// 00481087  7404                 je 0x48108d
// 00481089  3bca                 cmp ecx, edx
// 0048108b  740a                 je 0x481097
// 0048108d  ffd3                 call ebx
// 0048108f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00481093  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00481097  3bc7                 cmp eax, edi
// 00481099  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0048109d  752c                 jne 0x4810cb
// 0048109f  8b5618               mov edx, dword ptr [esi + 0x18]
// 004810a2  8b4208               mov eax, dword ptr [edx + 8]
// 004810a5  8b480c               mov ecx, dword ptr [eax + 0xc]
// 004810a8  3b0f                 cmp ecx, dword ptr [edi]
// 004810aa  0f8d00010000         jge 0x4811b0
// 004810b0  57                   push edi
// 004810b1  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004810b5  50                   push eax
// 004810b6  6a00                 push 0
// 004810b8  57                   push edi
// 004810b9  8bce                 mov ecx, esi
// 004810bb  e8709f3000           call 0x78b030
// 004810c0  5b                   pop ebx
// 004810c1  8bc7                 mov eax, edi
// 004810c3  5f                   pop edi
// 004810c4  5e                   pop esi
// 004810c5  83c414               add esp, 0x14
// 004810c8  c21000               ret 0x10
// 004810cb  8b17                 mov edx, dword ptr [edi]
// 004810cd  39500c               cmp dword ptr [eax + 0xc], edx
// 004810d0  7e63                 jle 0x481135
// 004810d2  894c240c             mov dword ptr [esp + 0xc], ecx
// 004810d6  8d4c240c             lea ecx, [esp + 0xc]
// 004810da  89442410             mov dword ptr [esp + 0x10], eax
// 004810de  e85d8b2800           call 0x709c40
// 004810e3  8b17                 mov edx, dword ptr [edi]
// 004810e5  8b442410             mov eax, dword ptr [esp + 0x10]
// 004810e9  39500c               cmp dword ptr [eax + 0xc], edx
// 004810ec  7d3c                 jge 0x48112a
// 004810ee  8b5008               mov edx, dword ptr [eax + 8]
// 004810f1  807a1500             cmp byte ptr [edx + 0x15], 0
// 004810f5  57                   push edi
// 004810f6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 004810fa  8bce                 mov ecx, esi
// 004810fc  7414                 je 0x481112
// 004810fe  50                   push eax
// 004810ff  6a00                 push 0
// 00481101  57                   push edi
// 00481102  e8299f3000           call 0x78b030
// 00481107  5b                   pop ebx
// 00481108  8bc7                 mov eax, edi
// 0048110a  5f                   pop edi
// 0048110b  5e                   pop esi
// 0048110c  83c414               add esp, 0x14
// 0048110f  c21000               ret 0x10
// 00481112  8b442430             mov eax, dword ptr [esp + 0x30]
// 00481116  50                   push eax
// 00481117  6a01                 push 1
// 00481119  57                   push edi
// 0048111a  e8119f3000           call 0x78b030
// 0048111f  5b                   pop ebx
// 00481120  8bc7                 mov eax, edi
// 00481122  5f                   pop edi
// 00481123  5e                   pop esi
// 00481124  83c414               add esp, 0x14
// 00481127  c21000               ret 0x10
// 0048112a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0048112e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00481132  39500c               cmp dword ptr [eax + 0xc], edx
// 00481135  7d79                 jge 0x4811b0
// 00481137  8b16                 mov edx, dword ptr [esi]
// 00481139  894c240c             mov dword ptr [esp + 0xc], ecx
// 0048113d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00481140  894c2418             mov dword ptr [esp + 0x18], ecx
// 00481144  8d4c240c             lea ecx, [esp + 0xc]
// 00481148  89442410             mov dword ptr [esp + 0x10], eax
// 0048114c  89542414             mov dword ptr [esp + 0x14], edx
// 00481150  e88b682600           call 0x6e79e0
// 00481155  8d442414             lea eax, [esp + 0x14]
// 00481159  50                   push eax
// 0048115a  8d4c2410             lea ecx, [esp + 0x10]
// 0048115e  e81d5efeff           call 0x466f80
// 00481163  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00481167  84c0                 test al, al
// 00481169  7507                 jne 0x481172
// 0048116b  8b17                 mov edx, dword ptr [edi]
// 0048116d  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 00481170  7d3e                 jge 0x4811b0
// 00481172  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00481176  8b5008               mov edx, dword ptr [eax + 8]
// 00481179  807a1500             cmp byte ptr [edx + 0x15], 0
// 0048117d  57                   push edi
// 0048117e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 00481182  7416                 je 0x48119a
// 00481184  50                   push eax
// 00481185  6a00                 push 0
// 00481187  57                   push edi
// 00481188  8bce                 mov ecx, esi
// 0048118a  e8a19e3000           call 0x78b030
// 0048118f  5b                   pop ebx
// 00481190  8bc7                 mov eax, edi
// 00481192  5f                   pop edi
// 00481193  5e                   pop esi
// 00481194  83c414               add esp, 0x14
// 00481197  c21000               ret 0x10
// 0048119a  51                   push ecx
// 0048119b  6a01                 push 1
// 0048119d  57                   push edi
// 0048119e  8bce                 mov ecx, esi
// 004811a0  e88b9e3000           call 0x78b030
// 004811a5  5b                   pop ebx
// 004811a6  8bc7                 mov eax, edi
// 004811a8  5f                   pop edi
// 004811a9  5e                   pop esi
// 004811aa  83c414               add esp, 0x14
// 004811ad  c21000               ret 0x10
// 004811b0  57                   push edi
// 004811b1  8d442418             lea eax, [esp + 0x18]
// 004811b5  50                   push eax
// 004811b6  8bce                 mov ecx, esi
// 004811b8  e8436d2600           call 0x6e7f00
// 004811bd  8b10                 mov edx, dword ptr [eax]
// 004811bf  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004811c3  5b                   pop ebx
// 004811c4  8911                 mov dword ptr [ecx], edx
// 004811c6  8b4004               mov eax, dword ptr [eax + 4]
// 004811c9  5f                   pop edi
// 004811ca  894104               mov dword ptr [ecx + 4], eax
// 004811cd  8bc1                 mov eax, ecx
// 004811cf  5e                   pop esi
// 004811d0  83c414               add esp, 0x14
// 004811d3  c21000               ret 0x10
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
