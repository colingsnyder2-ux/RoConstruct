// from server: 100% by colin
struct ModelInstance {
    char pad[0x1f8];
    void getWorldTransform(float* out);
    void getPrimaryPartCFrame(float* out);
};

void ModelInstance::getPrimaryPartCFrame(float* out) {
    float tmp[6];
    ((ModelInstance*)((char*)this + 0x1f8))->getWorldTransform(tmp);
    out[0] = tmp[0];
    out[1] = tmp[1];
    out[2] = tmp[2];
    out[3] = tmp[3];
    out[4] = tmp[4];
    out[5] = tmp[5];
}
