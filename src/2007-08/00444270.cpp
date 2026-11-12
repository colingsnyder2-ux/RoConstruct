// from server: 100% by EspClaude
// from server: 41% by colin
// roc 2007-08 00444270  unit: 1RBX::Metadata::VReflection::?$FactoryProduct  size: 261 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00444270
//
// 00444270  6aff                 push -1
// 00444272  6818a67400           push 0x74a618
// 00444277  64a100000000         mov eax, dword ptr fs:[0]
// 0044427d  50                   push eax
// 0044427e  83ec28               sub esp, 0x28
// 00444281  56                   push esi
// 00444282  57                   push edi
// 00444283  a188518b00           mov eax, dword ptr [0x8b5188]
// 00444288  33c4                 xor eax, esp
// 0044428a  50                   push eax
// 0044428b  8d442434             lea eax, [esp + 0x34]
// 0044428f  64a300000000         mov dword ptr fs:[0], eax
// 00444295  8d842488000000       lea eax, [esp + 0x88]
// 0044429c  50                   push eax
// 0044429d  8d4c244c             lea ecx, [esp + 0x4c]
// 004442a1  e8fa4d0400           call 0x4890a0
// 004442a6  84c0                 test al, al
// 004442a8  0f8598000000         jne 0x444346
// 004442ae  8b3d08e77700         mov edi, dword ptr [0x77e708]
// 004442b4  8b8c2484000000       mov ecx, dword ptr [esp + 0x84]
// 004442bb  803900               cmp byte ptr [ecx], 0
// 004442be  7564                 jne 0x444324
// 004442c0  8d4c2448             lea ecx, [esp + 0x48]
// 004442c4  e8974c2e00           call 0x728f60
// 004442c9  8d7010               lea esi, [eax + 0x10]
// 004442cc  85f6                 test esi, esi
// 004442ce  7428                 je 0x4442f8
// 004442d0  8b0e                 mov ecx, dword ptr [esi]
// 004442d2  85c9                 test ecx, ecx
// 004442d4  7409                 je 0x4442df
// 004442d6  8b11                 mov edx, dword ptr [ecx]
// 004442d8  8b4204               mov eax, dword ptr [edx + 4]
// 004442db  ffd0                 call eax
// 004442dd  eb05                 jmp 0x4442e4
// 004442df  b8c8278800           mov eax, 0x8827c8
// 004442e4  6888668800           push 0x886688
// 004442e9  8bc8                 mov ecx, eax
// 004442eb  ffd7                 call edi
// 004442ed  84c0                 test al, al
// 004442ef  7407                 je 0x4442f8
// 004442f1  8b06                 mov eax, dword ptr [esi]
// 004442f3  83c004               add eax, 4
// 004442f6  eb02                 jmp 0x4442fa
// 004442f8  33c0                 xor eax, eax
// 004442fa  833800               cmp dword ptr [eax], 0
// 004442fd  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 00444304  8b09                 mov ecx, dword ptr [ecx]
// 00444306  7456                 je 0x44435e
// 00444308  8b5004               mov edx, dword ptr [eax + 4]
// 0044430b  8b4008               mov eax, dword ptr [eax + 8]
// 0044430e  51                   push ecx
// 0044430f  52                   push edx
// 00444310  ffd0                 call eax
// 00444312  8b84248c000000       mov eax, dword ptr [esp + 0x8c]
// 00444319  83c408               add esp, 8
// 0044431c  803800               cmp byte ptr [eax], 0
// 0044431f  7503                 jne 0x444324
// 00444321  c60001               mov byte ptr [eax], 1
// 00444324  8d4c2448             lea ecx, [esp + 0x48]
// 00444328  e813d71a00           call 0x5f1a40
// 0044432d  8d8c2488000000       lea ecx, [esp + 0x88]
// 00444334  51                   push ecx
// 00444335  8d4c244c             lea ecx, [esp + 0x4c]
// 00444339  e8624d0400           call 0x4890a0
// 0044433e  84c0                 test al, al
// 00444340  0f846effffff         je 0x4442b4
// 00444346  8b442444             mov eax, dword ptr [esp + 0x44]
// 0044434a  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0044434e  64890d00000000       mov dword ptr fs:[0], ecx
// 00444355  59                   pop ecx
// 00444356  5f                   pop edi
// 00444357  5e                   pop esi
// 00444358  83c434               add esp, 0x34
// 0044435b  c28400               ret 0x84
// 0044435e  8d4c240c             lea ecx, [esp + 0xc]
// 00444362  e899f8fcff           call 0x413c00
// 00444367  50                   push eax
// 00444368  c744244000000000     mov dword ptr [esp + 0x40], 0
// 00444370  e8fbfdfcff           call 0x414170

#include <typeinfo>

struct bad_function_call {
    int storage[10];
    bad_function_call();
    ~bad_function_call();
};

__declspec(noreturn) void __cdecl throw_exception(const bad_function_call&);

namespace RBX { namespace Reflection { class PropertyDescriptor; } }
namespace std { template<class T> class allocator; }

namespace boost {
template<typename Signature, typename Allocator = std::allocator<void> >
class function;

template<>
class function<void (const RBX::Reflection::PropertyDescriptor*), std::allocator<void> > {
public:
    void* manager;
    void* functor;
    void (__cdecl *invoker)(void*, const RBX::Reflection::PropertyDescriptor*);

    void operator()(const RBX::Reflection::PropertyDescriptor* a) const
    {
        if (!manager)
            throw_exception(bad_function_call());
        invoker(functor, a);
    }
};
}

typedef boost::function<void (const RBX::Reflection::PropertyDescriptor*)> Function;

struct placeholder {
    virtual ~placeholder();
    virtual const type_info& type() const = 0;
};

template<class T>
struct holder : placeholder {
    T held;
};

struct any {
    placeholder* content;
    const type_info& type() const { return content ? content->type() : typeid(void); }
};

template<class T>
inline T* any_cast(any* operand)
{
    return operand && operand->type() == typeid(T)
        ? &static_cast<holder<T>*>(operand->content)->held
        : 0;
}

struct Entry {
    int key[4];
    any value;
};

struct Iterator {
    int data[14];
    const RBX::Reflection::PropertyDescriptor** argument;
    unsigned char* invoked;

    bool equal(const Iterator&);
    Entry& dereference();
    void increment();
};

struct Result {
    Result() {}
};

Result __stdcall apply(Iterator first, Iterator last)
{
    while (!first.equal(last)) {
        if (!*first.invoked) {
            Entry& e = first.dereference();
            Function* f = any_cast<Function>(&e.value);
            (*f)(*first.argument);
            if (!*first.invoked)
                *first.invoked = 1;
        }
        first.increment();
    }
    return Result();
}
