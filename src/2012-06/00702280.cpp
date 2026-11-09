// from server: 100% by atomic.potato
struct ChangeHistoryService {
    char pad0[0x94];
    unsigned int count;
    char pad1[0x98 - 0x94 - 4 + 1];
    char pad2[0xa1 - 0x98 - 1];
    char enabled;
    void method_7020d0(const char*);
    void method_701be0();
    void func();
};

void ChangeHistoryService::func() {
    if (enabled != 0) {
        method_7020d0((const char*)0xb9e300);
        while (count > 1) {
            method_701be0();
        }
    }
}
