// from server: 100% by colin
// roc 2007-03 005cfcb0  unit: seg_005c0000  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005cfcb0
//
// 005cfcb0  8b442404             mov eax, dword ptr [esp + 4]
// 005cfcb4  d981d0010000         fld dword ptr [ecx + 0x1d0]
// 005cfcba  d918                 fstp dword ptr [eax]
// 005cfcbc  d981d4010000         fld dword ptr [ecx + 0x1d4]
// 005cfcc2  d95804               fstp dword ptr [eax + 4]
// 005cfcc5  d981d8010000         fld dword ptr [ecx + 0x1d8]
// 005cfccb  d95808               fstp dword ptr [eax + 8]
// 005cfcce  c20400               ret 4
// copied from an identical function in another client (function ?getVector@CSHA1@@QBE?AUVector3@@XZ)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Vector3 {
    float x, y, z;
};

struct CSHA1 {
    char padding[0x1d0];
    float x, y, z;
    Vector3 getVector() const;
};

Vector3 CSHA1::getVector() const {
    Vector3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}