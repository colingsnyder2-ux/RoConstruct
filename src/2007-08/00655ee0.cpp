// from server: 100% by colin
struct Sub {
    char pad[0x20];
    int field_20;
};

struct Target {
    char pad[0x94];
    int field_94;
};

struct CXTPReportControl {
    char pad[0xac];
    Sub* field_ac;
    char pad2[0x200 - 0xac - 4];
    Target* field_200;
    void func();
};

extern "C" int __fastcall sub_47b540(int);

void CXTPReportControl::func()
{
    CXTPReportControl* self = this;
    Sub* s = self->field_ac;
    int arg = s->field_20;
    Target* t = self->field_200;
    t->field_94 = sub_47b540(arg);
}
