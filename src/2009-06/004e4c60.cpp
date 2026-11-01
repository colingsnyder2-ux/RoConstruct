// from server: 81% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class ExeBase {
public:
    ExeBase(int a, std::string name, bool flag);
private:
    char data[0x20];
};
class ExeDerived : public ExeBase {
public:
    ExeDerived(int a, std::string name, bool flag);
};
ExeDerived::ExeDerived(int a, std::string name, bool flag) : ExeBase(a, name, flag) {}
}
