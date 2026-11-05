// from server: 100% by auto
// roc 2010-06 006e8690  unit: RBX::VInstance::?$NonFactoryProduct  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006e8690
//
// 006e8690  8b542404             mov edx, dword ptr [esp + 4]
// 006e8694  83ec10               sub esp, 0x10
// 006e8697  53                   push ebx
// 006e8698  55                   push ebp
// 006e8699  57                   push edi
// 006e869a  8bf9                 mov edi, ecx
// 006e869c  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006e869f  8b4104               mov eax, dword ptr [ecx + 4]
// 006e86a2  80781500             cmp byte ptr [eax + 0x15], 0
// 006e86a6  8bd9                 mov ebx, ecx
// 006e86a8  751a                 jne 0x6e86c4
// 006e86aa  8b0a                 mov ecx, dword ptr [edx]
// 006e86ac  8d642400             lea esp, [esp]
// 006e86b0  39480c               cmp dword ptr [eax + 0xc], ecx
// 006e86b3  7d05                 jge 0x6e86ba
// 006e86b5  8b4008               mov eax, dword ptr [eax + 8]
// 006e86b8  eb04                 jmp 0x6e86be
// 006e86ba  8bd8                 mov ebx, eax
// 006e86bc  8b00                 mov eax, dword ptr [eax]
// 006e86be  80781500             cmp byte ptr [eax + 0x15], 0
// 006e86c2  74ec                 je 0x6e86b0
// 006e86c4  8b4718               mov eax, dword ptr [edi + 0x18]
// 006e86c7  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006e86cd  56                   push esi
// 006e86ce  8b37                 mov esi, dword ptr [edi]
// 006e86d0  89442414             mov dword ptr [esp + 0x14], eax
// 006e86d4  85f6                 test esi, esi
// 006e86d6  7404                 je 0x6e86dc
// 006e86d8  3bf6                 cmp esi, esi
// 006e86da  740c                 je 0x6e86e8
// 006e86dc  ffd5                 call ebp
// 006e86de  8b542424             mov edx, dword ptr [esp + 0x24]
// 006e86e2  8b2d0ca99e00         mov ebp, dword ptr [0x9ea90c]
// 006e86e8  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 006e86ec  7407                 je 0x6e86f5
// 006e86ee  8b0a                 mov ecx, dword ptr [edx]
// 006e86f0  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 006e86f3  7d23                 jge 0x6e8718
// 006e86f5  8b12                 mov edx, dword ptr [edx]
// 006e86f7  8d442410             lea eax, [esp + 0x10]
// 006e86fb  50                   push eax
// 006e86fc  53                   push ebx
// 006e86fd  56                   push esi
// 006e86fe  8d4c2424             lea ecx, [esp + 0x24]
// 006e8702  51                   push ecx
// 006e8703  8bcf                 mov ecx, edi
// 006e8705  89542420             mov dword ptr [esp + 0x20], edx
// 006e8709  c644242400           mov byte ptr [esp + 0x24], 0
// 006e870e  e8ed88d9ff           call 0x481000
// 006e8713  8b30                 mov esi, dword ptr [eax]
// 006e8715  8b5804               mov ebx, dword ptr [eax + 4]
// 006e8718  85f6                 test esi, esi
// 006e871a  7516                 jne 0x6e8732
// 006e871c  ffd5                 call ebp
// 006e871e  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 006e8721  5e                   pop esi
// 006e8722  7502                 jne 0x6e8726
// 006e8724  ffd5                 call ebp
// 006e8726  5f                   pop edi
// 006e8727  5d                   pop ebp
// 006e8728  8d4310               lea eax, [ebx + 0x10]
// 006e872b  5b                   pop ebx
// 006e872c  83c410               add esp, 0x10
// 006e872f  c20400               ret 4
// 006e8732  8b36                 mov esi, dword ptr [esi]
// 006e8734  ebe8                 jmp 0x6e871e
// standard library map_int<char> (function ??A?$map@HDU?$less@H@std@@V?$allocator@U?$pair@$$CBHD@std@@@2@@std@@QAEAADABH@Z)

// stl: map_int<char>
typedef char E;
#include <map>
template class std::map<int, E>;
