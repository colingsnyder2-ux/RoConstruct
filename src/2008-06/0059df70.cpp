// from server: 100% by tester
// roc-cl: 50727
namespace RBX {
namespace Reflection {
class PropertyDescriptor
{
    const char* name;
};
}

enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };

class FaceInstance
{
    char gap0[0x1e0];
    NormalId face;
public:
    static Reflection::PropertyDescriptor prop_Face;
    void raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor);
    void setFace(NormalId value);
};

void FaceInstance::setFace(NormalId value)
{
    if (value != face) {
        face = value;
        raisePropertyChanged(prop_Face);
    }
}
}
