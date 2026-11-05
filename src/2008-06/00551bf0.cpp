// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS /EHsc /MD
// Constructor analog for 00551bf0 (base of 00551b30): root ctor 00472990,
// std::string at +0xc, then 1 and 1.0f at +0x28/+0x2c.
#include <string>

class Root {
public:
    Root();
    virtual ~Root();
    char data[8];
};

class Named : public Root {
public:
    Named();
    virtual ~Named();
    std::string name;
    int count;
    float weight;
};

Named::Named()
{
    count = 1;
    weight = 1.0f;
}
