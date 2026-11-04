#pragma once
// Declaration-only overlay for RBX::Workspace (copied to out/native-body-movers-pending/v8datamodel/Workspace.h by
// tests/record_native_body_movers.py); not a shared header. The donor Workspace.h does not compile against the
// 2008 reflection.h (&sWorkspace, C2440). Signatures from the donor; addresses from the BodyMover unit call sites.
namespace RBX {
class Instance;
class World;
class Workspace {
public:
    static Workspace* findWorkspace(const Instance* context);       // 005a3380 (Rocket::fire 0062e1c0)
    static World* getWorldIfInWorkspace(const Instance* context);  // 005a3390 (BodyMover::onAncestorChanged 006308f0)
private:
    Workspace();
};
}
