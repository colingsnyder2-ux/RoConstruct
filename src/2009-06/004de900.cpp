// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <algorithm>
namespace RBX {
class Instance;
namespace Network {
struct A { virtual void a(); };
struct B { virtual void b(); };
class IdSerializer : public A, public B {
public:
    struct WaitItem { int a, b, c; };
    void resolve(WaitItem& item, Instance* inst);
};
struct Mf2 {
    void (IdSerializer::*f_)(IdSerializer::WaitItem&, Instance*);
    void operator()(IdSerializer* p, IdSerializer::WaitItem& w, Instance* i) const { (p->*f_)(w, i); }
};
struct Binder {
    Mf2 f;
    IdSerializer* obj;
    Instance* inst;
    void operator()(IdSerializer::WaitItem& w) const { IdSerializer* p = obj; f(p, w, inst); }
};
}}
template RBX::Network::Binder std::for_each(std::vector<RBX::Network::IdSerializer::WaitItem>::iterator,
    std::vector<RBX::Network::IdSerializer::WaitItem>::iterator, RBX::Network::Binder);
