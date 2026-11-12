// from server: 100% by EspClaude
// repaired: boost 1.33.1 function1 member dtor inlined into TypedStatsItem dtor
// roc 2007-08 004b1ed0  unit: RBX::Stats::_N::?$TypedStatsItem  size: 135 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004b1ed0
//
// 004b1ed0  6aff                 push -1
// 004b1ed2  6878237400           push 0x742378
// 004b1ed7  64a100000000         mov eax, dword ptr fs:[0]
// 004b1edd  50                   push eax
// 004b1ede  51                   push ecx
// 004b1edf  56                   push esi
// 004b1ee0  a188518b00           mov eax, dword ptr [0x8b5188]
// 004b1ee5  33c4                 xor eax, esp
// 004b1ee7  50                   push eax
// 004b1ee8  8d44240c             lea eax, [esp + 0xc]
// 004b1eec  64a300000000         mov dword ptr fs:[0], eax
// 004b1ef2  8bf1                 mov esi, ecx
// 004b1ef4  89742408             mov dword ptr [esp + 8], esi
// 004b1ef8  83be1001000000       cmp dword ptr [esi + 0x110], 0
// 004b1eff  c744241400000000     mov dword ptr [esp + 0x14], 0
// 004b1f07  741a                 je 0x4b1f23
// 004b1f09  8b8614010000         mov eax, dword ptr [esi + 0x114]
// 004b1f0f  8b8e10010000         mov ecx, dword ptr [esi + 0x110]
// 004b1f15  6a01                 push 1
// 004b1f17  50                   push eax
// 004b1f18  ffd1                 call ecx
// 004b1f1a  83c408               add esp, 8
// 004b1f1d  898614010000         mov dword ptr [esi + 0x114], eax
// 004b1f23  8bce                 mov ecx, esi
// 004b1f25  c7861001000000000000 mov dword ptr [esi + 0x110], 0
// 004b1f2f  c7861801000000000000 mov dword ptr [esi + 0x118], 0
// 004b1f39  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 004b1f41  e89a69faff           call 0x4588e0
// 004b1f46  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004b1f4a  64890d00000000       mov dword ptr fs:[0], ecx
// 004b1f51  59                   pop ecx
// 004b1f52  5e                   pop esi
// 004b1f53  83c410               add esp, 0x10
// 004b1f56  c3                   ret 

// Base layout: target passes this to the base dtor (0x4588e0); derived member at 0x110 (manager), 0x114 (functor), 0x118 (invoker).
// boost 1.33.1 function_base::any_pointer / functor_manager_operation_type
union any_pointer {
    void* obj_ptr;
    const void* const_obj_ptr;
    void (*func_ptr)();
    char data[1];
};
enum functor_manager_operation_type { clone_functor_tag, destroy_functor_tag, check_functor_type_tag };
struct function_base {
    any_pointer (*manager)(any_pointer, functor_manager_operation_type);
    any_pointer functor;
    bool empty() const { return !manager; }
};

struct function1 : public function_base {
    void* invoker;
    ~function1() { clear(); }
    void clear() {
        if (this->manager)
            function_base::functor = this->manager(this->functor, destroy_functor_tag);
        this->manager = 0;
        invoker = 0;
    }
};

class StatsItem {
public:
    char pad[0x110];
    ~StatsItem();
};

class TypedStatsItem : public StatsItem {
public:
    function1 func;
    ~TypedStatsItem();
};

TypedStatsItem::~TypedStatsItem()
{
}
