// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 00403aa0  unit: ATL::CComClassFactory  size: 489 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00403aa0
//
// 00403aa0  6aff                 push -1
// 00403aa2  6808987300           push 0x739808
// 00403aa7  64a100000000         mov eax, dword ptr fs:[0]
// 00403aad  50                   push eax
// 00403aae  83ec0c               sub esp, 0xc
// 00403ab1  53                   push ebx
// 00403ab2  56                   push esi
// 00403ab3  57                   push edi
// 00403ab4  a188518b00           mov eax, dword ptr [0x8b5188]
// 00403ab9  33c4                 xor eax, esp
// 00403abb  50                   push eax
// 00403abc  8d44241c             lea eax, [esp + 0x1c]
// 00403ac0  64a300000000         mov dword ptr fs:[0], eax
// 00403ac6  33db                 xor ebx, ebx
// 00403ac8  895c2410             mov dword ptr [esp + 0x10], ebx
// 00403acc  3bcb                 cmp ecx, ebx
// 00403ace  895c2424             mov dword ptr [esp + 0x24], ebx
// 00403ad2  7405                 je 0x403ad9
// 00403ad4  8d41e8               lea eax, [ecx - 0x18]
// 00403ad7  eb02                 jmp 0x403adb
// 00403ad9  33c0                 xor eax, eax
// 00403adb  8b4820               mov ecx, dword ptr [eax + 0x20]
// 00403ade  8d542410             lea edx, [esp + 0x10]
// 00403ae2  83c020               add eax, 0x20
// 00403ae5  52                   push edx
// 00403ae6  68f04c7800           push 0x784cf0
// 00403aeb  50                   push eax
// 00403aec  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00403aef  ffd0                 call eax
// 00403af1  8bf0                 mov esi, eax
// 00403af3  3bf3                 cmp esi, ebx
// 00403af5  0f8c10010000         jl 0x403c0b
// 00403afb  895c2414             mov dword ptr [esp + 0x14], ebx
// 00403aff  8b442410             mov eax, dword ptr [esp + 0x10]
// 00403b03  8b08                 mov ecx, dword ptr [eax]
// 00403b05  8d542414             lea edx, [esp + 0x14]
// 00403b09  52                   push edx
// 00403b0a  681c4e7c00           push 0x7c4e1c
// 00403b0f  682c4e7c00           push 0x7c4e2c
// 00403b14  50                   push eax
// 00403b15  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00403b18  c644243401           mov byte ptr [esp + 0x34], 1
// 00403b1d  ffd0                 call eax
// 00403b1f  8bf8                 mov edi, eax
// 00403b21  3bfb                 cmp edi, ebx
// 00403b23  8b442414             mov eax, dword ptr [esp + 0x14]
// 00403b27  7d3f                 jge 0x403b68
// 00403b29  3bc3                 cmp eax, ebx
// 00403b2b  885c2424             mov byte ptr [esp + 0x24], bl
// 00403b2f  7408                 je 0x403b39
// 00403b31  8b08                 mov ecx, dword ptr [eax]
// 00403b33  8b5108               mov edx, dword ptr [ecx + 8]
// 00403b36  50                   push eax
// 00403b37  ffd2                 call edx
// 00403b39  8b442410             mov eax, dword ptr [esp + 0x10]
// 00403b3d  3bc3                 cmp eax, ebx
// 00403b3f  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00403b47  7408                 je 0x403b51
// 00403b49  8b08                 mov ecx, dword ptr [eax]
// 00403b4b  8b5108               mov edx, dword ptr [ecx + 8]
// 00403b4e  50                   push eax
// 00403b4f  ffd2                 call edx
// 00403b51  8bc7                 mov eax, edi
// 00403b53  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00403b57  64890d00000000       mov dword ptr fs:[0], ecx
// 00403b5e  59                   pop ecx
// 00403b5f  5f                   pop edi
// 00403b60  5e                   pop esi
// 00403b61  5b                   pop ebx
// 00403b62  83c418               add esp, 0x18
// 00403b65  c20800               ret 8
// 00403b68  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00403b6c  8b08                 mov ecx, dword ptr [eax]
// 00403b6e  8b5178               mov edx, dword ptr [ecx + 0x78]
// 00403b71  56                   push esi
// 00403b72  50                   push eax
// 00403b73  ffd2                 call edx
// 00403b75  85c0                 test eax, eax
// 00403b77  7d06                 jge 0x403b7f
// 00403b79  8b442414             mov eax, dword ptr [esp + 0x14]
// 00403b7d  ebaa                 jmp 0x403b29
// 00403b7f  895c2418             mov dword ptr [esp + 0x18], ebx
// 00403b83  8b442410             mov eax, dword ptr [esp + 0x10]
// 00403b87  8b08                 mov ecx, dword ptr [eax]
// 00403b89  8d542418             lea edx, [esp + 0x18]
// 00403b8d  52                   push edx
// 00403b8e  680c4e7c00           push 0x7c4e0c
// 00403b93  680c4e7c00           push 0x7c4e0c
// 00403b98  50                   push eax
// 00403b99  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00403b9c  c644243402           mov byte ptr [esp + 0x34], 2
// 00403ba1  ffd0                 call eax
// 00403ba3  8bf8                 mov edi, eax
// 00403ba5  3bfb                 cmp edi, ebx
// 00403ba7  7d1e                 jge 0x403bc7
// 00403ba9  8b442418             mov eax, dword ptr [esp + 0x18]
// 00403bad  3bc3                 cmp eax, ebx
// 00403baf  c644242401           mov byte ptr [esp + 0x24], 1
// 00403bb4  7408                 je 0x403bbe
// 00403bb6  8b08                 mov ecx, dword ptr [eax]
// 00403bb8  8b5108               mov edx, dword ptr [ecx + 8]
// 00403bbb  50                   push eax
// 00403bbc  ffd2                 call edx
// 00403bbe  8b442414             mov eax, dword ptr [esp + 0x14]
// 00403bc2  e962ffffff           jmp 0x403b29
// 00403bc7  8b06                 mov eax, dword ptr [esi]
// 00403bc9  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00403bcd  8b742430             mov esi, dword ptr [esp + 0x30]
// 00403bd1  8b11                 mov edx, dword ptr [ecx]
// 00403bd3  53                   push ebx
// 00403bd4  56                   push esi
// 00403bd5  50                   push eax
// 00403bd6  8b4214               mov eax, dword ptr [edx + 0x14]
// 00403bd9  51                   push ecx
// 00403bda  ffd0                 call eax
// 00403bdc  8bf0                 mov esi, eax
// 00403bde  3bf3                 cmp esi, ebx
// 00403be0  8b442418             mov eax, dword ptr [esp + 0x18]
// 00403be4  c644242401           mov byte ptr [esp + 0x24], 1
// 00403be9  7d4f                 jge 0x403c3a
// 00403beb  3bc3                 cmp eax, ebx
// 00403bed  7408                 je 0x403bf7
// 00403bef  8b08                 mov ecx, dword ptr [eax]
// 00403bf1  8b5108               mov edx, dword ptr [ecx + 8]
// 00403bf4  50                   push eax
// 00403bf5  ffd2                 call edx
// 00403bf7  8b442414             mov eax, dword ptr [esp + 0x14]
// 00403bfb  3bc3                 cmp eax, ebx
// 00403bfd  885c2424             mov byte ptr [esp + 0x24], bl
// 00403c01  7408                 je 0x403c0b
// 00403c03  8b08                 mov ecx, dword ptr [eax]
// 00403c05  8b5108               mov edx, dword ptr [ecx + 8]
// 00403c08  50                   push eax
// 00403c09  ffd2                 call edx
// 00403c0b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00403c0f  3bc3                 cmp eax, ebx
// 00403c11  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00403c19  7408                 je 0x403c23
// 00403c1b  8b08                 mov ecx, dword ptr [eax]
// 00403c1d  8b5108               mov edx, dword ptr [ecx + 8]
// 00403c20  50                   push eax
// 00403c21  ffd2                 call edx
// 00403c23  8bc6                 mov eax, esi
// 00403c25  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00403c29  64890d00000000       mov dword ptr fs:[0], ecx
// 00403c30  59                   pop ecx
// 00403c31  5f                   pop edi
// 00403c32  5e                   pop esi
// 00403c33  5b                   pop ebx
// 00403c34  83c418               add esp, 0x18
// 00403c37  c20800               ret 8
// 00403c3a  3bc3                 cmp eax, ebx
// 00403c3c  7408                 je 0x403c46
// 00403c3e  8b08                 mov ecx, dword ptr [eax]
// 00403c40  8b5108               mov edx, dword ptr [ecx + 8]
// 00403c43  50                   push eax
// 00403c44  ffd2                 call edx
// 00403c46  8b442414             mov eax, dword ptr [esp + 0x14]
// 00403c4a  3bc3                 cmp eax, ebx
// 00403c4c  885c2424             mov byte ptr [esp + 0x24], bl
// 00403c50  7408                 je 0x403c5a
// 00403c52  8b08                 mov ecx, dword ptr [eax]
// 00403c54  8b5108               mov edx, dword ptr [ecx + 8]
// 00403c57  50                   push eax
// 00403c58  ffd2                 call edx
// 00403c5a  8b442410             mov eax, dword ptr [esp + 0x10]
// 00403c5e  3bc3                 cmp eax, ebx
// 00403c60  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00403c68  7408                 je 0x403c72
// 00403c6a  8b08                 mov ecx, dword ptr [eax]
// 00403c6c  8b5108               mov edx, dword ptr [ecx + 8]
// 00403c6f  50                   push eax
// 00403c70  ffd2                 call edx
// 00403c72  33c0                 xor eax, eax
// 00403c74  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00403c78  64890d00000000       mov dword ptr fs:[0], ecx
// 00403c7f  59                   pop ecx
// 00403c80  5f                   pop edi
// 00403c81  5e                   pop esi
// 00403c82  5b                   pop ebx
// 00403c83  83c418               add esp, 0x18
// 00403c86  c20800               ret 8

// from server: 100% by colin
// roc 2008-06 00403210  unit: ATL::CComClassFactory  size: 505 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403210
//
// 00403210  6aff                 push -1
// 00403212  68f8cb7b00           push 0x7bcbf8
// 00403217  64a100000000         mov eax, dword ptr fs:[0]
// 0040321d  50                   push eax
// 0040321e  64892500000000       mov dword ptr fs:[0], esp
// 00403225  83ec0c               sub esp, 0xc
// 00403228  53                   push ebx
// 00403229  33db                 xor ebx, ebx
// 0040322b  56                   push esi
// 0040322c  895c2408             mov dword ptr [esp + 8], ebx
// 00403230  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00403234  3bcb                 cmp ecx, ebx
// 00403236  7405                 je 0x40323d
// 00403238  8d41f8               lea eax, [ecx - 8]
// 0040323b  eb02                 jmp 0x40323f
// 0040323d  33c0                 xor eax, eax
// 0040323f  8b4810               mov ecx, dword ptr [eax + 0x10]
// 00403242  8d542408             lea edx, [esp + 8]
// 00403246  83c010               add eax, 0x10
// 00403249  52                   push edx
// 0040324a  68a8af8000           push 0x80afa8
// 0040324f  50                   push eax
// 00403250  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00403253  ffd0                 call eax
// 00403255  8bf0                 mov esi, eax
// 00403257  3bf3                 cmp esi, ebx
// 00403259  7d2d                 jge 0x403288
// 0040325b  8b442408             mov eax, dword ptr [esp + 8]
// 0040325f  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00403267  3bc3                 cmp eax, ebx
// 00403269  7408                 je 0x403273
// 0040326b  8b08                 mov ecx, dword ptr [eax]
// 0040326d  8b5108               mov edx, dword ptr [ecx + 8]
// 00403270  50                   push eax
// 00403271  ffd2                 call edx
// 00403273  8bc6                 mov eax, esi
// 00403275  5e                   pop esi
// 00403276  5b                   pop ebx
// 00403277  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040327b  64890d00000000       mov dword ptr fs:[0], ecx
// 00403282  83c418               add esp, 0x18
// 00403285  c20800               ret 8
// 00403288  57                   push edi
// 00403289  895c2410             mov dword ptr [esp + 0x10], ebx
// 0040328d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403291  8b08                 mov ecx, dword ptr [eax]
// 00403293  8d542410             lea edx, [esp + 0x10]
// 00403297  52                   push edx
// 00403298  68ac018500           push 0x8501ac
// 0040329d  689c018500           push 0x85019c
// 004032a2  50                   push eax
// 004032a3  8b410c               mov eax, dword ptr [ecx + 0xc]
// 004032a6  c644243001           mov byte ptr [esp + 0x30], 1
// 004032ab  ffd0                 call eax
// 004032ad  8bf8                 mov edi, eax
// 004032af  3bfb                 cmp edi, ebx
// 004032b1  8b442410             mov eax, dword ptr [esp + 0x10]
// 004032b5  7c54                 jl 0x40330b
// 004032b7  8b742428             mov esi, dword ptr [esp + 0x28]
// 004032bb  8b08                 mov ecx, dword ptr [eax]
// 004032bd  8b5178               mov edx, dword ptr [ecx + 0x78]
// 004032c0  56                   push esi
// 004032c1  50                   push eax
// 004032c2  ffd2                 call edx
// 004032c4  85c0                 test eax, eax
// 004032c6  7c3f                 jl 0x403307
// 004032c8  895c2414             mov dword ptr [esp + 0x14], ebx
// 004032cc  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004032d0  8b08                 mov ecx, dword ptr [eax]
// 004032d2  8d542414             lea edx, [esp + 0x14]
// 004032d6  52                   push edx
// 004032d7  688c018500           push 0x85018c
// 004032dc  688c018500           push 0x85018c
// 004032e1  50                   push eax
// 004032e2  8b410c               mov eax, dword ptr [ecx + 0xc]
// 004032e5  c644243002           mov byte ptr [esp + 0x30], 2
// 004032ea  ffd0                 call eax
// 004032ec  8bf8                 mov edi, eax
// 004032ee  3bfb                 cmp edi, ebx
// 004032f0  7d57                 jge 0x403349
// 004032f2  8b442414             mov eax, dword ptr [esp + 0x14]
// 004032f6  c644242001           mov byte ptr [esp + 0x20], 1
// 004032fb  3bc3                 cmp eax, ebx
// 004032fd  7408                 je 0x403307
// 004032ff  8b08                 mov ecx, dword ptr [eax]
// 00403301  8b5108               mov edx, dword ptr [ecx + 8]
// 00403304  50                   push eax
// 00403305  ffd2                 call edx
// 00403307  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040330b  885c2420             mov byte ptr [esp + 0x20], bl
// 0040330f  3bc3                 cmp eax, ebx
// 00403311  7408                 je 0x40331b
// 00403313  8b08                 mov ecx, dword ptr [eax]
// 00403315  8b5108               mov edx, dword ptr [ecx + 8]
// 00403318  50                   push eax
// 00403319  ffd2                 call edx
// 0040331b  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0040331f  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00403327  3bc3                 cmp eax, ebx
// 00403329  7408                 je 0x403333
// 0040332b  8b08                 mov ecx, dword ptr [eax]
// 0040332d  8b5108               mov edx, dword ptr [ecx + 8]
// 00403330  50                   push eax
// 00403331  ffd2                 call edx
// 00403333  8bc7                 mov eax, edi
// 00403335  5f                   pop edi
// 00403336  5e                   pop esi
// 00403337  5b                   pop ebx
// 00403338  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0040333c  64890d00000000       mov dword ptr fs:[0], ecx
// 00403343  83c418               add esp, 0x18
// 00403346  c20800               ret 8
// 00403349  8b06                 mov eax, dword ptr [esi]
// 0040334b  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0040334f  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 00403353  8b11                 mov edx, dword ptr [ecx]
// 00403355  53                   push ebx
// 00403356  56                   push esi
// 00403357  50                   push eax
// 00403358  8b4214               mov eax, dword ptr [edx + 0x14]
// 0040335b  51                   push ecx
// 0040335c  ffd0                 call eax
// 0040335e  8bf0                 mov esi, eax
// 00403360  3bf3                 cmp esi, ebx
// 00403362  8b442414             mov eax, dword ptr [esp + 0x14]
// 00403366  c644242001           mov byte ptr [esp + 0x20], 1
// 0040336b  7d4e                 jge 0x4033bb
// 0040336d  3bc3                 cmp eax, ebx
// 0040336f  7408                 je 0x403379
// 00403371  8b08                 mov ecx, dword ptr [eax]
// 00403373  8b5108               mov edx, dword ptr [ecx + 8]
// 00403376  50                   push eax
// 00403377  ffd2                 call edx
// 00403379  8b442410             mov eax, dword ptr [esp + 0x10]
// 0040337d  885c2420             mov byte ptr [esp + 0x20], bl
// 00403381  3bc3                 cmp eax, ebx
// 00403383  7408                 je 0x40338d
// 00403385  8b08                 mov ecx, dword ptr [eax]
// 00403387  8b5108               mov edx, dword ptr [ecx + 8]
// 0040338a  50                   push eax
// 0040338b  ffd2                 call edx
// 0040338d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00403391  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 00403399  3bc3                 cmp eax, ebx
// 0040339b  7408                 je 0x4033a5
// 0040339d  8b08                 mov ecx, dword ptr [eax]
// 0040339f  8b5108               mov edx, dword ptr [ecx + 8]
// 004033a2  50                   push eax
// 004033a3  ffd2                 call edx
// 004033a5  5f                   pop edi
// 004033a6  8bc6                 mov eax, esi
// 004033a8  5e                   pop esi
// 004033a9  5b                   pop ebx
// 004033aa  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004033ae  64890d00000000       mov dword ptr fs:[0], ecx
// 004033b5  83c418               add esp, 0x18
// 004033b8  c20800               ret 8
// 004033bb  3bc3                 cmp eax, ebx
// 004033bd  7408                 je 0x4033c7
// 004033bf  8b08                 mov ecx, dword ptr [eax]
// 004033c1  8b5108               mov edx, dword ptr [ecx + 8]
// 004033c4  50                   push eax
// 004033c5  ffd2                 call edx
// 004033c7  8b442410             mov eax, dword ptr [esp + 0x10]
// 004033cb  885c2420             mov byte ptr [esp + 0x20], bl
// 004033cf  3bc3                 cmp eax, ebx
// 004033d1  7408                 je 0x4033db
// 004033d3  8b08                 mov ecx, dword ptr [eax]
// 004033d5  8b5108               mov edx, dword ptr [ecx + 8]
// 004033d8  50                   push eax
// 004033d9  ffd2                 call edx
// 004033db  8b44240c             mov eax, dword ptr [esp + 0xc]
// 004033df  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 004033e7  3bc3                 cmp eax, ebx
// 004033e9  7408                 je 0x4033f3
// 004033eb  8b08                 mov ecx, dword ptr [eax]
// 004033ed  8b5108               mov edx, dword ptr [ecx + 8]
// 004033f0  50                   push eax
// 004033f1  ffd2                 call edx
// 004033f3  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 004033f7  5f                   pop edi
// 004033f8  5e                   pop esi
// 004033f9  33c0                 xor eax, eax
// 004033fb  5b                   pop ebx
// 004033fc  64890d00000000       mov dword ptr fs:[0], ecx
// 00403403  83c418               add esp, 0x18
// 00403406  c20800               ret 8

// from server: 99% by colin
// roc 2008-06 00403210  unit: CSiteLock<CLauncher>::GetOurUrl  size: 420 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00403210
//
// roc-lang: cpp
// roc-cl: 50727

typedef unsigned long DWORD;
typedef unsigned long ULONG;
typedef long HRESULT;
typedef wchar_t OLECHAR;
struct GUID { unsigned long a; unsigned short b, c; unsigned char d[8]; };
#define FAILED(hr) ((HRESULT)(hr) < 0)
#define S_OK 0

extern "C" const GUID IID_IServiceProvider;
extern "C" const GUID IID_IWebBrowser2;
extern "C" const GUID IID_IInternetSecurityManager;
extern "C" const GUID SID_SWebBrowserApp;
extern "C" const GUID SID_SInternetSecurityManager;

struct IUnknown {
    virtual HRESULT __stdcall QueryInterface(const GUID&, void**) = 0;
    virtual ULONG __stdcall AddRef() = 0;
    virtual ULONG __stdcall Release() = 0;
};

struct IServiceProvider : IUnknown {
    virtual HRESULT __stdcall QueryService(const GUID&, const GUID&, void**) = 0;
};

struct IWebBrowser2 : IUnknown {
    virtual void __stdcall s3() = 0; virtual void __stdcall s4() = 0; virtual void __stdcall s5() = 0;
    virtual void __stdcall s6() = 0; virtual void __stdcall s7() = 0; virtual void __stdcall s8() = 0;
    virtual void __stdcall s9() = 0; virtual void __stdcall s10() = 0; virtual void __stdcall s11() = 0;
    virtual void __stdcall s12() = 0; virtual void __stdcall s13() = 0; virtual void __stdcall s14() = 0;
    virtual void __stdcall s15() = 0; virtual void __stdcall s16() = 0; virtual void __stdcall s17() = 0;
    virtual void __stdcall s18() = 0; virtual void __stdcall s19() = 0; virtual void __stdcall s20() = 0;
    virtual void __stdcall s21() = 0; virtual void __stdcall s22() = 0; virtual void __stdcall s23() = 0;
    virtual void __stdcall s24() = 0; virtual void __stdcall s25() = 0; virtual void __stdcall s26() = 0;
    virtual void __stdcall s27() = 0; virtual void __stdcall s28() = 0; virtual void __stdcall s29() = 0;
    virtual HRESULT __stdcall get_LocationURL(OLECHAR**) = 0;
};

struct IInternetSecurityManager : IUnknown {
    virtual void __stdcall s3() = 0;
    virtual void __stdcall s4() = 0;
    virtual HRESULT __stdcall MapUrlToZone(const OLECHAR*, DWORD*, DWORD) = 0;
};

struct IObjectWithSite : IUnknown {
    virtual HRESULT __stdcall SetSite(IUnknown*) = 0;
    virtual HRESULT __stdcall GetSite(const GUID&, void**) = 0;
};

struct CComBSTR {
    OLECHAR* m_str;
    OLECHAR** operator&() { return &m_str; }
    operator OLECHAR*() const { return m_str; }
};

template <class T>
struct CComPtr {
    T* p;
    CComPtr() : p(0) {}
    ~CComPtr() { if (p) p->Release(); }
    T* operator->() const { return p; }
    T** operator&() { return &p; }
};

template <class T>
class CSiteLock {
public:
    virtual void lock0();
    void* reserved;
    HRESULT GetOurUrl(CComBSTR& bstrURL, DWORD& dwZone)
    {
        HRESULT hr = S_OK;
        CComPtr<IServiceProvider> spSrvProv;

        T* pT = static_cast<T*>(this);
        hr = pT->GetSite(IID_IServiceProvider, (void**)&spSrvProv);
        if (FAILED(hr))
            return hr;

        CComPtr<IWebBrowser2> spWebBrowser;
        hr = spSrvProv->QueryService(SID_SWebBrowserApp, IID_IWebBrowser2, (void**)&spWebBrowser);
        if (FAILED(hr))
            return hr;

        if (FAILED(spWebBrowser->get_LocationURL(&bstrURL)))
            return hr;

        CComPtr<IInternetSecurityManager> spInetSecMgr;
        hr = spSrvProv->QueryService(SID_SInternetSecurityManager, IID_IInternetSecurityManager, (void**)&spInetSecMgr);
        if (FAILED(hr))
            return hr;

        hr = spInetSecMgr->MapUrlToZone(bstrURL, &dwZone, 0);
        if (FAILED(hr))
            return hr;
        return S_OK;
    }
};

struct Root {
    virtual void root0();
    long m_dwRef;
    char padding[0x10];
};

class CLauncher : public Root, public CSiteLock<CLauncher>, public IObjectWithSite {
public:
    HRESULT __stdcall QueryInterface(const GUID&, void**);
    ULONG __stdcall AddRef();
    ULONG __stdcall Release();
    HRESULT __stdcall SetSite(IUnknown*);
    HRESULT __stdcall GetSite(const GUID&, void**);
};

template class CSiteLock<CLauncher>;
