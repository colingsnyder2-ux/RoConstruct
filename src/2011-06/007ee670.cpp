// from server: 35% by atomic.potato
struct SimulateStage
{
    int value;
    SimulateStage* get();
};

SimulateStage* SimulateStage::get()
{
    SimulateStage* p = this;
    while (p->value)
        p = (SimulateStage*)((char*)p - 8);
    return p;
}
