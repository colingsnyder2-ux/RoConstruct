// from server: 100% by EspClaude
// roc 2009-06 00485af0  unit: RBX::QuadVolumeBuilder  size: 46 bytes
struct QuadBase {
    char pad0[0x34];
    void assign(void* arg);
};

struct QuadVolumeBuilder : QuadBase {
    void* field34;
    void* field38;
    QuadVolumeBuilder* method(void* arg);
};

extern "C" void* __cdecl sub_52c3a0(void*);

QuadVolumeBuilder* QuadVolumeBuilder::method(void* arg) {
    assign(arg);
    field34 = sub_52c3a0(field34);
    field38 = sub_52c3a0(field38);
    return this;
}
