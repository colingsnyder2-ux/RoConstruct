// from server: 100% by colin
struct CXTPKeyboardManager {
    int unknown0;
    int unknown4;
    int field8;
    int fieldC;
    int field10;
    int sub_6a37c0(int);
    int func(int);
};

int CXTPKeyboardManager::func(int arg) {
    if (field10 == 0)
        return 0;
    if (arg == 0)
        return 1;
    if (*(int*)(arg + 0x128) > 0)
        return 1;
    int r = ((CXTPKeyboardManager*)((char*)this + 8))->sub_6a37c0(arg);
    return r == -1 ? 1 : 0;
}
