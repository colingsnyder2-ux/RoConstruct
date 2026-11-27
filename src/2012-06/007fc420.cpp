// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
extern void (__thiscall *copyString)(String*, String*);
struct String {
    char b[28];
    __declspec(dllimport) String(const String&);
    ~String() { destroyString(this); }
};
struct M { int pad[2]; int x; void g(int, String, int, int); };
struct S { char pad[0x10]; M m; void f(String s, int a, int b); };
void S::f(String s, int a, int b) { M* mp = &m; mp->g(mp->x, s, a, b); }