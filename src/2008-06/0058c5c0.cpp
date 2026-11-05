// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Svc { public: void doIt(int a); }; Svc* find(int b);
void handle(int a, int b) { if (Svc* s = find(b)) s->doIt(a); } }
