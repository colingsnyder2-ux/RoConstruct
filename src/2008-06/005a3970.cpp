// from server: 100% by colin
// roc 2008-06 005a3970  unit: RBX::Workspace  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005a3970

namespace RBX {
class Instance { public: virtual ~Instance(); char pad[0x100]; Instance* next; };
class ServiceProvider : public Instance { public: ServiceProvider* finish(); };
}

RBX::ServiceProvider* func_005a32e0(RBX::Instance* p);

struct Workspace {
    char pad0[0x3f8];
    bool flag3f8;
    void method(bool);
};

void Workspace::method(bool b) {
    RBX::ServiceProvider* sp = func_005a32e0((RBX::Instance*)this);
    if (!sp) return;
    RBX::Instance* inst = *(RBX::Instance**)((char*)sp + 0x130);
    if (!inst) return;
    if (b) {
        void** vt = *(void***)inst;
        ((void (__thiscall*)(RBX::Instance*))vt[4])(inst);
        void** vt2 = *(void***)inst;
        ((void (__thiscall*)(RBX::Instance*, int))vt2[2])(inst, 1);
    } else {
        if (this->flag3f8) return;
        void** vt = *(void***)inst;
        ((void (__thiscall*)(RBX::Instance*, int))vt[2])(inst, 0);
    }
}
