// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2008-06 005fb160  unit: RBX::Kernel  size: 60 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fb160
//
// 005fb160  53                   push ebx
// 005fb161  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005fb165  55                   push ebp
// 005fb166  56                   push esi
// 005fb167  57                   push edi
// 005fb168  8bf9                 mov edi, ecx
// 005fb16a  8b7710               mov esi, dword ptr [edi + 0x10]
// 005fb16d  8b6e28               mov ebp, dword ptr [esi + 0x28]
// 005fb170  83c624               add esi, 0x24
// 005fb173  8bcb                 mov ecx, ebx
// 005fb175  895c2414             mov dword ptr [esp + 0x14], ebx
// 005fb179  e892f4ffff           call 0x5fa610
// 005fb17e  8928                 mov dword ptr [eax], ebp
// 005fb180  8d442414             lea eax, [esp + 0x14]
// 005fb184  50                   push eax
// 005fb185  8bce                 mov ecx, esi
// 005fb187  e8c4f9ffff           call 0x5fab50
// 005fb18c  8b4f10               mov ecx, dword ptr [edi + 0x10]
// 005fb18f  53                   push ebx
// 005fb190  e85bfeffff           call 0x5faff0
// 005fb195  5f                   pop edi
// 005fb196  5e                   pop esi
// 005fb197  5d                   pop ebp
// 005fb198  5b                   pop ebx
// 005fb199  c20400               ret 4

template<class T> class Array {
public:
    T* data;
    int num;
    int numAllocated;
    int size() const { return num; }
    void append(const T& value);
};

class Body {
public:
    int& index();
};

class Kernel;

class KernelData {
public:
    char pad[0x24];
    Array<Body*> bodies;
    void onBodyAdded(Body* b);
};

class Kernel {
public:
    char pad[0x10];
    KernelData* data;
    void insertBody(Body* b);
};

void Kernel::insertBody(Body* b)
{
    Array<Body*>& bodies = data->bodies;
    int n = bodies.size();
    Body* body = b;
    b->index() = n;
    bodies.append(body);
    data->onBodyAdded(b);
}
