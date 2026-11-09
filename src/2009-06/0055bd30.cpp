// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct BuilderBase {
    void init(int arg);
    char pad[0x28];
};
struct TorsoBuilder : BuilderBase {
    float unknown_28;
    TorsoBuilder* someFunction(int arg);
};
TorsoBuilder* TorsoBuilder::someFunction(int arg) {
    init(arg);
    unknown_28 = 0.0f;
    return this;
}
