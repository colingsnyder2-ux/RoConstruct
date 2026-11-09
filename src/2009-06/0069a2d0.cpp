// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
struct Motor { char pad[0x9c]; float value; void setValue(float v); };
struct Desc {};
extern Desc desc_Value;
struct C {
    char pad[0xac];
    Motor* motor;
    void raisePropertyChanged(const Desc& d);
    void setValue(float v);
};
void C::setValue(float v) {
    if (v != motor->value) {
        motor->setValue(v);
        raisePropertyChanged(desc_Value);
    }
}
