// from server: 100% by auto
// roc 2009-06 0067db40  unit: RBX::JointsService  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0067db40
//
// 0067db40  51                   push ecx
// 0067db41  8b542408             mov edx, dword ptr [esp + 8]
// 0067db45  53                   push ebx
// 0067db46  8bd9                 mov ebx, ecx
// 0067db48  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0067db4b  b9ffffff0f           mov ecx, 0xfffffff
// 0067db50  2bc8                 sub ecx, eax
// 0067db52  3bca                 cmp ecx, edx
// 0067db54  7305                 jae 0x67db5b
// 0067db56  e8151ddbff           call 0x42f870
// 0067db5b  8bc8                 mov ecx, eax
// 0067db5d  d1e9                 shr ecx, 1
// 0067db5f  83f908               cmp ecx, 8
// 0067db62  7305                 jae 0x67db69
// 0067db64  b908000000           mov ecx, 8
// 0067db69  55                   push ebp
// 0067db6a  56                   push esi
// 0067db6b  57                   push edi
// 0067db6c  3bd1                 cmp edx, ecx
// 0067db6e  7311                 jae 0x67db81
// 0067db70  beffffff0f           mov esi, 0xfffffff
// 0067db75  2bf1                 sub esi, ecx
// 0067db77  3bc6                 cmp eax, esi
// 0067db79  7706                 ja 0x67db81
// 0067db7b  894c2418             mov dword ptr [esp + 0x18], ecx
// 0067db7f  8bd1                 mov edx, ecx
// 0067db81  8b6b18               mov ebp, dword ptr [ebx + 0x18]
// 0067db84  03c2                 add eax, edx
// 0067db86  6a00                 push 0
// 0067db88  50                   push eax
// 0067db89  d1ed                 shr ebp, 1
// 0067db8b  e870aef7ff           call 0x5f8a00
// 0067db90  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0067db93  89442418             mov dword ptr [esp + 0x18], eax
// 0067db97  8d34ad00000000       lea esi, [ebp*4]
// 0067db9e  8d3c06               lea edi, [esi + eax]
// 0067dba1  8b4314               mov eax, dword ptr [ebx + 0x14]
// 0067dba4  03c0                 add eax, eax
// 0067dba6  03c0                 add eax, eax
// 0067dba8  8d140e               lea edx, [esi + ecx]
// 0067dbab  2bc2                 sub eax, edx
// 0067dbad  03c1                 add eax, ecx
// 0067dbaf  c1f802               sar eax, 2
// 0067dbb2  8d0c8500000000       lea ecx, [eax*4]
// 0067dbb9  83c408               add esp, 8
// 0067dbbc  03f9                 add edi, ecx
// 0067dbbe  85c0                 test eax, eax
// 0067dbc0  7614                 jbe 0x67dbd6
// 0067dbc2  51                   push ecx
// 0067dbc3  52                   push edx
// 0067dbc4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0067dbc8  51                   push ecx
// 0067dbc9  8d0416               lea eax, [esi + edx]
// 0067dbcc  50                   push eax
// 0067dbcd  ff155ce98900         call dword ptr [0x89e95c]
// 0067dbd3  83c410               add esp, 0x10
// 0067dbd6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0067dbda  3be8                 cmp ebp, eax
// 0067dbdc  773d                 ja 0x67dc1b
// 0067dbde  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0067dbe1  c1fe02               sar esi, 2
// 0067dbe4  8bce                 mov ecx, esi
// 0067dbe6  8d148d00000000       lea edx, [ecx*4]
// 0067dbed  8d343a               lea esi, [edx + edi]
// 0067dbf0  85c9                 test ecx, ecx
// 0067dbf2  760d                 jbe 0x67dc01
// 0067dbf4  52                   push edx
// 0067dbf5  50                   push eax
// 0067dbf6  52                   push edx
// 0067dbf7  57                   push edi
// 0067dbf8  ff155ce98900         call dword ptr [0x89e95c]
// 0067dbfe  83c410               add esp, 0x10
// 0067dc01  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0067dc05  2bcd                 sub ecx, ebp
// 0067dc07  7406                 je 0x67dc0f
// 0067dc09  33c0                 xor eax, eax
// 0067dc0b  8bfe                 mov edi, esi
// 0067dc0d  f3ab                 rep stosd dword ptr es:[edi], eax
// 0067dc0f  85ed                 test ebp, ebp
// 0067dc11  7664                 jbe 0x67dc77
// 0067dc13  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 0067dc17  8bcd                 mov ecx, ebp
// 0067dc19  eb58                 jmp 0x67dc73
// 0067dc1b  8b4b10               mov ecx, dword ptr [ebx + 0x10]
// 0067dc1e  8d2c8500000000       lea ebp, [eax*4]
// 0067dc25  8bc5                 mov eax, ebp
// 0067dc27  c1f802               sar eax, 2
// 0067dc2a  85c0                 test eax, eax
// 0067dc2c  7611                 jbe 0x67dc3f
// 0067dc2e  03c0                 add eax, eax
// 0067dc30  03c0                 add eax, eax
// 0067dc32  50                   push eax
// 0067dc33  51                   push ecx
// 0067dc34  50                   push eax
// 0067dc35  57                   push edi
// 0067dc36  ff155ce98900         call dword ptr [0x89e95c]
// 0067dc3c  83c410               add esp, 0x10
// 0067dc3f  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0067dc42  8b542410             mov edx, dword ptr [esp + 0x10]
// 0067dc46  8d0c28               lea ecx, [eax + ebp]
// 0067dc49  2bf1                 sub esi, ecx
// 0067dc4b  03f0                 add esi, eax
// 0067dc4d  c1fe02               sar esi, 2
// 0067dc50  8d04b500000000       lea eax, [esi*4]
// 0067dc57  8d3c10               lea edi, [eax + edx]
// 0067dc5a  85f6                 test esi, esi
// 0067dc5c  760d                 jbe 0x67dc6b
// 0067dc5e  50                   push eax
// 0067dc5f  51                   push ecx
// 0067dc60  50                   push eax
// 0067dc61  52                   push edx
// 0067dc62  ff155ce98900         call dword ptr [0x89e95c]
// 0067dc68  83c410               add esp, 0x10
// 0067dc6b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0067dc6f  85c9                 test ecx, ecx
// 0067dc71  7604                 jbe 0x67dc77
// 0067dc73  33c0                 xor eax, eax
// 0067dc75  f3ab                 rep stosd dword ptr es:[edi], eax
// 0067dc77  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0067dc7a  5f                   pop edi
// 0067dc7b  5e                   pop esi
// 0067dc7c  5d                   pop ebp
// 0067dc7d  85c0                 test eax, eax
// 0067dc7f  7409                 je 0x67dc8a
// 0067dc81  50                   push eax
// 0067dc82  e8abad0900           call 0x718a32
// 0067dc87  83c404               add esp, 4
// 0067dc8a  8b442404             mov eax, dword ptr [esp + 4]
// 0067dc8e  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0067dc92  014b14               add dword ptr [ebx + 0x14], ecx
// 0067dc95  894310               mov dword ptr [ebx + 0x10], eax
// 0067dc98  5b                   pop ebx
// 0067dc99  59                   pop ecx
// 0067dc9a  c20400               ret 4
// standard library deque<double> (function ?_Growmap@?$deque@NV?$allocator@N@std@@@std@@IAEXI@Z)

// stl: deque<double>
typedef double E;
#include <deque>
template class std::deque<E>;
