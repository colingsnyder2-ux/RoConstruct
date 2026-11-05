// from server: 52% by atomic.potato
struct RBX_ArrowToolBase {
    char pad[8];
    bool field8;
    bool field9;
    bool check();
};

bool RBX_ArrowToolBase::check() {
    if (field8) return true;
    if (field9) return true;
    return false;
}
