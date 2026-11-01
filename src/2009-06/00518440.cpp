// from server: 98% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor; }
class Surfaces { public: static const bool isSurfaceDescriptor(const Reflection::PropertyDescriptor&); };
extern const Reflection::PropertyDescriptor descA;
extern const Reflection::PropertyDescriptor descB;
extern const Reflection::PropertyDescriptor descC;
extern const Reflection::PropertyDescriptor descD;
class PartChunk {
public:
    void invalidateGeometry();
    void invalidateColor();
    void onPropertyChanged(const Reflection::PropertyDescriptor* descriptor);
};
void PartChunk::onPropertyChanged(const Reflection::PropertyDescriptor* descriptor)
{
    if (descriptor == &descA) {
    } else if (descriptor == &descB || descriptor == &descC) {
        invalidateColor();
        return;
    } else if (descriptor == &descD) {
    } else {
        if (Surfaces::isSurfaceDescriptor(*descriptor))
            invalidateGeometry();
        return;
    }
    invalidateGeometry();
    invalidateColor();
}
}
