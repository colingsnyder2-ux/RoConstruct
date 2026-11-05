// from server: 55% by atomic.potato
// roc 2009-12 007a9640  unit: RBX::CloneTool  size: 130 bytes

extern "C" void* __cdecl operator_new(unsigned int size);

struct Name {
    void* vtable0;
    void* vtable1;
    char pad[0x14];
    void* field1c;
    void* field20;
    void init(void* arg);
};

struct CloneTool {
    char pad[0x18];
    void* field18;
    Name* makeName();
};

Name* CloneTool::makeName() {
    Name* p = (Name*)operator_new(0x24);
    if (p) {
        p->init(this->field18);
        p->vtable0 = (void*)0x9ed6bc;
        p->vtable1 = (void*)0x9ed6a0;
        p->field1c = 0;
        p->field20 = 0;
        return p;
    }
    return 0;
}
