// from server: 100% by why2
struct TwoDManager {
    char pad[0x10];
    int field10;
    int field14;
    int get(int arg);
};

int TwoDManager::get(int arg) {
    int result = field10;
    if (arg == result) {
        result = field14;
    }
    return result;
}
