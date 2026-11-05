// from server: 100% by atomic.potato
struct IStage {};
struct IPipelined {
    void removeFromStage(IStage*);
};
struct S : IStage {
    void f(IPipelined* p);
};

void S::f(IPipelined* p) {
    p->removeFromStage(this);
}
