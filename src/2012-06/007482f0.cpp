// from server: 37% by atomic.potato
extern "C" void Decal_Update(void* object, float value);

struct Decal
{
    char padding[196];
    float value;
    void update(float value);
};

void Decal::update(float value)
{
    if (value == value || value < this->value || value > this->value)
    {
        this->value = value;
        Decal_Update(this, value);
    }
}
