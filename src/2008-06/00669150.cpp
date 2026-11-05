// from server: 100% by king_originala
struct Primitive;
struct Edge;

struct InsertResult
{
    void* data[3];
};

struct Primitive
{
    Edge* first();
    Edge* next(Edge*);
    InsertResult insert(Primitive* const&);
};

struct Edge
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int inactive();
    virtual void v4();
    virtual int kind();

    unsigned char padding0[8];
    Primitive* endpoint0;
    Primitive* endpoint1;
    unsigned char padding1[16];
    unsigned char enabled;
};

Primitive* __cdecl selectedEndpoint(Edge*);

struct TreeStage
{
    void process(Primitive*, Primitive*);
};

void TreeStage::process(Primitive* primitive, Primitive* collection)
{
    Edge* edge = primitive->first();
    while (edge)
    {
        if (edge->enabled && !edge->inactive() && edge->kind() >= 5)
        {
            Primitive* other = edge->endpoint0;
            if (primitive == other)
                other = edge->endpoint1;

            Primitive* value = other;
            if (other == selectedEndpoint(edge))
            {
                collection->insert(value);
                process(other, collection);
            }
        }
        edge = primitive->next(edge);
    }
}
