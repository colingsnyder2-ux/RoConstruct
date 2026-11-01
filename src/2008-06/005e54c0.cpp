// from server: 100% by colin
struct IRenderable;

struct IRenderableBucket {
    void onAdded(IRenderable* r);
};

struct JointsService {
    char pad[0x138];
    IRenderableBucket bucket;
    void addInstance(void* inst);
};

struct Other {
    void sub_55AE20(void* inst);
};

extern "C" void* __cdecl sub_6A17C6(void* inst, int a, void* b, void* c, int d);

void JointsService::addInstance(void* inst) {
    ((Other*)this)->sub_55AE20(inst);
    void* r = sub_6A17C6(inst, 0, (void*)0x92907c, (void*)0x939f70, 0);
    if (r) {
        bucket.onAdded((IRenderable*)r);
    }
}
