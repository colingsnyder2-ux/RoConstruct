// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
extern int g_flag;
std::string make();
const std::string& getName()
{
    static std::string s;
    if (g_flag == 0)
        s = make();
    return s;
}
