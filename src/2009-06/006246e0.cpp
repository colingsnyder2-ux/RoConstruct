// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
bool isReserved(std::string name);
class Humanoid {
public:
    void setNameImpl(const std::string& name);
    void setName(const std::string& name);
};
void Humanoid::setName(const std::string& name)
{
    if (!isReserved(name))
        setNameImpl(name);
}
