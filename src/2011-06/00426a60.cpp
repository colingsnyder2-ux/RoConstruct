// from server: 100% by tester
struct CSelectionTreeCtrl {
    char pad[0xd0];
    unsigned char flag;
    void getFlag(int, int* out);
};

void CSelectionTreeCtrl::getFlag(int, int* out) {
    *out = (this->flag != 0) ? 1 : 0;
}