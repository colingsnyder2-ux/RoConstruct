// from server: 59% by colin
struct Edge {
    char pad[0xc];
    void* downstream;
    void* upstream;
};

struct JointStage {
    char pad[8];
    void* vtable;
};

struct CleanStage {
    char pad[8];
    JointStage* jointStage;
    void onJointPrimitiveNulling(Edge* e, void* p);
};

void CleanStage::onJointPrimitiveNulling(Edge* e, void* p) {
    if (e->downstream) {
        if (e->upstream) {
            if (e->downstream != e->upstream) {
                JointStage* js = this->jointStage;
                void** vt = (void**)js->vtable;
                void (*fn)(JointStage*, Edge*) = (void (*)(JointStage*, Edge*))vt[3];
                fn(js, e);
            }
        }
    }
}
