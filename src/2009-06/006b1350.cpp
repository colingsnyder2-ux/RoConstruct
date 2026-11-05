// from server: 100% by EspClaude
// from server: 78% by EspClaude
// roc 2009-06 006b1350  unit: RBX::BallBallContact  size: 512 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b1350
//
// 006b1350  6aff                 push -1
// 006b1352  6890038700           push 0x870390
// 006b1357  64a100000000         mov eax, dword ptr fs:[0]
// 006b135d  50                   push eax
// 006b135e  64892500000000       mov dword ptr fs:[0], esp
// 006b1365  83ec50               sub esp, 0x50
// 006b1368  53                   push ebx
// 006b1369  55                   push ebp
// 006b136a  56                   push esi
// 006b136b  57                   push edi
// 006b136c  33ff                 xor edi, edi
// 006b136e  8bd9                 mov ebx, ecx
// 006b1370  897c2418             mov dword ptr [esp + 0x18], edi
// 006b1374  897c241c             mov dword ptr [esp + 0x1c], edi
// 006b1378  897c2414             mov dword ptr [esp + 0x14], edi
// 006b137c  8b742470             mov esi, dword ptr [esp + 0x70]
// 006b1380  8d4604               lea eax, [esi + 4]
// 006b1383  50                   push eax
// 006b1384  8d4c2424             lea ecx, [esp + 0x24]
// 006b1388  57                   push edi
// 006b1389  51                   push ecx
// 006b138a  897c2474             mov dword ptr [esp + 0x74], edi
// 006b138e  e85dae0200           call 0x6dc1f0
// 006b1393  d94618               fld dword ptr [esi + 0x18]
// 006b1396  d94614               fld dword ptr [esi + 0x14]
// 006b1399  83c40c               add esp, 0xc
// 006b139c  d94610               fld dword ptr [esi + 0x10]
// 006b139f  dcc8                 fmul st(0), st(0)
// 006b13a1  d9c1                 fld st(1)
// 006b13a3  deca                 fmulp st(2)
// 006b13a5  dec1                 faddp st(1)
// 006b13a7  d9c1                 fld st(1)
// 006b13a9  deca                 fmulp st(2)
// 006b13ab  dec1                 faddp st(1)
// 006b13ad  d9fa                 fsqrt 
// 006b13af  d9542470             fst dword ptr [esp + 0x70]
// 006b13b3  d90528a18c00         fld dword ptr [0x8ca128]
// 006b13b9  d9542410             fst dword ptr [esp + 0x10]
// 006b13bd  ded9                 fcompp 
// 006b13bf  dfe0                 fnstsw ax
// 006b13c1  f6c441               test ah, 0x41
// 006b13c4  8d442470             lea eax, [esp + 0x70]
// 006b13c8  7404                 je 0x6b13ce
// 006b13ca  8d442410             lea eax, [esp + 0x10]
// 006b13ce  d900                 fld dword ptr [eax]
// 006b13d0  8d542444             lea edx, [esp + 0x44]
// 006b13d4  52                   push edx
// 006b13d5  d95c2474             fstp dword ptr [esp + 0x74]
// 006b13d9  8bce                 mov ecx, esi
// 006b13db  e870c3feff           call 0x69d750
// 006b13e0  8bac2484000000       mov ebp, dword ptr [esp + 0x84]
// 006b13e7  8b74247c             mov esi, dword ptr [esp + 0x7c]
// 006b13eb  c644246801           mov byte ptr [esp + 0x68], 1
// 006b13f0  57                   push edi
// 006b13f1  57                   push edi
// 006b13f2  8d4c241c             lea ecx, [esp + 0x1c]
// 006b13f6  e885a5f7ff           call 0x62b980
// 006b13fb  8d442414             lea eax, [esp + 0x14]
// 006b13ff  50                   push eax
// 006b1400  8d4c2424             lea ecx, [esp + 0x24]
// 006b1404  51                   push ecx
// 006b1405  8b0b                 mov ecx, dword ptr [ebx]
// 006b1407  e844b60200           call 0x6dca50
// 006b140c  d9442470             fld dword ptr [esp + 0x70]
// 006b1410  8b942480000000       mov edx, dword ptr [esp + 0x80]
// 006b1417  8b442478             mov eax, dword ptr [esp + 0x78]
// 006b141b  55                   push ebp
// 006b141c  52                   push edx
// 006b141d  51                   push ecx
// 006b141e  8b8c2480000000       mov ecx, dword ptr [esp + 0x80]
// 006b1425  d91c24               fstp dword ptr [esp]
// 006b1428  56                   push esi
// 006b1429  50                   push eax
// 006b142a  51                   push ecx
// 006b142b  8d54245c             lea edx, [esp + 0x5c]
// 006b142f  52                   push edx
// 006b1430  8d442430             lea eax, [esp + 0x30]
// 006b1434  50                   push eax
// 006b1435  8bcb                 mov ecx, ebx
// 006b1437  e834faffff           call 0x6b0e70
// 006b143c  8bf8                 mov edi, eax
// 006b143e  85ff                 test edi, edi
// 006b1440  0f84b2000000         je 0x6b14f8
// 006b1446  8d4c2420             lea ecx, [esp + 0x20]
// 006b144a  51                   push ecx
// 006b144b  8d542430             lea edx, [esp + 0x30]
// 006b144f  6a00                 push 0
// 006b1451  52                   push edx
// 006b1452  e83910ddff           call 0x482490
// 006b1457  d9442438             fld dword ptr [esp + 0x38]
// 006b145b  d905ec8f8b00         fld dword ptr [0x8b8fec]
// 006b1461  83c40c               add esp, 0xc
// 006b1464  dce9                 fsub st(1), st(0)
// 006b1466  d9c9                 fxch st(1)
// 006b1468  d81e                 fcomp dword ptr [esi]
// 006b146a  dfe0                 fnstsw ax
// 006b146c  f6c441               test ah, 0x41
// 006b146f  0f8a81000000         jp 0x6b14f6
// 006b1475  d9442430             fld dword ptr [esp + 0x30]
// 006b1479  d8e1                 fsub st(1)
// 006b147b  d85e04               fcomp dword ptr [esi + 4]
// 006b147e  dfe0                 fnstsw ax
// 006b1480  f6c441               test ah, 0x41
// 006b1483  7a71                 jp 0x6b14f6
// 006b1485  d9442434             fld dword ptr [esp + 0x34]
// 006b1489  d8e1                 fsub st(1)
// 006b148b  d85e08               fcomp dword ptr [esi + 8]
// 006b148e  dfe0                 fnstsw ax
// 006b1490  f6c441               test ah, 0x41
// 006b1493  7a61                 jp 0x6b14f6
// 006b1495  d9442438             fld dword ptr [esp + 0x38]
// 006b1499  d8c1                 fadd st(1)
// 006b149b  d81e                 fcomp dword ptr [esi]
// 006b149d  dfe0                 fnstsw ax
// 006b149f  f6c401               test ah, 1
// 006b14a2  7552                 jne 0x6b14f6
// 006b14a4  d944243c             fld dword ptr [esp + 0x3c]
// 006b14a8  d8c1                 fadd st(1)
// 006b14aa  d85e04               fcomp dword ptr [esi + 4]
// 006b14ad  dfe0                 fnstsw ax
// 006b14af  f6c401               test ah, 1
// 006b14b2  7542                 jne 0x6b14f6
// 006b14b4  d8442440             fadd dword ptr [esp + 0x40]
// 006b14b8  d85e08               fcomp dword ptr [esi + 8]
// 006b14bb  dfe0                 fnstsw ax
// 006b14bd  f6c401               test ah, 1
// 006b14c0  7536                 jne 0x6b14f8
// 006b14c2  8b542414             mov edx, dword ptr [esp + 0x14]
// 006b14c6  52                   push edx
// 006b14c7  c74424481cb78c00     mov dword ptr [esp + 0x48], 0x8cb71c
// 006b14cf  c744246cffffffff     mov dword ptr [esp + 0x6c], 0xffffffff
// 006b14d7  e8b49debff           call 0x56b290
// 006b14dc  83c404               add esp, 4
// 006b14df  8bc7                 mov eax, edi
// 006b14e1  5f                   pop edi
// 006b14e2  5e                   pop esi
// 006b14e3  5d                   pop ebp
// 006b14e4  5b                   pop ebx
// 006b14e5  8b4c2450             mov ecx, dword ptr [esp + 0x50]
// 006b14e9  64890d00000000       mov dword ptr fs:[0], ecx
// 006b14f0  83c45c               add esp, 0x5c
// 006b14f3  c21800               ret 0x18
// 006b14f6  ddd8                 fstp st(0)
// 006b14f8  d9442470             fld dword ptr [esp + 0x70]
// 006b14fc  51                   push ecx
// 006b14fd  d91c24               fstp dword ptr [esp]
// 006b1500  8d442448             lea eax, [esp + 0x48]
// 006b1504  50                   push eax
// 006b1505  8d4c2428             lea ecx, [esp + 0x28]
// 006b1509  51                   push ecx
// 006b150a  8b0b                 mov ecx, dword ptr [ebx]
// 006b150c  e8dfb00200           call 0x6dc5f0
// 006b1511  84c0                 test al, al
// 006b1513  7407                 je 0x6b151c
// 006b1515  33ff                 xor edi, edi
// 006b1517  e9d4feffff           jmp 0x6b13f0
// 006b151c  8b442414             mov eax, dword ptr [esp + 0x14]
// 006b1520  50                   push eax
// 006b1521  c74424481cb78c00     mov dword ptr [esp + 0x48], 0x8cb71c
// 006b1529  c744246cffffffff     mov dword ptr [esp + 0x6c], 0xffffffff
// 006b1531  e85a9debff           call 0x56b290
// 006b1536  8b4c2464             mov ecx, dword ptr [esp + 0x64]
// 006b153a  83c404               add esp, 4
// 006b153d  5f                   pop edi
// 006b153e  5e                   pop esi
// 006b153f  5d                   pop ebp
// 006b1540  33c0                 xor eax, eax
// 006b1542  5b                   pop ebx
// 006b1543  64890d00000000       mov dword ptr fs:[0], ecx
// 006b154a  83c45c               add esp, 0x5c
// 006b154d  c21800               ret 0x18

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <algorithm>
#include <math.h>

extern void alignedFree(void*);

namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    float magnitude() const { return sqrtf(x * x + y * y + z * z); }
};
class Vector3int32 { public: int x, y, z; Vector3int32() {} Vector3int32(const Vector3int32& v) : x(v.x), y(v.y), z(v.z) {} };
template <class T>
class Array {
public:
    T* data;
    int num;
    int numAllocated;
    Array() { num = 0; numAllocated = 0; data = 0; }
    ~Array() { alignedFree(data); }
    void resize(int n, bool shrinkIfNecessary);
};
class Ray {
public:
    virtual void dummy();
    Vector3 origin;
    Vector3 direction;
    Ray unit() const;
    ~Ray() {}
};
}
using namespace G3D;

namespace RBX {
class Primitive;
class HitTestFilter;
struct Extents {
    Vector3 low, high;
    Extents() {}
    Extents(const Extents& e) : low(e.low), high(e.high) {}
    bool fuzzyContains(const Vector3& point, float slop) const
    {
        return low.x - slop <= point.x && low.y - slop <= point.y && low.z - slop <= point.z && point.x <= high.x + slop &&
               point.y <= high.y + slop && point.z <= slop + high.z;
    }
};
class SpatialHash {
public:
    static Vector3int32 realToHashGrid(int level, const Vector3& v);
    static Extents hashGridToRealExtents(int level, const Vector3int32& v);
    void getPrimitivesInGrid(const Vector3int32& grid, Array<Primitive*>& found);
    bool getNextGrid(Vector3int32& grid, const Ray& ray, float maxDistance);
};
class ContactManager {
    SpatialHash* spatialHash;
public:
    Primitive* getSlowHit(const Array<Primitive*>& found, const Ray& unitRay, const Array<const Primitive*>* ignore,
                          const HitTestFilter* filter, Vector3& hitPoint, float maxDistance, bool& hitSurface, bool& blocked) const;
    Primitive* getFastHit(const Ray& ray, const Array<const Primitive*>* ignore, const HitTestFilter* filter,
                          Vector3& hitPoint, bool& hitSurface, bool& blocked) const;
};

Primitive* ContactManager::getFastHit(const Ray& ray, const Array<const Primitive*>* ignore, const HitTestFilter* filter,
                                      Vector3& hitPoint, bool& hitSurface, bool& blocked) const
{
    Array<Primitive*> found;

    Vector3int32 grid = SpatialHash::realToHashGrid(0, ray.origin);

    float length = ray.direction.magnitude();
    float maxDistance = std::min(5000.0f, length);

    Ray unitRay = ray.unit();

    do {
        found.resize(0, false);
        spatialHash->getPrimitivesInGrid(grid, found);

        Primitive* hit = getSlowHit(found, unitRay, ignore, filter, hitPoint, maxDistance, hitSurface, blocked);

        if (hit != 0) {
            Extents extents = SpatialHash::hashGridToRealExtents(0, grid);

            if (extents.fuzzyContains(hitPoint, 0.001f)) {
                return hit;
            }
        }
    } while (spatialHash->getNextGrid(grid, unitRay, maxDistance));

    return 0;
}
}
