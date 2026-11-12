// from server: 100% by EspClaude
// from server: 43% by colin
// roc 2007-08 00494c40  unit: RBX::VInstance::V?$shared_ptr::V?$vector::?$sp_counted_impl_p  size: 338 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00494c40
//
// 00494c40  6aff                 push -1
// 00494c42  6828817400           push 0x748128
// 00494c47  64a100000000         mov eax, dword ptr fs:[0]
// 00494c4d  50                   push eax
// 00494c4e  83ec14               sub esp, 0x14
// 00494c51  53                   push ebx
// 00494c52  55                   push ebp
// 00494c53  56                   push esi
// 00494c54  57                   push edi
// 00494c55  a188518b00           mov eax, dword ptr [0x8b5188]
// 00494c5a  33c4                 xor eax, esp
// 00494c5c  50                   push eax
// 00494c5d  8d442428             lea eax, [esp + 0x28]
// 00494c61  64a300000000         mov dword ptr fs:[0], eax
// 00494c67  8bf9                 mov edi, ecx
// 00494c69  33db                 xor ebx, ebx
// 00494c6b  895c2430             mov dword ptr [esp + 0x30], ebx
// 00494c6f  895c2414             mov dword ptr [esp + 0x14], ebx
// 00494c73  8d442414             lea eax, [esp + 0x14]
// 00494c77  50                   push eax
// 00494c78  6a01                 push 1
// 00494c7a  8d4c2420             lea ecx, [esp + 0x20]
// 00494c7e  c644243801           mov byte ptr [esp + 0x38], 1
// 00494c83  e88832f8ff           call 0x417f10
// 00494c88  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00494c8c  3bc3                 cmp eax, ebx
// 00494c8e  c644243002           mov byte ptr [esp + 0x30], 2
// 00494c93  740b                 je 0x494ca0
// 00494c95  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00494c99  2bc8                 sub ecx, eax
// 00494c9b  c1f902               sar ecx, 2
// 00494c9e  750a                 jne 0x494caa
// 00494ca0  ff15d8e67700         call dword ptr [0x77e6d8]
// 00494ca6  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00494caa  6a0c                 push 0xc
// 00494cac  8bf0                 mov esi, eax
// 00494cae  e843b21900           call 0x62fef6
// 00494cb3  8b6c2440             mov ebp, dword ptr [esp + 0x40]
// 00494cb7  83c404               add esp, 4
// 00494cba  3bc3                 cmp eax, ebx
// 00494cbc  7422                 je 0x494ce0
// 00494cbe  3beb                 cmp ebp, ebx
// 00494cc0  8b542438             mov edx, dword ptr [esp + 0x38]
// 00494cc4  c70040787800         mov dword ptr [eax], 0x787840
// 00494cca  895004               mov dword ptr [eax + 4], edx
// 00494ccd  896808               mov dword ptr [eax + 8], ebp
// 00494cd0  7410                 je 0x494ce2
// 00494cd2  8d4d04               lea ecx, [ebp + 4]
// 00494cd5  ba01000000           mov edx, 1
// 00494cda  f00fc111             lock xadd dword ptr [ecx], edx
// 00494cde  eb02                 jmp 0x494ce2
// 00494ce0  33c0                 xor eax, eax
// 00494ce2  8b0e                 mov ecx, dword ptr [esi]
// 00494ce4  3bcb                 cmp ecx, ebx
// 00494ce6  8906                 mov dword ptr [esi], eax
// 00494ce8  7408                 je 0x494cf2
// 00494cea  8b01                 mov eax, dword ptr [ecx]
// 00494cec  8b10                 mov edx, dword ptr [eax]
// 00494cee  6a01                 push 1
// 00494cf0  ffd2                 call edx
// 00494cf2  8b0f                 mov ecx, dword ptr [edi]
// 00494cf4  8b01                 mov eax, dword ptr [ecx]
// 00494cf6  8b4004               mov eax, dword ptr [eax + 4]
// 00494cf9  8d542418             lea edx, [esp + 0x18]
// 00494cfd  52                   push edx
// 00494cfe  ffd0                 call eax
// 00494d00  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00494d04  3bf3                 cmp esi, ebx
// 00494d06  885c2430             mov byte ptr [esp + 0x30], bl
// 00494d0a  742c                 je 0x494d38
// 00494d0c  8b442420             mov eax, dword ptr [esp + 0x20]
// 00494d10  3bf0                 cmp esi, eax
// 00494d12  8bf8                 mov edi, eax
// 00494d14  7419                 je 0x494d2f
// 00494d16  8b0e                 mov ecx, dword ptr [esi]
// 00494d18  3bcb                 cmp ecx, ebx
// 00494d1a  7408                 je 0x494d24
// 00494d1c  8b11                 mov edx, dword ptr [ecx]
// 00494d1e  8b02                 mov eax, dword ptr [edx]
// 00494d20  6a01                 push 1
// 00494d22  ffd0                 call eax
// 00494d24  83c604               add esi, 4
// 00494d27  3bf7                 cmp esi, edi
// 00494d29  75eb                 jne 0x494d16
// 00494d2b  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00494d2f  56                   push esi
// 00494d30  e82daf1900           call 0x62fc62
// 00494d35  83c404               add esp, 4
// 00494d38  3beb                 cmp ebp, ebx
// 00494d3a  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00494d3e  895c2420             mov dword ptr [esp + 0x20], ebx
// 00494d42  895c2424             mov dword ptr [esp + 0x24], ebx
// 00494d46  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 00494d4e  742c                 je 0x494d7c
// 00494d50  8d4d04               lea ecx, [ebp + 4]
// 00494d53  83caff               or edx, 0xffffffff
// 00494d56  f00fc111             lock xadd dword ptr [ecx], edx
// 00494d5a  7520                 jne 0x494d7c
// 00494d5c  8b4500               mov eax, dword ptr [ebp]
// 00494d5f  8b5004               mov edx, dword ptr [eax + 4]
// 00494d62  8bcd                 mov ecx, ebp
// 00494d64  ffd2                 call edx
// 00494d66  8d4508               lea eax, [ebp + 8]
// 00494d69  83c9ff               or ecx, 0xffffffff
// 00494d6c  f00fc108             lock xadd dword ptr [eax], ecx
// 00494d70  750a                 jne 0x494d7c
// 00494d72  8b5500               mov edx, dword ptr [ebp]
// 00494d75  8b4208               mov eax, dword ptr [edx + 8]
// 00494d78  8bcd                 mov ecx, ebp
// 00494d7a  ffd0                 call eax
// 00494d7c  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 00494d80  64890d00000000       mov dword ptr fs:[0], ecx
// 00494d87  59                   pop ecx
// 00494d88  5f                   pop edi
// 00494d89  5e                   pop esi
// 00494d8a  5d                   pop ebp
// 00494d8b  5b                   pop ebx
// 00494d8c  83c420               add esp, 0x20
// 00494d8f  c20800               ret 8

#include <vector>

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct sp_counted_base {
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    long use_count_;
    long weak_count_;

    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void release()
    {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release()
    {
        if (_InterlockedDecrement(&weak_count_) == 0) {
            destroy();
        }
    }
};

struct Target;

struct SharedPtr {
    Target* px;
    sp_counted_base* pi;
    SharedPtr(const SharedPtr& r) : px(r.px), pi(r.pi)
    {
        if (pi != 0) pi->add_ref_copy();
    }
    ~SharedPtr()
    {
        if (pi != 0) pi->release();
    }
};

struct Item {
    virtual ~Item();
};

struct TargetItem : Item {
    SharedPtr target;
    TargetItem(const SharedPtr& t) : target(t) {}
};

struct Owned {
    Item* p;
    Owned() : p(0) {}

    ~Owned() { delete p; }
    void reset(Item* q)
    {
        Item* old = p;
        p = q;
        delete old;
    }
};

typedef std::vector<Owned> ItemVector;

struct Sink {
    virtual void f0();
    virtual void accept(ItemVector& items);
};

struct S {
    Sink* sink;
    void send(SharedPtr target);
};

void S::send(SharedPtr target)
{
    ItemVector items(1);
    Owned& slot = items[0];
    slot.reset(new TargetItem(target));
    sink->accept(items);
}
