// from server: 100% by EspClaude
// roc 2009-06 005729f0  unit: seg_00570000  size: 448 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005729f0
//
// 005729f0  64a100000000         mov eax, dword ptr fs:[0]
// 005729f6  6aff                 push -1
// 005729f8  68d8048600           push 0x8604d8
// 005729fd  50                   push eax
// 005729fe  8b442414             mov eax, dword ptr [esp + 0x14]
// 00572a02  64892500000000       mov dword ptr fs:[0], esp
// 00572a09  81ec98000000         sub esp, 0x98
// 00572a0f  83f807               cmp eax, 7
// 00572a12  0f8727010000         ja 0x572b3f
// 00572a18  ff2485902b5700       jmp dword ptr [eax*4 + 0x572b90]
// 00572a1f  8b8424a8000000       mov eax, dword ptr [esp + 0xa8]
// 00572a26  50                   push eax
// 00572a27  e8e4fbffff           call 0x572610
// 00572a2c  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00572a33  64890d00000000       mov dword ptr fs:[0], ecx
// 00572a3a  81c4a4000000         add esp, 0xa4
// 00572a40  c20800               ret 8
// 00572a43  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 00572a4a  52                   push edx
// 00572a4b  e810e9ffff           call 0x571360
// 00572a50  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00572a57  64890d00000000       mov dword ptr fs:[0], ecx
// 00572a5e  81c4a4000000         add esp, 0xa4
// 00572a64  c20800               ret 8
// 00572a67  8b8424a8000000       mov eax, dword ptr [esp + 0xa8]
// 00572a6e  50                   push eax
// 00572a6f  e88ccaffff           call 0x56f500
// 00572a74  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00572a7b  64890d00000000       mov dword ptr fs:[0], ecx
// 00572a82  81c4a4000000         add esp, 0xa4
// 00572a88  c20800               ret 8
// 00572a8b  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 00572a92  52                   push edx
// 00572a93  e8d8c7ffff           call 0x56f270
// 00572a98  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00572a9f  64890d00000000       mov dword ptr fs:[0], ecx
// 00572aa6  81c4a4000000         add esp, 0xa4
// 00572aac  c20800               ret 8
// 00572aaf  8b8424a8000000       mov eax, dword ptr [esp + 0xa8]
// 00572ab6  50                   push eax
// 00572ab7  e8a4b7ffff           call 0x56e260
// 00572abc  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00572ac3  64890d00000000       mov dword ptr fs:[0], ecx
// 00572aca  81c4a4000000         add esp, 0xa4
// 00572ad0  c20800               ret 8
// 00572ad3  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 00572ada  52                   push edx
// 00572adb  e890bcffff           call 0x56e770
// 00572ae0  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00572ae7  64890d00000000       mov dword ptr fs:[0], ecx
// 00572aee  81c4a4000000         add esp, 0xa4
// 00572af4  c20800               ret 8
// 00572af7  8b8424a8000000       mov eax, dword ptr [esp + 0xa8]
// 00572afe  50                   push eax
// 00572aff  e8dcf0ffff           call 0x571be0
// 00572b04  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00572b0b  64890d00000000       mov dword ptr fs:[0], ecx
// 00572b12  81c4a4000000         add esp, 0xa4
// 00572b18  c20800               ret 8
// 00572b1b  8b9424a8000000       mov edx, dword ptr [esp + 0xa8]
// 00572b22  52                   push edx
// 00572b23  e8b8d5ffff           call 0x5700e0
// 00572b28  8b8c2498000000       mov ecx, dword ptr [esp + 0x98]
// 00572b2f  64890d00000000       mov dword ptr fs:[0], ecx
// 00572b36  81c4a4000000         add esp, 0xa4
// 00572b3c  c20800               ret 8
// 00572b3f  68dcb68c00           push 0x8cb6dc
// 00572b44  8d4c2404             lea ecx, [esp + 4]
// 00572b48  ff15b4e48900         call dword ptr [0x89e4b4]
// 00572b4e  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 00572b55  8d44241c             lea eax, [esp + 0x1c]
// 00572b59  50                   push eax
// 00572b5a  c78424a400000000000000 mov dword ptr [esp + 0xa4], 0
// 00572b65  e846a6ffff           call 0x56d1b0
// 00572b6a  50                   push eax
// 00572b6b  8d4c2404             lea ecx, [esp + 4]
// 00572b6f  51                   push ecx
// 00572b70  8d4c2440             lea ecx, [esp + 0x40]
// 00572b74  c68424a800000001     mov byte ptr [esp + 0xa8], 1
// 00572b7c  e81f74f2ff           call 0x499fa0
// 00572b81  68308a9800           push 0x988a30
// 00572b86  8d54243c             lea edx, [esp + 0x3c]
// 00572b8a  52                   push edx
// 00572b8b  e8ba6e1a00           call 0x719a4a
// 00572b90  8b2a                 mov ebp, dword ptr [edx]
// 00572b92  57                   push edi
// 00572b93  00d3                 add bl, dl
// 00572b95  2a5700               sub dl, byte ptr [edi]
// 00572b98  af                   scasd eax, dword ptr es:[edi]
// 00572b99  2a5700               sub dl, byte ptr [edi]
// 00572b9c  1b2b                 sbb ebp, dword ptr [ebx]
// 00572b9e  57                   push edi
// 00572b9f  00f7                 add bh, dh
// 00572ba1  2a5700               sub dl, byte ptr [edi]
// 00572ba4  672a5700             sub dl, byte ptr [bx]
// 00572ba8  1f                   pop ds
// 00572ba9  2a5700               sub dl, byte ptr [edi]
// 00572bac  43                   inc ebx
// 00572bad  2a5700               sub dl, byte ptr [edi]
// copied from an identical function in another client (function ?decode@GImage@G3D@@QAEXAAVBinaryInput@2@W4Format@12@@Z)

// from server: 67% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
#include <stdexcept>
namespace G3D {
class BinaryInput {
public:
    std::string getFilename() const;
};
class GImage {
public:
    enum Format {JPEG, BMP, TGA, PCX, ICO, PNG, PPM_ASCII, PPM, AUTODETECT, UNKNOWN};
    class Error : public std::runtime_error {
    public:
        Error(const std::string& reason, const std::string& filename = "");
        std::string reason;
        std::string filename;
    };
    void decode(BinaryInput& input, Format format);
    void decodePCX(BinaryInput& input);
    void decodeICO(BinaryInput& input);
    void decodeTGA(BinaryInput& input);
    void decodeBMP(BinaryInput& input);
    void decodeJPEG(BinaryInput& input);
    void decodePNG(BinaryInput& input);
    void decodePPMASCII(BinaryInput& input);
    void decodePPM(BinaryInput& input);
};
void GImage::decode(BinaryInput& input, Format format) {
    switch (format) {
    case PPM_ASCII:
        decodePPMASCII(input);
        break;
    case PPM:
        decodePPM(input);
        break;
    case PNG:
        decodePNG(input);
        break;
    case JPEG:
        decodeJPEG(input);
        break;
    case TGA:
        decodeTGA(input);
        break;
    case BMP:
        decodeBMP(input);
        break;
    case ICO:
        decodeICO(input);
        break;
    case PCX:
        decodePCX(input);
        break;
    default:
        throw Error("invalid format", input.getFilename());
    }
}
}