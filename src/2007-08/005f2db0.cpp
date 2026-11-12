// from server: 100% by EspClaude
// roc 2007-08 005f2db0  unit: RBX::Reflection::Z::$$A6AXMM::?$TSignalDesc::TSignalInstance  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005f2db0
//
// 005f2db0  56                   push esi
// 005f2db1  57                   push edi
// 005f2db2  8d442450             lea eax, [esp + 0x50]
// 005f2db6  50                   push eax
// 005f2db7  8d4c2414             lea ecx, [esp + 0x14]
// 005f2dbb  e8e062e9ff           call 0x4890a0
// 005f2dc0  84c0                 test al, al
// 005f2dc2  0f8594000000         jne 0x5f2e5c
// 005f2dc8  8b3d08e77700         mov edi, dword ptr [0x77e708]
// 005f2dce  8bff                 mov edi, edi
// 005f2dd0  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 005f2dd4  803900               cmp byte ptr [ecx], 0
// 005f2dd7  7564                 jne 0x5f2e3d
// 005f2dd9  8d4c2410             lea ecx, [esp + 0x10]
// 005f2ddd  e87e611300           call 0x728f60
// 005f2de2  8bf0                 mov esi, eax
// 005f2de4  83c610               add esi, 0x10
// 005f2de7  7428                 je 0x5f2e11
// 005f2de9  8b0e                 mov ecx, dword ptr [esi]
// 005f2deb  85c9                 test ecx, ecx
// 005f2ded  7409                 je 0x5f2df8
// 005f2def  8b11                 mov edx, dword ptr [ecx]
// 005f2df1  8b4204               mov eax, dword ptr [edx + 4]
// 005f2df4  ffd0                 call eax
// 005f2df6  eb05                 jmp 0x5f2dfd
// 005f2df8  b8c8278800           mov eax, 0x8827c8
// 005f2dfd  68e00e8b00           push 0x8b0ee0
// 005f2e02  8bc8                 mov ecx, eax
// 005f2e04  ffd7                 call edi
// 005f2e06  84c0                 test al, al
// 005f2e08  7407                 je 0x5f2e11
// 005f2e0a  8b0e                 mov ecx, dword ptr [esi]
// 005f2e0c  83c104               add ecx, 4
// 005f2e0f  eb02                 jmp 0x5f2e13
// 005f2e11  33c9                 xor ecx, ecx
// 005f2e13  8b542448             mov edx, dword ptr [esp + 0x48]
// 005f2e17  d902                 fld dword ptr [edx]
// 005f2e19  83ec0c               sub esp, 0xc
// 005f2e1c  8bc4                 mov eax, esp
// 005f2e1e  d918                 fstp dword ptr [eax]
// 005f2e20  d94204               fld dword ptr [edx + 4]
// 005f2e23  d95804               fstp dword ptr [eax + 4]
// 005f2e26  d94208               fld dword ptr [edx + 8]
// 005f2e29  d95808               fstp dword ptr [eax + 8]
// 005f2e2c  e8cfe8ffff           call 0x5f1700
// 005f2e31  8b44244c             mov eax, dword ptr [esp + 0x4c]
// 005f2e35  803800               cmp byte ptr [eax], 0
// 005f2e38  7503                 jne 0x5f2e3d
// 005f2e3a  c60001               mov byte ptr [eax], 1
// 005f2e3d  8d4c2410             lea ecx, [esp + 0x10]
// 005f2e41  e8faebffff           call 0x5f1a40
// 005f2e46  8d4c2450             lea ecx, [esp + 0x50]
// 005f2e4a  51                   push ecx
// 005f2e4b  8d4c2414             lea ecx, [esp + 0x14]
// 005f2e4f  e84c62e9ff           call 0x4890a0
// 005f2e54  84c0                 test al, al
// 005f2e56  0f8474ffffff         je 0x5f2dd0
// 005f2e5c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 005f2e60  5f                   pop edi
// 005f2e61  5e                   pop esi
// 005f2e62  c28400               ret 0x84
#include <typeinfo>
#include <memory>

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};
}

namespace boost {

class any {
public:
    class placeholder {
    public:
        virtual ~placeholder();
        virtual const std::type_info& type() const = 0;
    };
    template<class ValueType> class holder : public placeholder {
    public:
        ValueType held;
    };
    const std::type_info& type() const { return content ? content->type() : typeid(void); }
    placeholder* content;
};

template<class ValueType>
inline ValueType* any_cast(any* operand)
{
    return operand && operand->type() == typeid(ValueType)
        ? &static_cast<any::holder<ValueType>*>(operand->content)->held
        : 0;
}

template<class Signature, class Allocator = std::allocator<void> >
class function;
template<class R, class T0, class Allocator>
class function<R (T0), Allocator> {
public:
    R operator()(T0 a0) const;
    int pad;
};

template<class T>
class optional {
public:
    bool m_initialized;
    bool is_initialized() const { return m_initialized; }
    void reset(const T&) { if (!m_initialized) m_initialized = true; }
};

namespace signals {
namespace detail {

class unusable {
public:
    unusable() {}
};

// the slot pair's `any` sits at +0x10 in the target
struct connection_slot_pair {
    int first[4];
    any second;
};

class named_slot_map_iterator {
public:
    connection_slot_pair& dereference() const;
    connection_slot_pair& operator*() const { return dereference(); }
    int state[7];
};

template<class T1> struct args1 { T1 a1; };

template<class R> struct call_bound1 {
    template<class T1, class F> struct caller {
        typedef args1<T1>* args_type;
        args_type args;
        unusable operator()(connection_slot_pair& slot) const
        {
            F* target = any_cast<F>(&slot.second);
            (*target)(args->a1);
            return unusable();
        }
    };
};

template<class Function, class Iterator>
class slot_call_iterator {
public:
    bool equal(const slot_call_iterator& other) const;
    void increment();
    bool operator!=(const slot_call_iterator& other) const { return !equal(other); }
    slot_call_iterator& operator++() { increment(); return *this; }
    const unusable& operator*() const
    {
        if (!cache->is_initialized())
            cache->reset(f(*iter));
        return *(const unusable*)cache;
    }

    mutable Iterator iter;
    Iterator end;
    Function f;
    optional<unusable>* cache;
};

}
}

template<class T> struct last_value;
template<> struct last_value<void> {
    typedef signals::detail::unusable result_type;
    template<class InputIterator>
    result_type operator()(InputIterator first, InputIterator last) const
    {
        while (first != last) {
            *first;
            ++first;
        }
        return result_type();
    }
};

typedef signals::detail::slot_call_iterator<
    signals::detail::call_bound1<void>::caller<G3D::Vector3, function<void (G3D::Vector3)> >,
    signals::detail::named_slot_map_iterator> Vector3SlotIterator;

template signals::detail::unusable last_value<void>::operator()<Vector3SlotIterator>(Vector3SlotIterator, Vector3SlotIterator) const;
}
