// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2007-08 00544fe0  unit: RBX::VDebugSettings::?$GlobalSettingsItem  size: 204 bytes
// Returns by hidden pointer an object built by the out-of-line ctor at 0x44cf10 (thiscall, one
// const std::string& arg).  MSVCP80 imports: basic_string::find(const char*,uint,uint),
// basic_string(const char*), operator+(const string&, const string&), ~basic_string.
// "file://" literal at 0x7a6ef8.
#include <string>

class ContentUrl {
public:
    ContentUrl(const std::string& s);
    ~ContentUrl();
};

ContentUrl makeFileUrl(const std::string& path)
{
    if (path.find("file://") == 0)
        return ContentUrl(path);
    std::string prefix("file://");
    return ContentUrl(prefix + path);
}
