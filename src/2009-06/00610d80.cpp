// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class B0 { public: virtual ~B0(); int pad[4]; };
class B14 { public: virtual void f14(); };
class B18 { public: virtual void f18(); void* descriptor; };
class B20 { public: virtual void f20(); };
class Instance : public B0, public B14, public B18, public B20 {
public:
    Instance();
    virtual ~Instance();
    char ipad[0x8c - 0x24];
};
class IX { public: virtual void fx(); };
class VB { public: virtual void fv(); };
class PVInstance : public Instance, public IX, public virtual VB {
public:
    PVInstance();
    ~PVInstance();
};
class Model : public PVInstance {
public:
    Model();
    virtual ~Model();
};
Model::~Model() {}
}
