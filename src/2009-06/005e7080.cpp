// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0056f5a0  unit: G3D::VColor3::?$TypedPropertyDescriptor  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0056f5a0
//
// 0056f5a0  83ec0c               sub esp, 0xc
// 0056f5a3  56                   push esi
// 0056f5a4  8d442404             lea eax, [esp + 4]
// 0056f5a8  8bf1                 mov esi, ecx
// 0056f5aa  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0056f5ae  50                   push eax
// 0056f5af  51                   push ecx
// 0056f5b0  e89bf70400           call 0x5bed50
// 0056f5b5  83c408               add esp, 8
// 0056f5b8  84c0                 test al, al
// 0056f5ba  741d                 je 0x56f5d9
// 0056f5bc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056f5bf  8b11                 mov edx, dword ptr [ecx]
// 0056f5c1  8b520c               mov edx, dword ptr [edx + 0xc]
// 0056f5c4  8d442404             lea eax, [esp + 4]
// 0056f5c8  50                   push eax
// 0056f5c9  8b442418             mov eax, dword ptr [esp + 0x18]
// 0056f5cd  50                   push eax
// 0056f5ce  ffd2                 call edx
// 0056f5d0  b001                 mov al, 1
// 0056f5d2  5e                   pop esi
// 0056f5d3  83c40c               add esp, 0xc
// 0056f5d6  c20800               ret 8
// 0056f5d9  32c0                 xor al, al
// 0056f5db  5e                   pop esi
// 0056f5dc  83c40c               add esp, 0xc
// 0056f5df  c20800               ret 8

struct Color {
    float x, y, z;
};

extern "C" bool __cdecl convertColor(void*, Color*);

struct Sink;

struct SinkTable {
    void* reserved[3];
    void (__thiscall *set)(Sink*, void*, const Color*);
};

struct Sink {
    SinkTable* table;
};

struct S {
    char reserved[24];
    Sink* sink;
    bool f(void* object, void* value);
};

bool S::f(void* object, void* value)
{
    Color color;
    if (convertColor(value, &color)) {
        sink->table->set(sink, object, &color);
        return true;
    }
    return false;
}
