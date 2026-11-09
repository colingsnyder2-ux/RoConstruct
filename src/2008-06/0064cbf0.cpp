// from server: 100% by king_originala
struct Climbing;

struct Edge {
    virtual ~Edge();
    Edge* get();
    void clear(int);
    void unlink(int);
};

struct Stage {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void remove(Edge*);
    void update(Edge*);
};

struct Climbing {
    char pad[8];
    Stage* stage;
    void f(Edge*);
};

void Climbing::f(Edge* edge)
{
    Edge* previous = edge->get();
    stage->remove(previous);
    stage->update(edge);
    previous->clear(reinterpret_cast<int>(this));
    delete previous;
    edge->unlink(reinterpret_cast<int>(this));
}
