// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: G3D GImage::resolveFormat; enum values from return constants.
// Arg order inferred from stack offsets (arg3 unused, length is arg5).
extern std::string toUpper_G3D(const std::string& s);
extern "C" int fn_0050d600(const std::string* ext); // GImage::stringToFormat
extern "C" int fn_0051dbf0(const unsigned char* sig, int start, int num); // png_sig_cmp

extern "C" int fn_0050ddc0(const std::string* filename, const unsigned char* data,
                           int unused, int maybeFormat, int length)
{
    if (maybeFormat != 8)
        return maybeFormat;

    std::string ext;
    int size = (int)filename->size();
    if (size >= 5) {
        int n = size - 1;
        if (n < 5) n = 5;
        for (int i = 1; i <= n; ++i) {
            if ((*filename)[size - i] == '.') {
                ext = toUpper_G3D(filename->substr(size - i + 1));
                break;
            }
        }
    }

    if (ext == "PPM" && length > 3) {
        if (data[0] == 'P' && data[1] == '6')
            return 7;
        return 6;
    }

    int f = fn_0050d600(&ext);
    if (f != 8 && f != 9)
        return f;

    if (length > 3 && data[0] == 'P') {
        if (data[1] == '3' || data[1] == '2' || data[1] == '1')
            return 6;
        if (data[1] == '6')
            return 7;
    }
    if (length > 8 && fn_0051dbf0(data, 0, 8) == 0)
        return 5;
    if (length > 0 && data[0] == 'B')
        return 1;
    if (length > 10 && length > 11 && data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff)
        return 0;
    if (length > 0x28 && memcmp(data + length - 0x12, "TRUEVISION-XFILE", 16) == 0)
        return 2;
    if (length > 4 && data[0] == 0 && data[1] == 0 && data[2] == 0 && data[3] == 1)
        return 4;
    if (length > 0 && data[0] == 10)
        return 3;
    return 9;
}
