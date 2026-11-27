// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Desc { bool isA(const void*) const; };
const void* classDescriptor();
struct Obj { char pad[0x14]; Desc* d; };
struct CSettingsPropGrid {
    bool sub_460400(int, Obj*);
    void sub_4a6020(int a, Obj* b);
};
void CSettingsPropGrid::sub_4a6020(int a, Obj* b) {
    if (b->d->isA(classDescriptor())) {
        sub_460400(a, b);
    }
}
