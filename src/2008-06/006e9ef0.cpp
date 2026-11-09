// from server: 100% by colin
struct CXTPControlColorSelector {
    int GetItem(int, int);
    void SetSelectedItem(int);
    void SetSelectedItem(int, int);
};

void CXTPControlColorSelector::SetSelectedItem(int a, int b) {
    int r = GetItem(a, b);
    if (r != -1) {
        SetSelectedItem(r);
    }
}
