// from server: 92% by atomic.potato
struct FaceEdgeConnector {
    char pad0[0x68];
    int field68;
    char pad1[0x7c - 0x6c];
    int field7c;
    char pad2[0x90 - 0x80];
    int field90;
    char pad3[0xac - 0x94];
    int fieldac;
    void sub_7c7750();
    FaceEdgeConnector* destroy(char flag);
};

FaceEdgeConnector* FaceEdgeConnector::destroy(char flag) {
    fieldac = 0xa7fbbc;
    field90 = 0xa7fbbc;
    field7c = 0xa7fbc4;
    field68 = 0xa7fbc4;
    if (flag & 1) {
        sub_7c7750();
    }
    return this;
}
