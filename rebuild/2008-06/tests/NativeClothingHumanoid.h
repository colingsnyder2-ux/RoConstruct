#pragma once
// Declaration-only overlay for RBX::Humanoid used by the inactive Clothing unit (no layout declared).
// tests/record_native_clothing.py copies it to out/clothing-overlay/humanoid/Humanoid.h until a native
// Humanoid header exists; it is not a shared header. Signatures from 2008-06 evidence symbols/call sites.
namespace RBX {
class Instance;
class PartInstance;
class Humanoid {
public:
    PartInstance* getHead() const;               // 005d8a10
    PartInstance* getTorso() const;              // 005d8b10
    PartInstance* getLeftLeg() const;            // 005d8c10
    PartInstance* getRightLeg() const;           // 005d8d10
    PartInstance* getLeftArm() const;            // 005d8e10
    PartInstance* getRightArm() const;           // 005d8f10
    static Humanoid* modelIsCharacter(const Instance* testModel); // 005d9a20
private:
    Humanoid();
};
}
