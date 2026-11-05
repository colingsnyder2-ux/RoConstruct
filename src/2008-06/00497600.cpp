// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Net { public: virtual void v0(); virtual void v1(); virtual bool has(void* p); }; extern Net* net;
struct P { char pad[0x14]; int addr; };
class Players { char pad[0x1a0]; P* p; public: bool f(); };
bool Players::f() { if (p) return net->has(&p->addr); return false; } }
