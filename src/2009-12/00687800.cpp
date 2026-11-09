// from server: 100% by atomic.potato
struct ChangeHistoryService {
    char pad0[0xb8];
    unsigned int count;
    char pad1[0xcd - 0xb8 - 4];
    unsigned char flag;
    void method_687140();
    void method_6874a0(const char*);
    void func();
};

void ChangeHistoryService::func() {
    if (flag != 0) {
        method_6874a0((const char*)0x9d08c4);
        while (count > 1) {
            method_687140();
        }
    }
}
