// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /D_SECURE_SCL=0
#include <string>
namespace G3D {
std::string toUpper(const std::string& x);
class GImage {
public:
    enum Format {JPEG, BMP, TGA, PCX, ICO, PNG, AUTODETECT, DDS, PVR, UNKNOWN};
    static Format stringToFormat(const std::string& format);
};
GImage::Format GImage::stringToFormat(
    const std::string& format) {

    std::string extension = toUpper(format);

    if ((extension == "JPG") || (extension == "JPEG")) {
        return JPEG;
    } else if (extension == "TGA") {
        return TGA;
    } else if (extension == "BMP") {
        return BMP;
    } else if (extension == "PCX") {
        return PCX;
    } else if (extension == "ICO") {
        return ICO;
    } else if (extension == "PNG") {
        return PNG;
    } else {
        return UNKNOWN;
    }
}
}