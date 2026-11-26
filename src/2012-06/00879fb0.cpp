// from server: 100% by Xemicl
// roc 2012-06 00879fb0  unit: RBX::VInstance::?$NonFactoryProduct  size: 167 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00879fb0
//
// 00879fb0  6aff                 push -1
// 00879fb2  68f301ad00           push 0xad01f3
// 00879fb7  64a100000000         mov eax, dword ptr fs:[0]
// 00879fbd  50                   push eax
// 00879fbe  64892500000000       mov dword ptr fs:[0], esp
// 00879fc5  51                   push ecx
// 00879fc6  56                   push esi
// 00879fc7  6a28                 push 0x28
// 00879fc9  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00879fd1  e844811000           call 0x98211a
// 00879fd6  8bf0                 mov esi, eax
// 00879fd8  83c404               add esp, 4
// 00879fdb  89742404             mov dword ptr [esp + 4], esi
// 00879fdf  c644241001           mov byte ptr [esp + 0x10], 1
// 00879fe4  85f6                 test esi, esi
// 00879fe6  7430                 je 0x87a018
// 00879fe8  8b442418             mov eax, dword ptr [esp + 0x18]
// 00879fec  8906                 mov dword ptr [esi], eax
// 00879fee  c7460800000000       mov dword ptr [esi + 8], 0
// 00879ff5  8b442420             mov eax, dword ptr [esp + 0x20]
// 00879ff9  85c0                 test eax, eax
// 00879ffb  7421                 je 0x87a01e
// 00879ffd  894608               mov dword ptr [esi + 8], eax
// 0087a000  8b442420             mov eax, dword ptr [esp + 0x20]
// 0087a004  6a00                 push 0
// 0087a006  8d4e10               lea ecx, [esi + 0x10]
// 0087a009  51                   push ecx
// 0087a00a  8b08                 mov ecx, dword ptr [eax]
// 0087a00c  8d542430             lea edx, [esp + 0x30]
// 0087a010  52                   push edx
// 0087a011  ffd1                 call ecx
// 0087a013  83c40c               add esp, 0xc
// 0087a016  eb02                 jmp 0x87a01a
// 0087a018  33f6                 xor esi, esi
// 0087a01a  8b442420             mov eax, dword ptr [esp + 0x20]
// 0087a01e  8b542440             mov edx, dword ptr [esp + 0x40]
// 0087a022  8932                 mov dword ptr [edx], esi
// 0087a024  c7442410ffffffff     mov dword ptr [esp + 0x10], 0xffffffff
// 0087a02c  5e                   pop esi
// 0087a02d  85c0                 test eax, eax
// 0087a02f  7415                 je 0x87a046
// 0087a031  8b00                 mov eax, dword ptr [eax]
// 0087a033  85c0                 test eax, eax
// 0087a035  740f                 je 0x87a046
// 0087a037  8d4c2424             lea ecx, [esp + 0x24]
// 0087a03b  6a02                 push 2
// 0087a03d  51                   push ecx
// 0087a03e  8bd1                 mov edx, ecx
// 0087a040  52                   push edx
// 0087a041  ffd0                 call eax
// 0087a043  83c40c               add esp, 0xc
// 0087a046  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0087a04a  64890d00000000       mov dword ptr fs:[0], ecx
// 0087a051  83c410               add esp, 0x10
// 0087a054  c23000               ret 0x30
// copied from an identical function in another client (function ?create@Queue@RBX@@QAEXUItem@2@PAPAU32@UTag@2@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { namespace function {
union function_buffer {
    void* obj_ptr;
    void (*func_ptr)();
    double align;
    char data[0x18];
};
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag };
struct vtable_base {
    void (*manager)(const function_buffer& in_buffer, function_buffer& out_buffer, functor_manager_operation_type op);
    void clear(function_buffer& functor)
    {
        if (manager)
            manager(functor, functor, destroy_functor_tag);
    }
};
}}
class function_base {
public:
    function_base() : vtable(0) {}
    bool empty() const { return !vtable; }
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
};
template<class R> class function0 : public function_base {
public:
    function0(const function0& f) : function_base() { assign_to_own(f); }
    ~function0() { if (vtable) vtable->clear(functor); }
    void assign_to_own(const function0& f)
    {
        if (!f.empty()) {
            this->vtable = f.vtable;
            f.vtable->manager(f.functor, this->functor, detail::function::clone_functor_tag);
        }
    }
};
}
namespace RBX {
struct Tag {};
struct Item {
    int key;
    boost::function0<void> f;
};
class Queue {
public:
    void create(Item item, Item** out, Tag);
};
void Queue::create(Item item, Item** out, Tag)
{
    *out = new Item(item);
}
}