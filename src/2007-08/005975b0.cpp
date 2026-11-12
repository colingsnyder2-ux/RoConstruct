// from server: 100% by EspClaude
// repaired: shared_ptr converting copy + setName(name.c_str()) + setParent, /GS-
// roc 2007-08 005975b0  unit: RBX::Stats::N::?$TypedStatsItem  size: 296 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005975b0
//
// 005975b0  6aff                 push -1
// 005975b2  68d1c97500           push 0x75c9d1
// 005975b7  64a100000000         mov eax, dword ptr fs:[0]
// 005975bd  50                   push eax
// 005975be  64892500000000       mov dword ptr fs:[0], esp
// 005975c5  83ec30               sub esp, 0x30
// 005975c8  53                   push ebx
// 005975c9  8b5c2444             mov ebx, dword ptr [esp + 0x44]
// 005975cd  56                   push esi
// 005975ce  57                   push edi
// 005975cf  8d442418             lea eax, [esp + 0x18]
// 005975d3  53                   push ebx
// 005975d4  50                   push eax
// 005975d5  894c2414             mov dword ptr [esp + 0x14], ecx
// 005975d9  e8c2fdffff           call 0x5973a0
// 005975de  8b7004               mov esi, dword ptr [eax + 4]
// 005975e1  8b38                 mov edi, dword ptr [eax]
// 005975e3  83c408               add esp, 8
// 005975e6  85f6                 test esi, esi
// 005975e8  897c2410             mov dword ptr [esp + 0x10], edi
// 005975ec  89742414             mov dword ptr [esp + 0x14], esi
// 005975f0  740c                 je 0x5975fe
// 005975f2  8d4e04               lea ecx, [esi + 4]
// 005975f5  ba01000000           mov edx, 1
// 005975fa  f00fc111             lock xadd dword ptr [ecx], edx
// 005975fe  55                   push ebp
// 005975ff  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00597603  85ed                 test ebp, ebp
// 00597605  c744244800000000     mov dword ptr [esp + 0x48], 0
// 0059760d  742c                 je 0x59763b
// 0059760f  8d4504               lea eax, [ebp + 4]
// 00597612  83c9ff               or ecx, 0xffffffff
// 00597615  f00fc108             lock xadd dword ptr [eax], ecx
// 00597619  7520                 jne 0x59763b
// 0059761b  8b5500               mov edx, dword ptr [ebp]
// 0059761e  8b4204               mov eax, dword ptr [edx + 4]
// 00597621  8bcd                 mov ecx, ebp
// 00597623  ffd0                 call eax
// 00597625  8d4d08               lea ecx, [ebp + 8]
// 00597628  83caff               or edx, 0xffffffff
// 0059762b  f00fc111             lock xadd dword ptr [ecx], edx
// 0059762f  750a                 jne 0x59763b
// 00597631  8b4500               mov eax, dword ptr [ebp]
// 00597634  8b5008               mov edx, dword ptr [eax + 8]
// 00597637  8bcd                 mov ecx, ebp
// 00597639  ffd2                 call edx
// 0059763b  83bb3000020010       cmp dword ptr [ebx + 0x20030], 0x10
// 00597642  5d                   pop ebp
// 00597643  7208                 jb 0x59764d
// 00597645  8b831c000200         mov eax, dword ptr [ebx + 0x2001c]
// 0059764b  eb06                 jmp 0x597653
// 0059764d  8d831c000200         lea eax, [ebx + 0x2001c]
// 00597653  50                   push eax
// 00597654  8d4c2424             lea ecx, [esp + 0x24]
// 00597658  ff1598e67700         call dword ptr [0x77e698]
// 0059765e  8b07                 mov eax, dword ptr [edi]
// 00597660  8b5008               mov edx, dword ptr [eax + 8]
// 00597663  8d4c2420             lea ecx, [esp + 0x20]
// 00597667  51                   push ecx
// 00597668  8bcf                 mov ecx, edi
// 0059766a  c644244801           mov byte ptr [esp + 0x48], 1
// 0059766f  ffd2                 call edx
// 00597671  8d4c2420             lea ecx, [esp + 0x20]
// 00597675  c644244400           mov byte ptr [esp + 0x44], 0
// 0059767a  ff15ace67700         call dword ptr [0x77e6ac]
// 00597680  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00597684  50                   push eax
// 00597685  8bcf                 mov ecx, edi
// 00597687  e8a49ffaff           call 0x541630
// 0059768c  85f6                 test esi, esi
// 0059768e  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 00597696  742a                 je 0x5976c2
// 00597698  8d4e04               lea ecx, [esi + 4]
// 0059769b  83caff               or edx, 0xffffffff
// 0059769e  f00fc111             lock xadd dword ptr [ecx], edx
// 005976a2  751e                 jne 0x5976c2
// 005976a4  8b06                 mov eax, dword ptr [esi]
// 005976a6  8b5004               mov edx, dword ptr [eax + 4]
// 005976a9  8bce                 mov ecx, esi
// 005976ab  ffd2                 call edx
// 005976ad  8d4608               lea eax, [esi + 8]
// 005976b0  83c9ff               or ecx, 0xffffffff
// 005976b3  f00fc108             lock xadd dword ptr [eax], ecx
// 005976b7  7509                 jne 0x5976c2
// 005976b9  8b16                 mov edx, dword ptr [esi]
// 005976bb  8b4208               mov eax, dword ptr [edx + 8]
// 005976be  8bce                 mov ecx, esi
// 005976c0  ffd0                 call eax
// 005976c2  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005976c6  8bc7                 mov eax, edi
// 005976c8  5f                   pop edi
// 005976c9  5e                   pop esi
// 005976ca  5b                   pop ebx
// 005976cb  64890d00000000       mov dword ptr fs:[0], ecx
// 005976d2  83c43c               add esp, 0x3c
// 005976d5  c20400               ret 4

// roc-flags: /O2 /GS- /EHsc /MD
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

// argument object: std::string at +0x20018 (target reads _Bx +0x2001c, _Myres +0x20030)
struct StatsSource {
    char pad[0x20018];
    std::string name;   // VS2005 basic_string: _Bx at +4, _Myres at +0x18
};

shared_ptr<ChildItem> __cdecl createItem(StatsSource* src);  // 0x5973a0, cdecl, hidden return slot

class TypedStatsItem : public Item {
public:
    Item* createChildItem(StatsSource* src);
};

Item* TypedStatsItem::createChildItem(StatsSource* src)
{
    shared_ptr<Item> item = createItem(src);
    item->setName(src->name.c_str());
    item->setParent(this);
    return item.get();
}
