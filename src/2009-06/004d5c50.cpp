// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <stdexcept>
namespace RBX {
std::runtime_error runtime_error(const char* fmt, ...);
struct ExeB0 { virtual void f0(); char p[0x10]; };
struct ExeB14 { virtual void f1(); };
struct ExeB18 { virtual void f2(); int x; };
struct ExeB20 { virtual void f3(); char p[0x68]; };
class GlobalSettingsItem : public ExeB0, public ExeB14, public ExeB18, public ExeB20 {
public:
    GlobalSettingsItem();
    ~GlobalSettingsItem();
    void setName(const std::string& name);
};
class NetworkSettings : public GlobalSettingsItem {
    static NetworkSettings* sing;
public:
    NetworkSettings();
};
NetworkSettings::NetworkSettings()
{
    setName("NetworkSettings");
    if (sing)
        throw RBX::runtime_error("singleton %s already exists", "NetworkSettings");
    sing = this;
}
}
