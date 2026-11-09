// from server: 100% by colin
struct CSelectionTreeCtrl {
    char pad[0xc8];
    unsigned char flag;
    void getFlag(int, int* out);
};

void CSelectionTreeCtrl::getFlag(int, int* out) {
    *out = (this->flag != 0) ? 1 : 0;
}
