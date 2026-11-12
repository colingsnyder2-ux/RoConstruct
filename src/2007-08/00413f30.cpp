// from server: 100% by EspClaude
// from server: 44% by colin
// roc 2007-08 00413f30  unit: std::D::DU?$char_traits::V?$basic_string::?$holder  size: 186 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00413f30
// 00413f30  6aff                 push -1
// 00413f32  68d8a67300           push 0x73a6d8
// 00413f37  64a100000000         mov eax, dword ptr fs:[0]
// 00413f3d  50                   push eax
// 00413f3e  51                   push ecx
// 00413f3f  56                   push esi
// 00413f40  57                   push edi
// 00413f41  a188518b00           mov eax, dword ptr [0x8b5188]
// 00413f46  33c4                 xor eax, esp
// 00413f48  50                   push eax
// 00413f49  8d442410             lea eax, [esp + 0x10]
// 00413f4d  64a300000000         mov dword ptr fs:[0], eax
// 00413f53  8bf9                 mov edi, ecx
// 00413f55  897c240c             mov dword ptr [esp + 0xc], edi
// 00413f59  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00413f61  8b742424             mov esi, dword ptr [esp + 0x24]
// 00413f65  85f6                 test esi, esi
// 00413f67  8b442420             mov eax, dword ptr [esp + 0x20]
// 00413f6b  8907                 mov dword ptr [edi], eax
// 00413f6d  897704               mov dword ptr [edi + 4], esi
// 00413f70  740c                 je 0x413f7e
// 00413f72  8d4e04               lea ecx, [esi + 4]
// 00413f75  ba01000000           mov edx, 1
// 00413f7a  f00fc111             lock xadd dword ptr [ecx], edx
// 00413f7e  8d442428             lea eax, [esp + 0x28]
// 00413f82  8d4f08               lea ecx, [edi + 8]
// 00413f85  50                   push eax
// 00413f86  c644241c02           mov byte ptr [esp + 0x1c], 2
// 00413f8b  e8608f1500           call 0x56cef0
// 00413f90  85f6                 test esi, esi
// 00413f92  c644241800           mov byte ptr [esp + 0x18], 0
// 00413f97  742a                 je 0x413fc3
// 00413f99  8d4e04               lea ecx, [esi + 4]
// 00413f9c  83caff               or edx, 0xffffffff
// 00413f9f  f00fc111             lock xadd dword ptr [ecx], edx
// 00413fa3  751e                 jne 0x413fc3
// 00413fa5  8b06                 mov eax, dword ptr [esi]
// 00413fa7  8b5004               mov edx, dword ptr [eax + 4]
// 00413faa  8bce                 mov ecx, esi
// 00413fac  ffd2                 call edx
// 00413fae  8d4608               lea eax, [esi + 8]
// 00413fb1  83c9ff               or ecx, 0xffffffff
// 00413fb4  f00fc108             lock xadd dword ptr [eax], ecx
// 00413fb8  7509                 jne 0x413fc3
// 00413fba  8b16                 mov edx, dword ptr [esi]
// 00413fbc  8b4208               mov eax, dword ptr [edx + 8]
// 00413fbf  8bce                 mov ecx, esi
// 00413fc1  ffd0                 call eax
// 00413fc3  8d4c2428             lea ecx, [esp + 0x28]
// 00413fc7  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00413fcf  e8ac8e1500           call 0x56ce80
// 00413fd4  8bc7                 mov eax, edi
// 00413fd6  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00413fda  64890d00000000       mov dword ptr fs:[0], ecx
// 00413fe1  59                   pop ecx
// 00413fe2  5f                   pop edi
// 00413fe3  5e                   pop esi
// 00413fe4  83c410               add esp, 0x10
// 00413fe7  c22c00               ret 0x2c

extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement, _InterlockedDecrement)

struct sp_counted_base {
    long use_count_;
    long weak_count_;
    virtual ~sp_counted_base();
    virtual void dispose() = 0;
    virtual void destroy();
    void add_ref_copy() { _InterlockedIncrement(&use_count_); }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count_) == 0) destroy();
    }
    void release() {
        if (_InterlockedDecrement(&use_count_) == 0) {
            dispose();
            weak_release();
        }
    }
};

struct T;

struct shared_ptr_T {
    T* px;
    sp_counted_base* pn;
    shared_ptr_T(const shared_ptr_T& o) : px(o.px), pn(o.pn) {
        if (pn != 0) pn->add_ref_copy();
    }
    ~shared_ptr_T() {
        if (pn != 0) pn->release();
    }
};

struct Value {
    int d[9];
    Value(const Value& o) { init(o); }
    void init(const Value&);
    ~Value();
};

struct Holder {
    shared_ptr_T sp;
    Value v;
    Holder(shared_ptr_T s, Value val);
};

Holder::Holder(shared_ptr_T s, Value val) : sp(s), v(val)
{
}
