// from server: 78% by atomic.potato
struct RbxEntity {
    float x;
    float y;
    float z;
    float w;
    float v;
    float u;
    int flag;
    int zero;
    void __cdecl set(const float* src);
};

void RbxEntity::set(const float* src) {
    this->zero = 0;
    this->flag = 1;
    this->x = src[0];
    this->y = src[1];
    this->z = src[2];
    this->w = src[3];
    this->v = src[4];
    this->u = src[5];
}
