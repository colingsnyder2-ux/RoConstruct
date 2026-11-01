// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class A0 { public: virtual void a0(); int pad[4]; };
class A1 { public: virtual void a1(); };
class A2 { public: virtual void a2(); int d; };
class A3 { public: virtual void a3(); };
class Instance : public A0, public A1, public A2, public A3 { public: virtual ~Instance(); };
class Item : public Instance { public: virtual ~Item() {} };
extern void* g_inst;
class DebugSettings : public Item { public: DebugSettings(); virtual ~DebugSettings(); };
DebugSettings::DebugSettings() {}
DebugSettings::~DebugSettings() { g_inst = 0; }
