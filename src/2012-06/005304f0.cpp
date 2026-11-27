// from server: 91% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct String;
extern void (__thiscall *destroyString)(String*);
struct String { char b[28]; ~String() { destroyString(this); } };
typedef void (__thiscall *Fn)(void*, String*);
struct Slot { Fn fn; char* obj; int adj; };
void f(Slot* p, String s) {
    Fn fn = p->fn; fn(p->obj + p->adj, &s);
}