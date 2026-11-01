// from server: 100% by EspClaude
// roc 2009-06 005d1260  unit: VAuthoringSettings::?$FactoryProduct  size: 205 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d1260
//

// 2009 SignalDesc<Instance, void(shared_ptr<Instance>)>(Signal Instance::*, name, arg1name) (self-contained)
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
class any {
    struct placeholder { virtual ~placeholder() {} };
public:
    ~any() { delete content; }
    placeholder* content;
};
template<class T> class shared_ptr { T* px; void* pn; };
}
namespace RBX {
namespace Reflection {
class ClassDescriptor;
class Type {
public:
    template<typename T> static const Type& singletonImpl();
};
template<class T> struct ExeCounter { static int n; };
template<typename T> inline const Type& singleton() { ++ExeCounter<T>::n; return Type::singletonImpl<T>(); }
class Name { public: static Name& declare(const char* name); };
class Value {
    const Type* _type;
    boost::any value;
public:
    Value();
};
struct SignatureDescriptor {
    struct Item { const Name* name; const Type* type; Value defaultValue; };
    struct Node { Node* next; Node* prev; Item value; };
    struct ArgList {
        char pad[0x14];
        Node* _Myhead;
        unsigned _Mysize;
        Node* _Buynode(Node* next, Node* prev, const Item& v);
        void _Incsize(unsigned n);
        static Node*& _Prevnode(Node* p) { return p->prev; }
        static Node*& _Nextnode(Node* p) { return p->next; }
        void push_back(const Item& v) {
            Node* p = _Myhead;
            Node* n = _Buynode(p, _Prevnode(p), v);
            _Incsize(1);
            _Prevnode(p) = n;
            _Nextnode(_Prevnode(n)) = n;
        }
    } arguments;
};
class SignalDescriptor {
public:
    SignalDescriptor(const ClassDescriptor& c, const char* name);
    virtual ~SignalDescriptor();
protected:
    char pad[0x10];
    SignatureDescriptor signature;
};
template<class C, class Sig> class __declspec(novtable) TSignalDesc : public SignalDescriptor {
protected:
    void* C::* member;
    TSignalDesc(void* C::* m, const char* name) : SignalDescriptor(C::classDescriptor(), name), member(m) {}
};
template<class C, class Sig> class SignalDesc : public TSignalDesc<C, Sig> {
public:
    SignalDesc(void* C::* m, const char* name, const char* arg1name);
    virtual ~SignalDesc();
};
template<class C, class Sig>
SignalDesc<C, Sig>::SignalDesc(void* C::* m, const char* name, const char* arg1name)
    : TSignalDesc<C, Sig>(m, name)
{
    SignatureDescriptor::Item arg1 = { &Name::declare(arg1name), &singleton<boost::shared_ptr<C> >() };
    this->signature.arguments.push_back(arg1);
}
}
class Instance { public: static const Reflection::ClassDescriptor& classDescriptor(); };
template class Reflection::SignalDesc<Instance, void(boost::shared_ptr<Instance>)>;
}
