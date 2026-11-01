// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct VB { virtual ~VB(); };
class C : public virtual VB { public: bool get() const; };
class Desc {
public:
    enum Functionality { F1 = 1 };
    Desc(const char* name, const char* category, bool (C::*getter)() const, int setter, Functionality f);
    ~Desc();
    char data[0x50];
};
static Desc desc_p("AreHingesDetected", "Control", &C::get, 0, Desc::F1);
