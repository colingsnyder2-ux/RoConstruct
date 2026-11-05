// from server: 100% by nuck16
// from server: 95% by atomic.potato
// roc 2009-12 007e23b0  unit: std::D::DU?$char_traits::V?$basic_string::?$thread_specific_ptr::PAUdelete_data::?$sp_counted_impl_pd  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007e23b0
//
// 007e23b0  56                   push esi
// 007e23b1  8bf1                 mov esi, ecx
// 007e23b3  8b4c2408             mov ecx, dword ptr [esp + 8]
// 007e23b7  685047b600           push 0xb64750
// 007e23bc  ff1568b79800         call dword ptr [0x98b768]
// 007e23c2  84c0                 test al, al
// 007e23c4  7407                 je 0x7e23cd
// 007e23c6  8d4610               lea eax, [esi + 0x10]
// 007e23c9  5e                   pop esi
// 007e23ca  c20400               ret 4
// 007e23cd  33c0                 xor eax, eax
// 007e23cf  5e                   pop esi
// 007e23d0  c20400               ret 4

struct TypeInfo
{
    __declspec(dllimport) bool operator==(const TypeInfo& other) const;
};

struct S
{
    void* f(void* p);
};

extern const TypeInfo type_info_object;

void* S::f(void* p)
{
    if (*(TypeInfo*)p == type_info_object)
        return (char*)this + 16;
    return 0;
}
