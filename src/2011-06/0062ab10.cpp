// from server: 93% by atomic.potato
// roc 2007-03 0062ab10  unit: seg_00620000  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0062ab10

extern "C" int __cdecl sub_7f90e0(int, const char*, const char*, int, int, int, int);

extern char byte_ccc3ae;
extern const char aThreadRef_cpp[];
extern const char aWeakThreadRefA[];

struct ScriptContext {
    char pad0[8];
    int field_8;
    int field_c;
    char pad10[4];
    int field_14;
    void addToNode();
};

void ScriptContext::addToNode() {
    int n = this->field_14;
    if (n == 0)
        return;
    if (byte_ccc3ae != 0) {
        sub_7f90e0(2, aThreadRef_cpp, aWeakThreadRefA, 0x47, n, 0, 0);
    }
    int m = this->field_14;
    int v = *(int*)(m + 4);
    if (v != 0) {
        this->field_c = v;
        *(int*)(v + 8) = (int)this;
        int p = this->field_14;
        this->field_8 = 0;
        *(int*)(p + 4) = (int)this;
        return;
    }
    int p = this->field_14;
    this->field_c = 0;
    this->field_8 = 0;
    *(int*)(p + 4) = (int)this;
}
