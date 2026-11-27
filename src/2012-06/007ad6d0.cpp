// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct T { std::string s; int n; };
struct PD;
struct Pad { virtual void pv(); char p[0x18]; };
struct DB { virtual void dv(); };
struct Sky;
typedef void (Sky::*Chg)(const PD*);
struct Sky : Pad, DB { T t; void raise(const PD*); void chg(const PD*); };
bool diff(const T*, const T*);
struct GetSet { virtual bool a() const; virtual bool b() const; virtual void c(const DB*) const; virtual void setValue(DB* o, const void* v) const; };
struct Bound : GetSet {
  const PD* desc; T Sky::* field; int pad; Chg changed;
  virtual void setValue(DB* o, const void* v) const;
};
void Bound::setValue(DB* o, const void* v) const {
  Sky* sky = static_cast<Sky*>(o);
  const T* nv = static_cast<const T*>(v);
  if (diff(&(sky->*field), nv)) {
    sky->*field = *nv;
    if (changed) (sky->*changed)(desc);
    sky->raise(desc);
  }
}
