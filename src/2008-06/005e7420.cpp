// from server: 100% by tester
namespace RBX {
class Primitive
{
    char gap0[0x14];
    unsigned int sizeMultiplier;
    char gap18[0x40];
    void* world;
public:
    void setSizeMultiplier(unsigned int value);
};

void Primitive::setSizeMultiplier(unsigned int value)
{
    if (value != sizeMultiplier && world == 0)
        sizeMultiplier = value;
}
}
