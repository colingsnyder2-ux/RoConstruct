// from server: 100% by tester
struct CXTTreeBase {
    int Get(int index);
};

int CXTTreeBase::Get(int index) {
    if ((unsigned)index > 0x3e)
        return index;
    int v = *(int*)((char*)this + index * 4 + 0x264);
    if (v == -1)
        return *(int*)((char*)this + index * 4 + 0x168);
    return v;
}
