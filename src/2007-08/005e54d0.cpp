// from server: 96% by EspClaude
// from server: 43% by colin
// roc 2007-08 005e54d0  unit: RBX::VInstance::?$FilteredSelection  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e54d0
//
// 005e54d0  64a100000000         mov eax, dword ptr fs:[0]
// 005e54d6  6aff                 push -1
// 005e54d8  68d8bc7500           push 0x75bcd8
// 005e54dd  50                   push eax
// 005e54de  64892500000000       mov dword ptr fs:[0], esp
// 005e54e5  83ec08               sub esp, 8
// 005e54e8  55                   push ebp
// 005e54e9  56                   push esi
// 005e54ea  8b742420             mov esi, dword ptr [esp + 0x20]
// 005e54ee  56                   push esi
// 005e54ef  8be9                 mov ebp, ecx
// 005e54f1  e86ac4f5ff           call 0x541960
// 005e54f6  83bdec00000000       cmp dword ptr [ebp + 0xec], 0
// 005e54fd  0f8512010000         jne 0x5e5615
// 005e5503  8b4608               mov eax, dword ptr [esi + 8]
// 005e5506  50                   push eax
// 005e5507  e83496e3ff           call 0x41eb40
// 005e550c  50                   push eax
// 005e550d  8d4c2410             lea ecx, [esp + 0x10]
// 005e5511  51                   push ecx
// 005e5512  e85981ebff           call 0x49d670
// 005e5517  83c40c               add esp, 0xc
// 005e551a  8b10                 mov edx, dword ptr [eax]
// 005e551c  83c004               add eax, 4
// 005e551f  50                   push eax
// 005e5520  8d8df0000000         lea ecx, [ebp + 0xf0]
// 005e5526  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 005e552e  8995ec000000         mov dword ptr [ebp + 0xec], edx
// 005e5534  e827d5e1ff           call 0x402a60
// 005e5539  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005e553d  85c0                 test eax, eax
// 005e553f  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 005e5547  742c                 je 0x5e5575
// 005e5549  8bf0                 mov esi, eax
// 005e554b  83c004               add eax, 4
// 005e554e  83c9ff               or ecx, 0xffffffff
// 005e5551  f00fc108             lock xadd dword ptr [eax], ecx
// 005e5555  751e                 jne 0x5e5575
// 005e5557  8b16                 mov edx, dword ptr [esi]
// 005e5559  8b4204               mov eax, dword ptr [edx + 4]
// 005e555c  8bce                 mov ecx, esi
// 005e555e  ffd0                 call eax
// 005e5560  8d4e08               lea ecx, [esi + 8]
// 005e5563  83caff               or edx, 0xffffffff
// 005e5566  f00fc111             lock xadd dword ptr [ecx], edx
// 005e556a  7509                 jne 0x5e5575
// 005e556c  8b06                 mov eax, dword ptr [esi]
// 005e556e  8b5008               mov edx, dword ptr [eax + 8]
// 005e5571  8bce                 mov ecx, esi
// 005e5573  ffd2                 call edx
// 005e5575  8b85ec000000         mov eax, dword ptr [ebp + 0xec]
// 005e557b  85c0                 test eax, eax
// 005e557d  0f8492000000         je 0x5e5615
// 005e5583  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 005e5589  53                   push ebx
// 005e558a  57                   push edi
// 005e558b  8b7804               mov edi, dword ptr [eax + 4]
// 005e558e  3b7808               cmp edi, dword ptr [eax + 8]
// 005e5591  89442428             mov dword ptr [esp + 0x28], eax
// 005e5595  7609                 jbe 0x5e55a0
// 005e5597  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e559d  8d4900               lea ecx, [ecx]
// 005e55a0  8b85ec000000         mov eax, dword ptr [ebp + 0xec]
// 005e55a6  8bb004010000         mov esi, dword ptr [eax + 0x104]
// 005e55ac  8b5e08               mov ebx, dword ptr [esi + 8]
// 005e55af  395e04               cmp dword ptr [esi + 4], ebx
// 005e55b2  7606                 jbe 0x5e55ba
// 005e55b4  ff15d8e67700         call dword ptr [0x77e6d8]
// 005e55ba  39742428             cmp dword ptr [esp + 0x28], esi
// 005e55be  8b35d8e67700         mov esi, dword ptr [0x77e6d8]
// 005e55c4  7402                 je 0x5e55c8
// 005e55c6  ffd6                 call esi
// 005e55c8  3bfb                 cmp edi, ebx
// 005e55ca  7435                 je 0x5e5601
// 005e55cc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005e55d0  3b7908               cmp edi, dword ptr [ecx + 8]
// 005e55d3  7202                 jb 0x5e55d7
// 005e55d5  ffd6                 call esi
// 005e55d7  8b07                 mov eax, dword ptr [edi]
// 005e55d9  85c0                 test eax, eax
// 005e55db  89442410             mov dword ptr [esp + 0x10], eax
// 005e55df  7410                 je 0x5e55f1
// 005e55e1  8d542410             lea edx, [esp + 0x10]
// 005e55e5  52                   push edx
// 005e55e6  8d8df4000000         lea ecx, [ebp + 0xf4]
// 005e55ec  e8cff8e7ff           call 0x464ec0
// 005e55f1  8b442428             mov eax, dword ptr [esp + 0x28]
// 005e55f5  3b7808               cmp edi, dword ptr [eax + 8]
// 005e55f8  7202                 jb 0x5e55fc
// 005e55fa  ffd6                 call esi
// 005e55fc  83c708               add edi, 8
// 005e55ff  eb9f                 jmp 0x5e55a0
// 005e5601  8d8de8000000         lea ecx, [ebp + 0xe8]
// 005e5607  51                   push ecx
// 005e5608  8b8dec000000         mov ecx, dword ptr [ebp + 0xec]
// 005e560e  e88dd5f4ff           call 0x532ba0
// 005e5613  5f                   pop edi
// 005e5614  5b                   pop ebx
// 005e5615  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005e5619  5e                   pop esi
// 005e561a  5d                   pop ebp
// 005e561b  64890d00000000       mov dword ptr fs:[0], ecx
// 005e5622  83c414               add esp, 0x14
// 005e5625  c20400               ret 4
// roc-flags: /O2 /GS- /EHsc /MD

#include <vector>
#include <intrin.h>

namespace boost {
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_;
    long weak_count_;
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
    shared_count& operator=(const shared_count& r);   // 0x402a60 (thiscall, out of line)
};
}
template<class T> class shared_ptr {
public:
    T* px;
    detail::shared_count pn;
    shared_ptr& operator=(const shared_ptr& r) { px = r.px; pn = r.pn; return *this; }
    T* operator->() const { return px; }
    T* get() const { return px; }
    bool operator!() const { return px == 0; }
};
}

namespace RBX {
class Instance;
class Workspace;
struct SelectionChanged;

struct AncestorEvent {
    int pad0;
    int pad4;
    Instance* parent;                 // +8: mov eax,[esi+8]
};

Instance* findAncestorWorkspace(Instance* i);                           // 0x41eb40 cdecl
boost::shared_ptr<Workspace> shared_from_workspace(Instance* i);          // 0x49d670 cdecl, hidden return

struct InstanceSet {
    void insert(Instance* const& i);      // 0x464ec0 thiscall
};

class Workspace {
public:
    char pad[0x104];
    std::vector<boost::shared_ptr<Instance> >* children;   // +0x104
    void connectSelection(SelectionChanged* sc);           // 0x532ba0 thiscall
};

class SelectionBase {
public:
    void onAncestorChanged(const AncestorEvent& ev);       // 0x541960 thiscall
};

class FilteredSelection : public SelectionBase {
public:
    char pad[0xe8];
    SelectionChanged* selectionChanged() { return (SelectionChanged*)&sc; }
    int sc;                                       // +0xe8 (address passed)
    boost::shared_ptr<Workspace> workspace;       // +0xec / +0xf0
    InstanceSet filter;                           // +0xf4
    void onAncestorChanged(const AncestorEvent& ev);
};

void FilteredSelection::onAncestorChanged(const AncestorEvent& ev)
{
    SelectionBase::onAncestorChanged(ev);
    if (!workspace)
    {
        workspace = shared_from_workspace(findAncestorWorkspace(ev.parent));
        if (workspace.get() != 0)
        {
            for (std::vector<boost::shared_ptr<Instance> >::iterator it = workspace->children->begin();
                 it != workspace->children->end(); ++it)
            {
                Instance* i = it->get();
                if (i)
                    filter.insert(i);
            }
            workspace->connectSelection(selectionChanged());
        }
    }
}
}
