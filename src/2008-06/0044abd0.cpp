// from server: 100% by king_originala
#include <exception>
// from server: 100% by king_originala
// roc 2008-06 0044abd0  unit: CIDEDocManager  size: 95 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044abd0
//
// 0044abd0  55                   push ebp
// 0044abd1  8bec                 mov ebp, esp
// 0044abd3  6aff                 push -1
// 0044abd5  6890117c00           push 0x7c1190
// 0044abda  64a100000000         mov eax, dword ptr fs:[0]
// 0044abe0  50                   push eax
// 0044abe1  64892500000000       mov dword ptr fs:[0], esp
// 0044abe8  83ec0c               sub esp, 0xc
// 0044abeb  53                   push ebx
// 0044abec  56                   push esi
// 0044abed  8bf1                 mov esi, ecx
// 0044abef  8b0df4dc9600         mov ecx, dword ptr [0x96dcf4]
// 0044abf5  57                   push edi
// 0044abf6  8965f0               mov dword ptr [ebp - 0x10], esp
// 0044abf9  c705f4dc960000000000 mov dword ptr [0x96dcf4], 0
// 0044ac03  85c9                 test ecx, ecx
// 0044ac05  7408                 je 0x44ac0f
// 0044ac07  8b01                 mov eax, dword ptr [ecx]
// 0044ac09  8b10                 mov edx, dword ptr [eax]
// 0044ac0b  6a01                 push 1
// 0044ac0d  ffd2                 call edx
// 0044ac0f  8b4e24               mov ecx, dword ptr [esi + 0x24]
// 0044ac12  8b01                 mov eax, dword ptr [ecx]
// 0044ac14  8b9088000000         mov edx, dword ptr [eax + 0x88]
// 0044ac1a  6a01                 push 1
// 0044ac1c  6a00                 push 0
// 0044ac1e  ffd2                 call edx
// 0044ac20  8945ec               mov dword ptr [ebp - 0x14], eax
// 0044ac23  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0044ac2a  e801ffffff           call 0x44ab30

struct Object {
    virtual ~Object();
};

extern Object* activeObject;

typedef Object* (__thiscall *OpenFunction)(void*, const char*, int);

struct DocumentTable {
    void* reserved[33];
    void (__thiscall *close)(void*);
    OpenFunction open;
};

struct DocumentSource {
    DocumentTable* table;
};

extern void fail();
extern void __cdecl logException(std::exception*);
int __stdcall messageBox(unsigned int, unsigned int, unsigned int);

struct Manager {
    char reserved[36];
    DocumentSource* source;
    void run();
};

void Manager::run()
{
    Object* old = activeObject;
    activeObject = 0;
    if (old)
        delete old;

    Object* document = source->table->open(source, 0, 1);
    try {
        fail();
    }
    catch (std::exception& exception) {
        logException(&exception);
        messageBox(0xF104, 0, static_cast<unsigned int>(-1));
        if (document) {
            DocumentSource* opened = reinterpret_cast<DocumentSource*>(document);
            opened->table->close(opened);
        }
    }
}
