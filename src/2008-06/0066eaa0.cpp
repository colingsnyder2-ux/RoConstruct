// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Ball { public: int getX(); }; class Sel { public: Ball* get(); }; Sel* getSel();
int f() { Ball* b = getSel()->get(); if (b) return b->getX(); return 0; } }
