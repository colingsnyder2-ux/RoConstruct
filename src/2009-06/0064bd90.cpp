// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
std::string formatFloat(const float& value);
struct Vector2 { float x, y; };
std::string toString(const Vector2& v)
{
    std::string s = formatFloat(v.x);
    s += ", ";
    s += formatFloat(v.y);
    return s;
}
