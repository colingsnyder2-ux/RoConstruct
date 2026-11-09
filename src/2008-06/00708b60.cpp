// from server: 100% by tester
struct CXTSplitterWnd {
    void SetSplit(int);
    int field0;
    char pad[0x5c];
    int field60;
    int field64;
    char pad2[8];
    int field70;
    int field74;
    char pad3[0x8c];
    int field104;
};

void CXTSplitterWnd::SetSplit(int value) {
    field104 = value;
    int v = (value != 0) ? 6 : 7;
    field60 = v;
    field64 = v;
    field70 = v;
    field74 = v;
    void** vtbl = *(void***)this;
    void (__thiscall *fn)(CXTSplitterWnd*) = (void (__thiscall *)(CXTSplitterWnd*))vtbl[0x150 / 4];
    fn(this);
}
