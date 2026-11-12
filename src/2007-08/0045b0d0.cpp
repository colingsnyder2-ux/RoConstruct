// from server: 100% by EspClaude
// repaired: shared_ptr converting copy + string temp vcall slot 2 + setParent
// roc 2007-08 0045b0d0  unit: RBX::Stats::H::?$TypedStatsItem  size: 283 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045b0d0
//
// 0045b0d0  6aff                 push -1
// 0045b0d2  68d1ab7400           push 0x74abd1
// 0045b0d7  64a100000000         mov eax, dword ptr fs:[0]
// 0045b0dd  50                   push eax
// 0045b0de  83ec2c               sub esp, 0x2c
// 0045b0e1  53                   push ebx
// 0045b0e2  55                   push ebp
// 0045b0e3  56                   push esi
// 0045b0e4  57                   push edi
// 0045b0e5  a188518b00           mov eax, dword ptr [0x8b5188]
// 0045b0ea  33c4                 xor eax, esp
// 0045b0ec  50                   push eax
// 0045b0ed  8d442440             lea eax, [esp + 0x40]
// 0045b0f1  64a300000000         mov dword ptr fs:[0], eax
// 0045b0f7  8bd9                 mov ebx, ecx
// 0045b0f9  8b442454             mov eax, dword ptr [esp + 0x54]
// 0045b0fd  50                   push eax
// 0045b0fe  8d4c2420             lea ecx, [esp + 0x20]
// 0045b102  51                   push ecx
// 0045b103  e818feffff           call 0x45af20
// 0045b108  8b7004               mov esi, dword ptr [eax + 4]
// 0045b10b  8b38                 mov edi, dword ptr [eax]
// 0045b10d  83c408               add esp, 8
// 0045b110  85f6                 test esi, esi
// 0045b112  897c2414             mov dword ptr [esp + 0x14], edi
// 0045b116  89742418             mov dword ptr [esp + 0x18], esi
// 0045b11a  740c                 je 0x45b128
// 0045b11c  8d5604               lea edx, [esi + 4]
// 0045b11f  b801000000           mov eax, 1
// 0045b124  f00fc102             lock xadd dword ptr [edx], eax
// 0045b128  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0045b12c  85ed                 test ebp, ebp
// 0045b12e  c744244800000000     mov dword ptr [esp + 0x48], 0
// 0045b136  742c                 je 0x45b164
// 0045b138  8d4d04               lea ecx, [ebp + 4]
// 0045b13b  83caff               or edx, 0xffffffff
// 0045b13e  f00fc111             lock xadd dword ptr [ecx], edx
// 0045b142  7520                 jne 0x45b164
// 0045b144  8b4500               mov eax, dword ptr [ebp]
// 0045b147  8b5004               mov edx, dword ptr [eax + 4]
// 0045b14a  8bcd                 mov ecx, ebp
// 0045b14c  ffd2                 call edx
// 0045b14e  8d4508               lea eax, [ebp + 8]
// 0045b151  83c9ff               or ecx, 0xffffffff
// 0045b154  f00fc108             lock xadd dword ptr [eax], ecx
// 0045b158  750a                 jne 0x45b164
// 0045b15a  8b5500               mov edx, dword ptr [ebp]
// 0045b15d  8b4208               mov eax, dword ptr [edx + 8]
// 0045b160  8bcd                 mov ecx, ebp
// 0045b162  ffd0                 call eax
// 0045b164  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 0045b168  51                   push ecx
// 0045b169  8d4c2428             lea ecx, [esp + 0x28]
// 0045b16d  ff1598e67700         call dword ptr [0x77e698]
// 0045b173  8b17                 mov edx, dword ptr [edi]
// 0045b175  8b5208               mov edx, dword ptr [edx + 8]
// 0045b178  8d442424             lea eax, [esp + 0x24]
// 0045b17c  50                   push eax
// 0045b17d  8bcf                 mov ecx, edi
// 0045b17f  c644244c01           mov byte ptr [esp + 0x4c], 1
// 0045b184  ffd2                 call edx
// 0045b186  8d4c2424             lea ecx, [esp + 0x24]
// 0045b18a  c644244800           mov byte ptr [esp + 0x48], 0
// 0045b18f  ff15ace67700         call dword ptr [0x77e6ac]
// 0045b195  53                   push ebx
// 0045b196  8bcf                 mov ecx, edi
// 0045b198  e893640e00           call 0x541630
// 0045b19d  85f6                 test esi, esi
// 0045b19f  c7442448ffffffff     mov dword ptr [esp + 0x48], 0xffffffff
// 0045b1a7  742a                 je 0x45b1d3
// 0045b1a9  8d4604               lea eax, [esi + 4]
// 0045b1ac  83c9ff               or ecx, 0xffffffff
// 0045b1af  f00fc108             lock xadd dword ptr [eax], ecx
// 0045b1b3  751e                 jne 0x45b1d3
// 0045b1b5  8b16                 mov edx, dword ptr [esi]
// 0045b1b7  8b4204               mov eax, dword ptr [edx + 4]
// 0045b1ba  8bce                 mov ecx, esi
// 0045b1bc  ffd0                 call eax
// 0045b1be  8d4e08               lea ecx, [esi + 8]
// 0045b1c1  83caff               or edx, 0xffffffff
// 0045b1c4  f00fc111             lock xadd dword ptr [ecx], edx
// 0045b1c8  7509                 jne 0x45b1d3
// 0045b1ca  8b06                 mov eax, dword ptr [esi]
// 0045b1cc  8b5008               mov edx, dword ptr [eax + 8]
// 0045b1cf  8bce                 mov ecx, esi
// 0045b1d1  ffd2                 call edx
// 0045b1d3  8bc7                 mov eax, edi
// 0045b1d5  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0045b1d9  64890d00000000       mov dword ptr fs:[0], ecx
// 0045b1e0  59                   pop ecx
// 0045b1e1  5f                   pop edi
// 0045b1e2  5e                   pop esi
// 0045b1e3  5d                   pop ebp
// 0045b1e4  5b                   pop ebx
// 0045b1e5  83c438               add esp, 0x38
// 0045b1e8  c20800               ret 8

#include <string>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

// shared_count control block: vtable slot 1 = dispose, slot 2 = destroy; use count +4, weak count +8
struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak_count_) == 0)
                destroy();
        }
    }
};

template <class T> struct shared_ptr {
    T* px;
    sp_counted_base* pi_;
    template <class Y> shared_ptr(const shared_ptr<Y>& r) : px(r.px), pi_(r.pi_) {
        if (pi_ != 0) pi_->add_ref_copy();
    }
    ~shared_ptr() { if (pi_ != 0) pi_->release(); }
    T* operator->() const { return px; }
    T* get() const { return px; }
};

class Item {
public:
    virtual ~Item();
    virtual void unused1();
    virtual void setName(const std::string& name);   // vtable slot 2 (+8)
    void setParent(Item* parent);                    // 0x541630, thiscall
};

class ChildItem : public Item {
};

shared_ptr<ChildItem> __cdecl createItem(void* arg);  // 0x45af20, cdecl, hidden return slot

class TypedStatsItem : public Item {
public:
    Item* createChildItem(const char* name, void* arg);
};

Item* TypedStatsItem::createChildItem(const char* name, void* arg)
{
    shared_ptr<Item> item = createItem(arg);
    item->setName(name);
    item->setParent(this);
    return item.get();
}
