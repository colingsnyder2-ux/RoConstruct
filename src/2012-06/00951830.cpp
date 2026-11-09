// from server: 100% by tajop
struct Iter {
    char* ptr;
    Iter(char* p) : ptr(p) {}
};

struct AdvRotateTool {
    char pad0[4];
    char* begin;
    char* end;
    void insert(char* pos, int count, char* val);

    Iter FactoryProduct(char* pos, char* val);
};

Iter AdvRotateTool::FactoryProduct(char* pos, char* val) {
    char* first = this->begin;
    int n = (int)((this->end - first) / 40);
    int idx;
    if (n == 0) {
        idx = 0;
    } else {
        idx = (int)((pos - first) / 40);
    }
    insert(pos, 1, val);
    return Iter(this->begin + idx * 40);
}
