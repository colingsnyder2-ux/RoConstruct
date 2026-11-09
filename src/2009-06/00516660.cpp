// from server: 100% by why2
struct MeshRefPartAdapter {
    char pad[12];
    float* field_c;
    void setValue(float value);
};

void MeshRefPartAdapter::setValue(float value) {
    *field_c = value;
}
