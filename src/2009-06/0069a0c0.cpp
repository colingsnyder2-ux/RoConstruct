// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class A0 { public: virtual ~A0(); char a0[0x10]; };
class A1 { public: virtual void a1(); };
class A2 { public: virtual void a2(); char a2p[4]; };
class A3 { public: virtual void a3(); char a3p[0x68]; };
class Instance : public A0, public A1, public A2, public A3 {
public:
    virtual ~Instance();
    void setName(const std::string& name);
};
class Base : public Instance {
public:
    Base();
};
class __declspec(novtable) IStepped { public: IStepped() : a(-1), b(-1), c(0) {} virtual ~IStepped(); int a, b, c; };
class Feature : public Base, public IStepped {
public:
    Feature();
    int d, e, f, g;
};
Feature::Feature() : d(0), e(1), f(1), g(2)
{
    setName("Feature");
}
}
