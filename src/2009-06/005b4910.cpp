// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT /EHsc

template <class T>
class Alloc
{
public:
    Alloc();
    template <class U> Alloc(const Alloc<U>& other);
};

struct Node;

class ListVal
{
public:
    ListVal(Alloc<Node> al);
    ~ListVal();
    char data[0x14];
};

class List : public ListVal
{
public:
    explicit List(const Alloc<int>& al);
    Node* buyNode();
    Node* head;
    unsigned int size;
};

List::List(const Alloc<int>& al)
    : ListVal(al), head(buyNode()), size(0)
{
}
