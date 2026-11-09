// from server: 100% by atomic.potato
struct TwoDManager {
    char pad0[8];
    char field8;
    char field9;
    char pad10[10];
    char field14;
    void unknownCall();
    void func(char a, int b, int c);
};

void TwoDManager::func(char a, int b, int c) {
    if (field14 == 0)
        return;
    if (field9 != 0)
        return;
    if (a != field8)
        return;
    unknownCall();
    field14 = 0;
}
