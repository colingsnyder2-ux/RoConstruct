// from server: 100% by auto
// roc 2009-12 00769230  unit: RBX::VInstance::?$NonFactoryProduct  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00769230
//
// 00769230  83ec14               sub esp, 0x14
// 00769233  56                   push esi
// 00769234  8bf1                 mov esi, ecx
// 00769236  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0076923a  57                   push edi
// 0076923b  7521                 jne 0x76925e
// 0076923d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00769241  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00769244  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00769248  50                   push eax
// 00769249  51                   push ecx
// 0076924a  6a01                 push 1
// 0076924c  57                   push edi
// 0076924d  8bce                 mov ecx, esi
// 0076924f  e83cf5ffff           call 0x768790
// 00769254  8bc7                 mov eax, edi
// 00769256  5f                   pop edi
// 00769257  5e                   pop esi
// 00769258  83c414               add esp, 0x14
// 0076925b  c21000               ret 0x10
// 0076925e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00769262  8b5618               mov edx, dword ptr [esi + 0x18]
// 00769265  8b3a                 mov edi, dword ptr [edx]
// 00769267  8b0e                 mov ecx, dword ptr [esi]
// 00769269  53                   push ebx
// 0076926a  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 00769270  85c0                 test eax, eax
// 00769272  7404                 je 0x769278
// 00769274  3bc1                 cmp eax, ecx
// 00769276  7406                 je 0x76927e
// 00769278  ffd3                 call ebx
// 0076927a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0076927e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00769282  55                   push ebp
// 00769283  3bd7                 cmp edx, edi
// 00769285  753a                 jne 0x7692c1
// 00769287  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0076928b  83c20c               add edx, 0xc
// 0076928e  52                   push edx
// 0076928f  57                   push edi
// 00769290  ff15d8b59800         call dword ptr [0x98b5d8]
// 00769296  83c408               add esp, 8
// 00769299  84c0                 test al, al
// 0076929b  0f849a010000         je 0x76943b
// 007692a1  8b442430             mov eax, dword ptr [esp + 0x30]
// 007692a5  57                   push edi
// 007692a6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007692aa  50                   push eax
// 007692ab  6a01                 push 1
// 007692ad  57                   push edi
// 007692ae  8bce                 mov ecx, esi
// 007692b0  e8dbf4ffff           call 0x768790
// 007692b5  5d                   pop ebp
// 007692b6  5b                   pop ebx
// 007692b7  8bc7                 mov eax, edi
// 007692b9  5f                   pop edi
// 007692ba  5e                   pop esi
// 007692bb  83c414               add esp, 0x14
// 007692be  c21000               ret 0x10
// 007692c1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007692c4  8b0e                 mov ecx, dword ptr [esi]
// 007692c6  85c0                 test eax, eax
// 007692c8  7404                 je 0x7692ce
// 007692ca  3bc1                 cmp eax, ecx
// 007692cc  7406                 je 0x7692d4
// 007692ce  ffd3                 call ebx
// 007692d0  8b542430             mov edx, dword ptr [esp + 0x30]
// 007692d4  3bd7                 cmp edx, edi
// 007692d6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 007692da  753e                 jne 0x76931a
// 007692dc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007692df  8b4108               mov eax, dword ptr [ecx + 8]
// 007692e2  83c00c               add eax, 0xc
// 007692e5  57                   push edi
// 007692e6  50                   push eax
// 007692e7  ff15d8b59800         call dword ptr [0x98b5d8]
// 007692ed  83c408               add esp, 8
// 007692f0  84c0                 test al, al
// 007692f2  0f8443010000         je 0x76943b
// 007692f8  8b5618               mov edx, dword ptr [esi + 0x18]
// 007692fb  8b4208               mov eax, dword ptr [edx + 8]
// 007692fe  57                   push edi
// 007692ff  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00769303  50                   push eax
// 00769304  6a00                 push 0
// 00769306  57                   push edi
// 00769307  8bce                 mov ecx, esi
// 00769309  e882f4ffff           call 0x768790
// 0076930e  5d                   pop ebp
// 0076930f  5b                   pop ebx
// 00769310  8bc7                 mov eax, edi
// 00769312  5f                   pop edi
// 00769313  5e                   pop esi
// 00769314  83c414               add esp, 0x14
// 00769317  c21000               ret 0x10
// 0076931a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 00769320  83c20c               add edx, 0xc
// 00769323  52                   push edx
// 00769324  57                   push edi
// 00769325  ffd5                 call ebp
// 00769327  83c408               add esp, 8
// 0076932a  84c0                 test al, al
// 0076932c  746c                 je 0x76939a
// 0076932e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00769332  8b542430             mov edx, dword ptr [esp + 0x30]
// 00769336  894c2410             mov dword ptr [esp + 0x10], ecx
// 0076933a  8d4c2410             lea ecx, [esp + 0x10]
// 0076933e  89542414             mov dword ptr [esp + 0x14], edx
// 00769342  e819a5daff           call 0x513860
// 00769347  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0076934b  57                   push edi
// 0076934c  8d430c               lea eax, [ebx + 0xc]
// 0076934f  50                   push eax
// 00769350  8d4e08               lea ecx, [esi + 8]
// 00769353  e8f814d1ff           call 0x47a850
// 00769358  84c0                 test al, al
// 0076935a  743e                 je 0x76939a
// 0076935c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0076935f  80793100             cmp byte ptr [ecx + 0x31], 0
// 00769363  57                   push edi
// 00769364  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00769368  8bce                 mov ecx, esi
// 0076936a  7415                 je 0x769381
// 0076936c  53                   push ebx
// 0076936d  6a00                 push 0
// 0076936f  57                   push edi
// 00769370  e81bf4ffff           call 0x768790
// 00769375  5d                   pop ebp
// 00769376  5b                   pop ebx
// 00769377  8bc7                 mov eax, edi
// 00769379  5f                   pop edi
// 0076937a  5e                   pop esi
// 0076937b  83c414               add esp, 0x14
// 0076937e  c21000               ret 0x10
// 00769381  8b542434             mov edx, dword ptr [esp + 0x34]
// 00769385  52                   push edx
// 00769386  6a01                 push 1
// 00769388  57                   push edi
// 00769389  e802f4ffff           call 0x768790
// 0076938e  5d                   pop ebp
// 0076938f  5b                   pop ebx
// 00769390  8bc7                 mov eax, edi
// 00769392  5f                   pop edi
// 00769393  5e                   pop esi
// 00769394  83c414               add esp, 0x14
// 00769397  c21000               ret 0x10
// 0076939a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0076939e  83c00c               add eax, 0xc
// 007693a1  57                   push edi
// 007693a2  50                   push eax
// 007693a3  ffd5                 call ebp
// 007693a5  83c408               add esp, 8
// 007693a8  84c0                 test al, al
// 007693aa  0f848b000000         je 0x76943b
// 007693b0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007693b4  8b542430             mov edx, dword ptr [esp + 0x30]
// 007693b8  8b4618               mov eax, dword ptr [esi + 0x18]
// 007693bb  894c2410             mov dword ptr [esp + 0x10], ecx
// 007693bf  8b0e                 mov ecx, dword ptr [esi]
// 007693c1  894c2418             mov dword ptr [esp + 0x18], ecx
// 007693c5  8d4c2410             lea ecx, [esp + 0x10]
// 007693c9  89542414             mov dword ptr [esp + 0x14], edx
// 007693cd  8944241c             mov dword ptr [esp + 0x1c], eax
// 007693d1  e81aa5daff           call 0x5138f0
// 007693d6  8d542418             lea edx, [esp + 0x18]
// 007693da  52                   push edx
// 007693db  8d4c2414             lea ecx, [esp + 0x14]
// 007693df  e87c2fe6ff           call 0x5cc360
// 007693e4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007693e8  84c0                 test al, al
// 007693ea  7511                 jne 0x7693fd
// 007693ec  8d430c               lea eax, [ebx + 0xc]
// 007693ef  50                   push eax
// 007693f0  57                   push edi
// 007693f1  8d4e08               lea ecx, [esi + 8]
// 007693f4  e85714d1ff           call 0x47a850
// 007693f9  84c0                 test al, al
// 007693fb  743e                 je 0x76943b
// 007693fd  8b442430             mov eax, dword ptr [esp + 0x30]
// 00769401  8b4808               mov ecx, dword ptr [eax + 8]
// 00769404  80793100             cmp byte ptr [ecx + 0x31], 0
// 00769408  57                   push edi
// 00769409  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0076940d  8bce                 mov ecx, esi
// 0076940f  7415                 je 0x769426
// 00769411  50                   push eax
// 00769412  6a00                 push 0
// 00769414  57                   push edi
// 00769415  e876f3ffff           call 0x768790
// 0076941a  5d                   pop ebp
// 0076941b  5b                   pop ebx
// 0076941c  8bc7                 mov eax, edi
// 0076941e  5f                   pop edi
// 0076941f  5e                   pop esi
// 00769420  83c414               add esp, 0x14
// 00769423  c21000               ret 0x10
// 00769426  53                   push ebx
// 00769427  6a01                 push 1
// 00769429  57                   push edi
// 0076942a  e861f3ffff           call 0x768790
// 0076942f  5d                   pop ebp
// 00769430  5b                   pop ebx
// 00769431  8bc7                 mov eax, edi
// 00769433  5f                   pop edi
// 00769434  5e                   pop esi
// 00769435  83c414               add esp, 0x14
// 00769438  c21000               ret 0x10
// 0076943b  57                   push edi
// 0076943c  8d54241c             lea edx, [esp + 0x1c]
// 00769440  52                   push edx
// 00769441  8bce                 mov ecx, esi
// 00769443  e888f8ffff           call 0x768cd0
// 00769448  8b10                 mov edx, dword ptr [eax]
// 0076944a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0076944e  5d                   pop ebp
// 0076944f  5b                   pop ebx
// 00769450  8911                 mov dword ptr [ecx], edx
// 00769452  8b4004               mov eax, dword ptr [eax + 4]
// 00769455  5f                   pop edi
// 00769456  894104               mov dword ptr [ecx + 4], eax
// 00769459  8bc1                 mov eax, ecx
// 0076945b  5e                   pop esi
// 0076945c  83c414               add esp, 0x14
// 0076945f  c21000               ret 0x10
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
