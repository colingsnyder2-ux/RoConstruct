// from server: 100% by auto
// roc 2009-12 006ada40  unit: RBX::Accoutrement  size: 239 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006ada40
//
// 006ada40  83ec0c               sub esp, 0xc
// 006ada43  53                   push ebx
// 006ada44  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 006ada48  55                   push ebp
// 006ada49  56                   push esi
// 006ada4a  57                   push edi
// 006ada4b  8bf9                 mov edi, ecx
// 006ada4d  8b7718               mov esi, dword ptr [edi + 0x18]
// 006ada50  8b4604               mov eax, dword ptr [esi + 4]
// 006ada53  80781500             cmp byte ptr [eax + 0x15], 0
// 006ada57  b101                 mov cl, 1
// 006ada59  884c2410             mov byte ptr [esp + 0x10], cl
// 006ada5d  751f                 jne 0x6ada7e
// 006ada5f  8b13                 mov edx, dword ptr [ebx]
// 006ada61  3b500c               cmp edx, dword ptr [eax + 0xc]
// 006ada64  8bf0                 mov esi, eax
// 006ada66  0f9cc1               setl cl
// 006ada69  884c2410             mov byte ptr [esp + 0x10], cl
// 006ada6d  84c9                 test cl, cl
// 006ada6f  7404                 je 0x6ada75
// 006ada71  8b00                 mov eax, dword ptr [eax]
// 006ada73  eb03                 jmp 0x6ada78
// 006ada75  8b4008               mov eax, dword ptr [eax + 8]
// 006ada78  80781500             cmp byte ptr [eax + 0x15], 0
// 006ada7c  74e3                 je 0x6ada61
// 006ada7e  8b17                 mov edx, dword ptr [edi]
// 006ada80  8bee                 mov ebp, esi
// 006ada82  896c2418             mov dword ptr [esp + 0x18], ebp
// 006ada86  89542414             mov dword ptr [esp + 0x14], edx
// 006ada8a  84c9                 test cl, cl
// 006ada8c  7452                 je 0x6adae0
// 006ada8e  8b4718               mov eax, dword ptr [edi + 0x18]
// 006ada91  8b28                 mov ebp, dword ptr [eax]
// 006ada93  85d2                 test edx, edx
// 006ada95  7404                 je 0x6ada9b
// 006ada97  3bd2                 cmp edx, edx
// 006ada99  7406                 je 0x6adaa1
// 006ada9b  ff1560b79800         call dword ptr [0x98b760]
// 006adaa1  8d4c2414             lea ecx, [esp + 0x14]
// 006adaa5  3bf5                 cmp esi, ebp
// 006adaa7  752a                 jne 0x6adad3
// 006adaa9  53                   push ebx
// 006adaaa  56                   push esi
// 006adaab  6a01                 push 1
// 006adaad  51                   push ecx
// 006adaae  8bcf                 mov ecx, edi
// 006adab0  e86bf8ffff           call 0x6ad320
// 006adab5  5f                   pop edi
// 006adab6  8bc8                 mov ecx, eax
// 006adab8  8b11                 mov edx, dword ptr [ecx]
// 006adaba  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006adabe  8b4904               mov ecx, dword ptr [ecx + 4]
// 006adac1  5e                   pop esi
// 006adac2  5d                   pop ebp
// 006adac3  894804               mov dword ptr [eax + 4], ecx
// 006adac6  c6400801             mov byte ptr [eax + 8], 1
// 006adaca  8910                 mov dword ptr [eax], edx
// 006adacc  5b                   pop ebx
// 006adacd  83c40c               add esp, 0xc
// 006adad0  c20800               ret 8
// 006adad3  e85867d9ff           call 0x444230
// 006adad8  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 006adadc  8b542414             mov edx, dword ptr [esp + 0x14]
// 006adae0  8b450c               mov eax, dword ptr [ebp + 0xc]
// 006adae3  3b03                 cmp eax, dword ptr [ebx]
// 006adae5  7d31                 jge 0x6adb18
// 006adae7  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 006adaeb  53                   push ebx
// 006adaec  56                   push esi
// 006adaed  51                   push ecx
// 006adaee  8d542420             lea edx, [esp + 0x20]
// 006adaf2  52                   push edx
// 006adaf3  8bcf                 mov ecx, edi
// 006adaf5  e826f8ffff           call 0x6ad320
// 006adafa  5f                   pop edi
// 006adafb  8bc8                 mov ecx, eax
// 006adafd  8b11                 mov edx, dword ptr [ecx]
// 006adaff  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006adb03  8b4904               mov ecx, dword ptr [ecx + 4]
// 006adb06  5e                   pop esi
// 006adb07  5d                   pop ebp
// 006adb08  894804               mov dword ptr [eax + 4], ecx
// 006adb0b  c6400801             mov byte ptr [eax + 8], 1
// 006adb0f  8910                 mov dword ptr [eax], edx
// 006adb11  5b                   pop ebx
// 006adb12  83c40c               add esp, 0xc
// 006adb15  c20800               ret 8
// 006adb18  8b442420             mov eax, dword ptr [esp + 0x20]
// 006adb1c  5f                   pop edi
// 006adb1d  5e                   pop esi
// 006adb1e  896804               mov dword ptr [eax + 4], ebp
// 006adb21  5d                   pop ebp
// 006adb22  c6400800             mov byte ptr [eax + 8], 0
// 006adb26  8910                 mov dword ptr [eax], edx
// 006adb28  5b                   pop ebx
// 006adb29  83c40c               add esp, 0xc
// 006adb2c  c20800               ret 8
// standard library map_int<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@HPAUT@@U?$less@H@std@@V?$allocator@U?$pair@$$CBHPAUT@@@std@@@3@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBHPAUT@@@2@@Z)

// stl: map_int<ptr>
struct T; typedef T* E;
#include <map>
template class std::map<int, E>;
