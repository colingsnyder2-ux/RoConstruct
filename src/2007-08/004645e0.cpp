// from server: 97% by EspClaude
// from server: 47% by colin
// roc 2007-08 004645e0  unit: DxUserInput  size: 313 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004645e0
//
// 004645e0  83ec24               sub esp, 0x24
// 004645e3  56                   push esi
// 004645e4  8bf1                 mov esi, ecx
// 004645e6  8b466c               mov eax, dword ptr [esi + 0x6c]
// 004645e9  83e800               sub eax, 0
// 004645ec  7426                 je 0x464614
// 004645ee  83e801               sub eax, 1
// 004645f1  0f851b010000         jne 0x464712
// 004645f7  8b442430             mov eax, dword ptr [esp + 0x30]
// 004645fb  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004645ff  83c670               add esi, 0x70
// 00464602  56                   push esi
// 00464603  50                   push eax
// 00464604  51                   push ecx
// 00464605  e8860d0000           call 0x465390
// 0046460a  83c40c               add esp, 0xc
// 0046460d  5e                   pop esi
// 0046460e  83c424               add esp, 0x24
// 00464611  c20800               ret 8
// 00464614  e807efffff           call 0x463520
// 00464619  84c0                 test al, al
// 0046461b  745b                 je 0x464678
// 0046461d  d94660               fld dword ptr [esi + 0x60]
// 00464620  57                   push edi
// 00464621  d86658               fsub dword ptr [esi + 0x58]
// 00464624  e837c71c00           call 0x630d60
// 00464629  d94664               fld dword ptr [esi + 0x64]
// 0046462c  d8665c               fsub dword ptr [esi + 0x5c]
// 0046462f  668bf8               mov di, ax
// 00464632  e829c71c00           call 0x630d60
// 00464637  0fbfd7               movsx edx, di
// 0046463a  89542408             mov dword ptr [esp + 8], edx
// 0046463e  8b542434             mov edx, dword ptr [esp + 0x34]
// 00464642  0fbfc0               movsx eax, ax
// 00464645  db442408             fild dword ptr [esp + 8]
// 00464649  8d4c2414             lea ecx, [esp + 0x14]
// 0046464d  51                   push ecx
// 0046464e  d95c2418             fstp dword ptr [esp + 0x18]
// 00464652  8944240c             mov dword ptr [esp + 0xc], eax
// 00464656  8b442434             mov eax, dword ptr [esp + 0x34]
// 0046465a  83c670               add esi, 0x70
// 0046465d  db44240c             fild dword ptr [esp + 0xc]
// 00464661  56                   push esi
// 00464662  52                   push edx
// 00464663  50                   push eax
// 00464664  d95c2428             fstp dword ptr [esp + 0x28]
// 00464668  e8b31b0000           call 0x466220
// 0046466d  83c410               add esp, 0x10
// 00464670  5f                   pop edi
// 00464671  5e                   pop esi
// 00464672  83c424               add esp, 0x24
// 00464675  c20800               ret 8
// 00464678  e893fdffff           call 0x464410
// 0046467d  84c0                 test al, al
// 0046467f  751d                 jne 0x46469e
// 00464681  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00464685  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00464689  83c670               add esi, 0x70
// 0046468c  56                   push esi
// 0046468d  51                   push ecx
// 0046468e  52                   push edx
// 0046468f  e8cc0c0000           call 0x465360
// 00464694  83c40c               add esp, 0xc
// 00464697  5e                   pop esi
// 00464698  83c424               add esp, 0x24
// 0046469b  c20800               ret 8
// 0046469e  8bce                 mov ecx, esi
// 004646a0  e8dbedffff           call 0x463480
// 004646a5  84c0                 test al, al
// 004646a7  7438                 je 0x4646e1
// 004646a9  8d442408             lea eax, [esp + 8]
// 004646ad  50                   push eax
// 004646ae  8bce                 mov ecx, esi
// 004646b0  e83beeffff           call 0x4634f0
// 004646b5  50                   push eax
// 004646b6  8d4c241c             lea ecx, [esp + 0x1c]
// 004646ba  e801edffff           call 0x4633c0
// 004646bf  8b542430             mov edx, dword ptr [esp + 0x30]
// 004646c3  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 004646c7  8d4c2418             lea ecx, [esp + 0x18]
// 004646cb  51                   push ecx
// 004646cc  83c670               add esi, 0x70
// 004646cf  56                   push esi
// 004646d0  52                   push edx
// 004646d1  50                   push eax
// 004646d2  e8791b0000           call 0x466250
// 004646d7  83c410               add esp, 0x10
// 004646da  5e                   pop esi
// 004646db  83c424               add esp, 0x24
// 004646de  c20800               ret 8
// 004646e1  8d4c240c             lea ecx, [esp + 0xc]
// 004646e5  51                   push ecx
// 004646e6  8bce                 mov ecx, esi
// 004646e8  e803eeffff           call 0x4634f0
// 004646ed  50                   push eax
// 004646ee  8d4c2424             lea ecx, [esp + 0x24]
// 004646f2  e8c9ecffff           call 0x4633c0
// 004646f7  8b442430             mov eax, dword ptr [esp + 0x30]
// 004646fb  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 004646ff  8d542420             lea edx, [esp + 0x20]
// 00464703  52                   push edx
// 00464704  83c670               add esi, 0x70
// 00464707  56                   push esi
// 00464708  50                   push eax
// 00464709  51                   push ecx
// 0046470a  e8d11b0000           call 0x4662e0
// 0046470f  83c410               add esp, 0x10
// 00464712  5e                   pop esi
// 00464713  83c424               add esp, 0x24
// 00464716  c20800               ret 8

struct V2i16 {
    short x, y;
    V2i16(short x_, short y_) : x(x_), y(y_) {}
};
struct Vec2 {
    float x, y;
    Vec2(float x_, float y_) : x(x_), y(y_) {}
    Vec2(const V2i16& v) : x((float)v.x), y((float)v.y) {}
};
struct Vec3 { float x, y, z; };
struct Pos2 {
    float x, y;
    Pos2(const Vec3& v);          // thiscall ctor, call 0x4633c0
};
struct Target70 { int v; };

void __cdecl mouseMove(int, int, Target70*, const Vec2*);        // 0x466220
void __cdecl mouseIdle(int, int, Target70*);                     // 0x465360
void __cdecl mouseDownA(int, int, Target70*, const Pos2*);       // 0x466250
void __cdecl mouseDownB(int, int, Target70*, const Pos2*);       // 0x4662e0
void __cdecl mouseOther(int, int, Target70*);                    // 0x465390
bool __cdecl isButtonDown();                                     // 0x464410

struct DxUserInput {
    char pad[0x58];
    float x0;      // +0x58
    float y0;      // +0x5c
    float x1;      // +0x60
    float y1;      // +0x64
    int pad68;
    int mode;      // +0x6c
    Target70 target; // +0x70
    bool isCaptured();      // 0x463520
    bool isLeft();          // 0x463480
    Vec3 getCursor();       // 0x4634f0, hidden return
    void method(int a, int b);
};

void DxUserInput::method(int a, int b)
{
    switch (mode) {
    case 0:
        if (isCaptured()) {
            V2i16 di((short)(x1 - x0), (short)(y1 - y0));
            Vec2 d(di);
            mouseMove(a, b, &target, &d);
        } else if (!isButtonDown()) {
            mouseIdle(a, b, &target);
        } else if (isLeft()) {
            Pos2 p(getCursor());
            mouseDownA(a, b, &target, &p);
        } else {
            Pos2 p(getCursor());
            mouseDownB(a, b, &target, &p);
        }
        break;
    case 1:
        mouseOther(a, b, &target);
        break;
    }
}
