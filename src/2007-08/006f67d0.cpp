// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Parent {
    void* GetDlgItem(int) const;
};

struct VCEdit {
    char pad[0xa0];
    Parent* field_a0;
    void method(int, int, int);
};

extern "C" void* __fastcall sub_006f5e80(void*);
extern "C" void __fastcall sub_0063023e(void*);

void VCEdit::method(int a, int b, int c)
{
    if (a == 0x28 || a == 0x26) {
        Parent* p = field_a0;
        if (p != 0) {
            void* q = p->GetDlgItem(0x65);
            void* r = sub_006f5e80(q);
            if (r != 0) {
                Parent* s = field_a0;
                void** vt = *(void***)s;
                void (__thiscall *fn)(void*, void*) = (void (__thiscall *)(void*, void*))vt[0xd0 / 4];
                fn(s, r);
            }
        }
    }
    sub_0063023e(this);
}
