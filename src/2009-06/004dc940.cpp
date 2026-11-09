// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
struct Holder { int id; const std::string* name; };
class Getter {
public:
    std::string get(const Holder& h);
};
std::string Getter::get(const Holder& h)
{
    return *h.name;
}
