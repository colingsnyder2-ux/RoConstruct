// from server: 57% by EspClaude
// from server: 40% by colin
// roc 2007-08 004e1210  unit: RBX::Render::Mesh::Level  size: 816 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004e1210
//
// 004e1210  83ec40               sub esp, 0x40
// 004e1213  53                   push ebx
// 004e1214  8b5910               mov ebx, dword ptr [ecx + 0x10]
// 004e1217  55                   push ebp
// 004e1218  56                   push esi
// 004e1219  894c2410             mov dword ptr [esp + 0x10], ecx
// 004e121d  57                   push edi
// 004e121e  83c104               add ecx, 4
// 004e1221  c1eb06               shr ebx, 6
// 004e1224  51                   push ecx
// 004e1225  8d44243c             lea eax, [esp + 0x3c]
// 004e1229  83e307               and ebx, 7
// 004e122c  50                   push eax
// 004e122d  895c242c             mov dword ptr [esp + 0x2c], ebx
// 004e1231  e87a870d00           call 0x5b99b0
// 004e1236  d9442448             fld dword ptr [esp + 0x48]
// 004e123a  d9e1                 fabs 
// 004e123c  8b6c246c             mov ebp, dword ptr [esp + 0x6c]
// 004e1240  d95c2418             fstp dword ptr [esp + 0x18]
// 004e1244  33ff                 xor edi, edi
// 004e1246  d9442418             fld dword ptr [esp + 0x18]
// 004e124a  83c408               add esp, 8
// 004e124d  3bef                 cmp ebp, edi
// 004e124f  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e1253  d944243c             fld dword ptr [esp + 0x3c]
// 004e1257  d9e1                 fabs 
// 004e1259  d95c2410             fstp dword ptr [esp + 0x10]
// 004e125d  d9442410             fld dword ptr [esp + 0x10]
// 004e1261  d95c2418             fstp dword ptr [esp + 0x18]
// 004e1265  d9442438             fld dword ptr [esp + 0x38]
// 004e1269  d9e1                 fabs 
// 004e126b  d95c2410             fstp dword ptr [esp + 0x10]
// 004e126f  d9442410             fld dword ptr [esp + 0x10]
// 004e1273  d95c2444             fstp dword ptr [esp + 0x44]
// 004e1277  d9442418             fld dword ptr [esp + 0x18]
// 004e127b  d9542448             fst dword ptr [esp + 0x48]
// 004e127f  d944241c             fld dword ptr [esp + 0x1c]
// 004e1283  d95c244c             fstp dword ptr [esp + 0x4c]
// 004e1287  7511                 jne 0x4e129a
// 004e1289  d9442444             fld dword ptr [esp + 0x44]
// 004e128d  ded9                 fcompp 
// 004e128f  dfe0                 fnstsw ax
// 004e1291  f6c405               test ah, 5
// 004e1294  7a06                 jp 0x4e129c
// 004e1296  b001                 mov al, 1
// 004e1298  eb04                 jmp 0x4e129e
// 004e129a  ddd8                 fstp st(0)
// 004e129c  32c0                 xor al, al
// 004e129e  33c9                 xor ecx, ecx
// 004e12a0  84c0                 test al, al
// 004e12a2  0f94c1               sete cl
// 004e12a5  3bef                 cmp ebp, edi
// 004e12a7  8bf1                 mov esi, ecx
// 004e12a9  753f                 jne 0x4e12ea
// 004e12ab  3bdf                 cmp ebx, edi
// 004e12ad  743b                 je 0x4e12ea
// 004e12af  d944b444             fld dword ptr [esp + esi*4 + 0x44]
// 004e12b3  83ec08               sub esp, 8
// 004e12b6  dc0d485b7900         fmul qword ptr [0x795b48]
// 004e12bc  d95c2424             fstp dword ptr [esp + 0x24]
// 004e12c0  d9442424             fld dword ptr [esp + 0x24]
// 004e12c4  dd1c24               fstp qword ptr [esp]
// 004e12c7  ff1530e97700         call dword ptr [0x77e930]
// 004e12cd  d95c2424             fstp dword ptr [esp + 0x24]
// 004e12d1  83c408               add esp, 8
// 004e12d4  d944241c             fld dword ptr [esp + 0x1c]
// 004e12d8  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e12dc  d944241c             fld dword ptr [esp + 0x1c]
// 004e12e0  db5c2410             fistp dword ptr [esp + 0x10]
// 004e12e4  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004e12e8  eb05                 jmp 0x4e12ef
// 004e12ea  bd01000000           mov ebp, 1
// 004e12ef  8d0c36               lea ecx, [esi + esi]
// 004e12f2  8d542462             lea edx, [esp + 0x62]
// 004e12f6  2bd1                 sub edx, ecx
// 004e12f8  66897c2410           mov word ptr [esp + 0x10], di
// 004e12fd  66897c2412           mov word ptr [esp + 0x12], di
// 004e1302  0fb73a               movzx edi, word ptr [edx]
// 004e1305  0fbfc7               movsx eax, di
// 004e1308  99                   cdq 
// 004e1309  f7fd                 idiv ebp
// 004e130b  c744241c01000000     mov dword ptr [esp + 0x1c], 1
// 004e1313  0fb7c0               movzx eax, ax
// 004e1316  89442460             mov dword ptr [esp + 0x60], eax
// 004e131a  663d0100             cmp ax, 1
// 004e131e  8d442460             lea eax, [esp + 0x60]
// 004e1322  7f04                 jg 0x4e1328
// 004e1324  8d44241c             lea eax, [esp + 0x1c]
// 004e1328  668b00               mov ax, word ptr [eax]
// 004e132b  d944244c             fld dword ptr [esp + 0x4c]
// 004e132f  6689440c10           mov word ptr [esp + ecx + 0x10], ax
// 004e1334  d95c2418             fstp dword ptr [esp + 0x18]
// 004e1338  8d542412             lea edx, [esp + 0x12]
// 004e133c  2bd1                 sub edx, ecx
// 004e133e  8d442438             lea eax, [esp + 0x38]
// 004e1342  50                   push eax
// 004e1343  8d4c2448             lea ecx, [esp + 0x48]
// 004e1347  66893a               mov word ptr [edx], di
// 004e134a  e8c19c0200           call 0x50b010
// 004e134f  d900                 fld dword ptr [eax]
// 004e1351  d9e0                 fchs 
// 004e1353  8d4c2430             lea ecx, [esp + 0x30]
// 004e1357  d95c2460             fstp dword ptr [esp + 0x60]
// 004e135b  51                   push ecx
// 004e135c  d94004               fld dword ptr [eax + 4]
// 004e135f  8d4c2448             lea ecx, [esp + 0x48]
// 004e1363  d9e0                 fchs 
// 004e1365  d95c2420             fstp dword ptr [esp + 0x20]
// 004e1369  d9442464             fld dword ptr [esp + 0x64]
// 004e136d  d95c243c             fstp dword ptr [esp + 0x3c]
// 004e1371  d9442420             fld dword ptr [esp + 0x20]
// 004e1375  d95c2440             fstp dword ptr [esp + 0x40]
// 004e1379  e8929c0200           call 0x50b010
// 004e137e  d9ee                 fldz 
// 004e1380  8b442464             mov eax, dword ptr [esp + 0x64]
// 004e1384  83e800               sub eax, 0
// 004e1387  d9542428             fst dword ptr [esp + 0x28]
// 004e138b  d954242c             fst dword ptr [esp + 0x2c]
// 004e138f  d954241c             fst dword ptr [esp + 0x1c]
// 004e1393  d9542420             fst dword ptr [esp + 0x20]
// 004e1397  7447                 je 0x4e13e0
// 004e1399  83e801               sub eax, 1
// 004e139c  741e                 je 0x4e13bc
// 004e139e  83e801               sub eax, 1
// 004e13a1  0f85b7000000         jne 0x4e145e
// 004e13a7  d9542428             fst dword ptr [esp + 0x28]
// 004e13ab  d954242c             fst dword ptr [esp + 0x2c]
// 004e13af  d954241c             fst dword ptr [esp + 0x1c]
// 004e13b3  d95c2420             fstp dword ptr [esp + 0x20]
// 004e13b7  e9a4000000           jmp 0x4e1460
// 004e13bc  8b442414             mov eax, dword ptr [esp + 0x14]
// 004e13c0  d95c2428             fstp dword ptr [esp + 0x28]
// 004e13c4  d9401c               fld dword ptr [eax + 0x1c]
// 004e13c7  d95c242c             fstp dword ptr [esp + 0x2c]
// 004e13cb  d94018               fld dword ptr [eax + 0x18]
// 004e13ce  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e13d2  d9401c               fld dword ptr [eax + 0x1c]
// 004e13d5  d9e0                 fchs 
// 004e13d7  d95c2420             fstp dword ptr [esp + 0x20]
// 004e13db  e980000000           jmp 0x4e1460
// 004e13e0  85db                 test ebx, ebx
// 004e13e2  7529                 jne 0x4e140d
// 004e13e4  d90550707800         fld dword ptr [0x787050]
// 004e13ea  8d04b500000000       lea eax, [esi*4]
// 004e13f1  d95c2428             fstp dword ptr [esp + 0x28]
// 004e13f5  8d542420             lea edx, [esp + 0x20]
// 004e13f9  d9059c7e7900         fld dword ptr [0x797e9c]
// 004e13ff  2bd0                 sub edx, eax
// 004e1401  d95c242c             fstp dword ptr [esp + 0x2c]
// 004e1405  d912                 fst dword ptr [edx]
// 004e1407  d95c041c             fstp dword ptr [esp + eax + 0x1c]
// 004e140b  eb53                 jmp 0x4e1460
// 004e140d  8d3cb500000000       lea edi, [esi*4]
// 004e1414  8d44242c             lea eax, [esp + 0x2c]
// 004e1418  2bc7                 sub eax, edi
// 004e141a  53                   push ebx
// 004e141b  d918                 fstp dword ptr [eax]
// 004e141d  e85ed5ffff           call 0x4de980
// 004e1422  d95c3c2c             fstp dword ptr [esp + edi + 0x2c]
// 004e1426  8d4c244c             lea ecx, [esp + 0x4c]
// 004e142a  2bcf                 sub ecx, edi
// 004e142c  d901                 fld dword ptr [ecx]
// 004e142e  8d542424             lea edx, [esp + 0x24]
// 004e1432  dcc0                 fadd st(0), st(0)
// 004e1434  2bd7                 sub edx, edi
// 004e1436  83c404               add esp, 4
// 004e1439  83fe01               cmp esi, 1
// 004e143c  d95c2460             fstp dword ptr [esp + 0x60]
// 004e1440  d9442460             fld dword ptr [esp + 0x60]
// 004e1444  d91a                 fstp dword ptr [edx]
// 004e1446  d9059c7e7900         fld dword ptr [0x797e9c]
// 004e144c  d95c3c1c             fstp dword ptr [esp + edi + 0x1c]
// 004e1450  750e                 jne 0x4e1460
// 004e1452  d944241c             fld dword ptr [esp + 0x1c]
// 004e1456  d9e0                 fchs 
// 004e1458  d95c241c             fstp dword ptr [esp + 0x1c]
// 004e145c  eb02                 jmp 0x4e1460
// 004e145e  ddd8                 fstp st(0)
// 004e1460  33ff                 xor edi, edi
// 004e1462  85ed                 test ebp, ebp
// 004e1464  0f8ecc000000         jle 0x4e1536
// 004e146a  668b5c245c           mov bx, word ptr [esp + 0x5c]
// 004e146f  8d45ff               lea eax, [ebp - 1]
// 004e1472  3bf8                 cmp edi, eax
// 004e1474  7532                 jne 0x4e14a8
// 004e1476  837c246400           cmp dword ptr [esp + 0x64], 0
// 004e147b  d944b444             fld dword ptr [esp + esi*4 + 0x44]
// 004e147f  d95c2460             fstp dword ptr [esp + 0x60]
// 004e1483  d9442460             fld dword ptr [esp + 0x60]
// 004e1487  d954b430             fst dword ptr [esp + esi*4 + 0x30]
// 004e148b  752b                 jne 0x4e14b8
// 004e148d  837c242400           cmp dword ptr [esp + 0x24], 0
// 004e1492  7424                 je 0x4e14b8
// 004e1494  d864b438             fsub dword ptr [esp + esi*4 + 0x38]
// 004e1498  dc0d48f37900         fmul qword ptr [0x79f348]
// 004e149e  d84cb41c             fmul dword ptr [esp + esi*4 + 0x1c]
// 004e14a2  d95cb41c             fstp dword ptr [esp + esi*4 + 0x1c]
// 004e14a6  eb12                 jmp 0x4e14ba
// 004e14a8  d944b438             fld dword ptr [esp + esi*4 + 0x38]
// 004e14ac  dc0540f37900         fadd qword ptr [0x79f340]
// 004e14b2  d95cb430             fstp dword ptr [esp + esi*4 + 0x30]
// 004e14b6  eb02                 jmp 0x4e14ba
// 004e14b8  ddd8                 fstp st(0)
// 004e14ba  8b442410             mov eax, dword ptr [esp + 0x10]
// 004e14be  d944241c             fld dword ptr [esp + 0x1c]
// 004e14c2  50                   push eax
// 004e14c3  56                   push esi
// 004e14c4  83ec08               sub esp, 8
// 004e14c7  8bc4                 mov eax, esp
// 004e14c9  d918                 fstp dword ptr [eax]
// 004e14cb  83ec08               sub esp, 8
// 004e14ce  d9442438             fld dword ptr [esp + 0x38]
// 004e14d2  8d542448             lea edx, [esp + 0x48]
// 004e14d6  d95804               fstp dword ptr [eax + 4]
// 004e14d9  8bc4                 mov eax, esp
// 004e14db  d9442440             fld dword ptr [esp + 0x40]
// 004e14df  83ec14               sub esp, 0x14
// 004e14e2  d918                 fstp dword ptr [eax]
// 004e14e4  8bcc                 mov ecx, esp
// 004e14e6  d9442458             fld dword ptr [esp + 0x58]
// 004e14ea  d95804               fstp dword ptr [eax + 4]
// 004e14ed  8d442464             lea eax, [esp + 0x64]
// 004e14f1  d9442444             fld dword ptr [esp + 0x44]
// 004e14f5  d95c2410             fstp dword ptr [esp + 0x10]
// 004e14f9  52                   push edx
// 004e14fa  50                   push eax
// 004e14fb  51                   push ecx
// 004e14fc  e87fecffff           call 0x4e0180
// 004e1501  d984248c000000       fld dword ptr [esp + 0x8c]
// 004e1508  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 004e150c  8bc4                 mov eax, esp
// 004e150e  d918                 fstp dword ptr [eax]
// 004e1510  66895808             mov word ptr [eax + 8], bx
// 004e1514  d9842490000000       fld dword ptr [esp + 0x90]
// 004e151b  d95804               fstp dword ptr [eax + 4]
// 004e151e  e89de8ffff           call 0x4dfdc0
// 004e1523  d944b430             fld dword ptr [esp + esi*4 + 0x30]
// 004e1527  83c701               add edi, 1
// 004e152a  3bfd                 cmp edi, ebp
// 004e152c  d95cb438             fstp dword ptr [esp + esi*4 + 0x38]
// 004e1530  0f8c39ffffff         jl 0x4e146f
// 004e1536  5f                   pop edi
// 004e1537  5e                   pop esi
// 004e1538  5d                   pop ebp
// 004e1539  5b                   pop ebx
// 004e153a  83c440               add esp, 0x40
// 004e153d  c21400               ret 0x14
//
// Body adapted from the matched 2008 sibling Builder::build (rbxgs native unit
// roc_sol_native_builder_004f3650); 2007-08 reads (surfaceTypes >> 6) & 7 (shr ebx, 6).
// G3D 6 Vector2/Vector3/Rect2D reduced to the members used (authentic inline bodies);
// Vector3::xy (0x50b010), Rect2D::xyxy (0x4e0180), mapFace (0x5b99b0),
// surfaceOffset (0x4de980) and emit (0x4dfdc0) are out-of-line calls in the target.
// The float->int step is a bare fld/fistp (G3D iRound/lrintf); /QIfist gives that
// without inline asm.
// roc-flags: /O2 /GS- /EHsc /MD /QIfist

extern "C" __declspec(dllimport) double __cdecl fabs(double);
extern "C" __declspec(dllimport) double __cdecl ceil(double);

namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}
    float& operator[](int i) { return ((float*)this)[i]; }
    const float& operator[](int i) const { return ((float*)this)[i]; }
    Vector2 operator-() const { return Vector2(-x, -y); }
};
class Vector3 {
public:
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ) {}
    float& operator[](int i) { return ((float*)this)[i]; }
    const float& operator[](int i) const { return ((float*)this)[i]; }
    Vector2 xy() const;
};
class Rect2D {
public:
    Vector2 min, max;
    static Rect2D xyxy(const Vector2& v0, const Vector2& v1);
};
inline int iRound(float f) { return (int)f; }
}

namespace MeshTypes {
typedef G3D::Vector2 Vector2;
typedef G3D::Vector3 Vector3;
struct Vector2int16 {
    short x, y;
    Vector2int16() : x(0), y(0) {}
    short& operator[](int i) { return (&x)[i]; }
    const short& operator[](int i) const { return (&x)[i]; }
};
typedef G3D::Rect2D Rect2D;
template<class T> const T& maximum(const T& a, const T& b) { return a < b ? b : a; }
}

namespace RBX { namespace View {
using MeshTypes::Vector2; using MeshTypes::Vector3; using MeshTypes::Vector2int16; using MeshTypes::Rect2D;
struct Function { Vector2 perturbation; bool bulge[2]; };
Vector3 __cdecl mapFace(const Vector3&);
float __cdecl surfaceOffset(int);
static __forceinline bool useFirstAxis(int purpose, const Vector3& size) { if (purpose == 0 && size.x < size.y) return true; return false; }
static __forceinline Vector3 absoluteSize(const Vector3& v) { Vector3 mapped = mapFace(v); float z = (float)fabs(mapped.z); float y = (float)fabs(mapped.y); float x = (float)fabs(mapped.x); return Vector3(x, y, z); }
struct Builder {
    enum Purpose { Surface, Decal, Shadow };
    virtual void build(Purpose); virtual void buildTop(Purpose) = 0; virtual void buildBottom(Purpose) = 0; virtual void buildLeft(Purpose) = 0; virtual void buildRight(Purpose) = 0; virtual void buildFront(Purpose) = 0; virtual void buildBack(Purpose) = 0;
    const Vector3 halfSize; unsigned surfaceTypes; void* level; Vector2 textureScale;
    void build(Function, Vector2int16, int);
    void emit(Function, Rect2D, float, Vector2, Vector2, int, Vector2int16);
};
void Builder::build(Function function, Vector2int16 grid, int purpose)
{
    int surface = (surfaceTypes >> 6) & 7;
    Vector3 size = absoluteSize(halfSize);
    int axis = !useFirstAxis(purpose, size);
    int steps = (purpose == 0 && surface) ? G3D::iRound((float)ceil((double)(size[axis] * 0.5f))) : 1;
    Vector2int16 divisions;
    short n = grid[1 - axis];
    divisions[axis] = MeshTypes::maximum<short>(1, (short)(n / steps));
    divisions[1 - axis] = n;
    float depth = size.z;
    Vector2 begin = -size.xy();
    Vector2 end = size.xy();
    Vector2 origin, extent;
    switch (purpose) {
    case 0:
        if (!surface) { origin = Vector2(0.25f, 0.5f); extent[1 - axis] = 0; extent[axis] = 0; }
        else { origin[1 - axis] = 0; origin[axis] = surfaceOffset(surface); extent[1 - axis] = size[1 - axis] * 2.0f; extent[axis] = 0.5f; if (axis == 1) extent.x = -extent.x; }
        break;
    case 1: origin.x = 0; origin.y = textureScale.y; extent.x = textureScale.x; extent.y = -textureScale.y; break;
    case 2: origin = Vector2(0, 0); extent = Vector2(0, 0); break;
    }
    for (int i = 0; i < steps; ++i) {
        if (i == steps - 1) { end[axis] = size[axis]; if (purpose == 0 && surface) extent[axis] = (end[axis] - begin[axis]) * 0.25 * extent[axis]; }
        else end[axis] = begin[axis] + 4.0f;
        emit(function, Rect2D::xyxy(begin, end), depth, origin, extent, axis, divisions);
        begin[axis] = end[axis];
    }
}
}}
