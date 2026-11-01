// from server: 100% by tester
namespace G3D {
template<class T>
class Array
{
    T* data;
    int num;
    int numAllocated;
public:
    int size() const { return num; }
    const T& front() const { return data[0]; }
};
}

namespace RBX {
namespace Render {
class Material
{
public:
    class Level
    {
        char gap0[0x28];
    public:
        float mTransparent;
    };

private:
    char gap0[0xc];
    G3D::Array<Level> levels;

public:
    bool veryTransparent() const;
};

bool Material::veryTransparent() const
{
    return levels.size() > 0 && levels.front().mTransparent > 0.25f;
}
}
}
