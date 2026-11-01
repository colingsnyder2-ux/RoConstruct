// from server: 100% by Yeetserama
// roc 2012-06 004379a0  unit: VCMDIFrameWnd::?$CXTPCommandBarsSiteBase  size: 486 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004379a0
//
// 004379a0  55                   push ebp
// 004379a1  8bec                 mov ebp, esp
// 004379a3  6aff                 push -1
// 004379a5  68a8d3a900           push 0xa9d3a8
// 004379aa  64a100000000         mov eax, dword ptr fs:[0]
// 004379b0  50                   push eax
// 004379b1  64892500000000       mov dword ptr fs:[0], esp
// 004379b8  83ec1c               sub esp, 0x1c
// 004379bb  53                   push ebx
// 004379bc  56                   push esi
// 004379bd  8b7508               mov esi, dword ptr [ebp + 8]
// 004379c0  57                   push edi
// 004379c1  8965f0               mov dword ptr [ebp - 0x10], esp
// 004379c4  33db                 xor ebx, ebx
// 004379c6  56                   push esi
// 004379c7  8d4dd8               lea ecx, [ebp - 0x28]
// 004379ca  33ff                 xor edi, edi
// 004379cc  895dec               mov dword ptr [ebp - 0x14], ebx
// 004379cf  e8dcfdffff           call 0x4377b0
// 004379d4  897dfc               mov dword ptr [ebp - 4], edi
// 004379d7  385ddc               cmp byte ptr [ebp - 0x24], bl
// 004379da  0f8465010000         je 0x437b45
// 004379e0  8b06                 mov eax, dword ptr [esi]
// 004379e2  8b4804               mov ecx, dword ptr [eax + 4]
// 004379e5  03ce                 add ecx, esi
// 004379e7  ff154827b200         call dword ptr [0xb22748]
// 004379ed  83f801               cmp eax, 1
// 004379f0  7e10                 jle 0x437a02
// 004379f2  8b0e                 mov ecx, dword ptr [esi]
// 004379f4  8b4904               mov ecx, dword ptr [ecx + 4]
// 004379f7  03ce                 add ecx, esi
// 004379f9  ff154827b200         call dword ptr [0xb22748]
// 004379ff  8bf8                 mov edi, eax
// 00437a01  4f                   dec edi
// 00437a02  8b16                 mov edx, dword ptr [esi]
// 00437a04  8b4a04               mov ecx, dword ptr [edx + 4]
// 00437a07  03ce                 add ecx, esi
// 00437a09  c645fc01             mov byte ptr [ebp - 4], 1
// 00437a0d  ff154427b200         call dword ptr [0xb22744]
// 00437a13  25c0010000           and eax, 0x1c0
// 00437a18  83f840               cmp eax, 0x40
// 00437a1b  745b                 je 0x437a78
// 00437a1d  8d4900               lea ecx, [ecx]
// 00437a20  85db                 test ebx, ebx
// 00437a22  0f85ed000000         jne 0x437b15
// 00437a28  85ff                 test edi, edi
// 00437a2a  7e4c                 jle 0x437a78
// 00437a2c  8b06                 mov eax, dword ptr [esi]
// 00437a2e  8b4804               mov ecx, dword ptr [eax + 4]
// 00437a31  8a543130             mov dl, byte ptr [ecx + esi + 0x30]
// 00437a35  03ce                 add ecx, esi
// 00437a37  8855e8               mov byte ptr [ebp - 0x18], dl
// 00437a3a  ff151427b200         call dword ptr [0xb22714]
// 00437a40  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 00437a43  51                   push ecx
// 00437a44  8bc8                 mov ecx, eax
// 00437a46  ff154027b200         call dword ptr [0xb22740]
// 00437a4c  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00437a4f  ff153c27b200         call dword ptr [0xb2273c]
// 00437a55  8d55e4               lea edx, [ebp - 0x1c]
// 00437a58  8945e0               mov dword ptr [ebp - 0x20], eax
// 00437a5b  52                   push edx
// 00437a5c  8d45e0               lea eax, [ebp - 0x20]
// 00437a5f  50                   push eax
// 00437a60  ff153827b200         call dword ptr [0xb22738]
// 00437a66  83c408               add esp, 8
// 00437a69  84c0                 test al, al
// 00437a6b  7408                 je 0x437a75
// 00437a6d  bb04000000           mov ebx, 4
// 00437a72  895dec               mov dword ptr [ebp - 0x14], ebx
// 00437a75  4f                   dec edi
// 00437a76  eba8                 jmp 0x437a20
// 00437a78  8b0e                 mov ecx, dword ptr [esi]
// 00437a7a  8b4904               mov ecx, dword ptr [ecx + 4]
// 00437a7d  03ce                 add ecx, esi
// 00437a7f  ff151427b200         call dword ptr [0xb22714]
// 00437a85  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00437a88  52                   push edx
// 00437a89  8bc8                 mov ecx, eax
// 00437a8b  ff154027b200         call dword ptr [0xb22740]
// 00437a91  8945e0               mov dword ptr [ebp - 0x20], eax
// 00437a94  ff153c27b200         call dword ptr [0xb2273c]
// 00437a9a  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00437a9d  8d45e0               lea eax, [ebp - 0x20]
// 00437aa0  50                   push eax
// 00437aa1  8d4de4               lea ecx, [ebp - 0x1c]
// 00437aa4  51                   push ecx
// 00437aa5  ff153827b200         call dword ptr [0xb22738]
// 00437aab  83c408               add esp, 8
// 00437aae  84c0                 test al, al
// 00437ab0  740e                 je 0x437ac0
// 00437ab2  bb04000000           mov ebx, 4
// 00437ab7  895dec               mov dword ptr [ebp - 0x14], ebx
// 00437aba  8d9b00000000         lea ebx, [ebx]
// 00437ac0  85db                 test ebx, ebx
// 00437ac2  7551                 jne 0x437b15
// 00437ac4  85ff                 test edi, edi
// 00437ac6  7e4d                 jle 0x437b15
// 00437ac8  8b16                 mov edx, dword ptr [esi]
// 00437aca  8b4204               mov eax, dword ptr [edx + 4]
// 00437acd  8a543030             mov dl, byte ptr [eax + esi + 0x30]
// 00437ad1  8d0c30               lea ecx, [eax + esi]
// 00437ad4  8855e0               mov byte ptr [ebp - 0x20], dl
// 00437ad7  ff151427b200         call dword ptr [0xb22714]
// 00437add  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 00437ae0  51                   push ecx
// 00437ae1  8bc8                 mov ecx, eax
// 00437ae3  ff154027b200         call dword ptr [0xb22740]
// 00437ae9  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00437aec  ff153c27b200         call dword ptr [0xb2273c]
// 00437af2  8d55e4               lea edx, [ebp - 0x1c]
// 00437af5  8945e8               mov dword ptr [ebp - 0x18], eax
// 00437af8  52                   push edx
// 00437af9  8d45e8               lea eax, [ebp - 0x18]
// 00437afc  50                   push eax
// 00437afd  ff153827b200         call dword ptr [0xb22738]
// 00437b03  83c408               add esp, 8
// 00437b06  84c0                 test al, al
// 00437b08  7408                 je 0x437b12
// 00437b0a  bb04000000           mov ebx, 4
// 00437b0f  895dec               mov dword ptr [ebp - 0x14], ebx
// 00437b12  4f                   dec edi
// 00437b13  ebab                 jmp 0x437ac0
// 00437b15  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00437b1c  eb27                 jmp 0x437b45
// 00437b1e  8b4508               mov eax, dword ptr [ebp + 8]
// 00437b21  8b08                 mov ecx, dword ptr [eax]
// 00437b23  8b4904               mov ecx, dword ptr [ecx + 4]
// 00437b26  6a01                 push 1
// 00437b28  6a04                 push 4
// 00437b2a  03c8                 add ecx, eax
// 00437b2c  ff153427b200         call dword ptr [0xb22734]
// 00437b32  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00437b39  b83f7b4300           mov eax, 0x437b3f
// 00437b3e  c3                   ret 
// 00437b3f  8b7508               mov esi, dword ptr [ebp + 8]
// 00437b42  8b5dec               mov ebx, dword ptr [ebp - 0x14]
// 00437b45  8b16                 mov edx, dword ptr [esi]
// 00437b47  8b4a04               mov ecx, dword ptr [edx + 4]
// 00437b4a  6a00                 push 0
// 00437b4c  03ce                 add ecx, esi
// 00437b4e  ff153027b200         call dword ptr [0xb22730]
// 00437b54  8b06                 mov eax, dword ptr [esi]
// 00437b56  8b4804               mov ecx, dword ptr [eax + 4]
// 00437b59  6a00                 push 0
// 00437b5b  53                   push ebx
// 00437b5c  03ce                 add ecx, esi
// 00437b5e  ff153427b200         call dword ptr [0xb22734]
// 00437b64  8d4dd8               lea ecx, [ebp - 0x28]
// 00437b67  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 00437b6e  e8edfcffff           call 0x437860
// 00437b73  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00437b76  5f                   pop edi
// 00437b77  8bc6                 mov eax, esi
// 00437b79  5e                   pop esi
// 00437b7a  64890d00000000       mov dword ptr fs:[0], ecx
// 00437b81  5b                   pop ebx
// 00437b82  8be5                 mov esp, ebp
// 00437b84  5d                   pop ebp
// 00437b85  c3                   ret 
// copied from an identical function in another client (function ?insert_character@ns_ROCX000001@@YAAAUStream@1@AAU21@D@Z)

namespace ns_ROCX000001 {
struct Buffer;
struct Stream;

struct IOS {
    char reserved[0x30];
    char fill;

    __declspec(dllimport) void setstate(int, bool = false);
    __declspec(dllimport) void width(int);
};

struct Stream : virtual IOS {
    struct Sentry {
        Stream *stream;
        bool ready;
        Sentry(Stream *);
        ~Sentry();
    };
};

extern int (__thiscall *get_width)(const IOS *);
extern int (__thiscall *get_flags)(const IOS *);
extern Buffer *(__thiscall *get_buffer)(const IOS *);
extern int (__thiscall *put_character)(Buffer *, char);
extern int (__cdecl *end_of_file)();
extern bool (__cdecl *equal_int_type)(const int &, const int &);

#define STREAM_IOS \
    reinterpret_cast<IOS *>(reinterpret_cast<char *>(&stream) + \
                            (*reinterpret_cast<int **>(&stream))[1])

Stream &__cdecl insert_character(Stream &stream, char character)
{
    int state = 0;
    Stream::Sentry sentry(&stream);

    if (sentry.ready) {
        int padding = 0;
        if (get_width(STREAM_IOS) > 1)
            padding = get_width(STREAM_IOS) - 1;

        try {
            if ((get_flags(STREAM_IOS) & 0x1c0) != 0x40) {
                for (; !state && padding > 0; --padding) {
                    char fill = stream.fill;
                    int result = put_character(get_buffer(STREAM_IOS), fill);
                    int eof = end_of_file();
                    if (equal_int_type(eof, result))
                        state = 4;
                }
            }

            if (!state) {
                {
                    int result = put_character(get_buffer(STREAM_IOS), character);
                    int eof = end_of_file();
                    if (equal_int_type(eof, result))
                        state = 4;
                }

                for (; !state && padding > 0; --padding) {
                    char fill = STREAM_IOS->fill;
                    int result = put_character(get_buffer(STREAM_IOS), fill);
                    int eof = end_of_file();
                    if (equal_int_type(eof, result))
                        state = 4;
                }
            }
        }
        catch (...) {
            stream.setstate(4, true);
        }
    }

    stream.width(0);
    stream.setstate(state);
    return stream;
}

#undef STREAM_IOS
}
