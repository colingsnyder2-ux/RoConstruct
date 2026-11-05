// from server: 66% by Intel
extern "C" char G1_00b2263c;

struct seg_00ac0000 {
    void func_00ac2a30();
};

void seg_00ac0000::func_00ac2a30() {
    char* ptr = &G1_00b2263c + 0x25ff044d;
    (*ptr)--;
    if ((*ptr & 0xFF) == 0x26) {
        // No operation, fall through
    }
    // dl is set to 0 but unused; no effect on behavior
}
