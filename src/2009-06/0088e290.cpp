// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct ExeBaseA { virtual ~ExeBaseA(); };
struct ExeBaseB { virtual ~ExeBaseB(); };
class C : public ExeBaseA, public ExeBaseB { public: int f(int); };
class Desc {
public:
    Desc(int (C::*fn)(int), const char* name, const char* arg1, int def, int security);
    ~Desc();
    char data[0x60];
};
static Desc desc_f(&C::f, "GetTimesForFrames", "frames", 1, 1);
