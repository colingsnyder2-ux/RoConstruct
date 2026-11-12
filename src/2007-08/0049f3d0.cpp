// from server: 100% by EspClaude
// from server: 46% by colin
// roc 2007-08 0049f3d0  unit: RBX::Network::VServer::?$BoundFuncDesc  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0049f3d0
//
// 0049f3d0  6aff                 push -1
// 0049f3d2  6883947400           push 0x749483
// 0049f3d7  64a100000000         mov eax, dword ptr fs:[0]
// 0049f3dd  50                   push eax
// 0049f3de  51                   push ecx
// 0049f3df  53                   push ebx
// 0049f3e0  56                   push esi
// 0049f3e1  57                   push edi
// 0049f3e2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0049f3e7  33c4                 xor eax, esp
// 0049f3e9  50                   push eax
// 0049f3ea  8d442414             lea eax, [esp + 0x14]
// 0049f3ee  64a300000000         mov dword ptr fs:[0], eax
// 0049f3f4  8bf1                 mov esi, ecx
// 0049f3f6  89742410             mov dword ptr [esp + 0x10], esi
// 0049f3fa  8b442438             mov eax, dword ptr [esp + 0x38]
// 0049f3fe  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0049f402  50                   push eax
// 0049f403  51                   push ecx
// 0049f404  e8279effff           call 0x499230
// 0049f409  50                   push eax
// 0049f40a  8bce                 mov ecx, esi
// 0049f40c  e89f190d00           call 0x570db0
// 0049f411  8b542424             mov edx, dword ptr [esp + 0x24]
// 0049f415  8b442428             mov eax, dword ptr [esp + 0x28]
// 0049f419  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0049f421  c706e4cb7900         mov dword ptr [esi], 0x79cbe4
// 0049f427  895628               mov dword ptr [esi + 0x28], edx
// 0049f42a  89462c               mov dword ptr [esi + 0x2c], eax
// 0049f42d  8d7e30               lea edi, [esi + 0x30]
// 0049f430  e89be30c00           call 0x56d7d0
// 0049f435  6a08                 push 8
// 0049f437  8907                 mov dword ptr [edi], eax
// 0049f439  e8b80a1900           call 0x62fef6
// 0049f43e  83c404               add esp, 4
// 0049f441  85c0                 test eax, eax
// 0049f443  740f                 je 0x49f454
// 0049f445  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0049f449  c70098717800         mov dword ptr [eax], 0x787198
// 0049f44f  894804               mov dword ptr [eax + 4], ecx
// 0049f452  eb02                 jmp 0x49f456
// 0049f454  33c0                 xor eax, eax
// 0049f456  894704               mov dword ptr [edi + 4], eax
// 0049f459  c644241c01           mov byte ptr [esp + 0x1c], 1
// 0049f45e  8d5e14               lea ebx, [esi + 0x14]
// 0049f461  e8eade0c00           call 0x56d350
// 0049f466  57                   push edi
// 0049f467  8903                 mov dword ptr [ebx], eax
// 0049f469  e862e30c00           call 0x56d7d0
// 0049f46e  8b542434             mov edx, dword ptr [esp + 0x34]
// 0049f472  50                   push eax
// 0049f473  6aff                 push -1
// 0049f475  52                   push edx
// 0049f476  e8c5d40800           call 0x52c940
// 0049f47b  83c408               add esp, 8
// 0049f47e  50                   push eax
// 0049f47f  8bcb                 mov ecx, ebx
// 0049f481  e87adf0c00           call 0x56d400
// 0049f486  8bc6                 mov eax, esi
// 0049f488  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0049f48c  64890d00000000       mov dword ptr fs:[0], ecx
// 0049f493  59                   pop ecx
// 0049f494  5f                   pop edi
// 0049f495  5e                   pop esi
// 0049f496  5b                   pop ebx
// 0049f497  83c410               add esp, 0x10
// 0049f49a  c21800               ret 0x18

#include <typeinfo>

namespace boost {
    class any {
    public:
        template<typename ValueType>
        any(const ValueType& value) : content(new holder<ValueType>(value)) {}
        ~any() { delete content; }
    private:
        class placeholder {
        public:
            virtual ~placeholder() {}
            virtual const std::type_info& type() const = 0;
            virtual placeholder* clone() const = 0;
        };
        template<typename ValueType>
        class holder : public placeholder {
        public:
            holder(const ValueType& value) : held(value) {}
            virtual const std::type_info& type() const { return typeid(ValueType); }
            virtual placeholder* clone() const { return new holder(held); }
            ValueType held;
        };
        placeholder* content;
    };
    template<typename F> struct function_traits;
    template<typename R, typename A1> struct function_traits<R(A1)> {
        typedef R result_type;
        typedef A1 arg1_type;
    };
}

namespace RBX {
    class Name {
    public:
        static const Name& __cdecl declare(const char* name, int dictionaryIndex);
    };
    namespace Reflection {
        class ClassDescriptor;
        class Type {
        public:
            template<typename T> static const Type& singleton();
        };
        class Value {
        private:
            const Type* _type;
            boost::any value;
        public:
            template<typename ValueType>
            Value(ValueType& value) : _type(&Type::singleton<ValueType>()), value(value) {}
        };
        class SignatureDescriptor {
        public:
            const Type* resultType;
            int argumentsList[4];   // std::list<Item>; target puts the next member at 0x28
            void addArgument(const Name& name, const Type& type, const Value& defaultValue);
        };
        class Descriptor {
        public:
            const Name& name;
            virtual ~Descriptor() {}
        };
        class DescribedBase;
        class __declspec(novtable) FunctionDescriptor : public Descriptor {
        public:
            enum Security { NeedTrustedCaller = 0, AnyCaller = 1 };
            class Arguments;
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
        class BoundFuncDesc<Class, Function, 1> : public FuncDesc<Class> {
        private:
            typedef typename boost::function_traits<Function>::result_type result_type;
            typedef typename boost::function_traits<Function>::arg1_type Arg1;
        public:
            typedef result_type (Class::*FunctionSig)(Arg1);
        private:
            FunctionSig function;
            Value default1;
            void declareSignature(const char* arg1Name)
            {
                signature.resultType = &Type::singleton<result_type>();
                signature.addArgument(Name::declare(arg1Name, -1), Type::singleton<Arg1>(), default1);
            }
        public:
            BoundFuncDesc(FunctionSig function, const char* name, const char* arg1Name, Arg1 default1, Security security)
                : FuncDesc<Class>(name, security), function(function), default1(default1)
            {
                declareSignature(arg1Name);
            }
            virtual void execute(DescribedBase* instance, Arguments& arguments) const;
        };
    }
}

// 8-byte member-function pointer in the target (function stored at 0x28/0x2c)
class BoundClassBase1 { public: virtual ~BoundClassBase1(); };
class BoundClassBase2 { public: virtual ~BoundClassBase2(); };
class BoundClass : public BoundClassBase1, public BoundClassBase2 {
public:
    static RBX::Reflection::ClassDescriptor& classDescriptor();
};

template RBX::Reflection::BoundFuncDesc<BoundClass, void(int), 1>::BoundFuncDesc(
    void (BoundClass::*)(int), const char*, const char*, int, RBX::Reflection::FunctionDescriptor::Security);
