// roc 2012-06 009e4df0  unit: CXTSplitterWnd  size: 423 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e4df0
//
// 009e4df0  83ec10               sub esp, 0x10
// 009e4df3  56                   push esi
// 009e4df4  8bf1                 mov esi, ecx
// 009e4df6  8b8684000000         mov eax, dword ptr [esi + 0x84]
// 009e4dfc  3b465c               cmp eax, dword ptr [esi + 0x5c]
// 009e4dff  750d                 jne 0x9e4e0e
// 009e4e01  83bef4000000ff       cmp dword ptr [esi + 0xf4], -1
// 009e4e08  0f8484010000         je 0x9e4f92
// 009e4e0e  8b9690000000         mov edx, dword ptr [esi + 0x90]
// 009e4e14  53                   push ebx
// 009e4e15  55                   push ebp
// 009e4e16  57                   push edi
// 009e4e17  8bbef4000000         mov edi, dword ptr [esi + 0xf4]
// 009e4e1d  8d0c40               lea ecx, [eax + eax*2]
// 009e4e20  c786f4000000ffffffff mov dword ptr [esi + 0xf4], 0xffffffff
// 009e4e2a  8b4c8a08             mov ecx, dword ptr [edx + ecx*4 + 8]
// 009e4e2e  40                   inc eax
// 009e4e2f  33db                 xor ebx, ebx
// 009e4e31  399e80000000         cmp dword ptr [esi + 0x80], ebx
// 009e4e37  897c2410             mov dword ptr [esp + 0x10], edi
// 009e4e3b  894c241c             mov dword ptr [esp + 0x1c], ecx
// 009e4e3f  898684000000         mov dword ptr [esi + 0x84], eax
// 009e4e45  0f8eb6000000         jle 0x9e4f01
// 009e4e4b  33c0                 xor eax, eax
// 009e4e4d  89442414             mov dword ptr [esp + 0x14], eax
// 009e4e51  eb04                 jmp 0x9e4e57
// 009e4e53  8b442414             mov eax, dword ptr [esp + 0x14]
// 009e4e57  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 009e4e5d  83f9ff               cmp ecx, -1
// 009e4e60  7407                 je 0x9e4e69
// 009e4e62  3bcb                 cmp ecx, ebx
// 009e4e64  7f03                 jg 0x9e4e69
// 009e4e66  83c010               add eax, 0x10
// 009e4e69  8b9684000000         mov edx, dword ptr [esi + 0x84]
// 009e4e6f  0500e90000           add eax, 0xe900
// 009e4e74  03d0                 add edx, eax
// 009e4e76  52                   push edx
// 009e4e77  8bce                 mov ecx, esi
// 009e4e79  e872e1f9ff           call 0x982ff0
// 009e4e7e  8be8                 mov ebp, eax
// 009e4e80  896c2418             mov dword ptr [esp + 0x18], ebp
// 009e4e84  85ed                 test ebp, ebp
// 009e4e86  0f8403010000         je 0x9e4f8f
// 009e4e8c  6a08                 push 8
// 009e4e8e  8bcd                 mov ecx, ebp
// 009e4e90  e80fdcf9ff           call 0x982aa4
// 009e4e95  8bbe84000000         mov edi, dword ptr [esi + 0x84]
// 009e4e9b  83ef02               sub edi, 2
// 009e4e9e  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 009e4ea2  7c32                 jl 0x9e4ed6
// 009e4ea4  57                   push edi
// 009e4ea5  53                   push ebx
// 009e4ea6  8bce                 mov ecx, esi
// 009e4ea8  e865ddf9ff           call 0x982c12
// 009e4ead  8be8                 mov ebp, eax
// 009e4eaf  85ed                 test ebp, ebp
// 009e4eb1  0f84d8000000         je 0x9e4f8f
// 009e4eb7  8d4701               lea eax, [edi + 1]
// 009e4eba  50                   push eax
// 009e4ebb  53                   push ebx
// 009e4ebc  8bce                 mov ecx, esi
// 009e4ebe  e8addcf9ff           call 0x982b70
// 009e4ec3  50                   push eax
// 009e4ec4  8bcd                 mov ecx, ebp
// 009e4ec6  e8354c0b00           call 0xa99b00
// 009e4ecb  4f                   dec edi
// 009e4ecc  3b7c2410             cmp edi, dword ptr [esp + 0x10]
// 009e4ed0  7dd2                 jge 0x9e4ea4
// 009e4ed2  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 009e4ed6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 009e4eda  51                   push ecx
// 009e4edb  53                   push ebx
// 009e4edc  8bce                 mov ecx, esi
// 009e4ede  e88ddcf9ff           call 0x982b70
// 009e4ee3  50                   push eax
// 009e4ee4  8bcd                 mov ecx, ebp
// 009e4ee6  e8154c0b00           call 0xa99b00
// 009e4eeb  8344241410           add dword ptr [esp + 0x14], 0x10
// 009e4ef0  43                   inc ebx
// 009e4ef1  3b9e80000000         cmp ebx, dword ptr [esi + 0x80]
// 009e4ef7  0f8c56ffffff         jl 0x9e4e53
// 009e4efd  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 009e4f01  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 009e4f07  83f8ff               cmp eax, -1
// 009e4f0a  7430                 je 0x9e4f3c
// 009e4f0c  05900e0000           add eax, 0xe90
// 009e4f11  c1e004               shl eax, 4
// 009e4f14  038684000000         add eax, dword ptr [esi + 0x84]
// 009e4f1a  8bce                 mov ecx, esi
// 009e4f1c  50                   push eax
// 009e4f1d  e8cee0f9ff           call 0x982ff0
// 009e4f22  85c0                 test eax, eax
// 009e4f24  7416                 je 0x9e4f3c
// 009e4f26  8b5658               mov edx, dword ptr [esi + 0x58]
// 009e4f29  81c2900e0000         add edx, 0xe90
// 009e4f2f  c1e204               shl edx, 4
// 009e4f32  03d7                 add edx, edi
// 009e4f34  52                   push edx
// 009e4f35  8bc8                 mov ecx, eax
// 009e4f37  e8c44b0b00           call 0xa99b00
// 009e4f3c  8d4f01               lea ecx, [edi + 1]
// 009e4f3f  3b8e84000000         cmp ecx, dword ptr [esi + 0x84]
// 009e4f45  7d24                 jge 0x9e4f6b
// 009e4f47  8d1449               lea edx, [ecx + ecx*2]
// 009e4f4a  03d2                 add edx, edx
// 009e4f4c  03d2                 add edx, edx
// 009e4f4e  8bff                 mov edi, edi
// 009e4f50  8b8690000000         mov eax, dword ptr [esi + 0x90]
// 009e4f56  8b5c10fc             mov ebx, dword ptr [eax + edx - 4]
// 009e4f5a  03c2                 add eax, edx
// 009e4f5c  41                   inc ecx
// 009e4f5d  895804               mov dword ptr [eax + 4], ebx
// 009e4f60  83c20c               add edx, 0xc
// 009e4f63  3b8e84000000         cmp ecx, dword ptr [esi + 0x84]
// 009e4f69  7ce5                 jl 0x9e4f50
// 009e4f6b  8b9690000000         mov edx, dword ptr [esi + 0x90]
// 009e4f71  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 009e4f75  8d0c7f               lea ecx, [edi + edi*2]
// 009e4f78  5f                   pop edi
// 009e4f79  89448a04             mov dword ptr [edx + ecx*4 + 4], eax
// 009e4f7d  8b16                 mov edx, dword ptr [esi]
// 009e4f7f  8b8250010000         mov eax, dword ptr [edx + 0x150]
// 009e4f85  5d                   pop ebp
// 009e4f86  5b                   pop ebx
// 009e4f87  8bce                 mov ecx, esi
// 009e4f89  5e                   pop esi
// 009e4f8a  83c410               add esp, 0x10
// 009e4f8d  ffe0                 jmp eax
// 009e4f8f  5f                   pop edi
// 009e4f90  5d                   pop ebp
// 009e4f91  5b                   pop ebx
// 009e4f92  5e                   pop esi
// 009e4f93  83c410               add esp, 0x10
// 009e4f96  c3                   ret 
// copied from an identical function in another client (function ?ShowColumn@CXTSplitterWnd@@UAEXXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1