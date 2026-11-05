// from server: 100% by tester
namespace RBX {
class Instance { public: virtual ~Instance(); char pad[0x100]; Instance* next; };
class ServiceProvider : public Instance { public: ServiceProvider* finish(); };
}

RBX::ServiceProvider* func_005a32e0(RBX::Instance* p);

struct Workspace {
    char pad0[0x224];
    bool flag3f8;
    void method(bool);
};

void Workspace::method(bool b) {
    RBX::ServiceProvider* sp = func_005a32e0((RBX::Instance*)this);
    if (!sp) return;
    RBX::Instance* inst = *(RBX::Instance**)((char*)sp + 0x8c);
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
