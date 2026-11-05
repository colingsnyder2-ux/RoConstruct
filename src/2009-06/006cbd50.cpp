// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Pad { virtual ~Pad(); char p[0xa4]; };
struct Sink { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void notify(int a, bool b); };
struct Target : Pad, Sink {};
class Holder { public: virtual ~Holder(); char p[0x14]; Target* target; void fire(int a); };
void Holder::fire(int a) { Target* t = target; if (t) t->notify(a, true); }
