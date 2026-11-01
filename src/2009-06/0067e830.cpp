// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Data { int x; };
class Node {
public:
    virtual ~Node();
    virtual int getType() const;
    int pad;
    Node* next;
    int pad2;
    Data data;
};
class Owner {
public:
    char pad[0xb8];
    Node* node;
    Data* find();
};
Data* Owner::find()
{
    Node* n = node;
    while (n->getType() != 7)
        n = n->next;
    return &n->data;
}
