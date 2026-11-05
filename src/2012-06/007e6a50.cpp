// roc 2012-06 007e6a50  unit: CXTPReportControl  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007e6a50
//
// 007e6a50  8b442404             mov eax, dword ptr [esp + 4]
// 007e6a54  d981d0010000         fld dword ptr [ecx + 0x1d0]
// 007e6a5a  d918                 fstp dword ptr [eax]
// 007e6a5c  d981d4010000         fld dword ptr [ecx + 0x1d4]
// 007e6a62  d95804               fstp dword ptr [eax + 4]
// 007e6a65  d981d8010000         fld dword ptr [ecx + 0x1d8]
// 007e6a6b  d95808               fstp dword ptr [eax + 8]
// 007e6a6e  c20400               ret 4
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