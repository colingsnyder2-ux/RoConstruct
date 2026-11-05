// from server: 100% by colin
// roc 2007-08 00427920  unit: RobloxCrashReporter  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00427920
//
// 00427920  a1e8b88b00           mov eax, dword ptr [0x8bb8e8]
// 00427925  c3                   ret 

extern int G1_var_008bb8e8;

struct RobloxCrashReporter {
    int f();
};

int RobloxCrashReporter::f() {
    return G1_var_008bb8e8;
}
