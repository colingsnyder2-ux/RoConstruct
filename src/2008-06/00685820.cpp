// from server: 100% by colin
struct RbxSubEntity {
    char pad[0x138];
    float value;
    void setValue(float v);
};

void RbxSubEntity::setValue(float v) {
    value = v;
}
