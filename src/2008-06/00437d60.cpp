// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

class String {
public:
    __declspec(dllimport) String(const char* s);
    __declspec(dllimport) ~String();
    char storage[0x1c];
};

namespace G3D {
class GImage {
public:
    enum Format { JPEG, BMP, TGA, PCX, ICO, PNG, AUTODETECT, UNKNOWN };
    static Format resolveFormat(const String& filename);
};
}

namespace RBX {
class Name {
public:
    static const Name& declare(const char* sName, int dictionaryIndex = -1);
    static const Name& getNullName();
};

const Name& getMimeType(const char* filename)
{
    switch (G3D::GImage::resolveFormat(filename))
    {
    case G3D::GImage::JPEG:
        return Name::declare("image/jpeg");
    case G3D::GImage::BMP:
        return Name::declare("image/bmp");
    case G3D::GImage::ICO:
        return Name::declare("image/vnd.microsoft.icon");
    case G3D::GImage::PNG:
        return Name::declare("image/png");
    default:
        return Name::getNullName();
    }
}
}
