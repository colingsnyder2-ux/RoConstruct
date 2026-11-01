// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
#include <string>
extern "C" __declspec(dllimport) char* __stdcall StrStrIA(const char*, const char*);
struct VideoCardInfo {
    char pad[0xe];
    bool squareOnly;
    char pad2;
    std::string name;
    void setSquareOnly(bool b);
};
void VideoCardInfo::setSquareOnly(bool b)
{
    squareOnly = b;
    if (StrStrIA(name.c_str(), "Savage") && !squareOnly)
        squareOnly = true;
}
