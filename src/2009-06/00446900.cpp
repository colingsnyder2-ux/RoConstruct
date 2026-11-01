// from server: 100% by Yeetserama
// roc 2009-06 00446900  unit: CBrowserDocManager  size: 486 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00446900
//
// 00446900  55                   push ebp
// 00446901  8bec                 mov ebp, esp
// 00446903  6aff                 push -1
// 00446905  68c8078500           push 0x8507c8
// 0044690a  64a100000000         mov eax, dword ptr fs:[0]
// 00446910  50                   push eax
// 00446911  64892500000000       mov dword ptr fs:[0], esp
// 00446918  83ec1c               sub esp, 0x1c
// 0044691b  53                   push ebx
// 0044691c  56                   push esi
// 0044691d  8b7508               mov esi, dword ptr [ebp + 8]
// 00446920  57                   push edi
// 00446921  8965f0               mov dword ptr [ebp - 0x10], esp
// 00446924  33db                 xor ebx, ebx
// 00446926  56                   push esi
// 00446927  8d4dd8               lea ecx, [ebp - 0x28]
// 0044692a  33ff                 xor edi, edi
// 0044692c  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044692f  e87cfcffff           call 0x4465b0
// 00446934  897dfc               mov dword ptr [ebp - 4], edi
// 00446937  385ddc               cmp byte ptr [ebp - 0x24], bl
// 0044693a  0f8465010000         je 0x446aa5
// 00446940  8b06                 mov eax, dword ptr [esi]
// 00446942  8b4804               mov ecx, dword ptr [eax + 4]
// 00446945  03ce                 add ecx, esi
// 00446947  ff15e8e38900         call dword ptr [0x89e3e8]
// 0044694d  83f801               cmp eax, 1
// 00446950  7e10                 jle 0x446962
// 00446952  8b0e                 mov ecx, dword ptr [esi]
// 00446954  8b4904               mov ecx, dword ptr [ecx + 4]
// 00446957  03ce                 add ecx, esi
// 00446959  ff15e8e38900         call dword ptr [0x89e3e8]
// 0044695f  8bf8                 mov edi, eax
// 00446961  4f                   dec edi
// 00446962  8b16                 mov edx, dword ptr [esi]
// 00446964  8b4a04               mov ecx, dword ptr [edx + 4]
// 00446967  03ce                 add ecx, esi
// 00446969  c645fc01             mov byte ptr [ebp - 4], 1
// 0044696d  ff15ece38900         call dword ptr [0x89e3ec]
// 00446973  25c0010000           and eax, 0x1c0
// 00446978  83f840               cmp eax, 0x40
// 0044697b  745b                 je 0x4469d8
// 0044697d  8d4900               lea ecx, [ecx]
// 00446980  85db                 test ebx, ebx
// 00446982  0f85ed000000         jne 0x446a75
// 00446988  85ff                 test edi, edi
// 0044698a  7e4c                 jle 0x4469d8
// 0044698c  8b06                 mov eax, dword ptr [esi]
// 0044698e  8b4804               mov ecx, dword ptr [eax + 4]
// 00446991  8a543130             mov dl, byte ptr [ecx + esi + 0x30]
// 00446995  03ce                 add ecx, esi
// 00446997  8855e8               mov byte ptr [ebp - 0x18], dl
// 0044699a  ff1520e48900         call dword ptr [0x89e420]
// 004469a0  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 004469a3  51                   push ecx
// 004469a4  8bc8                 mov ecx, eax
// 004469a6  ff15f0e38900         call dword ptr [0x89e3f0]
// 004469ac  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004469af  ff15f4e38900         call dword ptr [0x89e3f4]
// 004469b5  8d55e4               lea edx, [ebp - 0x1c]
// 004469b8  8945e0               mov dword ptr [ebp - 0x20], eax
// 004469bb  52                   push edx
// 004469bc  8d45e0               lea eax, [ebp - 0x20]
// 004469bf  50                   push eax
// 004469c0  ff15f8e38900         call dword ptr [0x89e3f8]
// 004469c6  83c408               add esp, 8
// 004469c9  84c0                 test al, al
// 004469cb  7408                 je 0x4469d5
// 004469cd  bb04000000           mov ebx, 4
// 004469d2  895dec               mov dword ptr [ebp - 0x14], ebx
// 004469d5  4f                   dec edi
// 004469d6  eba8                 jmp 0x446980
// 004469d8  8b0e                 mov ecx, dword ptr [esi]
// 004469da  8b4904               mov ecx, dword ptr [ecx + 4]
// 004469dd  03ce                 add ecx, esi
// 004469df  ff1520e48900         call dword ptr [0x89e420]
// 004469e5  8b550c               mov edx, dword ptr [ebp + 0xc]
// 004469e8  52                   push edx
// 004469e9  8bc8                 mov ecx, eax
// 004469eb  ff15f0e38900         call dword ptr [0x89e3f0]
// 004469f1  8945e0               mov dword ptr [ebp - 0x20], eax
// 004469f4  ff15f4e38900         call dword ptr [0x89e3f4]
// 004469fa  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004469fd  8d45e0               lea eax, [ebp - 0x20]
// 00446a00  50                   push eax
// 00446a01  8d4de4               lea ecx, [ebp - 0x1c]
// 00446a04  51                   push ecx
// 00446a05  ff15f8e38900         call dword ptr [0x89e3f8]
// 00446a0b  83c408               add esp, 8
// 00446a0e  84c0                 test al, al
// 00446a10  740e                 je 0x446a20
// 00446a12  bb04000000           mov ebx, 4
// 00446a17  895dec               mov dword ptr [ebp - 0x14], ebx
// 00446a1a  8d9b00000000         lea ebx, [ebx]
// 00446a20  85db                 test ebx, ebx
// 00446a22  7551                 jne 0x446a75
// 00446a24  85ff                 test edi, edi
// 00446a26  7e4d                 jle 0x446a75
// 00446a28  8b16                 mov edx, dword ptr [esi]
// 00446a2a  8b4204               mov eax, dword ptr [edx + 4]
// 00446a2d  8a543030             mov dl, byte ptr [eax + esi + 0x30]
// 00446a31  8d0c30               lea ecx, [eax + esi]
// 00446a34  8855e0               mov byte ptr [ebp - 0x20], dl
// 00446a37  ff1520e48900         call dword ptr [0x89e420]
// 00446a3d  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 00446a40  51                   push ecx
// 00446a41  8bc8                 mov ecx, eax
// 00446a43  ff15f0e38900         call dword ptr [0x89e3f0]
// 00446a49  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00446a4c  ff15f4e38900         call dword ptr [0x89e3f4]
// 00446a52  8d55e4               lea edx, [ebp - 0x1c]
// 00446a55  8945e8               mov dword ptr [ebp - 0x18], eax
// 00446a58  52                   push edx
// 00446a59  8d45e8               lea eax, [ebp - 0x18]
// 00446a5c  50                   push eax
// 00446a5d  ff15f8e38900         call dword ptr [0x89e3f8]
// 00446a63  83c408               add esp, 8
// 00446a66  84c0                 test al, al
// 00446a68  7408                 je 0x446a72
// 00446a6a  bb04000000           mov ebx, 4
// 00446a6f  895dec               mov dword ptr [ebp - 0x14], ebx
// 00446a72  4f                   dec edi
// 00446a73  ebab                 jmp 0x446a20
// 00446a75  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00446a7c  eb27                 jmp 0x446aa5
// 00446a7e  8b4508               mov eax, dword ptr [ebp + 8]
// 00446a81  8b08                 mov ecx, dword ptr [eax]
// 00446a83  8b4904               mov ecx, dword ptr [ecx + 4]
// 00446a86  6a01                 push 1
// 00446a88  6a04                 push 4
// 00446a8a  03c8                 add ecx, eax
// 00446a8c  ff1504e48900         call dword ptr [0x89e404]
// 00446a92  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00446a99  b89f6a4400           mov eax, 0x446a9f
// 00446a9e  c3                   ret 
// 00446a9f  8b7508               mov esi, dword ptr [ebp + 8]
// 00446aa2  8b5dec               mov ebx, dword ptr [ebp - 0x14]
// 00446aa5  8b16                 mov edx, dword ptr [esi]
// 00446aa7  8b4a04               mov ecx, dword ptr [edx + 4]
// 00446aaa  6a00                 push 0
// 00446aac  03ce                 add ecx, esi
// 00446aae  ff1500e48900         call dword ptr [0x89e400]
// 00446ab4  8b06                 mov eax, dword ptr [esi]
// 00446ab6  8b4804               mov ecx, dword ptr [eax + 4]
// 00446ab9  6a00                 push 0
// 00446abb  53                   push ebx
// 00446abc  03ce                 add ecx, esi
// 00446abe  ff1504e48900         call dword ptr [0x89e404]
// 00446ac4  8d4dd8               lea ecx, [ebp - 0x28]
// 00446ac7  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 00446ace  e88dfbffff           call 0x446660
// 00446ad3  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00446ad6  5f                   pop edi
// 00446ad7  8bc6                 mov eax, esi
// 00446ad9  5e                   pop esi
// 00446ada  64890d00000000       mov dword ptr fs:[0], ecx
// 00446ae1  5b                   pop ebx
// 00446ae2  8be5                 mov esp, ebp
// 00446ae4  5d                   pop ebp
// 00446ae5  c3                   ret 
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
