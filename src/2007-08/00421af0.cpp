// from server: 41% by colin
struct CSelectionTreeCtrl {
    char pad[0x30];
    void* field30;
    char pad2[4];
    void* field38;
    void func421af0(int);
};

extern "C" void __stdcall sub_725750(void*);
extern "C" void __stdcall sub_725770(void*);
extern "C" void __stdcall sub_421640(void*, void*, int);

void CSelectionTreeCtrl::func421af0(int arg) {
    void* p = (char*)field30 + 0xb0;
    sub_725750(p);
    sub_421640((char*)this + 0x38, &p, arg);
    sub_725770(p);
    void* v = field30;
    void** vt = *(void***)v;
    void (__stdcall *fn)(void*) = (void (__stdcall *)(void*))vt[0x154/4];
    fn(this);
}
