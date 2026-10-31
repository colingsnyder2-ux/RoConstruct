// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF- /GS- /EHsc /MD
namespace RBX {
class Instance { public: virtual ~Instance(); };
class Service { public: virtual ~Service(); };
class Profile : public Instance, public Service { public: int getValue() const; };
namespace Reflection {
template<class Class, typename T>
class PropDesc {
    char data[0x40];
public:
    template<typename Getter>
    PropDesc(const char* name, const char* category, Getter getter, int setter, int security);
    ~PropDesc();
};
}
}
using namespace RBX;
static Reflection::PropDesc<Profile, int> prop_SystemProductName("SystemProductName", "Profile", &Profile::getValue, 0, 7);
