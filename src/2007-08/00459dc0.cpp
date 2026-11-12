// from server: 100% by EspClaude
// from server: 58% by colin
// roc 2007-08 00459dc0  unit: RBX::AdornG3D  size: 250 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00459dc0
//
// 00459dc0  6aff                 push -1
// 00459dc2  68f6217400           push 0x7421f6
// 00459dc7  64a100000000         mov eax, dword ptr fs:[0]
// 00459dcd  50                   push eax
// 00459dce  83ec08               sub esp, 8
// 00459dd1  56                   push esi
// 00459dd2  57                   push edi
// 00459dd3  a188518b00           mov eax, dword ptr [0x8b5188]
// 00459dd8  33c4                 xor eax, esp
// 00459dda  50                   push eax
// 00459ddb  8d442414             lea eax, [esp + 0x14]
// 00459ddf  64a300000000         mov dword ptr fs:[0], eax
// 00459de5  8bf1                 mov esi, ecx
// 00459de7  6a58                 push 0x58
// 00459de9  e808611d00           call 0x62fef6
// 00459dee  83c404               add esp, 4
// 00459df1  8944240c             mov dword ptr [esp + 0xc], eax
// 00459df5  85c0                 test eax, eax
// 00459df7  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 00459dff  742f                 je 0x459e30
// 00459e01  8b4e68               mov ecx, dword ptr [esi + 0x68]
// 00459e04  83ec08               sub esp, 8
// 00459e07  8bfc                 mov edi, esp
// 00459e09  890f                 mov dword ptr [edi], ecx
// 00459e0b  8b566c               mov edx, dword ptr [esi + 0x6c]
// 00459e0e  85d2                 test edx, edx
// 00459e10  89642418             mov dword ptr [esp + 0x18], esp
// 00459e14  895704               mov dword ptr [edi + 4], edx
// 00459e17  740c                 je 0x459e25
// 00459e19  83c204               add edx, 4
// 00459e1c  b901000000           mov ecx, 1
// 00459e21  f00fc10a             lock xadd dword ptr [edx], ecx
// 00459e25  8bc8                 mov ecx, eax
// 00459e27  e8145a0700           call 0x4cf840
// 00459e2c  8bf8                 mov edi, eax
// 00459e2e  eb02                 jmp 0x459e32
// 00459e30  33ff                 xor edi, edi
// 00459e32  8b8ea0000000         mov ecx, dword ptr [esi + 0xa0]
// 00459e38  3bf9                 cmp edi, ecx
// 00459e3a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00459e42  740c                 je 0x459e50
// 00459e44  85c9                 test ecx, ecx
// 00459e46  7408                 je 0x459e50
// 00459e48  8b11                 mov edx, dword ptr [ecx]
// 00459e4a  8b02                 mov eax, dword ptr [edx]
// 00459e4c  6a01                 push 1
// 00459e4e  ffd0                 call eax
// 00459e50  6a20                 push 0x20
// 00459e52  89bea0000000         mov dword ptr [esi + 0xa0], edi
// 00459e58  e899601d00           call 0x62fef6
// 00459e5d  83c404               add esp, 4
// 00459e60  89442410             mov dword ptr [esp + 0x10], eax
// 00459e64  85c0                 test eax, eax
// 00459e66  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00459e6e  7412                 je 0x459e82
// 00459e70  8b8e9c000000         mov ecx, dword ptr [esi + 0x9c]
// 00459e76  51                   push ecx
// 00459e77  8bc8                 mov ecx, eax
// 00459e79  e862feffff           call 0x459ce0
// 00459e7e  8bf8                 mov edi, eax
// 00459e80  eb02                 jmp 0x459e84
// 00459e82  33ff                 xor edi, edi
// 00459e84  8b8ea4000000         mov ecx, dword ptr [esi + 0xa4]
// 00459e8a  3bf9                 cmp edi, ecx
// 00459e8c  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00459e94  740c                 je 0x459ea2
// 00459e96  85c9                 test ecx, ecx
// 00459e98  7408                 je 0x459ea2
// 00459e9a  8b11                 mov edx, dword ptr [ecx]
// 00459e9c  8b02                 mov eax, dword ptr [edx]
// 00459e9e  6a01                 push 1
// 00459ea0  ffd0                 call eax
// 00459ea2  89bea4000000         mov dword ptr [esi + 0xa4], edi
// 00459ea8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00459eac  64890d00000000       mov dword ptr fs:[0], ecx
// 00459eb3  59                   pop ecx
// 00459eb4  5f                   pop edi
// 00459eb5  5e                   pop esi
// 00459eb6  83c414               add esp, 0x14

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct CountedBase {
    void* vtbl;
    long use_count;
};

struct SharedPtr {
    void* px;
    CountedBase* pn;
    SharedPtr(const SharedPtr& o) : px(o.px), pn(o.pn)
    {
        if (pn != 0)
            _InterlockedIncrement(&pn->use_count);
    }
    ~SharedPtr();
};

struct Renderable {
    virtual ~Renderable();
};

struct Body : Renderable {
    int pad[21];
    Body(SharedPtr p);
};

struct Part : Renderable {
    int pad[7];
    Part(void* p);
};

template <class T>
struct AutoPtr {
    T* ptr;
    void reset(T* p)
    {
        if (p != ptr)
            delete ptr;
        ptr = p;
    }
};

struct AdornG3D {
    int pad_0000[26];
    SharedPtr field_68;
    int pad_0070[11];
    void* field_9c;
    AutoPtr<Renderable> field_a0;
    AutoPtr<Renderable> field_a4;

    void rebuild();
};

void AdornG3D::rebuild()
{
    field_a0.reset(new Body(field_68));
    field_a4.reset(new Part(field_9c));
}
