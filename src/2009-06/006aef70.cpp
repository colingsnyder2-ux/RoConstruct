// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00606d10  unit: RBX::ContactConnector  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00606d10
//
// 00606d10  56                   push esi
// 00606d11  8b742408             mov esi, dword ptr [esp + 8]
// 00606d15  8b06                 mov eax, dword ptr [esi]
// 00606d17  50                   push eax
// 00606d18  e833eb0300           call 0x645850
// 00606d1d  8bc8                 mov ecx, eax
// 00606d1f  e8cc44ffff           call 0x5fb1f0
// 00606d24  8b0e                 mov ecx, dword ptr [esi]
// 00606d26  85c9                 test ecx, ecx
// 00606d28  7408                 je 0x606d32
// 00606d2a  8b11                 mov edx, dword ptr [ecx]
// 00606d2c  8b02                 mov eax, dword ptr [edx]
// 00606d2e  6a01                 push 1
// 00606d30  ffd0                 call eax
// 00606d32  c70600000000         mov dword ptr [esi], 0
// 00606d38  5e                   pop esi
// 00606d39  c20400               ret 4

struct Node {
    int field0;
    int index;
    int* f();
};

struct Object {
    virtual ~Object();
};

struct ContactConnector {
    Node* resolve(Object*);
    void release(Object**);
};

void ContactConnector::release(Object** object)
{
    resolve(*object)->f();
    if (*object)
        delete *object;
    *object = 0;
}
