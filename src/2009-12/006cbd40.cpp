// from server: 100% by atomic.potato
struct PartInstance
{
    float getValue();
};

float PartInstance::getValue()
{
    struct Data
    {
        char padding[0x94];
        float value;
    };

    Data* data = *(Data**)((char*)this + 0x168);
    Data* nested = *(Data**)((char*)data + 0xf4);
    return nested->value;
}
