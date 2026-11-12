// from server: 100% by EspClaude
// from server: 50% by colin
// roc 2007-08 004ef2e0  unit: RBX::Render::SceneManager  size: 131 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ef2e0
//
// 004ef2e0  57                   push edi
// 004ef2e1  8b7c2408             mov edi, dword ptr [esp + 8]
// 004ef2e5  3b7c240c             cmp edi, dword ptr [esp + 0xc]
// 004ef2e9  7476                 je 0x4ef361
// 004ef2eb  53                   push ebx
// 004ef2ec  55                   push ebp
// 004ef2ed  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 004ef2f1  56                   push esi
// 004ef2f2  8b5d00               mov ebx, dword ptr [ebp]
// 004ef2f5  8b07                 mov eax, dword ptr [edi]
// 004ef2f7  3bd8                 cmp ebx, eax
// 004ef2f9  745a                 je 0x4ef355
// 004ef2fb  85c0                 test eax, eax
// 004ef2fd  7446                 je 0x4ef345
// 004ef2ff  83c004               add eax, 4
// 004ef302  50                   push eax
// 004ef303  ff15e8d27700         call dword ptr [0x77d2e8]
// 004ef309  85c0                 test eax, eax
// 004ef30b  7532                 jne 0x4ef33f
// 004ef30d  8b07                 mov eax, dword ptr [edi]
// 004ef30f  8b7008               mov esi, dword ptr [eax + 8]
// 004ef312  85f6                 test esi, esi
// 004ef314  741b                 je 0x4ef331
// 004ef316  8b0e                 mov ecx, dword ptr [esi]
// 004ef318  8b11                 mov edx, dword ptr [ecx]
// 004ef31a  8b4204               mov eax, dword ptr [edx + 4]
// 004ef31d  ffd0                 call eax
// 004ef31f  8bc6                 mov eax, esi
// 004ef321  8b7604               mov esi, dword ptr [esi + 4]
// 004ef324  50                   push eax
// 004ef325  e838091400           call 0x62fc62
// 004ef32a  83c404               add esp, 4
// 004ef32d  85f6                 test esi, esi
// 004ef32f  75e5                 jne 0x4ef316
// 004ef331  8b0f                 mov ecx, dword ptr [edi]
// 004ef333  85c9                 test ecx, ecx
// 004ef335  7408                 je 0x4ef33f
// 004ef337  8b11                 mov edx, dword ptr [ecx]
// 004ef339  8b02                 mov eax, dword ptr [edx]
// 004ef33b  6a01                 push 1
// 004ef33d  ffd0                 call eax
// 004ef33f  c70700000000         mov dword ptr [edi], 0
// 004ef345  85db                 test ebx, ebx
// 004ef347  740c                 je 0x4ef355
// 004ef349  891f                 mov dword ptr [edi], ebx
// 004ef34b  83c304               add ebx, 4
// 004ef34e  53                   push ebx
// 004ef34f  ff15ecd27700         call dword ptr [0x77d2ec]
// 004ef355  83c704               add edi, 4
// 004ef358  3b7c2418             cmp edi, dword ptr [esp + 0x18]
// 004ef35c  7594                 jne 0x4ef2f2
// 004ef35e  5e                   pop esi
// 004ef35f  5d                   pop ebp
// 004ef360  5b                   pop ebx
// 004ef361  5f                   pop edi
// 004ef362  c3                   ret 

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);

struct Listener {
    virtual void unused0();
    virtual void detach();
};

struct Node {
    Listener* obj;
    Node* next;
};

struct Shared {
    virtual ~Shared();
    long refCount;
    Node* head;
};

struct Handle {
    Shared* p;
    __forceinline Handle& operator=(const Handle& o) {
        Shared* np = o.p;
        if (np != p) {
            if (p) {
                if (InterlockedDecrement(&p->refCount) == 0) {
                    Node* n = p->head;
                    while (n) {
                        n->obj->detach();
                        Node* t = n;
                        n = n->next;
                        delete t;
                    }
                    delete p;
                }
                p = 0;
            }
            if (np) {
                p = np;
                InterlockedIncrement(&np->refCount);
            }
        }
        return *this;
    }
};

void fillHandles(Handle* first, Handle* last, const Handle& val) {
    for (; first != last; ++first)
        *first = val;
}
