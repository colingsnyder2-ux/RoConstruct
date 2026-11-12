// from server: 100% by EspClaude
// from server: 49% by colin
// roc 2007-08 004559d0  unit: CRobloxReportPaneView  size: 219 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004559d0
// 004559d0  6aff                 push -1
// 004559d2  6870187400           push 0x741870
// 004559d7  64a100000000         mov eax, dword ptr fs:[0]
// 004559dd  50                   push eax
// 004559de  51                   push ecx
// 004559df  56                   push esi
// 004559e0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004559e5  33c4                 xor eax, esp
// 004559e7  50                   push eax
// 004559e8  8d44240c             lea eax, [esp + 0xc]
// 004559ec  64a300000000         mov dword ptr fs:[0], eax
// 004559f2  8b742420             mov esi, dword ptr [esp + 0x20]
// 004559f6  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 004559fa  83ec08               sub esp, 8
// 004559fd  85f6                 test esi, esi
// 004559ff  8bc4                 mov eax, esp
// 00455a01  8910                 mov dword ptr [eax], edx
// 00455a03  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 00455a0b  89642410             mov dword ptr [esp + 0x10], esp
// 00455a0f  897004               mov dword ptr [eax + 4], esi
// 00455a12  740c                 je 0x455a20
// 00455a14  8d4604               lea eax, [esi + 4]
// 00455a17  ba01000000           mov edx, 1
// 00455a1c  f00fc110             lock xadd dword ptr [eax], edx
// 00455a20  81c1e8fcffff         add ecx, 0xfffffce8
// 00455a26  e885fbffff           call 0x4555b0
// 00455a2b  85f6                 test esi, esi
// 00455a2d  c644241400           mov byte ptr [esp + 0x14], 0
// 00455a32  742a                 je 0x455a5e
// 00455a34  8d4604               lea eax, [esi + 4]
// 00455a37  83c9ff               or ecx, 0xffffffff
// 00455a3a  f00fc108             lock xadd dword ptr [eax], ecx
// 00455a3e  751e                 jne 0x455a5e
// 00455a40  8b16                 mov edx, dword ptr [esi]
// 00455a42  8b4204               mov eax, dword ptr [edx + 4]
// 00455a45  8bce                 mov ecx, esi
// 00455a47  ffd0                 call eax
// 00455a49  8d4e08               lea ecx, [esi + 8]
// 00455a4c  83caff               or edx, 0xffffffff
// 00455a4f  f00fc111             lock xadd dword ptr [ecx], edx
// 00455a53  7509                 jne 0x455a5e
// 00455a55  8b06                 mov eax, dword ptr [esi]
// 00455a57  8b5008               mov edx, dword ptr [eax + 8]
// 00455a5a  8bce                 mov ecx, esi
// 00455a5c  ffd2                 call edx
// 00455a5e  8b742428             mov esi, dword ptr [esp + 0x28]
// 00455a62  85f6                 test esi, esi
// 00455a64  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00455a6c  742a                 je 0x455a98
// 00455a6e  8d4604               lea eax, [esi + 4]
// 00455a71  83c9ff               or ecx, 0xffffffff
// 00455a74  f00fc108             lock xadd dword ptr [eax], ecx
// 00455a78  751e                 jne 0x455a98
// 00455a7a  8b16                 mov edx, dword ptr [esi]
// 00455a7c  8b4204               mov eax, dword ptr [edx + 4]
// 00455a7f  8bce                 mov ecx, esi
// 00455a81  ffd0                 call eax
// 00455a83  8d4e08               lea ecx, [esi + 8]
// 00455a86  83caff               or edx, 0xffffffff
// 00455a89  f00fc111             lock xadd dword ptr [ecx], edx
// 00455a8d  7509                 jne 0x455a98
// 00455a8f  8b06                 mov eax, dword ptr [esi]
// 00455a91  8b5008               mov edx, dword ptr [eax + 8]
// 00455a94  8bce                 mov ecx, esi
// 00455a96  ffd2                 call edx
// 00455a98  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00455a9c  64890d00000000       mov dword ptr fs:[0], ecx
// 00455aa3  59                   pop ecx
// 00455aa4  5e                   pop esi
// 00455aa5  83c410               add esp, 0x10
// 00455aa8  c21000               ret 0x10

#include <intrin.h>

class sp_counted_base {
public:
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0)
        {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0)
            destroy();
    }
    long use_count_;
    long weak_count_;
};

class shared_count {
public:
    sp_counted_base* pi_;
    shared_count(const shared_count& r) : pi_(r.pi_) { if (pi_ != 0) pi_->add_ref_copy(); }
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};

template<class T> class shared_ptr {
public:
    T* px;
    shared_count pn;
};

class Item;

class Listener {
public:
    virtual void onChanged(shared_ptr<Item> current, shared_ptr<Item> previous) = 0;
};

class PaneBase {
public:
    virtual ~PaneBase();
    char pad_4[0x314];
};

class CRobloxReportPaneView : public PaneBase, public Listener {
public:
    void setItem(shared_ptr<Item> item);
    virtual void onChanged(shared_ptr<Item> current, shared_ptr<Item> previous);
};

void CRobloxReportPaneView::onChanged(shared_ptr<Item> current, shared_ptr<Item> previous)
{
    setItem(current);
}
