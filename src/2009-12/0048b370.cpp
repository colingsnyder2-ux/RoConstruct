// from server: 73% by atomic.potato
struct VisualEngine
{
    double value;
    int field;
    void f(int value);
};

void VisualEngine::f(int value)
{
    this->value = 1.0;
    this->field = value;
}
