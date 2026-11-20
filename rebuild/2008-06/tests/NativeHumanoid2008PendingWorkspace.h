#pragma once
// Declaration-only overlay for RBX::Workspace (copied to out/native-layouts/humanoid2008-pending/v8datamodel/Workspace.h
// by tests/record_native_humanoid2008.py for the NATIVE_HUMANOID2008_PENDING build); not a shared header. The donor
// Workspace.h does not compile against the 2008 reflection.h (&sWorkspace, C2440). Signatures from the donor;
// addresses from the Humanoid unit call sites (hasWalkToPoint 005d79b0).
namespace RBX {
class Instance;
class Workspace {
public:
    static Workspace* findWorkspace(const Instance* context);       // 005a3380
    static bool contextInWorkspace(const Instance* context);        // 005a33d0
private:
    Workspace();
};
}
