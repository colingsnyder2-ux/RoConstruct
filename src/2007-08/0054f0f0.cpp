// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 71% by tajop
// roc 2007-08 0054f0f0  unit: boost::iostreams::DUoutput::V?$basic_null_device::?$stream_buffer  size: 159 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0054f0f0
//
// 0054f0f0  6aff                 push -1
// 0054f0f2  6863287500           push 0x752863
// 0054f0f7  64a100000000         mov eax, dword ptr fs:[0]
// 0054f0fd  50                   push eax
// 0054f0fe  64892500000000       mov dword ptr fs:[0], esp
// 0054f105  83ec08               sub esp, 8
// 0054f108  57                   push edi
// 0054f109  8bf9                 mov edi, ecx
// 0054f10b  897c2408             mov dword ptr [esp + 8], edi
// 0054f10f  8b4750               mov eax, dword ptr [edi + 0x50]
// 0054f112  85c0                 test eax, eax
// 0054f114  c744241401000000     mov dword ptr [esp + 0x14], 1
// 0054f11c  740f                 je 0x54f12d
// 0054f11e  8b4f54               mov ecx, dword ptr [edi + 0x54]
// 0054f121  51                   push ecx
// 0054f122  50                   push eax
// 0054f123  8d4c240f             lea ecx, [esp + 0xf]
// 0054f127  ff1510e67700         call dword ptr [0x77e610]
// 0054f12d  807f4800             cmp byte ptr [edi + 0x48], 0
// 0054f131  c644241400           mov byte ptr [esp + 0x14], 0
// 0054f136  7437                 je 0x54f16f
// 0054f138  56                   push esi
// 0054f139  8b7744               mov esi, dword ptr [edi + 0x44]
// 0054f13c  85f6                 test esi, esi
// 0054f13e  742a                 je 0x54f16a
// 0054f140  8d5604               lea edx, [esi + 4]
// 0054f143  83c8ff               or eax, 0xffffffff
// 0054f146  f00fc102             lock xadd dword ptr [edx], eax
// 0054f14a  751e                 jne 0x54f16a
// 0054f14c  8b16                 mov edx, dword ptr [esi]
// 0054f14e  8b4204               mov eax, dword ptr [edx + 4]
// 0054f151  8bce                 mov ecx, esi
// 0054f153  ffd0                 call eax
// 0054f155  8d4e08               lea ecx, [esi + 8]
// 0054f158  83caff               or edx, 0xffffffff
// 0054f15b  f00fc111             lock xadd dword ptr [ecx], edx
// 0054f15f  7509                 jne 0x54f16a
// 0054f161  8b06                 mov eax, dword ptr [esi]
// 0054f163  8b5008               mov edx, dword ptr [eax + 8]
// 0054f166  8bce                 mov ecx, esi
// 0054f168  ffd2                 call edx
// 0054f16a  c6474800             mov byte ptr [edi + 0x48], 0
// 0054f16e  5e                   pop esi
// 0054f16f  8bcf                 mov ecx, edi
// 0054f171  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0054f179  ff151ce57700         call dword ptr [0x77e51c]
// 0054f17f  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0054f183  5f                   pop edi
// 0054f184  64890d00000000       mov dword ptr fs:[0], ecx
// 0054f18b  83c414               add esp, 0x14
// 0054f18e  c3                   ret 

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct CountedBase {
    virtual void f0();
    virtual void dispose();
    virtual void destroy();
    long use_count;
    long weak_count;
    void release()
    {
        if (_InterlockedDecrement(&use_count) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count) == 0)
                destroy();
        }
    }
};

struct __declspec(dllimport) Alloc {
    void deallocate(char* p, unsigned n);
};

struct Buffer {
    char* p;
    unsigned n;
    ~Buffer()
    {
        if (p) {
            Alloc a;
            a.deallocate(p, n);
        }
    }
};

struct Opt {
    void* px;
    CountedBase* pi;
    bool init;
    ~Opt()
    {
        if (init) {
            if (pi)
                pi->release();
            init = false;
        }
    }
};

struct __declspec(dllimport) StreambufBase {
    char pad[0x40];
    ~StreambufBase();
};

struct S : StreambufBase {
    Opt storage;
    int m4c;
    Buffer buf;
    ~S();
};

S::~S()
{
}
