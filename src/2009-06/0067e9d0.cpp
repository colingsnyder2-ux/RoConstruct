// from server: 93% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e9520  unit: RBX::PhysicsService  size: 46 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e9520
//
// 005e9520  56                   push esi
// 005e9521  8bb188000000         mov esi, dword ptr [ecx + 0x88]
// 005e9527  8b06                 mov eax, dword ptr [esi]
// 005e9529  8b5004               mov edx, dword ptr [eax + 4]
// 005e952c  8bce                 mov ecx, esi
// 005e952e  ffd2                 call edx
// 005e9530  83f802               cmp eax, 2
// 005e9533  7411                 je 0x5e9546
// 005e9535  8b7608               mov esi, dword ptr [esi + 8]
// 005e9538  8b06                 mov eax, dword ptr [esi]
// 005e953a  8b5004               mov edx, dword ptr [eax + 4]
// 005e953d  8bce                 mov ecx, esi
// 005e953f  ffd2                 call edx
// 005e9541  83f802               cmp eax, 2
// 005e9544  75ef                 jne 0x5e9535
// 005e9546  8bce                 mov ecx, esi
// 005e9548  5e                   pop esi
// 005e9549  e982350600           jmp 0x64cad0

struct Node {
    virtual void slot0();
    virtual int type();
    unsigned int reserved;
    Node* next;
    void finish();
};

struct PhysicsService {
    unsigned char reserved[0x88];
    Node* node;
    void finish();
};

void PhysicsService::finish()
{
    Node* current = node;
    while (current->type() != 2)
        current = current->next;
    current->finish();
}
