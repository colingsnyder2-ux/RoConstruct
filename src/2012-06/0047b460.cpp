// from server: 88% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String {
    char b[28];
    __declspec(dllimport) String(const String&);
    String() {}
    ~String() { destroyString(this); }
};
struct Obj;
typedef String* (__thiscall *Fn)(Obj*, String*);
struct Slot { Fn fn; String f(Obj* o); };
String Slot::f(Obj* o) { String tmp; return *fn(o, &tmp); }