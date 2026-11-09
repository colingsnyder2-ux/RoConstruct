// from server: 100% by tester
struct CXTPKeyboardManager {
    int field0;
    int* field4;
    int field8;
    int Find(int key);
};

int CXTPKeyboardManager::Find(int key) {
    int count = field8;
    int i = 0;
    if (count > 0) {
        do {
            if (i < 0 || i >= count) {
                goto fail;
            }
            if (key == field4[i]) {
                return i;
            }
            i++;
        } while (i < count);
    }
    return -1;
fail:
    __declspec(noreturn) void fail_func();
    fail_func();
}
