#pragma once
// Proposed declaration-only overlay for RBX::Humanoid and RBX::Primitive (no layout declared).
// tests/record_native_humanoid_state.py copies this to out/humanoid-state-overlay/humanoid/Humanoid.h
// until a native Humanoid header exists; it is not a shared header.
// Signatures come from 2008-06 evidence symbols and call sites.
#include <G3D/Vector3.h>
namespace RBX {
class PartInstance;
class Primitive;
class Body;
class ModelInstance;
class Primitive {
public:
    void setFlagAB(bool value);                  // 005e75e0: stores +0xab when changed
private:
    Primitive();
};
class Humanoid {
public:
    void setJump(bool value);                    // 005dc270 ?setJump@Humanoid@RBX@@QAEX_N@Z
    void setStrafe(bool value);                  // 005dc230 (bit 4 of +0x1e8)
    PartInstance* getHead() const;               // 005d8a10
    PartInstance* getTorso() const;              // 005d8b10
    PartInstance* getLeftLeg() const;            // 005d8c10
    PartInstance* getRightLeg() const;           // 005d8d10
    PartInstance* getLeftArm() const;            // 005d8e10
    PartInstance* getRightArm() const;           // 005d8f10
    Primitive* getTorsoPrimitive() const;        // 005d90a0
    Primitive* getLeftLegPrimitive() const;      // 005d90c0
    Primitive* getRightLegPrimitive() const;     // 005d90e0
    Primitive* getHeadPrimitive() const;         // 005d9100
    Primitive* getLeftArmPrimitive() const;      // 005d9120
    Primitive* getRightArmPrimitive() const;     // 005d9140
    Body* getTorsoBody();                        // 005d9160
    Body* getRootBody();                         // 005d9180
    G3D::Vector3 getIntendedMovementVector();    // 005d9c10
    static ModelInstance* getCharacterFromHumanoid(Humanoid* humanoid); // 005d7670
private:
    Humanoid();
};
}
