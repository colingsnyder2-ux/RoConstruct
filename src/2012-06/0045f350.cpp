// from server: 100% by tester
struct RefItem {
    void method(void* arg);
};

extern "C" void (__fastcall *sub_77ddbc)(void*);

void RefItem::method(void* arg) {
    sub_77ddbc(&arg);
}
