// from server: 100% by colin
// from server: 92% by colin
// roc 2008-06 004e6050  unit: RBX::ViewNew::PartChunk  size: 155 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e6050
//
// 004e6050  51                   push ecx
// 004e6051  53                   push ebx
// 004e6052  55                   push ebp
// 004e6053  8b6c2410             mov ebp, dword ptr [esp + 0x10]
// 004e6057  56                   push esi
// 004e6058  8bf1                 mov esi, ecx
// 004e605a  57                   push edi
// 004e605b  89742410             mov dword ptr [esp + 0x10], esi
// 004e605f  8bfe                 mov edi, esi
// 004e6061  2bee                 sub ebp, esi
// 004e6063  c744241804000000     mov dword ptr [esp + 0x18], 4
// 004e606b  eb03                 jmp 0x4e6070
// 004e606d  8d4900               lea ecx, [ecx]
// 004e6070  8b1c2f               mov ebx, dword ptr [edi + ebp]
// 004e6073  8b07                 mov eax, dword ptr [edi]
// 004e6075  3bd8                 cmp ebx, eax
// 004e6077  745e                 je 0x4e60d7
// 004e6079  85c0                 test eax, eax
// 004e607b  744a                 je 0x4e60c7
// 004e607d  83c004               add eax, 4
// 004e6080  50                   push eax
// 004e6081  ff15ac218000         call dword ptr [0x8021ac]
// 004e6087  85c0                 test eax, eax
// 004e6089  7532                 jne 0x4e60bd
// 004e608b  8b07                 mov eax, dword ptr [edi]
// 004e608d  8b7008               mov esi, dword ptr [eax + 8]
// 004e6090  85f6                 test esi, esi
// 004e6092  741b                 je 0x4e60af
// 004e6094  8b0e                 mov ecx, dword ptr [esi]
// 004e6096  8b11                 mov edx, dword ptr [ecx]
// 004e6098  8b4204               mov eax, dword ptr [edx + 4]
// 004e609b  ffd0                 call eax
// 004e609d  8bc6                 mov eax, esi
// 004e609f  8b7604               mov esi, dword ptr [esi + 4]
// 004e60a2  50                   push eax
// 004e60a3  e8d2a51b00           call 0x6a067a
// 004e60a8  83c404               add esp, 4
// 004e60ab  85f6                 test esi, esi
// 004e60ad  75e5                 jne 0x4e6094
// 004e60af  8b0f                 mov ecx, dword ptr [edi]
// 004e60b1  85c9                 test ecx, ecx
// 004e60b3  7408                 je 0x4e60bd
// 004e60b5  8b11                 mov edx, dword ptr [ecx]
// 004e60b7  8b02                 mov eax, dword ptr [edx]
// 004e60b9  6a01                 push 1
// 004e60bb  ffd0                 call eax
// 004e60bd  8b742410             mov esi, dword ptr [esp + 0x10]
// 004e60c1  c70700000000         mov dword ptr [edi], 0
// 004e60c7  85db                 test ebx, ebx
// 004e60c9  740c                 je 0x4e60d7
// 004e60cb  891f                 mov dword ptr [edi], ebx
// 004e60cd  83c304               add ebx, 4
// 004e60d0  53                   push ebx
// 004e60d1  ff15b0218000         call dword ptr [0x8021b0]
// 004e60d7  83c704               add edi, 4
// 004e60da  836c241801           sub dword ptr [esp + 0x18], 1
// 004e60df  758f                 jne 0x4e6070
// 004e60e1  5f                   pop edi
// 004e60e2  8bc6                 mov eax, esi
// 004e60e4  5e                   pop esi
// 004e60e5  5d                   pop ebp
// 004e60e6  5b                   pop ebx
// 004e60e7  59                   pop ecx
// 004e60e8  c20400               ret 4

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long *);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long *);
void __cdecl operator delete(void *);

struct Object {
    virtual ~Object();
    virtual void release();
};

struct Node {
    Object *object;
    Node *next;
};

struct Container {
    virtual ~Container();
    volatile long references;
    Node *head;
};

struct S {
    Container *values[4];
    S &operator=(const S &other);
};

S &S::operator=(const S &other)
{
    for (int i = 0; i < 4; ++i) {
        Container *replacement = other.values[i];
        if (replacement != values[i]) {
            if (values[i]) {
                if (InterlockedDecrement(&values[i]->references) == 0) {
                    Node *node = values[i]->head;
                    while (node) {
                        node->object->release();
                        Node *old = node;
                        node = node->next;
                        operator delete(old);
                    }
                    delete values[i];
                }
                values[i] = 0;
            }
            if (replacement) {
                values[i] = replacement;
                InterlockedIncrement(&replacement->references);
            }
        }
    }
    return *this;
}
