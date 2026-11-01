// from server: 100% by king_originala
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
