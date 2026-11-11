// from server: 100% by EspClaude
// from server: 94% by EspClaude
// roc 2007-08 005e1630  unit: RBX::VMotorFeature::?$FactoryProduct  size: 317 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005e1630
//
// 005e1630  83ec18               sub esp, 0x18
// 005e1633  53                   push ebx
// 005e1634  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 005e1638  56                   push esi
// 005e1639  8b74242c             mov esi, dword ptr [esp + 0x2c]
// 005e163d  57                   push edi
// 005e163e  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005e1642  53                   push ebx
// 005e1643  56                   push esi
// 005e1644  57                   push edi
// 005e1645  e856fcffff           call 0x5e12a0
// 005e164a  8b442444             mov eax, dword ptr [esp + 0x44]
// 005e164e  50                   push eax
// 005e164f  57                   push edi
// 005e1650  e8fbfbffff           call 0x5e1250
// 005e1655  83c414               add esp, 0x14
// 005e1658  84c0                 test al, al
// 005e165a  0f8406010000         je 0x5e1766
// 005e1660  55                   push ebp
// 005e1661  8b6c2430             mov ebp, dword ptr [esp + 0x30]
// 005e1665  d94500               fld dword ptr [ebp]
// 005e1668  b801000000           mov eax, 1
// 005e166d  8405fc2a8c00         test byte ptr [0x8c2afc], al
// 005e1673  d806                 fadd dword ptr [esi]
// 005e1675  d94504               fld dword ptr [ebp + 4]
// 005e1678  d84604               fadd dword ptr [esi + 4]
// 005e167b  d94508               fld dword ptr [ebp + 8]
// 005e167e  d84608               fadd dword ptr [esi + 8]
// 005e1681  d90518cf7b00         fld dword ptr [0x7bcf18]
// 005e1687  dccb                 fmul st(3), st(0)
// 005e1689  d9cb                 fxch st(3)
// 005e168b  d95c241c             fstp dword ptr [esp + 0x1c]
// 005e168f  d9c9                 fxch st(1)
// 005e1691  d8ca                 fmul st(2)
// 005e1693  d95c2420             fstp dword ptr [esp + 0x20]
// 005e1697  dec9                 fmulp st(1)
// 005e1699  d95c2424             fstp dword ptr [esp + 0x24]
// 005e169d  7520                 jne 0x5e16bf
// 005e169f  d9e8                 fld1 
// 005e16a1  0905fc2a8c00         or dword ptr [0x8c2afc], eax
// 005e16a7  d915f02a8c00         fst dword ptr [0x8c2af0]
// 005e16ad  d905b07e7900         fld dword ptr [0x797eb0]
// 005e16b3  d91df42a8c00         fstp dword ptr [0x8c2af4]
// 005e16b9  d91df82a8c00         fstp dword ptr [0x8c2af8]
// 005e16bf  68f02a8c00           push 0x8c2af0
// 005e16c4  8d4c2420             lea ecx, [esp + 0x20]
// 005e16c8  51                   push ecx
// 005e16c9  8d542418             lea edx, [esp + 0x18]
// 005e16cd  52                   push edx
// 005e16ce  e88da8fcff           call 0x5abf60
// 005e16d3  53                   push ebx
// 005e16d4  8d442420             lea eax, [esp + 0x20]
// 005e16d8  50                   push eax
// 005e16d9  57                   push edi
// 005e16da  e8c1fbffff           call 0x5e12a0
// 005e16df  8b4c2454             mov ecx, dword ptr [esp + 0x54]
// 005e16e3  51                   push ecx
// 005e16e4  57                   push edi
// 005e16e5  e866fbffff           call 0x5e1250
// 005e16ea  d906                 fld dword ptr [esi]
// 005e16ec  d85c2430             fcomp dword ptr [esp + 0x30]
// 005e16f0  8ac8                 mov cl, al
// 005e16f2  83c420               add esp, 0x20
// 005e16f5  dfe0                 fnstsw ax
// 005e16f7  f6c444               test ah, 0x44
// 005e16fa  7a33                 jp 0x5e172f
// 005e16fc  d94604               fld dword ptr [esi + 4]
// 005e16ff  d85c2414             fcomp dword ptr [esp + 0x14]
// 005e1703  dfe0                 fnstsw ax
// 005e1705  f6c444               test ah, 0x44
// 005e1708  7a25                 jp 0x5e172f
// 005e170a  d94608               fld dword ptr [esi + 8]
// 005e170d  d85c2418             fcomp dword ptr [esp + 0x18]
// 005e1711  dfe0                 fnstsw ax
// 005e1713  f6c444               test ah, 0x44
// 005e1716  7a17                 jp 0x5e172f
// 005e1718  84c9                 test cl, cl
// 005e171a  7449                 je 0x5e1765
// 005e171c  53                   push ebx
// 005e171d  55                   push ebp
// 005e171e  57                   push edi
// 005e171f  e87cfbffff           call 0x5e12a0
// 005e1724  83c40c               add esp, 0xc
// 005e1727  5d                   pop ebp
// 005e1728  5f                   pop edi
// 005e1729  5e                   pop esi
// 005e172a  5b                   pop ebx
// 005e172b  83c418               add esp, 0x18
// 005e172e  c3                   ret 
// 005e172f  84c9                 test cl, cl
// 005e1731  741d                 je 0x5e1750
// 005e1733  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 005e1737  52                   push edx
// 005e1738  53                   push ebx
// 005e1739  8d442418             lea eax, [esp + 0x18]
// 005e173d  50                   push eax
// 005e173e  55                   push ebp
// 005e173f  57                   push edi
// 005e1740  e8ebfeffff           call 0x5e1630
// 005e1745  83c414               add esp, 0x14
// 005e1748  5d                   pop ebp
// 005e1749  5f                   pop edi
// 005e174a  5e                   pop esi
// 005e174b  5b                   pop ebx
// 005e174c  83c418               add esp, 0x18
// 005e174f  c3                   ret 
// 005e1750  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 005e1754  51                   push ecx
// 005e1755  53                   push ebx
// 005e1756  56                   push esi
// 005e1757  8d54241c             lea edx, [esp + 0x1c]
// 005e175b  52                   push edx
// 005e175c  57                   push edi
// 005e175d  e8cefeffff           call 0x5e1630
// 005e1762  83c414               add esp, 0x14
// 005e1765  5d                   pop ebp
// 005e1766  5f                   pop edi
// 005e1767  5e                   pop esi
// 005e1768  5b                   pop ebx
// 005e1769  83c418               add esp, 0x18
// 005e176c  c3                   ret 

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc 2008-06 00610580  (agentH rewrite)

struct Vector3
{
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3 operator+(const Vector3& o) const { return Vector3(x + o.x, y + o.y, z + o.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    bool operator==(const Vector3& o) const { return x == o.x && y == o.y && z == o.z; }
};

extern const float half;
extern const float scaleY;
extern Vector3 adjustment;
extern unsigned int adjustmentInitialized;

extern void __cdecl transformVector(
    Vector3* result, const Vector3* value, const Vector3* scale);
extern bool __cdecl testVector(Vector3* result, void* context);
extern Vector3* __cdecl multiplyVector(
    Vector3* result, const Vector3* value, const Vector3* scale);

void __cdecl subdivideVector(
    Vector3* result,
    const Vector3* start,
    const Vector3* end,
    const Vector3* scale,
    void* context)
{
    transformVector(result, end, scale);
    if (!testVector(result, context))
        return;

    Vector3 average = (*start + *end) * 0.51f;

    if (!(adjustmentInitialized & 1))
    {
        adjustmentInitialized |= 1;
        adjustment.x = 1.0f;
        adjustment.y = scaleY;
        adjustment.z = 1.0f;
    }

    Vector3 midpoint;
    multiplyVector(&midpoint, &average, &adjustment);

    transformVector(result, &midpoint, scale);
    bool accepted = testVector(result, context);

    if (midpoint == *end)
    {
        if (accepted)
            transformVector(result, start, scale);
    }
    else if (accepted)
    {
        subdivideVector(result, start, &midpoint, scale, context);
    }
    else
    {
        subdivideVector(result, &midpoint, end, scale, context);
    }
}
