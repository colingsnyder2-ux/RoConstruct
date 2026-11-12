// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 44% by colin
// roc 2007-08 00560c00  unit: RBX::VModelInstance::?$FilteredSelection  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00560c00
//
// 00560c00  53                   push ebx
// 00560c01  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00560c05  8b03                 mov eax, dword ptr [ebx]
// 00560c07  8b80c0000000         mov eax, dword ptr [eax + 0xc0]
// 00560c0d  85c0                 test eax, eax
// 00560c0f  55                   push ebp
// 00560c10  8be9                 mov ebp, ecx
// 00560c12  0f848b000000         je 0x560ca3
// 00560c18  8b4804               mov ecx, dword ptr [eax + 4]
// 00560c1b  85c9                 test ecx, ecx
// 00560c1d  0f8480000000         je 0x560ca3
// 00560c23  8b4008               mov eax, dword ptr [eax + 8]
// 00560c26  2bc1                 sub eax, ecx
// 00560c28  c1f803               sar eax, 3
// 00560c2b  7476                 je 0x560ca3
// 00560c2d  56                   push esi
// 00560c2e  57                   push edi
// 00560c2f  33ff                 xor edi, edi
// 00560c31  8b13                 mov edx, dword ptr [ebx]
// 00560c33  8b82c0000000         mov eax, dword ptr [edx + 0xc0]
// 00560c39  85c0                 test eax, eax
// 00560c3b  744e                 je 0x560c8b
// 00560c3d  8b4804               mov ecx, dword ptr [eax + 4]
// 00560c40  85c9                 test ecx, ecx
// 00560c42  7447                 je 0x560c8b
// 00560c44  8b4008               mov eax, dword ptr [eax + 8]
// 00560c47  2bc1                 sub eax, ecx
// 00560c49  c1f803               sar eax, 3
// 00560c4c  3bf8                 cmp edi, eax
// 00560c4e  733b                 jae 0x560c8b
// 00560c50  8bb2c0000000         mov esi, dword ptr [edx + 0xc0]
// 00560c56  8b4e04               mov ecx, dword ptr [esi + 4]
// 00560c59  85c9                 test ecx, ecx
// 00560c5b  740c                 je 0x560c69
// 00560c5d  8b4608               mov eax, dword ptr [esi + 8]
// 00560c60  2bc1                 sub eax, ecx
// 00560c62  c1f803               sar eax, 3
// 00560c65  3bf8                 cmp edi, eax
// 00560c67  7206                 jb 0x560c6f
// 00560c69  ff15d8e67700         call dword ptr [0x77e6d8]
// 00560c6f  8b4604               mov eax, dword ptr [esi + 4]
// 00560c72  8b0cf8               mov ecx, dword ptr [eax + edi*8]
// 00560c75  8d542414             lea edx, [esp + 0x14]
// 00560c79  894c2414             mov dword ptr [esp + 0x14], ecx
// 00560c7d  8b4d00               mov ecx, dword ptr [ebp]
// 00560c80  52                   push edx
// 00560c81  e83a42f0ff           call 0x464ec0
// 00560c86  83c701               add edi, 1
// 00560c89  eba6                 jmp 0x560c31
// 00560c8b  8bca                 mov ecx, edx
// 00560c8d  e8ce12feff           call 0x541f60
// 00560c92  8b0b                 mov ecx, dword ptr [ebx]
// 00560c94  6a00                 push 0
// 00560c96  e89509feff           call 0x541630
// 00560c9b  8b4504               mov eax, dword ptr [ebp + 4]
// 00560c9e  5f                   pop edi
// 00560c9f  c60001               mov byte ptr [eax], 1
// 00560ca2  5e                   pop esi
// 00560ca3  5d                   pop ebp
// 00560ca4  5b                   pop ebx
// 00560ca5  c20400               ret 4

#include <vector>

template<class T> struct shared_ptr {
    T* px;
    void* pn;
    ~shared_ptr();
    T* operator->() const { return px; }
    T* get() const { return px; }
};

struct Instance {
    int pad[0xc0 / 4];
    std::vector< shared_ptr<Instance> >* children;   // +0xc0

    unsigned int numChildren() const {
        return children ? children->size() : 0;
    }
    Instance* getChild(unsigned int i) const {
        return (*children)[i].get();
    }
    void removeAllChildren();          // 0x541f60
    void setParent(Instance* parent);  // 0x541630
};

struct InstanceSet {
    void erase(Instance* const& inst); // 0x464ec0
};

struct FilteredSelection {
    InstanceSet* selection;   // +0
    bool* dirty;              // +4
    void clearChildren(const shared_ptr<Instance>& inst);
};

void FilteredSelection::clearChildren(const shared_ptr<Instance>& inst)
{
    if (inst->numChildren() == 0)
        return;
    for (unsigned int i = 0; i < inst->numChildren(); i++)
        selection->erase(inst->getChild(i));
    inst->removeAllChildren();
    inst->setParent(0);
    *dirty = true;
}
