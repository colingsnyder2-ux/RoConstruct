// from server: 100% by auto
// roc 2007-08 0052e350  unit: RBX::RunService  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0052e350
//
// 0052e350  8b5104               mov edx, dword ptr [ecx + 4]
// 0052e353  8b4204               mov eax, dword ptr [edx + 4]
// 0052e356  83ec10               sub esp, 0x10
// 0052e359  80781500             cmp byte ptr [eax + 0x15], 0
// 0052e35d  53                   push ebx
// 0052e35e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0052e362  56                   push esi
// 0052e363  57                   push edi
// 0052e364  7516                 jne 0x52e37c
// 0052e366  8b33                 mov esi, dword ptr [ebx]
// 0052e368  39700c               cmp dword ptr [eax + 0xc], esi
// 0052e36b  7305                 jae 0x52e372
// 0052e36d  8b4008               mov eax, dword ptr [eax + 8]
// 0052e370  eb04                 jmp 0x52e376
// 0052e372  8bd0                 mov edx, eax
// 0052e374  8b00                 mov eax, dword ptr [eax]
// 0052e376  80781500             cmp byte ptr [eax + 0x15], 0
// 0052e37a  74ec                 je 0x52e368
// 0052e37c  3b5104               cmp edx, dword ptr [ecx + 4]
// 0052e37f  8bfa                 mov edi, edx
// 0052e381  8bf1                 mov esi, ecx
// 0052e383  7407                 je 0x52e38c
// 0052e385  8b03                 mov eax, dword ptr [ebx]
// 0052e387  3b420c               cmp eax, dword ptr [edx + 0xc]
// 0052e38a  7321                 jae 0x52e3ad
// 0052e38c  8b13                 mov edx, dword ptr [ebx]
// 0052e38e  8d44240c             lea eax, [esp + 0xc]
// 0052e392  50                   push eax
// 0052e393  57                   push edi
// 0052e394  89542414             mov dword ptr [esp + 0x14], edx
// 0052e398  56                   push esi
// 0052e399  8d542420             lea edx, [esp + 0x20]
// 0052e39d  52                   push edx
// 0052e39e  c644242000           mov byte ptr [esp + 0x20], 0
// 0052e3a3  e8c8cb0a00           call 0x5daf70
// 0052e3a8  8b30                 mov esi, dword ptr [eax]
// 0052e3aa  8b7804               mov edi, dword ptr [eax + 4]
// 0052e3ad  85f6                 test esi, esi
// 0052e3af  8b1dd8e67700         mov ebx, dword ptr [0x77e6d8]
// 0052e3b5  7502                 jne 0x52e3b9
// 0052e3b7  ffd3                 call ebx
// 0052e3b9  3b7e04               cmp edi, dword ptr [esi + 4]
// 0052e3bc  7502                 jne 0x52e3c0
// 0052e3be  ffd3                 call ebx
// 0052e3c0  8d4710               lea eax, [edi + 0x10]
// 0052e3c3  5f                   pop edi
// 0052e3c4  5e                   pop esi
// 0052e3c5  5b                   pop ebx
// 0052e3c6  83c410               add esp, 0x10
// 0052e3c9  c20400               ret 4
// standard library map_ptr<char> (function ??A?$map@PAUK@@DU?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@D@std@@@3@@std@@QAEAADABQAUK@@@Z)

// stl: map_ptr<char>
typedef char E;
#include <map>
struct K; template class std::map<K*, E>;
