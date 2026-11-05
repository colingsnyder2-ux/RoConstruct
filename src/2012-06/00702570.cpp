// from server: 77% by Intel
struct ChangeHistoryService {
    char pad0[0xA1];
    char enabled;
    char pad1[3];
    char pad2[0xC];
    void method_7022c0();
    void method_701730();
    void method_972e20();
    void func(char);
};

void ChangeHistoryService::func(char arg) {
    if (arg != enabled) {
        enabled = arg;
        if (arg) {
            method_7022c0();
        } else {
            method_701730();
            method_972e20();
            method_972e20();
            method_972e20();
        }
    }
}
