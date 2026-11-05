// from server: 30% by atomic.potato
struct Ball
{
    float value;
    float result;
    float update();
};

float Ball::update()
{
    result = value * *(const float*)0x009af2dc;
    return result;
}
