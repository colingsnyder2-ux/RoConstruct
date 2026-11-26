// from server: 100% by Xemicl
// roc 2012-06 006a5750  unit: RBX::VScriptContext::?$FactoryProduct  size: 138 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006a5750
//
// 006a5750  64a100000000         mov eax, dword ptr fs:[0]
// 006a5756  6aff                 push -1
// 006a5758  68281caa00           push 0xaa1c28
// 006a575d  50                   push eax
// 006a575e  64892500000000       mov dword ptr fs:[0], esp
// 006a5765  83ec20               sub esp, 0x20
// 006a5768  56                   push esi
// 006a5769  57                   push edi
// 006a576a  8b7c2438             mov edi, dword ptr [esp + 0x38]
// 006a576e  8bf1                 mov esi, ecx
// 006a5770  3bfe                 cmp edi, esi
// 006a5772  7453                 je 0x6a57c7
// 006a5774  c744240800000000     mov dword ptr [esp + 8], 0
// 006a577c  56                   push esi
// 006a577d  8d4c240c             lea ecx, [esp + 0xc]
// 006a5781  c744243400000000     mov dword ptr [esp + 0x34], 0
// 006a5789  e892abe0ff           call 0x4b0320
// 006a578e  57                   push edi
// 006a578f  8bce                 mov ecx, esi
// 006a5791  e88aabe0ff           call 0x4b0320
// 006a5796  8d442408             lea eax, [esp + 8]
// 006a579a  50                   push eax
// 006a579b  8bcf                 mov ecx, edi
// 006a579d  e87eabe0ff           call 0x4b0320
// 006a57a2  8b442408             mov eax, dword ptr [esp + 8]
// 006a57a6  c7442430ffffffff     mov dword ptr [esp + 0x30], 0xffffffff
// 006a57ae  85c0                 test eax, eax
// 006a57b0  7415                 je 0x6a57c7
// 006a57b2  8b00                 mov eax, dword ptr [eax]
// 006a57b4  85c0                 test eax, eax
// 006a57b6  740f                 je 0x6a57c7
// 006a57b8  8d4c2410             lea ecx, [esp + 0x10]
// 006a57bc  6a02                 push 2
// 006a57be  51                   push ecx
// 006a57bf  8bd1                 mov edx, ecx
// 006a57c1  52                   push edx
// 006a57c2  ffd0                 call eax
// 006a57c4  83c40c               add esp, 0xc
// 006a57c7  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006a57cb  5f                   pop edi
// 006a57cc  5e                   pop esi
// 006a57cd  64890d00000000       mov dword ptr fs:[0], ecx
// 006a57d4  83c42c               add esp, 0x2c
// 006a57d7  c20400               ret 4
// copied from an identical function in another client (function ?swap@?$function1@X_NV?$allocator@X@std@@@boost@@QAEXAAV12@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>
namespace boost {
namespace detail { namespace function {
union function_buffer { void* obj_ptr; double align; char data[0x18]; };
enum functor_manager_operation_type { clone_functor_tag, move_functor_tag, destroy_functor_tag, check_functor_type_tag, get_functor_type_tag };
struct vtable_base {
    void (*manager)(const function_buffer&, function_buffer&, functor_manager_operation_type);
};
} }
class function_base {
public:
    detail::function::vtable_base* vtable;
    mutable detail::function::function_buffer functor;
    function_base() : vtable(0) {}
};
template<class R, class T0, class Allocator = std::allocator<void> >
class function1 : public function_base {
public:
    function1() {}
    ~function1() { clear(); }
    void clear() {
        if (vtable) {
            void (*m)(const detail::function::function_buffer&, detail::function::function_buffer&, detail::function::functor_manager_operation_type) = vtable->manager;
            if (m)
                m(functor, functor, detail::function::destroy_functor_tag);
        }
    }
    void swap(function1& other)
    {
        if (&other == this)
            return;
        function1 tmp;
        tmp.move_assign(*this);
        this->move_assign(other);
        other.move_assign(tmp);
    }
    void move_assign(function1& f);
};
template void function1<void, bool>::swap(function1<void, bool>&);
}