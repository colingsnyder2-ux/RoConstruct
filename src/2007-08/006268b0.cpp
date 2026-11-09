// from server: 33% by colin
// roc 2007-08 006268b0  unit: RBX::Balancing  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006268b0
//
// 006268b0  dec1                 faddp st(1)
// 006268b2  d9400c               fld dword ptr [eax + 0xc]
// 006268b5  d8ca                 fmul st(2)
// 006268b7  dec1                 faddp st(1)
// 006268b9  d95c2414             fstp dword ptr [esp + 0x14]
// 006268bd  d94020               fld dword ptr [eax + 0x20]
// 006268c0  deca                 fmulp st(2)
// 006268c2  d9401c               fld dword ptr [eax + 0x1c]
// 006268c5  decb                 fmulp st(3)
// 006268c7  d9c9                 fxch st(1)
// 006268c9  dec2                 faddp st(2)
// 006268cb  d84818               fmul dword ptr [eax + 0x18]
// 006268ce  8d442410             lea eax, [esp + 0x10]
// 006268d2  50                   push eax
// 006268d3  dec1                 faddp st(1)
// 006268d5  d95c241c             fstp dword ptr [esp + 0x1c]
// 006268d9  ffd2                 call edx
// 006268db  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 006268df  5f                   pop edi
// 006268e0  5e                   pop esi
// 006268e1  64890d00000000       mov dword ptr fs:[0], ecx
// 006268e8  83c444               add esp, 0x44
// 006268eb  c20400               ret 4

struct Balancing {
    char pad[0x0c];
    float kP;
    char pad2[0x10];
    float kD;
    float lastBalanceTorque_x;
    float lastBalanceTorque_y;
    float lastBalanceTorque_z;
    int tick;
    void onComputeForceImpl(float arg);
};

void Balancing::onComputeForceImpl(float arg)
{
    float result[4];
    result[0] = kP * arg + kD * arg;
    result[1] = lastBalanceTorque_x * arg + lastBalanceTorque_y * arg;
    result[2] = lastBalanceTorque_z * arg;
    void (__stdcall *fn)(float*) = *(void (__stdcall **)(float*))((char*)this + 0x24);
    fn(result);
}
