// from server: 100% by EspClaude
// from server: 85% by EspClaude
// roc 2008-06 007b8180  unit: RBX::Render::Material  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007b8180
//
// 007b8180  6aff                 push -1
// 007b8182  6828517c00           push 0x7c5128
// 007b8187  64a100000000         mov eax, dword ptr fs:[0]
// 007b818d  50                   push eax
// 007b818e  64892500000000       mov dword ptr fs:[0], esp
// 007b8195  83ec24               sub esp, 0x24
// 007b8198  55                   push ebp
// 007b8199  56                   push esi
// 007b819a  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 007b819e  8b4610               mov eax, dword ptr [esi + 0x10]
// 007b81a1  50                   push eax
// 007b81a2  8b460c               mov eax, dword ptr [esi + 0xc]
// 007b81a5  99                   cdq 
// 007b81a6  2bc2                 sub eax, edx
// 007b81a8  d1f8                 sar eax, 1
// 007b81aa  50                   push eax
// 007b81ab  8b4608               mov eax, dword ptr [esi + 8]
// 007b81ae  99                   cdq 
// 007b81af  2bc2                 sub eax, edx
// 007b81b1  d1f8                 sar eax, 1
// 007b81b3  50                   push eax
// 007b81b4  8d4c2424             lea ecx, [esp + 0x24]
// 007b81b8  e8e36cd5ff           call 0x50eea0
// 007b81bd  8b6e08               mov ebp, dword ptr [esi + 8]
// 007b81c0  0faf6e10             imul ebp, dword ptr [esi + 0x10]
// 007b81c4  33c0                 xor eax, eax
// 007b81c6  39442424             cmp dword ptr [esp + 0x24], eax
// 007b81ca  89442434             mov dword ptr [esp + 0x34], eax
// 007b81ce  896c2410             mov dword ptr [esp + 0x10], ebp
// 007b81d2  8944243c             mov dword ptr [esp + 0x3c], eax
// 007b81d6  0f8ed6000000         jle 0x7b82b2
// 007b81dc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007b81e0  8b442420             mov eax, dword ptr [esp + 0x20]
// 007b81e4  53                   push ebx
// 007b81e5  57                   push edi
// 007b81e6  c744241401000000     mov dword ptr [esp + 0x14], 1
// 007b81ee  8bff                 mov edi, edi
// 007b81f0  33db                 xor ebx, ebx
// 007b81f2  85c0                 test eax, eax
// 007b81f4  0f8e9e000000         jle 0x7b8298
// 007b81fa  c744241001000000     mov dword ptr [esp + 0x10], 1
// 007b8202  33ff                 xor edi, edi
// 007b8204  85c9                 test ecx, ecx
// 007b8206  0f8e7e000000         jle 0x7b828a
// 007b820c  8d642400             lea esp, [esp]
// 007b8210  0faf442444           imul eax, dword ptr [esp + 0x44]
// 007b8215  8b5608               mov edx, dword ptr [esi + 8]
// 007b8218  03c3                 add eax, ebx
// 007b821a  0fafc1               imul eax, ecx
// 007b821d  03442424             add eax, dword ptr [esp + 0x24]
// 007b8221  8b4e04               mov ecx, dword ptr [esi + 4]
// 007b8224  03c7                 add eax, edi
// 007b8226  8944241c             mov dword ptr [esp + 0x1c], eax
// 007b822a  8bc2                 mov eax, edx
// 007b822c  0faf442444           imul eax, dword ptr [esp + 0x44]
// 007b8231  03c3                 add eax, ebx
// 007b8233  0faf4610             imul eax, dword ptr [esi + 0x10]
// 007b8237  8d0c41               lea ecx, [ecx + eax*2]
// 007b823a  03cf                 add ecx, edi
// 007b823c  39542410             cmp dword ptr [esp + 0x10], edx
// 007b8240  7d28                 jge 0x7b826a
// 007b8242  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b8246  3b560c               cmp edx, dword ptr [esi + 0xc]
// 007b8249  7d1f                 jge 0x7b826a
// 007b824b  8b4610               mov eax, dword ptr [esi + 0x10]
// 007b824e  03c1                 add eax, ecx
// 007b8250  0fb61428             movzx edx, byte ptr [eax + ebp]
// 007b8254  0fb62c29             movzx ebp, byte ptr [ecx + ebp]
// 007b8258  0fb609               movzx ecx, byte ptr [ecx]
// 007b825b  0fb600               movzx eax, byte ptr [eax]
// 007b825e  03d5                 add edx, ebp
// 007b8260  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007b8264  03d1                 add edx, ecx
// 007b8266  03d0                 add edx, eax
// 007b8268  eb07                 jmp 0x7b8271
// 007b826a  0fb611               movzx edx, byte ptr [ecx]
// 007b826d  03d2                 add edx, edx
// 007b826f  03d2                 add edx, edx
// 007b8271  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007b8275  83c202               add edx, 2
// 007b8278  c1fa02               sar edx, 2
// 007b827b  8811                 mov byte ptr [ecx], dl
// 007b827d  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007b8281  8b442428             mov eax, dword ptr [esp + 0x28]
// 007b8285  47                   inc edi
// 007b8286  3bf9                 cmp edi, ecx
// 007b8288  7c86                 jl 0x7b8210
// 007b828a  8344241002           add dword ptr [esp + 0x10], 2
// 007b828f  43                   inc ebx
// 007b8290  3bd8                 cmp ebx, eax
// 007b8292  0f8c6affffff         jl 0x7b8202
// 007b8298  8b542444             mov edx, dword ptr [esp + 0x44]
// 007b829c  8344241402           add dword ptr [esp + 0x14], 2
// 007b82a1  42                   inc edx
// 007b82a2  3b54242c             cmp edx, dword ptr [esp + 0x2c]
// 007b82a6  89542444             mov dword ptr [esp + 0x44], edx
// 007b82aa  0f8c40ffffff         jl 0x7b81f0
// 007b82b0  5f                   pop edi
// 007b82b1  5b                   pop ebx
// 007b82b2  8b542440             mov edx, dword ptr [esp + 0x40]
// 007b82b6  6a05                 push 5
// 007b82b8  52                   push edx
// 007b82b9  8d4c2420             lea ecx, [esp + 0x20]
// 007b82bd  e86e71d5ff           call 0x50f430
// 007b82c2  8d4c2418             lea ecx, [esp + 0x18]
// 007b82c6  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 007b82ce  e85d5fd5ff           call 0x50e230
// 007b82d3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007b82d7  5e                   pop esi
// 007b82d8  5d                   pop ebp
// 007b82d9  64890d00000000       mov dword ptr fs:[0], ecx
// 007b82e0  83c430               add esp, 0x30
// 007b82e3  c3                   ret 

// from server: 83% by coldek
// roc 2008-06 007b8180  unit: RBX::Render::Material  size: 356 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 007b8180
//
// 007b8180  6aff                 push -1
// 007b8182  6828517c00           push 0x7c5128
// 007b8187  64a100000000         mov eax, dword ptr fs:[0]
// 007b818d  50                   push eax
// 007b818e  64892500000000       mov dword ptr fs:[0], esp
// 007b8195  83ec24               sub esp, 0x24
// 007b8198  55                   push ebp
// 007b8199  56                   push esi
// 007b819a  8b74243c             mov esi, dword ptr [esp + 0x3c]
// 007b819e  8b4610               mov eax, dword ptr [esi + 0x10]
// 007b81a1  50                   push eax
// 007b81a2  8b460c               mov eax, dword ptr [esi + 0xc]
// 007b81a5  99                   cdq 
// 007b81a6  2bc2                 sub eax, edx
// 007b81a8  d1f8                 sar eax, 1
// 007b81aa  50                   push eax
// 007b81ab  8b4608               mov eax, dword ptr [esi + 8]
// 007b81ae  99                   cdq 
// 007b81af  2bc2                 sub eax, edx
// 007b81b1  d1f8                 sar eax, 1
// 007b81b3  50                   push eax
// 007b81b4  8d4c2424             lea ecx, [esp + 0x24]
// 007b81b8  e8e36cd5ff           call 0x50eea0
// 007b81bd  8b6e08               mov ebp, dword ptr [esi + 8]
// 007b81c0  0faf6e10             imul ebp, dword ptr [esi + 0x10]
// 007b81c4  33c0                 xor eax, eax
// 007b81c6  39442424             cmp dword ptr [esp + 0x24], eax
// 007b81ca  89442434             mov dword ptr [esp + 0x34], eax
// 007b81ce  896c2410             mov dword ptr [esp + 0x10], ebp
// 007b81d2  8944243c             mov dword ptr [esp + 0x3c], eax
// 007b81d6  0f8ed6000000         jle 0x7b82b2
// 007b81dc  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007b81e0  8b442420             mov eax, dword ptr [esp + 0x20]
// 007b81e4  53                   push ebx
// 007b81e5  57                   push edi
// 007b81e6  c744241401000000     mov dword ptr [esp + 0x14], 1
// 007b81ee  8bff                 mov edi, edi
// 007b81f0  33db                 xor ebx, ebx
// 007b81f2  85c0                 test eax, eax
// 007b81f4  0f8e9e000000         jle 0x7b8298
// 007b81fa  c744241001000000     mov dword ptr [esp + 0x10], 1
// 007b8202  33ff                 xor edi, edi
// 007b8204  85c9                 test ecx, ecx
// 007b8206  0f8e7e000000         jle 0x7b828a
// 007b820c  8d642400             lea esp, [esp]
// 007b8210  0faf442444           imul eax, dword ptr [esp + 0x44]
// 007b8215  8b5608               mov edx, dword ptr [esi + 8]
// 007b8218  03c3                 add eax, ebx
// 007b821a  0fafc1               imul eax, ecx
// 007b821d  03442424             add eax, dword ptr [esp + 0x24]
// 007b8221  8b4e04               mov ecx, dword ptr [esi + 4]
// 007b8224  03c7                 add eax, edi
// 007b8226  8944241c             mov dword ptr [esp + 0x1c], eax
// 007b822a  8bc2                 mov eax, edx
// 007b822c  0faf442444           imul eax, dword ptr [esp + 0x44]
// 007b8231  03c3                 add eax, ebx
// 007b8233  0faf4610             imul eax, dword ptr [esi + 0x10]
// 007b8237  8d0c41               lea ecx, [ecx + eax*2]
// 007b823a  03cf                 add ecx, edi
// 007b823c  39542410             cmp dword ptr [esp + 0x10], edx
// 007b8240  7d28                 jge 0x7b826a
// 007b8242  8b542414             mov edx, dword ptr [esp + 0x14]
// 007b8246  3b560c               cmp edx, dword ptr [esi + 0xc]
// 007b8249  7d1f                 jge 0x7b826a
// 007b824b  8b4610               mov eax, dword ptr [esi + 0x10]
// 007b824e  03c1                 add eax, ecx
// 007b8250  0fb61428             movzx edx, byte ptr [eax + ebp]
// 007b8254  0fb62c29             movzx ebp, byte ptr [ecx + ebp]
// 007b8258  0fb609               movzx ecx, byte ptr [ecx]
// 007b825b  0fb600               movzx eax, byte ptr [eax]
// 007b825e  03d5                 add edx, ebp
// 007b8260  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 007b8264  03d1                 add edx, ecx
// 007b8266  03d0                 add edx, eax
// 007b8268  eb07                 jmp 0x7b8271
// 007b826a  0fb611               movzx edx, byte ptr [ecx]
// 007b826d  03d2                 add edx, edx
// 007b826f  03d2                 add edx, edx
// 007b8271  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 007b8275  83c202               add edx, 2
// 007b8278  c1fa02               sar edx, 2
// 007b827b  8811                 mov byte ptr [ecx], dl
// 007b827d  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 007b8281  8b442428             mov eax, dword ptr [esp + 0x28]
// 007b8285  47                   inc edi
// 007b8286  3bf9                 cmp edi, ecx
// 007b8288  7c86                 jl 0x7b8210
// 007b828a  8344241002           add dword ptr [esp + 0x10], 2
// 007b828f  43                   inc ebx
// 007b8290  3bd8                 cmp ebx, eax
// 007b8292  0f8c6affffff         jl 0x7b8202
// 007b8298  8b542444             mov edx, dword ptr [esp + 0x44]
// 007b829c  8344241402           add dword ptr [esp + 0x14], 2
// 007b82a1  42                   inc edx
// 007b82a2  3b54242c             cmp edx, dword ptr [esp + 0x2c]
// 007b82a6  89542444             mov dword ptr [esp + 0x44], edx
// 007b82aa  0f8c40ffffff         jl 0x7b81f0
// 007b82b0  5f                   pop edi
// 007b82b1  5b                   pop ebx
// 007b82b2  8b542440             mov edx, dword ptr [esp + 0x40]
// 007b82b6  6a05                 push 5
// 007b82b8  52                   push edx
// 007b82b9  8d4c2420             lea ecx, [esp + 0x20]
// 007b82bd  e86e71d5ff           call 0x50f430
// 007b82c2  8d4c2418             lea ecx, [esp + 0x18]
// 007b82c6  c7442434ffffffff     mov dword ptr [esp + 0x34], 0xffffffff
// 007b82ce  e85d5fd5ff           call 0x50e230
// 007b82d3  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007b82d7  5e                   pop esi
// 007b82d8  5d                   pop ebp
// 007b82d9  64890d00000000       mov dword ptr fs:[0], ecx
// 007b82e0  83c430               add esp, 0x30
// 007b82e3  c3                   ret 

#include <string>
typedef unsigned char uint8;
class GImage {
    uint8* _byte;
public:
    enum Format {JPEG, BMP, TGA, PCX, ICO, PNG, PPM_ASCII, PPM, AUTODETECT, UNKNOWN};
    int width;
    int height;
    int channels;
    inline const uint8* byte() const { return _byte; }
    inline uint8* byte() { return _byte; }
    GImage(int, int, int channels = 3);
    virtual ~GImage();
    void save(const std::string&, Format = AUTODETECT) const;
};

void resizeTexture(GImage& source, std::string& filename)
{
    GImage result(source.width / 2, source.height / 2, source.channels);
    int stride = source.width * source.channels;
    for (int y = 0; y < result.height; ++y)
        for (int x = 0; x < result.width; ++x)
            for (int c = 0; c < result.channels; ++c) {
                unsigned char* dest = result.byte() + (x + y * result.width) * result.channels + c;
                const unsigned char* src = source.byte() + (x + y * source.width) * 2 * source.channels + c;
                int sum;
                if (x * 2 + 1 < source.width && y * 2 + 1 < source.height)
                    sum = src[stride] + src[source.channels] + src[0] + src[stride + source.channels];
                else
                    sum = src[0] * 4;
                *dest = (sum + 2) >> 2;
            }
    result.save(filename, GImage::PNG);
}
