// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct ExeBaseA { virtual ~ExeBaseA(); };
struct ExeBaseB { virtual ~ExeBaseB(); };
class C : public ExeBaseA, public ExeBaseB { public: int get() const; };
class Desc {
public:
    enum Functionality { Standard = 7 };
    Desc(const char* name, const char* category, int (C::*getter)() const, int setter, Functionality f);
    ~Desc();
    char data[0x50];
};
static Desc desc_p("Hit", "Data", &C::get, 0, Desc::Standard);
