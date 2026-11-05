// from server: 100% by Intel
struct Workspace {
    int getOffset();
};

int Workspace::getOffset() {
    return reinterpret_cast<int>(this) - 0x150;
}
