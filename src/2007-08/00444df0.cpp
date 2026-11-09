// from server: 100% by colin
// roc 2007-08 00444df0  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00444df0
//
// 00444df0  a1607a8900           mov eax, dword ptr [0x897a60]
// 00444df5  c3                   ret 

extern int G;

int func_00444df0()
{
    return G;
}
