// from server: 100% by colin
extern "C" __declspec(dllimport) void* __stdcall GetFocus();

struct CXTPCustomizeSheet_CCustomizeEdit {
    void sub_673CA0(void*);
    void sub_6C71D0(void*);
    void func(void*);
};

void CXTPCustomizeSheet_CCustomizeEdit::func(void* arg) {
    if (arg == 0) {
        void* p = *(void**)((char*)this + 0x168);
        if (p != 0) {
            void* focus = *(void**)((char*)p + 0x20);
            if (GetFocus() == focus) {
                sub_673CA0(arg);
            }
        }
    }
    sub_6C71D0(arg);
}
