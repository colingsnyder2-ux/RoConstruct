// from server: 100% by king_originala
struct Node;
struct TreeStage;

struct Primitive
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int inactive();
    virtual void v4();
    virtual int kind();

    unsigned char padding[32];
    unsigned char enabled;

    void f(int);
};

Node* __cdecl selectedEndpoint(Primitive*);
void __cdecl remove(Primitive*);

struct TreeStage
{
    unsigned char padding[20];
    unsigned char changed;

    Node* find(Node*, Node**);
    void detach(Primitive*, Node*, Node*);
    void reject(Primitive*);
    void process(Primitive*);
};

void TreeStage::process(Primitive* primitive)
{
    if (primitive->inactive() || primitive->kind() < 5)
    {
        reject(primitive);
    }
    else if (primitive->enabled)
    {
        Node* endpoint = selectedEndpoint(primitive);
        Node* parent = 0;
        Node* node = find(endpoint, &parent);
        detach(primitive, node, parent);
        changed = 1;
    }

    primitive->f(reinterpret_cast<int>(this));
    remove(primitive);
}
