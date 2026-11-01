// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
namespace RBX {
class A0 { public: virtual void a0(); char pad[0x10]; };
class A1 { public: virtual void a1(); };
class A2 { public: virtual ~A2(); void* d; };
class A3 { public: virtual void a3(); char pad[8]; };
class Instance : public A0, public A1, public A2, public A3 {
public:
	virtual ~Instance();
	void setName(const std::string& name);
	char ipad[0x8c - 0x2c];
};
class __declspec(novtable) SettingsItem : public Instance {
public:
	SettingsItem();
};
class GameSettings : public SettingsItem {
	int a;
	int b;
	bool c;
	bool d;
public:
	GameSettings();
};
GameSettings::GameSettings() : a(50), b(5), c(true), d(false)
{
	setName("Game Options");
}
}
