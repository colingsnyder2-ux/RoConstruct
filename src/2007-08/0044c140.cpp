// from server: 87% by EspClaude
// from server: 51% by colin
// roc 2007-08 0044c140  unit: CRobloxControlColorSelector  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c140
//
// 0044c140  83ec14               sub esp, 0x14
// 0044c143  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0044c147  85c0                 test eax, eax
// 0044c149  53                   push ebx
// 0044c14a  55                   push ebp
// 0044c14b  56                   push esi
// 0044c14c  57                   push edi
// 0044c14d  8bd9                 mov ebx, ecx
// 0044c14f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0044c157  0f8490000000         je 0x44c1ed
// 0044c15d  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0044c161  85ff                 test edi, edi
// 0044c163  0f8484000000         je 0x44c1ed
// 0044c169  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0044c16d  85ed                 test ebp, ebp
// 0044c16f  747c                 je 0x44c1ed
// 0044c171  8b08                 mov ecx, dword ptr [eax]
// 0044c173  8b5004               mov edx, dword ptr [eax + 4]
// 0044c176  83ec08               sub esp, 8
// 0044c179  8bc4                 mov eax, esp
// 0044c17b  8908                 mov dword ptr [eax], ecx
// 0044c17d  8bcb                 mov ecx, ebx
// 0044c17f  89642434             mov dword ptr [esp + 0x34], esp
// 0044c183  895004               mov dword ptr [eax + 4], edx
// 0044c186  e845faffff           call 0x44bbd0
// 0044c18b  8bf0                 mov esi, eax
// 0044c18d  83feff               cmp esi, -1
// 0044c190  745b                 je 0x44c1ed
// 0044c192  56                   push esi
// 0044c193  b9b8be8b00           mov ecx, 0x8bbeb8
// 0044c198  e8c3f8ffff           call 0x44ba60
// 0044c19d  8b4004               mov eax, dword ptr [eax + 4]
// 0044c1a0  56                   push esi
// 0044c1a1  8d4c2418             lea ecx, [esp + 0x18]
// 0044c1a5  51                   push ecx
// 0044c1a6  8bcb                 mov ecx, ebx
// 0044c1a8  894500               mov dword ptr [ebp], eax
// 0044c1ab  e8d0f9ffff           call 0x44bb80
// 0044c1b0  8b10                 mov edx, dword ptr [eax]
// 0044c1b2  8917                 mov dword ptr [edi], edx
// 0044c1b4  8b4804               mov ecx, dword ptr [eax + 4]
// 0044c1b7  894f04               mov dword ptr [edi + 4], ecx
// 0044c1ba  8b5008               mov edx, dword ptr [eax + 8]
// 0044c1bd  895708               mov dword ptr [edi + 8], edx
// 0044c1c0  8b400c               mov eax, dword ptr [eax + 0xc]
// 0044c1c3  56                   push esi
// 0044c1c4  b9b8be8b00           mov ecx, 0x8bbeb8
// 0044c1c9  89470c               mov dword ptr [edi + 0xc], eax
// 0044c1cc  e88ff8ffff           call 0x44ba60
// 0044c1d1  8b742428             mov esi, dword ptr [esp + 0x28]
// 0044c1d5  83c008               add eax, 8
// 0044c1d8  50                   push eax
// 0044c1d9  8bce                 mov ecx, esi
// 0044c1db  ff1574dd7700         call dword ptr [0x77dd74]
// 0044c1e1  8bc6                 mov eax, esi
// 0044c1e3  5f                   pop edi
// 0044c1e4  5e                   pop esi
// 0044c1e5  5d                   pop ebp
// 0044c1e6  5b                   pop ebx
// 0044c1e7  83c414               add esp, 0x14
// 0044c1ea  c21000               ret 0x10
// 0044c1ed  8b742428             mov esi, dword ptr [esp + 0x28]
// 0044c1f1  6854597800           push 0x785954
// 0044c1f6  8bce                 mov ecx, esi
// 0044c1f8  ff15b8dd7700         call dword ptr [0x77ddb8]
// 0044c1fe  5f                   pop edi
// 0044c1ff  8bc6                 mov eax, esi
// 0044c201  5e                   pop esi
// 0044c202  5d                   pop ebp
// 0044c203  5b                   pop ebx
// 0044c204  83c414               add esp, 0x14
// 0044c207  c21000               ret 0x10

// MFC CString imports (thiscall through IAT): copy ctor and const char* ctor.
class CStr {
public:
    __declspec(dllimport) CStr(const CStr& src);
    __declspec(dllimport) CStr(const char* s);
    __declspec(dllimport) ~CStr();
private:
    void* m_p;
};

struct ColorKey {                             // 8 bytes passed by value, copied via sub esp,8
    int lo; int hi;
    ColorKey(const ColorKey& o) { int l = o.lo; int h = o.hi; lo = l; hi = h; }
};
struct Color4 { int v[4]; };                   // 16 bytes returned by value

struct ColorEntry {
    int field0;
    int value;      // +4
    CStr name;      // +8
};

struct ColorTable {
    ColorEntry* get(int index);
};
extern ColorTable g_colorTable;

class CRobloxControlColorSelector {
public:
    int findIndex(ColorKey key);
    Color4 colorAt(int index);
    CStr lookup(const ColorKey* key, Color4* color, int* value);
};

CStr CRobloxControlColorSelector::lookup(const ColorKey* key, Color4* color, int* value)
{
    if (key && color && value) {
        int index = findIndex(*key);
        if (index != -1) {
            *value = g_colorTable.get(index)->value;
            *color = colorAt(index);
            return CStr(g_colorTable.get(index)->name);
        }
    }
    return CStr("");
}
