// from server: 100% by auto
// roc 2009-06 006994d0  unit: RBX::VVelocityMotor::?$FactoryProduct  size: 169 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006994d0
//
// 006994d0  8b542404             mov edx, dword ptr [esp + 4]
// 006994d4  83ec10               sub esp, 0x10
// 006994d7  53                   push ebx
// 006994d8  55                   push ebp
// 006994d9  57                   push edi
// 006994da  8bf9                 mov edi, ecx
// 006994dc  8b4f18               mov ecx, dword ptr [edi + 0x18]
// 006994df  8b4104               mov eax, dword ptr [ecx + 4]
// 006994e2  80781500             cmp byte ptr [eax + 0x15], 0
// 006994e6  8bd9                 mov ebx, ecx
// 006994e8  751a                 jne 0x699504
// 006994ea  8b0a                 mov ecx, dword ptr [edx]
// 006994ec  8d642400             lea esp, [esp]
// 006994f0  39480c               cmp dword ptr [eax + 0xc], ecx
// 006994f3  7305                 jae 0x6994fa
// 006994f5  8b4008               mov eax, dword ptr [eax + 8]
// 006994f8  eb04                 jmp 0x6994fe
// 006994fa  8bd8                 mov ebx, eax
// 006994fc  8b00                 mov eax, dword ptr [eax]
// 006994fe  80781500             cmp byte ptr [eax + 0x15], 0
// 00699502  74ec                 je 0x6994f0
// 00699504  8b4718               mov eax, dword ptr [edi + 0x18]
// 00699507  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 0069950d  56                   push esi
// 0069950e  8b37                 mov esi, dword ptr [edi]
// 00699510  89442414             mov dword ptr [esp + 0x14], eax
// 00699514  85f6                 test esi, esi
// 00699516  7404                 je 0x69951c
// 00699518  3bf6                 cmp esi, esi
// 0069951a  740c                 je 0x699528
// 0069951c  ffd5                 call ebp
// 0069951e  8b542424             mov edx, dword ptr [esp + 0x24]
// 00699522  8b2dace98900         mov ebp, dword ptr [0x89e9ac]
// 00699528  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 0069952c  7407                 je 0x699535
// 0069952e  8b0a                 mov ecx, dword ptr [edx]
// 00699530  3b4b0c               cmp ecx, dword ptr [ebx + 0xc]
// 00699533  7326                 jae 0x69955b
// 00699535  8b12                 mov edx, dword ptr [edx]
// 00699537  8d442410             lea eax, [esp + 0x10]
// 0069953b  50                   push eax
// 0069953c  53                   push ebx
// 0069953d  56                   push esi
// 0069953e  8d4c2424             lea ecx, [esp + 0x24]
// 00699542  51                   push ecx
// 00699543  8bcf                 mov ecx, edi
// 00699545  89542420             mov dword ptr [esp + 0x20], edx
// 00699549  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00699551  e89afdffff           call 0x6992f0
// 00699556  8b30                 mov esi, dword ptr [eax]
// 00699558  8b5804               mov ebx, dword ptr [eax + 4]
// 0069955b  85f6                 test esi, esi
// 0069955d  7516                 jne 0x699575
// 0069955f  ffd5                 call ebp
// 00699561  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 00699564  5e                   pop esi
// 00699565  7502                 jne 0x699569
// 00699567  ffd5                 call ebp
// 00699569  5f                   pop edi
// 0069956a  5d                   pop ebp
// 0069956b  8d4310               lea eax, [ebx + 0x10]
// 0069956e  5b                   pop ebx
// 0069956f  83c410               add esp, 0x10
// 00699572  c20400               ret 4
// 00699575  8b36                 mov esi, dword ptr [esi]
// 00699577  ebe8                 jmp 0x699561
// standard library map_ptr<ptr> (function ??A?$map@PAUK@@PAUT@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@PAUT@@@std@@@4@@std@@QAEAAPAUT@@ABQAUK@@@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
