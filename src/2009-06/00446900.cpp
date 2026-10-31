// from server: 88% by EspClaude
// from server: 100% by coldek
// roc 2008-06 0044a640  unit: CRbxPlayDocTemplate  size: 382 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044a640
//
// 0044a640  55                   push ebp
// 0044a641  8bec                 mov ebp, esp
// 0044a643  6aff                 push -1
// 0044a645  6848117c00           push 0x7c1148
// 0044a64a  64a100000000         mov eax, dword ptr fs:[0]
// 0044a650  50                   push eax
// 0044a651  64892500000000       mov dword ptr fs:[0], esp
// 0044a658  83ec1c               sub esp, 0x1c
// 0044a65b  53                   push ebx
// 0044a65c  56                   push esi
// 0044a65d  8b7508               mov esi, dword ptr [ebp + 8]
// 0044a660  57                   push edi
// 0044a661  8965f0               mov dword ptr [ebp - 0x10], esp
// 0044a664  33db                 xor ebx, ebx
// 0044a666  56                   push esi
// 0044a667  8d4dd8               lea ecx, [ebp - 0x28]
// 0044a66a  33ff                 xor edi, edi
// 0044a66c  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044a66f  e8acfcffff           call 0x44a320
// 0044a674  897dfc               mov dword ptr [ebp - 4], edi
// 0044a677  385ddc               cmp byte ptr [ebp - 0x24], bl
// 0044a67a  0f8465010000         je 0x44a7e5
// 0044a680  8b06                 mov eax, dword ptr [esi]
// 0044a682  8b4804               mov ecx, dword ptr [eax + 4]
// 0044a685  03ce                 add ecx, esi
// 0044a687  ff158c238000         call dword ptr [0x80238c]
// 0044a68d  83f801               cmp eax, 1
// 0044a690  7e10                 jle 0x44a6a2
// 0044a692  8b0e                 mov ecx, dword ptr [esi]
// 0044a694  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044a697  03ce                 add ecx, esi
// 0044a699  ff158c238000         call dword ptr [0x80238c]
// 0044a69f  8bf8                 mov edi, eax
// 0044a6a1  4f                   dec edi
// 0044a6a2  8b16                 mov edx, dword ptr [esi]
// 0044a6a4  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044a6a7  03ce                 add ecx, esi
// 0044a6a9  c645fc01             mov byte ptr [ebp - 4], 1
// 0044a6ad  ff1590238000         call dword ptr [0x802390]
// 0044a6b3  25c0010000           and eax, 0x1c0
// 0044a6b8  83f840               cmp eax, 0x40
// 0044a6bb  745b                 je 0x44a718
// 0044a6bd  8d4900               lea ecx, [ecx]
// 0044a6c0  85db                 test ebx, ebx
// 0044a6c2  0f85ed000000         jne 0x44a7b5
// 0044a6c8  85ff                 test edi, edi
// 0044a6ca  7e4c                 jle 0x44a718
// 0044a6cc  8b06                 mov eax, dword ptr [esi]
// 0044a6ce  8b4804               mov ecx, dword ptr [eax + 4]
// 0044a6d1  8a543130             mov dl, byte ptr [ecx + esi + 0x30]
// 0044a6d5  03ce                 add ecx, esi
// 0044a6d7  8855e8               mov byte ptr [ebp - 0x18], dl
// 0044a6da  ff15c4238000         call dword ptr [0x8023c4]
// 0044a6e0  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0044a6e3  51                   push ecx
// 0044a6e4  8bc8                 mov ecx, eax
// 0044a6e6  ff1594238000         call dword ptr [0x802394]
// 0044a6ec  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0044a6ef  ff1598238000         call dword ptr [0x802398]
// 0044a6f5  8d55e4               lea edx, [ebp - 0x1c]
// 0044a6f8  8945e0               mov dword ptr [ebp - 0x20], eax
// 0044a6fb  52                   push edx
// 0044a6fc  8d45e0               lea eax, [ebp - 0x20]
// 0044a6ff  50                   push eax
// 0044a700  ff159c238000         call dword ptr [0x80239c]
// 0044a706  83c408               add esp, 8
// 0044a709  84c0                 test al, al
// 0044a70b  7408                 je 0x44a715
// 0044a70d  bb04000000           mov ebx, 4
// 0044a712  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044a715  4f                   dec edi
// 0044a716  eba8                 jmp 0x44a6c0
// 0044a718  8b0e                 mov ecx, dword ptr [esi]
// 0044a71a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044a71d  03ce                 add ecx, esi
// 0044a71f  ff15c4238000         call dword ptr [0x8023c4]
// 0044a725  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0044a728  52                   push edx
// 0044a729  8bc8                 mov ecx, eax
// 0044a72b  ff1594238000         call dword ptr [0x802394]
// 0044a731  8945e0               mov dword ptr [ebp - 0x20], eax
// 0044a734  ff1598238000         call dword ptr [0x802398]
// 0044a73a  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0044a73d  8d45e0               lea eax, [ebp - 0x20]
// 0044a740  50                   push eax
// 0044a741  8d4de4               lea ecx, [ebp - 0x1c]
// 0044a744  51                   push ecx
// 0044a745  ff159c238000         call dword ptr [0x80239c]
// 0044a74b  83c408               add esp, 8
// 0044a74e  84c0                 test al, al
// 0044a750  740e                 je 0x44a760
// 0044a752  bb04000000           mov ebx, 4
// 0044a757  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044a75a  8d9b00000000         lea ebx, [ebx]
// 0044a760  85db                 test ebx, ebx
// 0044a762  7551                 jne 0x44a7b5
// 0044a764  85ff                 test edi, edi
// 0044a766  7e4d                 jle 0x44a7b5
// 0044a768  8b16                 mov edx, dword ptr [esi]
// 0044a76a  8b4204               mov eax, dword ptr [edx + 4]
// 0044a76d  8a543030             mov dl, byte ptr [eax + esi + 0x30]
// 0044a771  8d0c30               lea ecx, [eax + esi]
// 0044a774  8855e0               mov byte ptr [ebp - 0x20], dl
// 0044a777  ff15c4238000         call dword ptr [0x8023c4]
// 0044a77d  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 0044a780  51                   push ecx
// 0044a781  8bc8                 mov ecx, eax
// 0044a783  ff1594238000         call dword ptr [0x802394]
// 0044a789  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0044a78c  ff1598238000         call dword ptr [0x802398]
// 0044a792  8d55e4               lea edx, [ebp - 0x1c]
// 0044a795  8945e8               mov dword ptr [ebp - 0x18], eax
// 0044a798  52                   push edx
// 0044a799  8d45e8               lea eax, [ebp - 0x18]
// 0044a79c  50                   push eax
// 0044a79d  ff159c238000         call dword ptr [0x80239c]
// 0044a7a3  83c408               add esp, 8
// 0044a7a6  84c0                 test al, al
// 0044a7a8  7408                 je 0x44a7b2
// 0044a7aa  bb04000000           mov ebx, 4
// 0044a7af  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044a7b2  4f                   dec edi
// 0044a7b3  ebab                 jmp 0x44a760
// 0044a7b5  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0044a7bc  eb27                 jmp 0x44a7e5

// from server: 100% by colin
// roc 2008-06 0044a640  unit: CRbxPlayDocTemplate  size: 382 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044a640
//
// 0044a640  55                   push ebp
// 0044a641  8bec                 mov ebp, esp
// 0044a643  6aff                 push -1
// 0044a645  6848117c00           push 0x7c1148
// 0044a64a  64a100000000         mov eax, dword ptr fs:[0]
// 0044a650  50                   push eax
// 0044a651  64892500000000       mov dword ptr fs:[0], esp
// 0044a658  83ec1c               sub esp, 0x1c
// 0044a65b  53                   push ebx
// 0044a65c  56                   push esi
// 0044a65d  8b7508               mov esi, dword ptr [ebp + 8]
// 0044a660  57                   push edi
// 0044a661  8965f0               mov dword ptr [ebp - 0x10], esp
// 0044a664  33db                 xor ebx, ebx
// 0044a666  56                   push esi
// 0044a667  8d4dd8               lea ecx, [ebp - 0x28]
// 0044a66a  33ff                 xor edi, edi
// 0044a66c  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044a66f  e8acfcffff           call 0x44a320
// 0044a674  897dfc               mov dword ptr [ebp - 4], edi
// 0044a677  385ddc               cmp byte ptr [ebp - 0x24], bl
// 0044a67a  0f8465010000         je 0x44a7e5
// 0044a680  8b06                 mov eax, dword ptr [esi]
// 0044a682  8b4804               mov ecx, dword ptr [eax + 4]
// 0044a685  03ce                 add ecx, esi
// 0044a687  ff158c238000         call dword ptr [0x80238c]
// 0044a68d  83f801               cmp eax, 1
// 0044a690  7e10                 jle 0x44a6a2
// 0044a692  8b0e                 mov ecx, dword ptr [esi]
// 0044a694  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044a697  03ce                 add ecx, esi
// 0044a699  ff158c238000         call dword ptr [0x80238c]
// 0044a69f  8bf8                 mov edi, eax
// 0044a6a1  4f                   dec edi
// 0044a6a2  8b16                 mov edx, dword ptr [esi]
// 0044a6a4  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044a6a7  03ce                 add ecx, esi
// 0044a6a9  c645fc01             mov byte ptr [ebp - 4], 1
// 0044a6ad  ff1590238000         call dword ptr [0x802390]
// 0044a6b3  25c0010000           and eax, 0x1c0
// 0044a6b8  83f840               cmp eax, 0x40
// 0044a6bb  745b                 je 0x44a718
// 0044a6bd  8d4900               lea ecx, [ecx]
// 0044a6c0  85db                 test ebx, ebx
// 0044a6c2  0f85ed000000         jne 0x44a7b5
// 0044a6c8  85ff                 test edi, edi
// 0044a6ca  7e4c                 jle 0x44a718
// 0044a6cc  8b06                 mov eax, dword ptr [esi]
// 0044a6ce  8b4804               mov ecx, dword ptr [eax + 4]
// 0044a6d1  8a543130             mov dl, byte ptr [ecx + esi + 0x30]
// 0044a6d5  03ce                 add ecx, esi
// 0044a6d7  8855e8               mov byte ptr [ebp - 0x18], dl
// 0044a6da  ff15c4238000         call dword ptr [0x8023c4]
// 0044a6e0  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0044a6e3  51                   push ecx
// 0044a6e4  8bc8                 mov ecx, eax
// 0044a6e6  ff1594238000         call dword ptr [0x802394]
// 0044a6ec  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0044a6ef  ff1598238000         call dword ptr [0x802398]
// 0044a6f5  8d55e4               lea edx, [ebp - 0x1c]
// 0044a6f8  8945e0               mov dword ptr [ebp - 0x20], eax
// 0044a6fb  52                   push edx
// 0044a6fc  8d45e0               lea eax, [ebp - 0x20]
// 0044a6ff  50                   push eax
// 0044a700  ff159c238000         call dword ptr [0x80239c]
// 0044a706  83c408               add esp, 8
// 0044a709  84c0                 test al, al
// 0044a70b  7408                 je 0x44a715
// 0044a70d  bb04000000           mov ebx, 4
// 0044a712  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044a715  4f                   dec edi
// 0044a716  eba8                 jmp 0x44a6c0
// 0044a718  8b0e                 mov ecx, dword ptr [esi]
// 0044a71a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044a71d  03ce                 add ecx, esi
// 0044a71f  ff15c4238000         call dword ptr [0x8023c4]
// 0044a725  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0044a728  52                   push edx
// 0044a729  8bc8                 mov ecx, eax
// 0044a72b  ff1594238000         call dword ptr [0x802394]
// 0044a731  8945e0               mov dword ptr [ebp - 0x20], eax
// 0044a734  ff1598238000         call dword ptr [0x802398]
// 0044a73a  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0044a73d  8d45e0               lea eax, [ebp - 0x20]
// 0044a740  50                   push eax
// 0044a741  8d4de4               lea ecx, [ebp - 0x1c]
// 0044a744  51                   push ecx
// 0044a745  ff159c238000         call dword ptr [0x80239c]
// 0044a74b  83c408               add esp, 8
// 0044a74e  84c0                 test al, al
// 0044a750  740e                 je 0x44a760
// 0044a752  bb04000000           mov ebx, 4
// 0044a757  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044a75a  8d9b00000000         lea ebx, [ebx]
// 0044a760  85db                 test ebx, ebx
// 0044a762  7551                 jne 0x44a7b5
// 0044a764  85ff                 test edi, edi
// 0044a766  7e4d                 jle 0x44a7b5
// 0044a768  8b16                 mov edx, dword ptr [esi]
// 0044a76a  8b4204               mov eax, dword ptr [edx + 4]
// 0044a76d  8a543030             mov dl, byte ptr [eax + esi + 0x30]
// 0044a771  8d0c30               lea ecx, [eax + esi]
// 0044a774  8855e0               mov byte ptr [ebp - 0x20], dl
// 0044a777  ff15c4238000         call dword ptr [0x8023c4]
// 0044a77d  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 0044a780  51                   push ecx
// 0044a781  8bc8                 mov ecx, eax
// 0044a783  ff1594238000         call dword ptr [0x802394]
// 0044a789  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0044a78c  ff1598238000         call dword ptr [0x802398]
// 0044a792  8d55e4               lea edx, [ebp - 0x1c]
// 0044a795  8945e8               mov dword ptr [ebp - 0x18], eax
// 0044a798  52                   push edx
// 0044a799  8d45e8               lea eax, [ebp - 0x18]
// 0044a79c  50                   push eax
// 0044a79d  ff159c238000         call dword ptr [0x80239c]
// 0044a7a3  83c408               add esp, 8
// 0044a7a6  84c0                 test al, al
// 0044a7a8  7408                 je 0x44a7b2
// 0044a7aa  bb04000000           mov ebx, 4
// 0044a7af  895dec               mov dword ptr [ebp - 0x14], ebx
// 0044a7b2  4f                   dec edi
// 0044a7b3  ebab                 jmp 0x44a760
// 0044a7b5  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0044a7bc  eb27                 jmp 0x44a7e5

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
