// from server: 100% by colin
// roc 2007-08 005a3d40  unit: RBX::VTimerService::?$FactoryProduct  size: 26 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005a3d40

extern "C" void* __cdecl operator_new(unsigned int size);

struct Node {
    Node* next;
    Node* prev;
};

void makeNode()
{
    Node* p = (Node*)operator_new(0x20);
    if (p) {
        p->next = p;
    }
    Node* q = (Node*)((char*)p + 4);
    if (q) {
        q->next = p;
    }
}
