// from server: 100% by EspClaude
// roc 2009-06 00473240  unit: RBX::LDraw2Lua::LDrawParser  size: 217 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00473240
//
// 00473240  6aff                 push -1
// 00473242  68673e8500           push 0x853e67
// 00473247  64a100000000         mov eax, dword ptr fs:[0]
// 0047324d  50                   push eax
// 0047324e  64892500000000       mov dword ptr fs:[0], esp
// 00473255  83ec0c               sub esp, 0xc
// 00473258  53                   push ebx
// 00473259  55                   push ebp
// 0047325a  56                   push esi
// 0047325b  57                   push edi
// 0047325c  894c2410             mov dword ptr [esp + 0x10], ecx
// 00473260  c70134db8b00         mov dword ptr [ecx], 0x8bdb34
// 00473266  8b7930               mov edi, dword ptr [ecx + 0x30]
// 00473269  2b792c               sub edi, dword ptr [ecx + 0x2c]
// 0047326c  8d7120               lea esi, [ecx + 0x20]
// 0047326f  c1ff02               sar edi, 2
// 00473272  33db                 xor ebx, ebx
// 00473274  c744242401000000     mov dword ptr [esp + 0x24], 1
// 0047327c  85ff                 test edi, edi
// 0047327e  761b                 jbe 0x47329b
// 00473280  53                   push ebx
// 00473281  8bce                 mov ecx, esi
// 00473283  e838fdffff           call 0x472fc0
// 00473288  8b08                 mov ecx, dword ptr [eax]
// 0047328a  85c9                 test ecx, ecx
// 0047328c  7408                 je 0x473296
// 0047328e  8b01                 mov eax, dword ptr [ecx]
// 00473290  8b10                 mov edx, dword ptr [eax]
// 00473292  6a01                 push 1
// 00473294  ffd2                 call edx
// 00473296  43                   inc ebx
// 00473297  3bdf                 cmp ebx, edi
// 00473299  72e5                 jb 0x473280
// 0047329b  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0047329e  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004732a1  7606                 jbe 0x4732a9
// 004732a3  ff15ace98900         call dword ptr [0x89e9ac]
// 004732a9  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004732ac  8b2e                 mov ebp, dword ptr [esi]
// 004732ae  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004732b1  7606                 jbe 0x4732b9
// 004732b3  ff15ace98900         call dword ptr [0x89e9ac]
// 004732b9  8b06                 mov eax, dword ptr [esi]
// 004732bb  53                   push ebx
// 004732bc  55                   push ebp
// 004732bd  57                   push edi
// 004732be  50                   push eax
// 004732bf  8d442424             lea eax, [esp + 0x24]
// 004732c3  50                   push eax
// 004732c4  8bce                 mov ecx, esi
// 004732c6  e855af2800           call 0x6fe220
// 004732cb  8b460c               mov eax, dword ptr [esi + 0xc]
// 004732ce  33ff                 xor edi, edi
// 004732d0  3bc7                 cmp eax, edi
// 004732d2  7409                 je 0x4732dd
// 004732d4  50                   push eax
// 004732d5  e858572a00           call 0x718a32
// 004732da  83c404               add esp, 4
// 004732dd  897e0c               mov dword ptr [esi + 0xc], edi
// 004732e0  897e10               mov dword ptr [esi + 0x10], edi
// 004732e3  897e14               mov dword ptr [esi + 0x14], edi
// 004732e6  8b36                 mov esi, dword ptr [esi]
// 004732e8  56                   push esi
// 004732e9  e844572a00           call 0x718a32
// 004732ee  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 004732f2  83c404               add esp, 4
// 004732f5  83c104               add ecx, 4
// 004732f8  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 00473300  ff15c4e48900         call dword ptr [0x89e4c4]
// 00473306  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0047330a  5f                   pop edi
// 0047330b  5e                   pop esi
// 0047330c  5d                   pop ebp
// 0047330d  5b                   pop ebx
// 0047330e  64890d00000000       mov dword ptr fs:[0], ecx
// 00473315  83c418               add esp, 0x18
// 00473318  c3                   ret 
// copied from an identical function in another client (function ??1S@@UAE@XZ)

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <vector>

struct Object {
    virtual ~Object();
};

struct Objects : std::vector<Object*> {
    Object*& at(unsigned int);
    iterator erase(iterator, iterator);
};

struct S {
    std::string name;
    Objects objects;

    virtual ~S();
};

S::~S()
{
    unsigned int count = objects.size();
    for (unsigned int i = 0; i < count; ++i) {
        Object *p = objects.at(i);
        if (p)
            delete p;
    }
    objects.erase(objects.begin(), objects.end());
}