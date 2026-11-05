// from server: 12% by atomic.potato
struct ShadowCaster {
    float getExtrusionDistance(const void* light) const;
};

struct RbxSubEntity {
    char pad[0x10];
    float x;
    char pad2[0xc];
    float y;
    char pad3[0xc];
    float z;
    float getExtrusionDistance(const void* light) const;
};

float RbxSubEntity::getExtrusionDistance(const void* light) const {
    float v[3];
    v[0] = this->x;
    v[1] = this->y;
    v[2] = this->z;
    return ((const ShadowCaster*)this)->getExtrusionDistance(light);
}
