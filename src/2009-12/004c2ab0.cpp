// from server: 11% by atomic.potato
struct Sub {
    void sub_4c29f0();
};

struct RbxCluster {
    char pad[0x1c];
    Sub field_1c;
    void sub_4c2ab0();
};

void RbxCluster::sub_4c2ab0() {
    this->field_1c.sub_4c29f0();
    this->~RbxCluster();
}
