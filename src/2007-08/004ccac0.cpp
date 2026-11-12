// from server: 100% by auto
// roc 2007-08 004ccac0  unit: CSHA1  size: 340 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ccac0
//
// 004ccac0  83ec28               sub esp, 0x28
// 004ccac3  a188518b00           mov eax, dword ptr [0x8b5188]
// 004ccac8  33c4                 xor eax, esp
// 004ccaca  89442424             mov dword ptr [esp + 0x24], eax
// 004ccace  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 004ccad2  8b442438             mov eax, dword ptr [esp + 0x38]
// 004ccad6  55                   push ebp
// 004ccad7  56                   push esi
// 004ccad8  8b742434             mov esi, dword ptr [esp + 0x34]
// 004ccadc  85f6                 test esi, esi
// 004ccade  8d2ccd00000000       lea ebp, [ecx*8]
// 004ccae5  7516                 jne 0x4ccafd
// 004ccae7  5e                   pop esi
// 004ccae8  b8fdffffff           mov eax, 0xfffffffd
// 004ccaed  5d                   pop ebp
// 004ccaee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004ccaf2  33cc                 xor ecx, esp
// 004ccaf4  e8253f1600           call 0x630a1e
// 004ccaf9  83c428               add esp, 0x28
// 004ccafc  c3                   ret 
// 004ccafd  53                   push ebx
// 004ccafe  8a5c243c             mov bl, byte ptr [esp + 0x3c]
// 004ccb02  84db                 test bl, bl
// 004ccb04  741a                 je 0x4ccb20
// 004ccb06  80fb01               cmp bl, 1
// 004ccb09  7415                 je 0x4ccb20
// 004ccb0b  5b                   pop ebx
// 004ccb0c  5e                   pop esi
// 004ccb0d  83c8ff               or eax, 0xffffffff
// 004ccb10  5d                   pop ebp
// 004ccb11  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004ccb15  33cc                 xor ecx, esp
// 004ccb17  e8023f1600           call 0x630a1e
// 004ccb1c  83c428               add esp, 0x28
// 004ccb1f  c3                   ret 
// 004ccb20  81fd80000000         cmp ebp, 0x80
// 004ccb26  881e                 mov byte ptr [esi], bl
// 004ccb28  7414                 je 0x4ccb3e
// 004ccb2a  81fdc0000000         cmp ebp, 0xc0
// 004ccb30  740c                 je 0x4ccb3e
// 004ccb32  81fd00010000         cmp ebp, 0x100
// 004ccb38  0f85bf000000         jne 0x4ccbfd
// 004ccb3e  85c0                 test eax, eax
// 004ccb40  896e04               mov dword ptr [esi + 4], ebp
// 004ccb43  0f84b4000000         je 0x4ccbfd
// 004ccb49  57                   push edi
// 004ccb4a  51                   push ecx
// 004ccb4b  50                   push eax
// 004ccb4c  8d7e08               lea edi, [esi + 8]
// 004ccb4f  57                   push edi
// 004ccb50  ff1578e97700         call dword ptr [0x77e978]
// 004ccb56  8bc5                 mov eax, ebp
// 004ccb58  99                   cdq 
// 004ccb59  83e21f               and edx, 0x1f
// 004ccb5c  03c2                 add eax, edx
// 004ccb5e  c1f805               sar eax, 5
// 004ccb61  83c006               add eax, 6
// 004ccb64  a3ccf98b00           mov dword ptr [0x8bf9cc], eax
// 004ccb69  8b6e04               mov ebp, dword ptr [esi + 4]
// 004ccb6c  8bc5                 mov eax, ebp
// 004ccb6e  99                   cdq 
// 004ccb6f  83e207               and edx, 7
// 004ccb72  03c2                 add eax, edx
// 004ccb74  c1f803               sar eax, 3
// 004ccb77  83c40c               add esp, 0xc
// 004ccb7a  33c9                 xor ecx, ecx
// 004ccb7c  85c0                 test eax, eax
// 004ccb7e  7e41                 jle 0x4ccbc1
// 004ccb80  8bc5                 mov eax, ebp
// 004ccb82  99                   cdq 
// 004ccb83  83e207               and edx, 7
// 004ccb86  03c2                 add eax, edx
// 004ccb88  c1f803               sar eax, 3
// 004ccb8b  89442410             mov dword ptr [esp + 0x10], eax
// 004ccb8f  90                   nop 
// 004ccb90  8bc1                 mov eax, ecx
// 004ccb92  99                   cdq 
// 004ccb93  83e203               and edx, 3
// 004ccb96  03c2                 add eax, edx
// 004ccb98  8bd1                 mov edx, ecx
// 004ccb9a  c1f802               sar eax, 2
// 004ccb9d  81e203000080         and edx, 0x80000003
// 004ccba3  7905                 jns 0x4ccbaa
// 004ccba5  4a                   dec edx
// 004ccba6  83cafc               or edx, 0xfffffffc
// 004ccba9  42                   inc edx
// 004ccbaa  8a1c0f               mov bl, byte ptr [edi + ecx]
// 004ccbad  83c101               add ecx, 1
// 004ccbb0  3b4c2410             cmp ecx, dword ptr [esp + 0x10]
// 004ccbb4  8d541414             lea edx, [esp + edx + 0x14]
// 004ccbb8  881c82               mov byte ptr [edx + eax*4], bl
// 004ccbbb  7cd3                 jl 0x4ccb90
// 004ccbbd  8a5c2440             mov bl, byte ptr [esp + 0x40]
// 004ccbc1  8d7e30               lea edi, [esi + 0x30]
// 004ccbc4  57                   push edi
// 004ccbc5  8d442418             lea eax, [esp + 0x18]
// 004ccbc9  55                   push ebp
// 004ccbca  50                   push eax
// 004ccbcb  e840f5ffff           call 0x4cc110
// 004ccbd0  83c40c               add esp, 0xc
// 004ccbd3  80fb01               cmp bl, 1
// 004ccbd6  750d                 jne 0x4ccbe5
// 004ccbd8  8b4e04               mov ecx, dword ptr [esi + 4]
// 004ccbdb  57                   push edi
// 004ccbdc  51                   push ecx
// 004ccbdd  e80ef7ffff           call 0x4cc2f0
// 004ccbe2  83c408               add esp, 8
// 004ccbe5  5f                   pop edi
// 004ccbe6  5b                   pop ebx
// 004ccbe7  5e                   pop esi
// 004ccbe8  b801000000           mov eax, 1
// 004ccbed  5d                   pop ebp
// 004ccbee  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 004ccbf2  33cc                 xor ecx, esp
// 004ccbf4  e8253e1600           call 0x630a1e
// 004ccbf9  83c428               add esp, 0x28
// 004ccbfc  c3                   ret 
// 004ccbfd  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 004ccc01  5b                   pop ebx
// 004ccc02  5e                   pop esi
// 004ccc03  5d                   pop ebp
// 004ccc04  33cc                 xor ecx, esp
// 004ccc06  b8feffffff           mov eax, 0xfffffffe
// 004ccc0b  e80e3e1600           call 0x630a1e
// 004ccc10  83c428               add esp, 0x28
// 004ccc13  c3                   ret 
// library openrbx-raknet/rijndael.cpp (function ?makeKey@@YAHPAUkeyInstance@@EHPAD@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /EHsc /MD
// roc-lib: openrbx-raknet rijndael.cpp
