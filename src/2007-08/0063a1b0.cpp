// from server: 100% by colin
struct CRobloxControlColorSelector {
    char pad[0x90];
    int field_90;
    char pad2[0xdc - 0x94];
    char field_dc[0xfc - 0xdc];
    void* field_fc;
    char pad3[0x148 - 0x100];
    int field_148;
    void func();
};

extern "C" char (__thiscall *sub_77dcd0)(void*);
extern "C" void (__thiscall *sub_77dd6c)(void*, const char*);
extern char sub_785954;

void CRobloxControlColorSelector::func()
{
    if (field_90 == 0) {
        if (sub_77dcd0(field_dc) != 0) {
            if (field_148 == -1) {
                return;
            }
        }
    }
    field_90 = 0;
    sub_77dd6c(field_dc, &sub_785954);
    field_148 = -1;
    void* p = field_fc;
    void** vt = *(void***)p;
    void (__thiscall *fn)(void*) = (void (__thiscall *)(void*))vt[0x17c / 4];
    fn(p);
}
