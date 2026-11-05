// roc 2012-06 00925bc0  unit: RBX::SleepStage  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00925bc0
//
// 00925bc0  56                   push esi
// 00925bc1  57                   push edi
// 00925bc2  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00925bc6  57                   push edi
// 00925bc7  8bf1                 mov esi, ecx
// 00925bc9  e882d80300           call 0x963450
// 00925bce  56                   push esi
// 00925bcf  8bcf                 mov ecx, edi
// 00925bd1  e87a17ffff           call 0x917350
// 00925bd6  5f                   pop edi
// 00925bd7  5e                   pop esi
// 00925bd8  c20400               ret 4
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
