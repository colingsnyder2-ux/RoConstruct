// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct U { int g(int); };
class CDocument { public: virtual void dv(); };
class CRobloxDoc : public CDocument { public: U* get(); };
template<class D, class B> class VerbBinder { public: virtual void v(); int f(int a); };
template<class D, class B> int VerbBinder<D, B>::f(int a) { D* t = dynamic_cast<D*>(this); if (!t) return 0; U* u = t->get(); if (!u) return 0; return u->g(a); }
template class VerbBinder<CRobloxDoc, CDocument>;
