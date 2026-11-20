// from server: 100% by Intel_Inside
// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD
// roc 2007-08 00544bd0  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 180 bytes
#include <string>

struct S0  { virtual void s0(); };
struct S4  { virtual void s4();  int pad[2]; };   // 0x04..0x10
struct S10 { virtual void s10(); };               // 0x10..0x14
struct S14 { virtual void s14(); int pad[5]; };   // 0x14..0x2c
struct S2c { virtual void s2c(); int pad[5]; };   // 0x2c..0x44
struct S44 { virtual void s44(); int pad[5]; };   // 0x44..0x5c
struct S5c { virtual void s5c(); int pad[5]; };   // 0x5c..0x74
struct S74 { virtual void s74(); int pad[5]; };   // 0x74..0x8c
struct S8c { virtual void s8c(); };               // 0x8c

struct Base : S0, S4, S10, S14, S2c, S44, S5c, S74, S8c {
    Base();
    ~Base();
    void setName(const std::string &name);
};

struct GameSettings : Base {
    GameSettings();
    virtual void s0();
    static GameSettings *singleton;
};

GameSettings::GameSettings()
{
    {
        std::string name("GameSettings");
        setName(name);
    }
    singleton = this;
}
