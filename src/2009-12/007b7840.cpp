// from server: 100% by auto
// roc 2009-12 007b7840  unit: RBX::SleepStage  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007b7840
//
// 007b7840  83ec18               sub esp, 0x18
// 007b7843  53                   push ebx
// 007b7844  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 007b7848  56                   push esi
// 007b7849  8bf1                 mov esi, ecx
// 007b784b  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 007b784e  57                   push edi
// 007b784f  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007b7852  8bc7                 mov eax, edi
// 007b7854  2bc1                 sub eax, ecx
// 007b7856  c1f802               sar eax, 2
// 007b7859  3bd8                 cmp ebx, eax
// 007b785b  762f                 jbe 0x7b788c
// 007b785d  3bcf                 cmp ecx, edi
// 007b785f  7606                 jbe 0x7b7867
// 007b7861  ff1560b79800         call dword ptr [0x98b760]
// 007b7867  8b5610               mov edx, dword ptr [esi + 0x10]
// 007b786a  2b560c               sub edx, dword ptr [esi + 0xc]
// 007b786d  8b06                 mov eax, dword ptr [esi]
// 007b786f  8d4c242c             lea ecx, [esp + 0x2c]
// 007b7873  51                   push ecx
// 007b7874  c1fa02               sar edx, 2
// 007b7877  2bda                 sub ebx, edx
// 007b7879  53                   push ebx
// 007b787a  57                   push edi
// 007b787b  50                   push eax
// 007b787c  8bce                 mov ecx, esi
// 007b787e  e8fd91ccff           call 0x480a80
// 007b7883  5f                   pop edi
// 007b7884  5e                   pop esi
// 007b7885  5b                   pop ebx
// 007b7886  83c418               add esp, 0x18
// 007b7889  c20800               ret 8
// 007b788c  7352                 jae 0x7b78e0
// 007b788e  3bcf                 cmp ecx, edi
// 007b7890  7606                 jbe 0x7b7898
// 007b7892  ff1560b79800         call dword ptr [0x98b760]
// 007b7898  8b06                 mov eax, dword ptr [esi]
// 007b789a  55                   push ebp
// 007b789b  8b6e0c               mov ebp, dword ptr [esi + 0xc]
// 007b789e  89442418             mov dword ptr [esp + 0x18], eax
// 007b78a2  3b6e10               cmp ebp, dword ptr [esi + 0x10]
// 007b78a5  7606                 jbe 0x7b78ad
// 007b78a7  ff1560b79800         call dword ptr [0x98b760]
// 007b78ad  8b0e                 mov ecx, dword ptr [esi]
// 007b78af  53                   push ebx
// 007b78b0  8d542424             lea edx, [esp + 0x24]
// 007b78b4  894c2414             mov dword ptr [esp + 0x14], ecx
// 007b78b8  52                   push edx
// 007b78b9  8d4c2418             lea ecx, [esp + 0x18]
// 007b78bd  896c241c             mov dword ptr [esp + 0x1c], ebp
// 007b78c1  e8bac1c7ff           call 0x433a80
// 007b78c6  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007b78ca  8b5004               mov edx, dword ptr [eax + 4]
// 007b78cd  8b00                 mov eax, dword ptr [eax]
// 007b78cf  57                   push edi
// 007b78d0  51                   push ecx
// 007b78d1  52                   push edx
// 007b78d2  50                   push eax
// 007b78d3  8d4c2428             lea ecx, [esp + 0x28]
// 007b78d7  51                   push ecx
// 007b78d8  8bce                 mov ecx, esi
// 007b78da  e86173cfff           call 0x4aec40
// 007b78df  5d                   pop ebp
// 007b78e0  5f                   pop edi
// 007b78e1  5e                   pop esi
// 007b78e2  5b                   pop ebx
// 007b78e3  83c418               add esp, 0x18
// 007b78e6  c20800               ret 8
// standard library vector<ptr> (function ?resize@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAEXIPAUT@@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
