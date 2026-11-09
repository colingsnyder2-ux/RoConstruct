// from server: 100% by EspClaude
// roc 2007-08 0059fba0  RBX::GameSettings::GameSettings() (int 30 @0xe8, bools @0xec..0xee; setName("Game Options"))
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class V0 { public: virtual ~V0(); };
class V1 { public: virtual ~V1(); int a, b; };
class V2 { public: virtual ~V2(); };
template<int N> class Notifier { public: virtual ~Notifier(); int pad[5]; };
class V8 { public: virtual ~V8(); char pad[0xe8 - 0x90]; };
class GlobalSettingsItem : public V0, public V1, public V2, public Notifier<1>, public Notifier<2>, public Notifier<3>,
                           public Notifier<4>, public Notifier<5>, public V8 {
public:
    GlobalSettingsItem();
    void setName(const std::string& name);
};
class GameSettings : public GlobalSettingsItem {
    int setting0;
    bool setting1;
    bool setting2;
    bool setting3;
public:
    GameSettings();
};
GameSettings::GameSettings()
    : setting0(30), setting1(true), setting2(false), setting3(true)
{
    setName("Game Options");
}
}
