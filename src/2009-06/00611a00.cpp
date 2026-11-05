// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005846d0  unit: G3D::VCoordinateFrame::?$TypedPropertyDescriptor  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005846d0
//
// 005846d0  8b442408             mov eax, dword ptr [esp + 8]
// 005846d4  83ec60               sub esp, 0x60
// 005846d7  56                   push esi
// 005846d8  57                   push edi
// 005846d9  8bf9                 mov edi, ecx
// 005846db  50                   push eax
// 005846dc  8d4c240c             lea ecx, [esp + 0xc]
// 005846e0  51                   push ecx
// 005846e1  8bcf                 mov ecx, edi
// 005846e3  e84884f2ff           call 0x4acb30
// 005846e8  8b54246c             mov edx, dword ptr [esp + 0x6c]
// 005846ec  8bf0                 mov esi, eax
// 005846ee  52                   push edx
// 005846ef  8d44243c             lea eax, [esp + 0x3c]
// 005846f3  50                   push eax
// 005846f4  8bcf                 mov ecx, edi
// 005846f6  e83584f2ff           call 0x4acb30
// 005846fb  d94624               fld dword ptr [esi + 0x24]
// 005846fe  8bc8                 mov ecx, eax
// 00584700  d85924               fcomp dword ptr [ecx + 0x24]
// 00584703  dfe0                 fnstsw ax
// 00584705  f6c444               test ah, 0x44
// 00584708  7a2e                 jp 0x584738
// 0058470a  d94628               fld dword ptr [esi + 0x28]
// 0058470d  d85928               fcomp dword ptr [ecx + 0x28]
// 00584710  dfe0                 fnstsw ax
// 00584712  f6c444               test ah, 0x44
// 00584715  7a21                 jp 0x584738
// 00584717  d9462c               fld dword ptr [esi + 0x2c]
// 0058471a  d8592c               fcomp dword ptr [ecx + 0x2c]
// 0058471d  dfe0                 fnstsw ax
// 0058471f  f6c444               test ah, 0x44
// 00584722  7a14                 jp 0x584738
// 00584724  56                   push esi
// 00584725  e856ebf8ff           call 0x513280
// 0058472a  84c0                 test al, al
// 0058472c  740a                 je 0x584738
// 0058472e  5f                   pop edi
// 0058472f  b001                 mov al, 1
// 00584731  5e                   pop esi
// 00584732  83c460               add esp, 0x60
// 00584735  c20800               ret 8
// 00584738  5f                   pop edi
// 00584739  32c0                 xor al, al
// 0058473b  5e                   pop esi
// 0058473c  83c460               add esp, 0x60
// 0058473f  c20800               ret 8

struct Frame
{
    float matrix[9];
    float x, y, z;
    bool equalMatrix(const Frame &other) const;
};

struct S
{
    int f(int destination, int object);
    bool compare(int left, int right);
};

#pragma float_control(precise, off)

bool S::compare(int left, int right)
{
    Frame rightStorage;
    Frame leftStorage;
    const Frame *r = (const Frame *)f((int)&rightStorage, right);
    const Frame *l = (const Frame *)f((int)&leftStorage, left);

    if (l->x == r->x &&
        l->y == r->y &&
        l->z == r->z &&
        l->equalMatrix(*r))
        return true;
    return false;
}
