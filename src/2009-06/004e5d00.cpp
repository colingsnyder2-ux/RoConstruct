// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
struct Counted { virtual ~Counted(); int use; int weak; };
template<class T> struct SP { T* px; Counted* pn;
  SP() : px(0), pn(0) {}
  SP(const SP& o) : px(o.px), pn(o.pn) { if (pn) _InterlockedIncrement((long*)&pn->use); } };
struct Item; struct Other;
struct Base { virtual ~Base(); int x4; SP<Other> other; };
struct Node : Base { int key; SP<Item> item; Node(int k, const SP<Item>& i); };
Node::Node(int k, const SP<Item>& i) : key(k), item(i) {}
