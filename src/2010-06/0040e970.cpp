// from server: 100% by Yeetserama
// roc 2010-06 0040e970  unit: UIEnumConnectionPoints::V?$CComEnum::?$CComObject  size: 174 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0040e970
//
// 0040e970  55                   push ebp
// 0040e971  8bec                 mov ebp, esp
// 0040e973  6aff                 push -1
// 0040e975  6800e39700           push 0x97e300
// 0040e97a  64a100000000         mov eax, dword ptr fs:[0]
// 0040e980  50                   push eax
// 0040e981  64892500000000       mov dword ptr fs:[0], esp
// 0040e988  83ec10               sub esp, 0x10
// 0040e98b  53                   push ebx
// 0040e98c  56                   push esi
// 0040e98d  57                   push edi
// 0040e98e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040e991  33f6                 xor esi, esi
// 0040e993  bf0e000780           mov edi, 0x8007000e
// 0040e998  6a20                 push 0x20
// 0040e99a  897dec               mov dword ptr [ebp - 0x14], edi
// 0040e99d  8975e8               mov dword ptr [ebp - 0x18], esi
// 0040e9a0  8975fc               mov dword ptr [ebp - 4], esi
// 0040e9a3  e8f88f3900           call 0x7a79a0
// 0040e9a8  83c404               add esp, 4
// 0040e9ab  3bc6                 cmp eax, esi
// 0040e9ad  743f                 je 0x40e9ee
// 0040e9af  897018               mov dword ptr [eax + 0x18], esi
// 0040e9b2  897010               mov dword ptr [eax + 0x10], esi
// 0040e9b5  89700c               mov dword ptr [eax + 0xc], esi
// 0040e9b8  c74008f418a000       mov dword ptr [eax + 8], 0xa018f4
// 0040e9bf  33c9                 xor ecx, ecx
// 0040e9c1  6689481c             mov word ptr [eax + 0x1c], cx
// 0040e9c5  c700d81da000         mov dword ptr [eax], 0xa01dd8
// 0040e9cb  c74004c01da000       mov dword ptr [eax + 4], 0xa01dc0
// 0040e9d2  c740089c1da000       mov dword ptr [eax + 8], 0xa01d9c
// 0040e9d9  c740146c1da000       mov dword ptr [eax + 0x14], 0xa01d6c
// 0040e9e0  3bc6                 cmp eax, esi
// 0040e9e2  7422                 je 0x40ea06
// 0040e9e4  ff4018               inc dword ptr [eax + 0x18]
// 0040e9e7  33ff                 xor edi, edi
// 0040e9e9  ff4818               dec dword ptr [eax + 0x18]
// 0040e9ec  eb18                 jmp 0x40ea06
// 0040e9ee  33c0                 xor eax, eax
// 0040e9f0  ebee                 jmp 0x40e9e0
// 0040e9f2  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 0040e9f5  e882923900           call 0x7a7c7c
// 0040e9fa  b800ea4000           mov eax, 0x40ea00
// 0040e9ff  c3                   ret 
// 0040ea00  8b7dec               mov edi, dword ptr [ebp - 0x14]
// 0040ea03  8b45e8               mov eax, dword ptr [ebp - 0x18]
// 0040ea06  8b5508               mov edx, dword ptr [ebp + 8]
// 0040ea09  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0040ea0c  8902                 mov dword ptr [edx], eax
// 0040ea0e  8bc7                 mov eax, edi
// 0040ea10  5f                   pop edi
// 0040ea11  5e                   pop esi
// 0040ea12  64890d00000000       mov dword ptr fs:[0], ecx
// 0040ea19  5b                   pop ebx
// 0040ea1a  8be5                 mov esp, ebp
// 0040ea1c  5d                   pop ebp
// 0040ea1d  c3                   ret 
// copied from an identical function in another client (function ?CreateInstance@@YAJPAPAUS@@@Z)

// from server: 97% by colin
// roc 2008-06 0040fbf0  unit: VCBrowserViewExternal::?$CComAggObject  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040fbf0
//
// from server: 97% by colin
// roc 2008-06 0040fbf0  unit: VCBrowserViewExternal::?$CComAggObject  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040fbf0
//
// 0040fbf0  55                   push ebp
// 0040fbf1  8bec                 mov ebp, esp
// 0040fbf3  6aff                 push -1
// 0040fbf5  6810d57b00           push 0x7bd510
// 0040fbfa  64a100000000         mov eax, dword ptr fs:[0]
// 0040fc00  50                   push eax
// 0040fc01  64892500000000       mov dword ptr fs:[0], esp
// 0040fc08  83ec10               sub esp, 0x10
// 0040fc0b  53                   push ebx
// 0040fc0c  56                   push esi
// 0040fc0d  57                   push edi
// 0040fc0e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040fc11  33f6                 xor esi, esi
// 0040fc13  bf0e000780           mov edi, 0x8007000e
// 0040fc18  6a20                 push 0x20
// 0040fc1a  897dec               mov dword ptr [ebp - 0x14], edi
// 0040fc1d  8975e8               mov dword ptr [ebp - 0x18], esi
// 0040fc20  8975fc               mov dword ptr [ebp - 4], esi
// 0040fc23  e8f80c2900           call 0x6a0920
// 0040fc28  83c404               add esp, 4
// 0040fc2b  3bc6                 cmp eax, esi
// 0040fc2d  743f                 je 0x40fc6e
// 0040fc2f  897018               mov dword ptr [eax + 0x18], esi
// 0040fc32  897010               mov dword ptr [eax + 0x10], esi
// 0040fc35  89700c               mov dword ptr [eax + 0xc], esi
// 0040fc38  c7400888d38000       mov dword ptr [eax + 8], 0x80d388
// 0040fc3f  33c9                 xor ecx, ecx
// 0040fc41  6689481c             mov word ptr [eax + 0x1c], cx
// 0040fc45  c70078d78000         mov dword ptr [eax], 0x80d778
// 0040fc4b  c7400460d78000       mov dword ptr [eax + 4], 0x80d760
// 0040fc52  c740083cd78000       mov dword ptr [eax + 8], 0x80d73c
// 0040fc59  c7401414d78000       mov dword ptr [eax + 0x14], 0x80d714
// 0040fc60  3bc6                 cmp eax, esi
// 0040fc62  7422                 je 0x40fc86
// 0040fc64  ff4018               inc dword ptr [eax + 0x18]
// 0040fc67  33ff                 xor edi, edi
// 0040fc69  ff4818               dec dword ptr [eax + 0x18]
// 0040fc6c  eb18                 jmp 0x40fc86
// 0040fc6e  33c0                 xor eax, eax
// 0040fc70  ebee                 jmp 0x40fc60

// from server: 92% by king_originala
// roc 2008-06 0040fbf0  unit: VCBrowserViewExternal::?$CComAggObject  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0040fbf0
//
// 0040fbf0  55                   push ebp
// 0040fbf1  8bec                 mov ebp, esp
// 0040fbf3  6aff                 push -1
// 0040fbf5  6810d57b00           push 0x7bd510
// 0040fbfa  64a100000000         mov eax, dword ptr fs:[0]
// 0040fc00  50                   push eax
// 0040fc01  64892500000000       mov dword ptr fs:[0], esp
// 0040fc08  83ec10               sub esp, 0x10
// 0040fc0b  53                   push ebx
// 0040fc0c  56                   push esi
// 0040fc0d  57                   push edi
// 0040fc0e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0040fc11  33f6                 xor esi, esi
// 0040fc13  bf0e000780           mov edi, 0x8007000e
// 0040fc18  6a20                 push 0x20
// 0040fc1a  897dec               mov dword ptr [ebp - 0x14], edi
// 0040fc1d  8975e8               mov dword ptr [ebp - 0x18], esi
// 0040fc20  8975fc               mov dword ptr [ebp - 4], esi
// 0040fc23  e8f80c2900           call 0x6a0920
// 0040fc28  83c404               add esp, 4
// 0040fc2b  3bc6                 cmp eax, esi
// 0040fc2d  743f                 je 0x40fc6e
// 0040fc2f  897018               mov dword ptr [eax + 0x18], esi
// 0040fc32  897010               mov dword ptr [eax + 0x10], esi
// 0040fc35  89700c               mov dword ptr [eax + 0xc], esi
// 0040fc38  c7400888d38000       mov dword ptr [eax + 8], 0x80d388
// 0040fc3f  33c9                 xor ecx, ecx
// 0040fc41  6689481c             mov word ptr [eax + 0x1c], cx
// 0040fc45  c70078d78000         mov dword ptr [eax], 0x80d778
// 0040fc4b  c7400460d78000       mov dword ptr [eax + 4], 0x80d760
// 0040fc52  c740083cd78000       mov dword ptr [eax + 8], 0x80d73c
// 0040fc59  c7401414d78000       mov dword ptr [eax + 0x14], 0x80d714
// 0040fc60  3bc6                 cmp eax, esi
// 0040fc62  7422                 je 0x40fc86
// 0040fc64  ff4018               inc dword ptr [eax + 0x18]
// 0040fc67  33ff                 xor edi, edi
// 0040fc69  ff4818               dec dword ptr [eax + 0x18]
// 0040fc6c  eb18                 jmp 0x40fc86
// 0040fc6e  33c0                 xor eax, eax
// 0040fc70  ebee                 jmp 0x40fc60

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

extern unsigned long tableBase[];
extern unsigned long table0[];
extern unsigned long table1[];
extern unsigned long table2[];
extern unsigned long table3[];

struct CException { void Delete(); };

struct S {
    unsigned long* v0;
    unsigned long* v1;
    unsigned long* volatile v2;
    unsigned long state;
    unsigned long outer;
    unsigned long* v3;
    volatile long references;
    volatile unsigned short flags;
    unsigned short padding;

    S();
};

inline S::S()
{
    references = 0;
    outer = 0;
    state = 0;
    v2 = tableBase;
    flags = 0;
    v0 = table0;
    v1 = table1;
    v2 = table2;
    v3 = table3;
}

long __cdecl CreateInstance(S** result)
{
    long status = (long)0x8007000EUL;
    S* object = 0;
    try {
        object = new S;
    }
    catch (CException* e) {
        e->Delete();
    }

    if (object) {
        ++object->references;
        status = 0;
        --object->references;
    }

    *result = object;
    return status;
}