// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
struct Base { virtual void dispose(); long use; long weak; };
struct Dummy {};
template<class T> struct shared_ptr { T* px; Base* pi; };
template<class T> struct weak_ptr { T* px; Base* pi;
  template<class Y> weak_ptr(const shared_ptr<Y>& r, Dummy = Dummy()) : px(r.px), pi(r.pi) { if (pi) _InterlockedIncrement(&pi->weak); } };
struct X {};
template weak_ptr<X>::weak_ptr(const shared_ptr<X>&, Dummy);
