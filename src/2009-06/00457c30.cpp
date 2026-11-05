// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Member { void set(int b); };
class BasePane { public: void Show(int show, int delay); };
class ExePane : public BasePane {
    char pad[0xa0];
    Member m;
public:
    void Show(int show, int delay);
};
void ExePane::Show(int show, int delay) { if (show) m.set(1); else m.set(0); BasePane::Show(show, delay); }
