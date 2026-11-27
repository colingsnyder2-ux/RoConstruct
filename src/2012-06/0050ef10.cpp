// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct __declspec(dllimport) OgreNode { void removeAllChildren(); };
struct S : OgreNode
{
    struct Node
    {
        Node *next;
        char pad[0x20];
        void *value;
    };
    char pad[0x10];
    Node *nodes;
    void remove(void *);
    void removeAll();
};
void S::removeAll()
{
    Node *head = nodes;
    Node *p = head->next;
    while (p != head)
    {
        remove(p->value);
        p = p->next;
    }
    removeAllChildren();
}
