// from server: 52% by atomic.potato
struct BallBlockConnector
{
    void Update(float);
    int field_0c;
    int field_10;
};

extern "C" void UpdatePart(int);

void BallBlockConnector::Update(float value)
{
    UpdatePart(field_0c);
    UpdatePart(field_10);
    Update(value);
}
