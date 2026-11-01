// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Name { public: static const Name& declare(const char* s); };
extern int typeCounter;
extern int typeCounter2;
namespace Reflection {
class ClassDescriptor;
class Type;
struct Holder { virtual ~Holder(); };
struct Variant {
    void* type;
    Holder* content;
    Variant();
    ~Variant() { if (content) delete content; }
};
struct Item {
    const Name* name;
    const Type* type;
    Variant def;
};
struct Node { Node* next; Node* prev; };
struct ArgList {
    char pad[0x14];
    Node* head;
    char pad2[4];
    Node* _Buynode(Node* next, Node* prev, const Item& v);
    void _Incsize(unsigned int n);
    static Node*& _Prevnode(Node* p) { return p->prev; }
    static Node*& _Nextnode(Node* p) { return p->next; }
    void _Insert(Node* where, const Item& v) {
        Node* n = _Buynode(where, _Prevnode(where), v);
        _Incsize(1);
        _Prevnode(where) = n;
        _Nextnode(_Prevnode(n)) = n;
    }
    Node* end() { return head; }
    void push_back(const Item& v) { _Insert(end(), v); }
};
const Type& typeSingleton();
inline const Type& singletonT() { ++typeCounter; return typeSingleton(); }
const Type& typeSingleton2();
inline const Type& singletonT2() { ++typeCounter2; return typeSingleton2(); }
class SignalDescriptor {
public:
    SignalDescriptor(const ClassDescriptor& c, const char* name);
    virtual ~SignalDescriptor();
    char pad[0x10];
    ArgList arguments;
};
template<class C, class Sig>
class __declspec(novtable) TSignalDesc : public SignalDescriptor {
protected:
    Sig C::* sig;
    TSignalDesc(Sig C::* s, const char* name) : SignalDescriptor(C::classDescriptor(), name), sig(s) {}
};
template<class C, class Sig>
class SignalDesc : public TSignalDesc<C, Sig> {
public:
    SignalDesc(Sig C::* s, const char* name, const char* arg1name, const char* arg2name);
    virtual ~SignalDesc() {}
};
template<class C, class Sig>
SignalDesc<C, Sig>::SignalDesc(Sig C::* s, const char* name, const char* arg1name, const char* arg2name)
    : TSignalDesc<C, Sig>(s, name)
{
    Item arg1 = {&Name::declare(arg1name), &singletonT()};
    this->arguments.push_back(arg1);
    Item arg2 = {&Name::declare(arg2name), &singletonT2()};
    this->arguments.push_back(arg2);
}
}
struct Signal { int x; };
class Target {
public:
    static const Reflection::ClassDescriptor& classDescriptor();
    Signal sigm;
};
template Reflection::SignalDesc<Target, Signal>::SignalDesc(Signal Target::*, const char*, const char*, const char*);
}
