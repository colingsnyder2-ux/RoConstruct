// from server: 100% by atomic.potato
struct ChangeHistoryService {
    char pad0[0xa4];
    unsigned int count;
    char pad1[0xb1 - 0xa8];
    unsigned char flag;
    int sub_611860();
    int sub_611a80(const char*);
    void func();
};

void ChangeHistoryService::func() {
    if (flag != 0) {
        sub_611a80((const char*)0xa93cec);
        while (count > 1) {
            sub_611860();
        }
    }
}
