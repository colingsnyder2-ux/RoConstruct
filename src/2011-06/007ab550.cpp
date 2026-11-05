// from server: 57% by atomic.potato
struct Node
{
    double value;
    char pad[4];
    Node* child;
    Node* next;
};

void __cdecl f(Node* node, int* count, double* out)
{
    while (node)
    {
        if (node->child)
            f(node->child, count, out);
        out[*count] = node->value;
        ++*count;
        node = node->next;
    }
}
