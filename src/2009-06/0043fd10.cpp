// from server: 100% by EspClaude
// roc 2009-06 0043fd10  unit: RBX::P8CRenderSettings::?$GetSetImpl
struct Pad0 { char pad[0x18]; };
struct DescribedBase { char pad[0x8c - 0x18]; };
struct Settings { int x; };
struct RenderSettings : Pad0, DescribedBase, Settings {};

struct X_0043fd10 {
    char pad_0[4];
    int (__thiscall *f_4)(Settings*);
    float get(DescribedBase* p);
};

float X_0043fd10::get(DescribedBase* p) {
    return (float)f_4(static_cast<RenderSettings*>(p));
}
