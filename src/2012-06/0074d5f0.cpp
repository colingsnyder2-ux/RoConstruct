// from server: 60% by Intel
struct SizeEnforcedLRUCache {
    int field_8;
    int field_C;
    int field_38;
    void func1(int a1, int a2, int a3);
    void func2(int a1);
};

void SizeEnforcedLRUCache::func1(int a1, int a2, int a3) {
    int v4 = a3;
    int v5 = a1;
    int v6 = a2;
    func2(v4);
    func2(v5);
    func2(v6);
    if (field_C > field_38) {
        int v7 = field_8;
        int v8 = *(int*)(v7 + 4);
        func2(v8 + 8);
    }
}
