// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0066c5a0  unit: RBX::GroupDragTool  size: 82 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0066c5a0
//
// 0066c5a0  83ec30               sub esp, 0x30
// 0066c5a3  56                   push esi
// 0066c5a4  57                   push edi
// 0066c5a5  8b7c243c             mov edi, dword ptr [esp + 0x3c]
// 0066c5a9  8bcf                 mov ecx, edi
// 0066c5ab  e800c7f2ff           call 0x598cb0
// 0066c5b0  8bf0                 mov esi, eax
// 0066c5b2  56                   push esi
// 0066c5b3  8d4c240c             lea ecx, [esp + 0xc]
// 0066c5b7  e8646ceaff           call 0x513220
// 0066c5bc  d94624               fld dword ptr [esi + 0x24]
// 0066c5bf  d95c242c             fstp dword ptr [esp + 0x2c]
// 0066c5c3  8d442408             lea eax, [esp + 8]
// 0066c5c7  d94628               fld dword ptr [esi + 0x28]
// 0066c5ca  6a01                 push 1
// 0066c5cc  d95c2434             fstp dword ptr [esp + 0x34]
// 0066c5d0  50                   push eax
// 0066c5d1  d9462c               fld dword ptr [esi + 0x2c]
// 0066c5d4  d95c243c             fstp dword ptr [esp + 0x3c]
// 0066c5d8  e86321f7ff           call 0x5de740
// 0066c5dd  83c408               add esp, 8
// 0066c5e0  8d4c2408             lea ecx, [esp + 8]
// 0066c5e4  51                   push ecx
// 0066c5e5  8bcf                 mov ecx, edi
// 0066c5e7  e8b412f3ff           call 0x59d8a0
// 0066c5ec  5f                   pop edi
// 0066c5ed  5e                   pop esi
// 0066c5ee  83c430               add esp, 0x30
// 0066c5f1  c3                   ret 

struct Matrix3 {
    float elements[9];
    Matrix3(const Matrix3& other);
};

struct Frame {
    Matrix3 rotation;
    float x, y, z;
    Frame(const Matrix3& matrix);
};

inline Frame::Frame(const Matrix3& matrix) : rotation(matrix)
{
}

struct Object {
    const Frame* getFrame();
    void setFrame(const Frame& frame);
};

extern void __cdecl sendFrame(const Frame& frame, int flag);

void __cdecl updateFrame(Object* object)
{
    const Frame* source = object->getFrame();
    Frame frame(source->rotation);
    frame.x = source->x;
    frame.y = source->y;
    frame.z = source->z;
    sendFrame(frame, 1);
    object->setFrame(frame);
}
