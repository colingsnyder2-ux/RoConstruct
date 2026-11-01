// from server: 100% by tester
struct CXTPControlSelector {
    int unknown0;
    void* unknown4;
    int unknown8;
    int unknownC;
    void SetValue(int nValue);
};

void CXTPControlSelector::SetValue(int nValue) {
    if (unknown4 != 0 && nValue != -1) {
        int result = (*(int (__thiscall**)(void*, int))(*(int*)unknown4 + 0x38))(unknown4, nValue);
        if (unknownC == -1) {
            unknownC = result;
        }
    }
}
