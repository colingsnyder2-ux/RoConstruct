// from server: 86% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d2320  unit: RBX::P8SpawnLocation::?$GetSetImpl  size: 72 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d2320
//
// 005d2320  56                   push esi
// 005d2321  8bf1                 mov esi, ecx
// 005d2323  8b8e44010000         mov ecx, dword ptr [esi + 0x144]
// 005d2329  8b01                 mov eax, dword ptr [ecx]
// 005d232b  8909                 mov dword ptr [ecx], ecx
// 005d232d  8b8e44010000         mov ecx, dword ptr [esi + 0x144]
// 005d2333  894904               mov dword ptr [ecx + 4], ecx
// 005d2336  c7864801000000000000 mov dword ptr [esi + 0x148], 0
// 005d2340  3b8644010000         cmp eax, dword ptr [esi + 0x144]
// 005d2346  741e                 je 0x5d2366
// 005d2348  57                   push edi
// 005d2349  8da42400000000       lea esp, [esp]
// 005d2350  8b38                 mov edi, dword ptr [eax]
// 005d2352  50                   push eax
// 005d2353  e822e30c00           call 0x6a067a
// 005d2358  83c404               add esp, 4
// 005d235b  8bc7                 mov eax, edi
// 005d235d  3bbe44010000         cmp edi, dword ptr [esi + 0x144]
// 005d2363  75eb                 jne 0x5d2350
// 005d2365  5f                   pop edi
// 005d2366  5e                   pop esi
// 005d2367  c3                   ret 

struct Node {
    Node* next;
    Node* prev;
};

extern "C" void __cdecl release_node(void*);

struct S {
    char padding[0x144];
    Node* head;
    unsigned int count;

    void clear();
};

void S::clear()
{
    Node* current = head->next;
    head->next = head;
    head->prev = head;
    count = 0;

    while (current != head) {
        Node* next = current->next;
        release_node(current);
        current = next;
    }
}
