// from server: 55% by Intel
struct GeoPairConnector {
    int field_C;
    int field_10;
    bool (__thiscall *vftable_20)(float);

    bool __thiscall sub_894670(float arg);
};

extern "C" void __stdcall sub_7BB0F0(int);

bool __thiscall GeoPairConnector::sub_894670(float arg) {
    int esi_field_C = this->field_C;
    sub_7BB0F0(esi_field_C);
    int esi_field_10 = this->field_10;
    sub_7BB0F0(esi_field_10);

    bool result = (this->vftable_20)(arg);
    if (result)
        return false;

    sub_7BB0F0(this->field_C);
    sub_7BB0F0(this->field_10);

    float negated = -arg;
    return (this->vftable_20)(negated);
}
