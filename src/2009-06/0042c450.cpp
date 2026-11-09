// from server: 100% by EspClaude
// roc 2009-06 0042c450  unit: CMultiPlayerPane  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042c450
//
// 0042c450  83ec10               sub esp, 0x10
// 0042c453  53                   push ebx
// 0042c454  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0042c458  56                   push esi
// 0042c459  57                   push edi
// 0042c45a  33ff                 xor edi, edi
// 0042c45c  57                   push edi
// 0042c45d  68ea030000           push 0x3ea
// 0042c462  53                   push ebx
// 0042c463  8d442418             lea eax, [esp + 0x18]
// 0042c467  50                   push eax
// 0042c468  6800000050           push 0x50000000
// 0042c46d  57                   push edi
// 0042c46e  57                   push edi
// 0042c46f  8bf1                 mov esi, ecx
// 0042c471  897c2428             mov dword ptr [esp + 0x28], edi
// 0042c475  897c242c             mov dword ptr [esp + 0x2c], edi
// 0042c479  897c2430             mov dword ptr [esp + 0x30], edi
// 0042c47d  897c2434             mov dword ptr [esp + 0x34], edi
// 0042c481  e81ec62e00           call 0x718aa4
// 0042c486  85c0                 test eax, eax
// 0042c488  750b                 jne 0x42c495
// 0042c48a  5f                   pop edi
// 0042c48b  5e                   pop esi
// 0042c48c  33c0                 xor eax, eax
// 0042c48e  5b                   pop ebx
// 0042c48f  83c410               add esp, 0x10
// 0042c492  c20800               ret 8
// 0042c495  e8e631feff           call 0x40f680
// 0042c49a  8bc8                 mov ecx, eax
// 0042c49c  e893cf2e00           call 0x719434
// 0042c4a1  57                   push edi
// 0042c4a2  68eb030000           push 0x3eb
// 0042c4a7  56                   push esi
// 0042c4a8  8d4c2418             lea ecx, [esp + 0x18]
// 0042c4ac  51                   push ecx
// 0042c4ad  6800000050           push 0x50000000
// 0042c4b2  894654               mov dword ptr [esi + 0x54], eax
// 0042c4b5  897c2420             mov dword ptr [esp + 0x20], edi
// 0042c4b9  897c2424             mov dword ptr [esp + 0x24], edi
// 0042c4bd  897c2428             mov dword ptr [esp + 0x28], edi
// 0042c4c1  897c242c             mov dword ptr [esp + 0x2c], edi
// 0042c4c5  8b10                 mov edx, dword ptr [eax]
// 0042c4c7  8b525c               mov edx, dword ptr [edx + 0x5c]
// 0042c4ca  57                   push edi
// 0042c4cb  57                   push edi
// 0042c4cc  8bc8                 mov ecx, eax
// 0042c4ce  ffd2                 call edx
// 0042c4d0  85c0                 test eax, eax
// 0042c4d2  74b6                 je 0x42c48a
// 0042c4d4  8b442424             mov eax, dword ptr [esp + 0x24]
// 0042c4d8  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0042c4db  53                   push ebx
// 0042c4dc  50                   push eax
// 0042c4dd  e83e45feff           call 0x410a20
// 0042c4e2  8b4e54               mov ecx, dword ptr [esi + 0x54]
// 0042c4e5  8b5120               mov edx, dword ptr [ecx + 0x20]
// 0042c4e8  57                   push edi
// 0042c4e9  57                   push edi
// 0042c4ea  6864030000           push 0x364
// 0042c4ef  52                   push edx
// 0042c4f0  ff1590ee8900         call dword ptr [0x89ee90]
// 0042c4f6  5f                   pop edi
// 0042c4f7  5e                   pop esi
// 0042c4f8  b801000000           mov eax, 1
// 0042c4fd  5b                   pop ebx
// 0042c4fe  83c410               add esp, 0x10
// 0042c501  c20800               ret 8
// copied from an identical function in another client (function ?initialize@CMultiPlayerPane@ns_ROCX000021@@QAEHPAX0@Z)

namespace ns_ROCX000021 {
struct Rect
{
    int left, top, right, bottom;
};

struct Pane;

struct PaneTable
{
    void* unused[23];
    int (__thiscall *create)(Pane*, const char*, const char*,
                            unsigned long, const Rect*, void*,
                            unsigned int, void*);
};

struct Pane
{
    PaneTable* table;
    char padding[28];
    void* window;

    void configure(void*, void*);
};

struct Manager
{
    Pane* getPane();
};

extern char* fn_ROCX000021_00411360();

extern "C" long (__stdcall *SendMessageA)(
    void*, unsigned int, unsigned int, long);

struct CMultiPlayerPane
{
    char padding[84];
    Pane* pane;

    int create(const char*, const char*, unsigned long,
               const Rect*, void*, unsigned int, void*);
    int initialize(void*, void*);
};

int CMultiPlayerPane::initialize(void* parent, void* context)
{
    Rect rect = { 0, 0, 0, 0 };

    if (!create(0, 0, 0x50000000, &rect, parent, 1002, 0))
        return 0;

    pane = reinterpret_cast<Manager*>(fn_ROCX000021_00411360())->getPane();

    rect.left = 0;
    rect.top = 0;
    rect.right = 0;
    rect.bottom = 0;

    if (!pane->table->create(pane, 0, 0, 0x50000000,
                             &rect, this, 1003, 0))
        return 0;

    pane->configure(context, parent);
    SendMessageA(pane->window, 0x364, 0, 0);
    return 1;
}
}
