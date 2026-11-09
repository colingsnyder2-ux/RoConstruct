// from server: 100% by why2
struct CRobloxTreeCtrl {
    void getFlagTo(int unused, int* out) const;
};

void CRobloxTreeCtrl::getFlagTo(int unused, int* out) const {
    *out = *(const unsigned char*)((const char*)this + 0xe8) != 0;
}
