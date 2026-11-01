// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Part;
struct A { virtual void a(); char pad[0x138]; };
struct Sec { virtual bool hasHead() = 0; };
class Humanoid : public A, public Sec {
public:
    Part* getHead();
    virtual bool hasHead();
};
bool Humanoid::hasHead() { return getHead() != 0; }
