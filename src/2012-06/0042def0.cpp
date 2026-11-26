// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <map>
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(void*);
struct CS { char d[24]; };
struct V { int a[4]; };
struct Less { int p; int q; Less() : p(0) {} bool operator()(int a, int b) const { return a < b; } };
struct Holder {
    std::map<int, V, Less> m;
    char pad[0x24];
    CS cs;
    Holder() { InitializeCriticalSection(&cs); }
};
Holder& get() { static Holder h; return h; }

