// from server: 100% by tester
struct CRenderSettingsItem {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};

bool equals(const CRenderSettingsItem* self, int other) {
    return self->field_c == other;
}
