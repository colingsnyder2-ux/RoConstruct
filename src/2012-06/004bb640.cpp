// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Base { Base(const Base&); virtual ~Base(); char pad[0x24]; };
struct Exc { virtual ~Exc(); void* data; const char* fn; const char* file; int line; Exc(): data(0), fn(0), file(0), line(-1) {} };
struct Inj : Base, Exc { Inj(const Base& b) : Base(b) {} virtual ~Inj(); };
template<class T> struct rp { T* p; rp():p(0){} };
struct Exc2 { virtual ~Exc2(); rp<int> data; const char* fn; const char* file; int line; Exc2(): fn(0), file(0), line(-1) {} };
struct Inj2 : Base, Exc2 { Inj2(const Base& b) : Base(b) {} virtual ~Inj2(); };
Inj2 enable(const Base& b) { return Inj2(b); }
