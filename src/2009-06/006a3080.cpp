// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct VehicleSeat {
    char pad[0x30c];
    int value;
    void update();
    int get();
};
int VehicleSeat::get() {
    update();
    return value;
}
