// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace boost { class any; }
const std::string& CopyVerb(boost::any* a);
std::string f(boost::any& a)
{
    return CopyVerb(&a);
}
