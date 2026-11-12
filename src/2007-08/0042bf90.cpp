// from server: 100% by EspClaude
// from server: 67% by colin
// roc 2007-08 0042bf90  unit: VCLuaFunction::?$CComObjectNoLock  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042bf90
//
// 0042bf90  6aff                 push -1
// 0042bf92  6848d17300           push 0x73d148
// 0042bf97  64a100000000         mov eax, dword ptr fs:[0]
// 0042bf9d  50                   push eax
// 0042bf9e  83ec10               sub esp, 0x10
// 0042bfa1  56                   push esi
// 0042bfa2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0042bfa7  33c4                 xor eax, esp
// 0042bfa9  50                   push eax
// 0042bfaa  8d442418             lea eax, [esp + 0x18]
// 0042bfae  64a300000000         mov dword ptr fs:[0], eax
// 0042bfb4  8bf1                 mov esi, ecx
// 0042bfb6  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0042bfbc  83ec08               sub esp, 8
// 0042bfbf  8bcc                 mov ecx, esp
// 0042bfc1  8901                 mov dword ptr [ecx], eax
// 0042bfc3  8b8600010000         mov eax, dword ptr [esi + 0x100]
// 0042bfc9  85c0                 test eax, eax
// 0042bfcb  89642410             mov dword ptr [esp + 0x10], esp
// 0042bfcf  894104               mov dword ptr [ecx + 4], eax
// 0042bfd2  740c                 je 0x42bfe0
// 0042bfd4  83c004               add eax, 4
// 0042bfd7  b901000000           mov ecx, 1
// 0042bfdc  f00fc108             lock xadd dword ptr [eax], ecx
// 0042bfe0  8d4c2414             lea ecx, [esp + 0x14]
// 0042bfe4  e86715feff           call 0x40d550
// 0042bfe9  8d8e0c010000         lea ecx, [esi + 0x10c]
// 0042bfef  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0042bff7  e8d4faffff           call 0x42bad0
// 0042bffc  8d4c240c             lea ecx, [esp + 0xc]
// 0042c000  c7442420ffffffff     mov dword ptr [esp + 0x20], 0xffffffff
// 0042c008  e893d51200           call 0x5595a0
// 0042c00d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0042c011  64890d00000000       mov dword ptr fs:[0], ecx
// 0042c018  59                   pop ecx
// 0042c019  5e                   pop esi
// 0042c01a  83c41c               add esp, 0x1c
// 0042c01d  c3                   ret 

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)

struct sp_counted_base {
    void* vtbl;
    long use_count_;
};

struct SharedPtr {
    void* px;
    sp_counted_base* pn;
    SharedPtr(const SharedPtr& o) : px(o.px), pn(o.pn)
    {
        if (pn != 0)
            _InterlockedIncrement(&pn->use_count_);
    }
    ~SharedPtr();
};

struct Holder {
    void* a;
    void* b;
    void* c;
    Holder(SharedPtr p);
    ~Holder();
};

struct Member10c {
    void run();
};

struct VCLuaFunction {
    char pad[0xfc];
    SharedPtr m_ptr;
    char pad2[0x10c - 0x104];
    Member10c m_10c;
    void destroy();
};

void VCLuaFunction::destroy()
{
    Holder h(m_ptr);
    m_10c.run();
}
