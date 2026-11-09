// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace RBX { class Face { public: void set(); };
class RunService { char pad[0x104]; int running; char p2[0x248-0x108]; bool dirty; char p3[0x264-0x249]; Face face; public: void f(int x); };
void RunService::f(int) { if (!running) { dirty = true; face.set(); } } }
