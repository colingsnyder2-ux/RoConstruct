// from server: 100% by EspClaude
// roc 2007-08 00471ff0  (trial): G3D 6.09 Texture::fromFile(const std::string&, ...)
// wrapper that builds std::string f[6] and forwards to the 6-name overload
// (0x471880). Argument order/sizes from the target's stack offsets:
// retptr, filename, desiredFormat, wrap, interpolate, dimension,
// double brighten, depthRead, float maxAnisotropy, float scale.
#include <string>

namespace G3D {

class ReferenceCountedObject {
public:
    virtual ~ReferenceCountedObject() {}
};

template <class T>
class ReferenceCountedPointer {
    T* m_pointer;
public:
    ReferenceCountedPointer(const ReferenceCountedPointer<T>& p);
    ~ReferenceCountedPointer();
};

class TextureFormat;

class Texture : public ReferenceCountedObject {
public:
    enum WrapMode { TILE, CLAMP, TRANSPARENT_BORDER };
    enum InterpolateMode { TRILINEAR_MIPMAP, BILINEAR_NO_MIPMAP, NO_INTERPOLATION };
    enum Dimension { DIM_2D, DIM_2D_RECT, DIM_CUBE_MAP, DIM_2D_NPOT, DIM_CUBE_MAP_NPOT };
    enum DepthReadMode { DEPTH_NORMAL, DEPTH_LEQUAL, DEPTH_GEQUAL };

    static ReferenceCountedPointer<Texture> fromFile(
        const std::string&      filename,
        const TextureFormat*    desiredFormat,
        WrapMode                wrap,
        InterpolateMode         interpolate,
        Dimension               dimension,
        double                  brighten,
        DepthReadMode           depthRead,
        float                   maxAnisotropy,
        float                   scale);

    static ReferenceCountedPointer<Texture> fromFile(
        const std::string       filename[6],
        const TextureFormat*    desiredFormat,
        WrapMode                wrap,
        InterpolateMode         interpolate,
        Dimension               dimension,
        double                  brighten,
        DepthReadMode           depthRead,
        float                   maxAnisotropy,
        float                   sizeFactor);
};

typedef ReferenceCountedPointer<Texture> TextureRef;

TextureRef Texture::fromFile(
    const std::string&      filename,
    const TextureFormat*    desiredFormat,
    WrapMode                wrap,
    InterpolateMode         interpolate,
    Dimension               dimension,
    double                  brighten,
    DepthReadMode           depthRead,
    float                   maxAnisotropy,
    float                   scale) {

    std::string f[6];
    f[0] = filename;
    f[1] = "";
    f[2] = "";
    f[3] = "";
    f[4] = "";
    f[5] = "";

    return fromFile(f, desiredFormat, wrap, interpolate, dimension, brighten, depthRead, maxAnisotropy, scale);
}

}
