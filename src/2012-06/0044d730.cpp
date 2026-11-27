// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <sstream>
#include <iomanip>
#include <string>
std::string formatPadded(__int64 value, int width)
{
    std::ostringstream ss;
    ss.imbue(std::locale::classic());
    ss << std::setw(width) << std::setfill('0') << value;
    return ss.str();
}