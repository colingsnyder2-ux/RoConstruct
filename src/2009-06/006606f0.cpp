// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Obj {
    char pad[0x120];
    int value;
    void raisePropertyChanged(const char* name);
    void setValue(int v);
};
extern char propA[];
extern char propB[];
void Obj::setValue(int v)
{
    if (v != value) {
        value = v;
        raisePropertyChanged(propA);
        raisePropertyChanged(propB);
    }
}
