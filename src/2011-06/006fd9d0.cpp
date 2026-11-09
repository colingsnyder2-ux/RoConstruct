// from server: 80% by atomic.potato
struct Node
{
    Node* next;
    int pad;
    void* value;
};

struct FlagStandService
{
    char pad[16];
    Node* head;
    void remove(void* value);
};

void FlagStandService::remove(void* value)
{
    Node* node = head->next;
    while (node != head)
    {
        remove(node->value);
        node = node->next;
    }
}
