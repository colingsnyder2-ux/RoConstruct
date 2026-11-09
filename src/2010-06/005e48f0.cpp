// from server: 55% by atomic.potato
namespace RBX {
class Instance { public: virtual ~Instance(); char pad[0x48]; Instance* next; };
class ServiceProvider : public Instance { public: ServiceProvider* finish(); };
}

extern float g_zoomOutThreshold;

struct CameraZoomOutCommand {
    char pad[0xc];
    RBX::Instance* instance;
    bool execute(int);
};

RBX::ServiceProvider* func_005e39f0(RBX::Instance* p);
void func_00628bc0(void*);
bool func_00652720(void*, float);

bool CameraZoomOutCommand::execute(int arg) {
    RBX::Instance* inst = this->instance;
    void* p = (void*)((char*)inst + 0x120);
    void* (*getFn)(void*) = *(void*(**)(void*))p;
    void* obj = getFn(p);
    if (func_00652720(obj, g_zoomOutThreshold)) {
        RBX::Instance* inst2 = this->instance;
        RBX::ServiceProvider* sp = func_005e39f0(inst2);
        func_00628bc0(sp);
        void* v = *(void**)((char*)&arg + 4);
        void** vt = *(void***)v;
        *(int*)((char*)&arg + 4) = 1;
        void (*fn)(void*) = (void(*)(void*))vt[0];
        fn(v);
    }
    return false;
}
