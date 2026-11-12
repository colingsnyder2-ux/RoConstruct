// from server: 100% by EspClaude
// from server: 47% by colin
// roc 2007-08 0044f110  unit: CRobloxDoc  size: 227 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044f110
//
// 0044f110  83ec08               sub esp, 8
// 0044f113  53                   push ebx
// 0044f114  56                   push esi
// 0044f115  8bd9                 mov ebx, ecx
// 0044f117  8d7364               lea esi, [ebx + 0x64]
// 0044f11a  57                   push edi
// 0044f11b  8b7e04               mov edi, dword ptr [esi + 4]
// 0044f11e  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044f121  7606                 jbe 0x44f129
// 0044f123  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044f129  55                   push ebp
// 0044f12a  8b6e08               mov ebp, dword ptr [esi + 8]
// 0044f12d  396e04               cmp dword ptr [esi + 4], ebp
// 0044f130  7606                 jbe 0x44f138
// 0044f132  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044f138  3bf6                 cmp esi, esi
// 0044f13a  7406                 je 0x44f142
// 0044f13c  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044f142  3bfd                 cmp edi, ebp
// 0044f144  742a                 je 0x44f170
// 0044f146  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044f149  7206                 jb 0x44f151
// 0044f14b  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044f151  8b0f                 mov ecx, dword ptr [edi]
// 0044f153  85c9                 test ecx, ecx
// 0044f155  7409                 je 0x44f160
// 0044f157  8b01                 mov eax, dword ptr [ecx]
// 0044f159  8b5004               mov edx, dword ptr [eax + 4]
// 0044f15c  6a01                 push 1
// 0044f15e  ffd2                 call edx
// 0044f160  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044f163  7206                 jb 0x44f16b
// 0044f165  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044f16b  83c704               add edi, 4
// 0044f16e  ebc8                 jmp 0x44f138
// 0044f170  8b6e08               mov ebp, dword ptr [esi + 8]
// 0044f173  396e04               cmp dword ptr [esi + 4], ebp
// 0044f176  7606                 jbe 0x44f17e
// 0044f178  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044f17e  8b7e04               mov edi, dword ptr [esi + 4]
// 0044f181  3b7e08               cmp edi, dword ptr [esi + 8]
// 0044f184  7606                 jbe 0x44f18c
// 0044f186  ff15d8e67700         call dword ptr [0x77e6d8]
// 0044f18c  55                   push ebp
// 0044f18d  56                   push esi
// 0044f18e  57                   push edi
// 0044f18f  56                   push esi
// 0044f190  8d442420             lea eax, [esp + 0x20]
// 0044f194  50                   push eax
// 0044f195  8bce                 mov ecx, esi
// 0044f197  e804eb1700           call 0x5cdca0
// 0044f19c  8b7374               mov esi, dword ptr [ebx + 0x74]
// 0044f19f  33ff                 xor edi, edi
// 0044f1a1  3bf7                 cmp esi, edi
// 0044f1a3  897b74               mov dword ptr [ebx + 0x74], edi
// 0044f1a6  5d                   pop ebp
// 0044f1a7  7410                 je 0x44f1b9
// 0044f1a9  8bce                 mov ecx, esi
// 0044f1ab  e840e8ffff           call 0x44d9f0
// 0044f1b0  56                   push esi
// 0044f1b1  e8ac0a1e00           call 0x62fc62
// 0044f1b6  83c404               add esp, 4
// 0044f1b9  8b4b78               mov ecx, dword ptr [ebx + 0x78]
// 0044f1bc  3bcf                 cmp ecx, edi
// 0044f1be  7413                 je 0x44f1d3
// 0044f1c0  e8ab820100           call 0x467470
// 0044f1c5  8b4378               mov eax, dword ptr [ebx + 0x78]
// 0044f1c8  8b08                 mov ecx, dword ptr [eax]
// 0044f1ca  8b5108               mov edx, dword ptr [ecx + 8]
// 0044f1cd  50                   push eax
// 0044f1ce  ffd2                 call edx
// 0044f1d0  897b78               mov dword ptr [ebx + 0x78], edi
// 0044f1d3  391d2cae8b00         cmp dword ptr [0x8bae2c], ebx
// 0044f1d9  750b                 jne 0x44f1e6
// 0044f1db  53                   push ebx
// 0044f1dc  6a01                 push 1
// 0044f1de  e80d70fbff           call 0x4061f0
// 0044f1e3  83c408               add esp, 8
// 0044f1e6  5f                   pop edi
// 0044f1e7  5e                   pop esi
// 0044f1e8  8bcb                 mov ecx, ebx
// 0044f1ea  5b                   pop ebx
// 0044f1eb  83c408               add esp, 8
// 0044f1ee  e9a50d1e00           jmp 0x62ff98

#include <vector>

class Item {
public:
    virtual void v0();
    virtual ~Item();                    // scalar deleting dtor at +4, push 1
};

// std::vector<Item*> whose range erase is the out-of-line COMDAT at 0x5cdca0
// (thiscall, iterator {cont, ptr} by value, iterator returned via hidden pointer).
class ItemVector : public std::vector<Item*> {
public:
    iterator erase(iterator first, iterator last);   // out of line (0x5cdca0)
    void clear() { erase(begin(), end()); }
};

class Session {
public:
    ~Session();                         // 0x44d9f0 (thiscall)
};

class Connector {
public:
    void disconnect();                  // 0x467470 (thiscall)
    virtual long __stdcall QueryInterface(const void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();  // +8
};

class CDocBase {
public:
    void DeleteContents();              // tail-jumped base
};

void __cdecl notifyDocument(int code, void* doc);  // 0x4061f0
extern void* g_activeDoc;                          // 0x8bae2c

class CRobloxDoc : public CDocBase {
public:
    char pad_0000[0x64];
    ItemVector items;           // +0x64 (16 bytes)
    Session* session;                   // +0x74
    Connector* connector;               // +0x78
    void DeleteContents();
};

void CRobloxDoc::DeleteContents()
{
    for (ItemVector::iterator it = items.begin(), e = items.end(); it != e; ++it)
        delete *it;
    items.clear();

    Session* s = session;
    session = 0;
    delete s;

    if (connector != 0) {
        connector->disconnect();
        connector->Release();
        connector = 0;
    }

    if (g_activeDoc == this)
        notifyDocument(1, this);

    CDocBase::DeleteContents();
}
