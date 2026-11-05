// from server: 27% by atomic.potato
struct RBX_FaceEdgeConnector {
    char pad0[0x68];
    void* field_68;
    char pad6c[0x10];
    void* field_7c;
    char pad80[0x10];
    void* field_90;
    char pad94[0x18];
    void* field_ac;
    void destroy();
    RBX_FaceEdgeConnector* scalar_deleting_dtor(char flags);
};

void RBX_FaceEdgeConnector::destroy() {
}

RBX_FaceEdgeConnector* RBX_FaceEdgeConnector::scalar_deleting_dtor(char flags) {
    this->field_ac = (void*)0xa20c08;
    this->field_90 = (void*)0xa20c08;
    this->field_7c = (void*)0xa20a34;
    this->field_68 = (void*)0xa20a34;
    if (flags & 1) {
        this->destroy();
    }
    return this;
}
