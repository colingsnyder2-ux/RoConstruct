// roc 2012-06 00925b80  unit: RBX::SleepStage  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00925b80
//
// 00925b80  56                   push esi
// 00925b81  57                   push edi
// 00925b82  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00925b86  57                   push edi
// 00925b87  8bf1                 mov esi, ecx
// 00925b89  e8c2d80300           call 0x963450
// 00925b8e  56                   push esi
// 00925b8f  8bcf                 mov ecx, edi
// 00925b91  e8ca19ffff           call 0x917560
// 00925b96  5f                   pop edi
// 00925b97  5e                   pop esi
// 00925b98  c20400               ret 4
// copied from an identical function in another client (function ?onPrimitiveAdded@JointStage@ns_ROCX00000e@@QAEXPAX@Z)

namespace ns_ROCX00000e {
struct IWorldStage {
    void onPrimitiveAdded(void* p);
};

struct JointStage : IWorldStage {
    void onPrimitiveAdded(void* p);
};

void JointStage::onPrimitiveAdded(void* p)
{
    IWorldStage::onPrimitiveAdded(p);
    ((IWorldStage*)p)->onPrimitiveAdded(this);
}
}
