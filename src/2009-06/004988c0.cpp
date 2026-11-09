// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <sstream>
#include <string>
std::string archiveName(int n)
{
    std::ostringstream s;
    s << "RbxArchive" << std::hex << n;
    return s.str();
}
