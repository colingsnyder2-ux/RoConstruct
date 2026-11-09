// from server: 100% by king_originala
struct Node {
    char padding[0x104];
    Node* next;
};

Node* __cdecl f(Node* node)
{
    Node* result = node->next;
    Node* current = result->next;
    while (current->next) {
        result = current;
        current = current->next;
    }
    return result;
}
