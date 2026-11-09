// from server: 100% by Intel
struct OgreRbxCluster {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int getCount();
};

int OgreRbxCluster::getCount() {
    return (this->field_18 - this->field_14) >> 3;
}
