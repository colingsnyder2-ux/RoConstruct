// from server: 48% by colin
extern "C" int __stdcall MessageBoxA_impl(unsigned int, const char*, const char*, unsigned int);
extern "C" int __stdcall MultiByteToWideChar_impl(unsigned int, unsigned int, const char*, int, wchar_t*, int);
extern "C" int __stdcall WideCharToMultiByte_impl(unsigned int, unsigned int, const wchar_t*, int, char*, int, const char*, int*);

extern "C" int __stdcall sub_401000(unsigned int code);
extern "C" int __stdcall sub_4016e0(const char* fmt, ...);
extern "C" int __stdcall sub_437030(unsigned int cp, wchar_t* out);
extern "C" int __stdcall sub_437090(unsigned int cp, wchar_t* out);

struct VStandardOutListener {
    int convert(const wchar_t* src, int srcLen, char* dst, int dstLen, unsigned int flags);
};

int VStandardOutListener::convert(const wchar_t* src, int srcLen, char* dst, int dstLen, unsigned int flags)
{
    int written = 0;
    int remaining = dstLen;
    unsigned int pending = 0;
    int i = 0;

    if (src == 0) {
        sub_401000(0x80004005);
    }

    if (srcLen == 0) {
        if (dst != 0 && remaining < 0) {
            return 0;
        }
        return written;
    }

    while (i < srcLen) {
        unsigned short ch = ((const unsigned short*)src)[i];
        int consumed = 0;

        if (ch >= 0x22 && ch <= 0x3e) {
            switch (ch) {
            case 0x22:
                if (dst != 0 && remaining > 3) {
                    ((unsigned short*)dst)[0] = 0x26;
                    ((unsigned short*)dst)[1] = (ch < 0x3c) ? 0x6c : 0x67;
                    ((unsigned short*)dst)[2] = 0x74;
                    ((unsigned short*)dst)[3] = 0x3b;
                    dst += 8;
                }
                consumed = 4;
                break;
            case 0x26:
                if (dst != 0 && remaining > 4) {
                    sub_4016e0("&amp;", dst, remaining * 2, 10);
                    dst += 10;
                }
                consumed = 5;
                break;
            case 0x27:
            case 0x3c:
            case 0x3e:
                if ((flags & 1) != 0) {
                    if (dst != 0 && remaining > 5) {
                        const char* ent = (ch == 0x27) ? "&#39;" : "&lt;";
                        sub_4016e0(ent, dst, remaining * 2, 12);
                        dst += 12;
                    }
                    consumed = 6;
                }
                break;
            default:
                break;
            }
        }

        if (consumed == 0) {
            if (ch >= 0xd800 && ch <= 0xdbff) {
                if (pending != 0) {
                    if (dst != 0 && remaining > 7) {
                        sub_437030(pending, (wchar_t*)dst);
                        dst += 16;
                    }
                    consumed = 8;
                }
                pending = ch;
                i++;
                continue;
            }
            else if (ch >= 0xdc00 && ch <= 0xdfff) {
                if (pending != 0) {
                    if (dst != 0 && remaining > 9) {
                        unsigned int cp = ((pending - 0xd7f7) << 10) + ch;
                        sub_437090(cp, (wchar_t*)dst);
                        dst += 20;
                    }
                    consumed = 10;
                    pending = 0;
                }
                else {
                    if (dst != 0 && remaining > 7) {
                        sub_437030(ch, (wchar_t*)dst);
                        dst += 16;
                    }
                    remaining -= 8;
                    written += 8;
                    i++;
                    continue;
                }
            }
            else {
                if (pending != 0) {
                    if (dst != 0 && remaining > 7) {
                        sub_437030(pending, (wchar_t*)dst);
                        dst += 16;
                    }
                    remaining -= 8;
                    written += 8;
                    pending = 0;
                }
                if (ch >= 0x20 && ch <= 0x7e) {
                    if (dst != 0 && remaining > 0) {
                        *(unsigned short*)dst = ch;
                        dst += 2;
                    }
                    consumed = 1;
                }
                else {
                    if (dst != 0 && remaining > 7) {
                        sub_437030(ch, (wchar_t*)dst);
                        dst += 16;
                    }
                    consumed = 8;
                }
            }
        }

        written += consumed;
        i++;
        remaining -= consumed;
    }

    if (pending != 0) {
        if (pending >= 0x20 && pending <= 0x7e) {
            if (dst != 0 && remaining > 0) {
                *(unsigned short*)dst = (unsigned short)pending;
            }
            remaining -= 1;
            written += 1;
        }
        else {
            if (dst != 0 && remaining > 7) {
                sub_437030(pending, (wchar_t*)dst);
            }
            remaining -= 8;
            written += 8;
        }
    }

    if (dst != 0 && remaining < 0) {
        return 0;
    }
    return written;
}
