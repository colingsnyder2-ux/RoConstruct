// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct PropertyDescriptor;
extern PropertyDescriptor desc_X;
struct Prim { char p[0x70]; char value; void setValue(char v); };
struct Inst { void raisePropertyChanged(const PropertyDescriptor& d); };
struct Part : Inst { char p[0x118]; Prim* prim; void set(char v); };
void Part::set(char v) { if (v != prim->value) { prim->setValue(v); raisePropertyChanged(desc_X); } }
