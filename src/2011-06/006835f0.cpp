// from server: 100% by colin

// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance { public: virtual ~Instance(); char pad[0x40]; Instance* next; };
class ServiceProvider : public Instance { public: ServiceProvider* finish(); };
}
RBX::ServiceProvider* func_006835f0(RBX::Instance* p) {
    while (p) {
        if (RBX::ServiceProvider* q = dynamic_cast<RBX::ServiceProvider*>(p)) return q->finish();
        p = p->next;
    }
    return 0;
}
