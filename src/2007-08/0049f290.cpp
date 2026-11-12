// from server: 100% by EspClaude
// from server: 42% by colin
// roc 2007-08 0049f290  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049f290
//
// 0049f290  6aff                 push -1
// 0049f292  6850947400           push 0x749450
// 0049f297  64a100000000         mov eax, dword ptr fs:[0]
// 0049f29d  50                   push eax
// 0049f29e  83ec1c               sub esp, 0x1c
// 0049f2a1  55                   push ebp
// 0049f2a2  56                   push esi
// 0049f2a3  57                   push edi
// 0049f2a4  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049f2a9  33c4                 xor eax, esp
// 0049f2ab  50                   push eax
// 0049f2ac  8d44242c             lea eax, [esp + 0x2c]
// 0049f2b0  64a300000000         mov dword ptr fs:[0], eax
// 0049f2b6  8bf1                 mov esi, ecx
// 0049f2b8  8b4e34               mov ecx, dword ptr [esi + 0x34]
// 0049f2bb  85c9                 test ecx, ecx
// 0049f2bd  8b4630               mov eax, dword ptr [esi + 0x30]
// 0049f2c0  89442418             mov dword ptr [esp + 0x18], eax
// 0049f2c4  7409                 je 0x49f2cf
// 0049f2c6  8b11                 mov edx, dword ptr [ecx]
// 0049f2c8  8b4208               mov eax, dword ptr [edx + 8]
// 0049f2cb  ffd0                 call eax
// 0049f2cd  eb02                 jmp 0x49f2d1
// 0049f2cf  33c0                 xor eax, eax
// 0049f2d1  8944241c             mov dword ptr [esp + 0x1c], eax
// 0049f2d5  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 0049f2d9  8b17                 mov edx, dword ptr [edi]
// 0049f2db  8b5204               mov edx, dword ptr [edx + 4]
// 0049f2de  8d442418             lea eax, [esp + 0x18]
// 0049f2e2  50                   push eax
// 0049f2e3  6a01                 push 1
// 0049f2e5  8bcf                 mov ecx, edi
// 0049f2e7  c744243c00000000     mov dword ptr [esp + 0x3c], 0
// 0049f2ef  ffd2                 call edx
// 0049f2f1  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0049f2f4  85c9                 test ecx, ecx
// 0049f2f6  8b4638               mov eax, dword ptr [esi + 0x38]
// 0049f2f9  89442410             mov dword ptr [esp + 0x10], eax
// 0049f2fd  7409                 je 0x49f308
// 0049f2ff  8b11                 mov edx, dword ptr [ecx]
// 0049f301  8b4208               mov eax, dword ptr [edx + 8]
// 0049f304  ffd0                 call eax
// 0049f306  eb02                 jmp 0x49f30a
// 0049f308  33c0                 xor eax, eax
// 0049f30a  89442414             mov dword ptr [esp + 0x14], eax
// 0049f30e  8b17                 mov edx, dword ptr [edi]
// 0049f310  8b5204               mov edx, dword ptr [edx + 4]
// 0049f313  8d442410             lea eax, [esp + 0x10]
// 0049f317  50                   push eax
// 0049f318  6a02                 push 2
// 0049f31a  8bcf                 mov ecx, edi
// 0049f31c  c644243c01           mov byte ptr [esp + 0x3c], 1
// 0049f321  ffd2                 call edx
// 0049f323  8b44243c             mov eax, dword ptr [esp + 0x3c]
// 0049f327  6a00                 push 0
// 0049f329  68bc048900           push 0x8904bc
// 0049f32e  689c208800           push 0x88209c
// 0049f333  6a00                 push 0
// 0049f335  50                   push eax
// 0049f336  e8fb191900           call 0x630d36
// 0049f33b  8bf8                 mov edi, eax
// 0049f33d  83c414               add esp, 0x14
// 0049f340  85ff                 test edi, edi
// 0049f342  751e                 jne 0x49f362
// 0049f344  68046e7800           push 0x786e04
// 0049f349  8d4c2424             lea ecx, [esp + 0x24]
// 0049f34d  ff1510e77700         call dword ptr [0x77e710]
// 0049f353  680c1e8400           push 0x841e0c
// 0049f358  8d4c2424             lea ecx, [esp + 0x24]
// 0049f35c  51                   push ecx
// 0049f35d  e83c181900           call 0x630b9e
// 0049f362  8d4c2410             lea ecx, [esp + 0x10]
// 0049f366  e845fc0c00           call 0x56efb0
// 0049f36b  8d4c2418             lea ecx, [esp + 0x18]
// 0049f36f  8be8                 mov ebp, eax
// 0049f371  e83afc0c00           call 0x56efb0
// 0049f376  8b5500               mov edx, dword ptr [ebp]
// 0049f379  8b00                 mov eax, dword ptr [eax]
// 0049f37b  8b4e2c               mov ecx, dword ptr [esi + 0x2c]
// 0049f37e  52                   push edx
// 0049f37f  8b5628               mov edx, dword ptr [esi + 0x28]
// 0049f382  50                   push eax
// 0049f383  03cf                 add ecx, edi
// 0049f385  ffd2                 call edx
// 0049f387  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049f38b  85c9                 test ecx, ecx
// 0049f38d  c644243400           mov byte ptr [esp + 0x34], 0
// 0049f392  7408                 je 0x49f39c
// 0049f394  8b01                 mov eax, dword ptr [ecx]
// 0049f396  8b10                 mov edx, dword ptr [eax]
// 0049f398  6a01                 push 1
// 0049f39a  ffd2                 call edx
// 0049f39c  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0049f3a0  85c9                 test ecx, ecx
// 0049f3a2  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 0049f3aa  7408                 je 0x49f3b4
// 0049f3ac  8b01                 mov eax, dword ptr [ecx]
// 0049f3ae  8b10                 mov edx, dword ptr [eax]
// 0049f3b0  6a01                 push 1
// 0049f3b2  ffd2                 call edx
// 0049f3b4  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0049f3b8  64890d00000000       mov dword ptr fs:[0], ecx
// 0049f3bf  59                   pop ecx
// 0049f3c0  5f                   pop edi
// 0049f3c1  5e                   pop esi
// 0049f3c2  5d                   pop ebp
// 0049f3c3  83c428               add esp, 0x28
// 0049f3c6  c20800               ret 8

#include <typeinfo>

namespace boost {
    class any {
    public:
        any(const any& other) : content(other.content ? other.content->clone() : 0) {}
        ~any() { delete content; }
    private:
        class placeholder {
        public:
            virtual ~placeholder() {}
            virtual const std::type_info& type() const = 0;
            virtual placeholder* clone() const = 0;
        };
        placeholder* content;
    };
    template<typename F> struct function_traits;
    template<typename R, typename A1, typename A2> struct function_traits<R(A1, A2)> {
        typedef R result_type;
        typedef A1 arg1_type;
        typedef A2 arg2_type;
    };
}

namespace RBX {
    class Name;
    namespace Reflection {
        class ClassDescriptor;
        class Type;
        class Value {
        private:
            const Type* _type;
            boost::any value;
        public:
            template<typename T> T& convert();
        };
        class SignatureDescriptor {
        public:
            const Type* resultType;
            int argumentsList[4];   // std::list<Item>; target puts the next member at 0x28
        };
        class Descriptor {
        public:
            const Name& name;
            virtual ~Descriptor() {}
        };
        class DescribedBase {
        public:
            virtual ~DescribedBase();
        };
        class __declspec(novtable) FunctionDescriptor : public Descriptor {
        public:
            enum Security { NeedTrustedCaller = 0, AnyCaller = 1 };
            class __declspec(novtable) Arguments {
            public:
                Value returnValue;
                virtual size_t size() const = 0;
                virtual void get(int, Value&) const = 0;
            };
            const Name& category;
            const ClassDescriptor& owner;
            const Security security;
        protected:
            SignatureDescriptor signature;
            FunctionDescriptor(ClassDescriptor& classDescriptor, const char* name, Security security);
        public:
            virtual void execute(DescribedBase* instance, Arguments& arguments) const = 0;
        };
        template<typename Class>
        class FuncDesc : public FunctionDescriptor {
        protected:
            FuncDesc(const char* name, Security security)
                : FunctionDescriptor(Class::classDescriptor(), name, security) {}
        };

        template<typename Class, typename Function, int ArgCount> class BoundFuncDesc;

        template<typename Class, typename Function>
        class BoundFuncDesc<Class, Function, 2> : public FuncDesc<Class> {
        private:
            typedef typename boost::function_traits<Function>::result_type result_type;
            typedef typename boost::function_traits<Function>::arg1_type Arg1;
            typedef typename boost::function_traits<Function>::arg2_type Arg2;
        public:
            typedef result_type (Class::*FunctionSig)(Arg1, Arg2);
        private:
            FunctionSig function;
            Value default1;
            Value default2;
        public:
            BoundFuncDesc(FunctionSig function, const char* name, const char* arg1Name, const char* arg2Name, Arg2 default2, Security security);
            virtual void execute(DescribedBase* instance, Arguments& arguments) const
            {
                Value arg1 = default1;
                arguments.get(1, arg1);
                Value arg2 = default2;
                arguments.get(2, arg2);

                Class* o = dynamic_cast<Class*>(instance);
                if (!o)
                    throw std::bad_cast();

                (o->*function)(arg1.convert<Arg1>(), arg2.convert<Arg2>());
            }
        };
    }
}

// 8-byte member-function pointer in the target (function stored at 0x28/0x2c)
class ServerSecondBase { public: virtual ~ServerSecondBase(); };
namespace RBX { namespace Network {
    class Server : public RBX::Reflection::DescribedBase, public ServerSecondBase {
    public:
        static RBX::Reflection::ClassDescriptor& classDescriptor();
    };
} }

template void RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int, int), 2>::execute(
    RBX::Reflection::DescribedBase*, RBX::Reflection::FunctionDescriptor::Arguments&) const;
