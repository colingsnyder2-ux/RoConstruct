// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
class Binder { public: void bind(); static void onEvent(int a, int b, Binder* c); };
void Binder::onEvent(int a, int b, Binder* c) { if (a == b) c->bind(); }
