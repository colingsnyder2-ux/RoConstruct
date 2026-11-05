// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GF /GS- /EHsc /MD /Ob1
#include <string>
struct First {
    virtual void a();
    std::string s;
    char pad[0x90];
};
struct Second {
    virtual std::string name() const;
};
struct D : public First, public Second {
    virtual std::string name() const;
};
std::string D::name() const
{
    return s;
}
