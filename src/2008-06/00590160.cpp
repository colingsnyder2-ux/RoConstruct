// from server: 100% by tester
struct RootInstance {
    char pad[0x2b0];
    bool flag;
    void setInsertPoint(int value);
};

extern "C" void __stdcall sub_531040(int value);

void RootInstance::setInsertPoint(int value) {
    sub_531040(value);
    flag = true;
}
