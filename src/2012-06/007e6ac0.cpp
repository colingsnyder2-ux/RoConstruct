// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 005034b0  unit: Ogre::RbxMeshPartAdapter  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005034b0
//
// 005034b0  8b442404             mov eax, dword ptr [esp + 4]
// 005034b4  d98188000000         fld dword ptr [ecx + 0x88]
// 005034ba  d918                 fstp dword ptr [eax]
// 005034bc  d9818c000000         fld dword ptr [ecx + 0x8c]
// 005034c2  d95804               fstp dword ptr [eax + 4]
// 005034c5  d98190000000         fld dword ptr [ecx + 0x90]
// 005034cb  d95808               fstp dword ptr [eax + 8]
// 005034ce  c20400               ret 4

struct Vector3 {
    float x, y, z;
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct OgreRbxMeshPartAdapter {
    char pad[0x1c4];
    float value88;
    float value8c;
    float value90;

    Vector3 func() const;
};

Vector3 OgreRbxMeshPartAdapter::func() const {
    return Vector3(value88, value8c, value90);
}
