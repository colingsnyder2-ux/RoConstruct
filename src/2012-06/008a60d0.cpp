// from server: 74% by Xemicl
// roc-cl: 21022
// roc-flags: /O1 /Ob2 /Oy /GF /GS- /EHsc /MD
#define _SECURE_SCL 0
#define _HAS_ITERATOR_DEBUGGING 0
#include <string>
struct Named { int pad; std::string name; };
struct ToolBase { ToolBase(std::string s); virtual ~ToolBase(); char pad[0x18]; };
struct WeldTool : ToolBase {
    char flag;
    WeldTool(Named* n, char b);
};
extern int g_flag;
extern int g_guard;
extern void __cdecl callback();
extern void __cdecl initialize(void (__cdecl *)(), int *);
extern Named* __stdcall getA(Named*);
extern Named* __stdcall getB(Named*);
static inline Named* lookup(Named* n)
{
    if (g_flag == 0)
        return getA(n);
    initialize(callback, &g_guard);
    return getB(n);
}
WeldTool::WeldTool(Named* n, char b) : ToolBase(lookup(n)->name + "Tool"), flag(b) { }
