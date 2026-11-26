// from server: 100% by Xemicl
// roc 2012-06 0081d980  unit: RBX::Reflection::UTuple::$$A6A?AV?$shared_ptr::V?$function::?$sp_counted_impl_p  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0081d980
//
// 0081d980  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0081d984  8d442404             lea eax, [esp + 4]
// 0081d988  50                   push eax
// 0081d989  e822550c00           call 0x8e2eb0
// 0081d98e  c3                   ret 
// copied from an identical function in another client (function ?sub_6A3110@ns_ROCX000009@@YAPAXPAXPAUCMap@1@@Z)

namespace ns_ROCX000009 {
struct CMap {
    void* GetValueAt(void* key);
};

void* __cdecl sub_6A3110(void* key, CMap* map) {
    return map->GetValueAt(&key);
}
}
