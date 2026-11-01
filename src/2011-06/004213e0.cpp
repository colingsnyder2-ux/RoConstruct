// from server: 100% by colin
namespace ns_ROCX000000 {
// from server: 98% by king_originala
// roc 2008-06 0044a450  unit: CRbxPlayDocTemplate  size: 398 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044a450
//
// 0044a450  55                   push ebp
// 0044a451  8bec                 mov ebp, esp
// 0044a453  6aff                 push -1
// 0044a455  6828117c00           push 0x7c1128
// 0044a45a  64a100000000         mov eax, dword ptr fs:[0]
// 0044a460  50                   push eax
// 0044a461  64892500000000       mov dword ptr fs:[0], esp
// 0044a468  83ec1c               sub esp, 0x1c
// 0044a46b  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0044a46e  53                   push ebx
// 0044a46f  56                   push esi
// 0044a470  57                   push edi
// 0044a471  8965f0               mov dword ptr [ebp - 0x10], esp
// 0044a474  33ff                 xor edi, edi
// 0044a476  50                   push eax
// 0044a477  897dec               mov dword ptr [ebp - 0x14], edi
// 0044a47a  ff1588238000         call dword ptr [0x802388]
// 0044a480  8b7508               mov esi, dword ptr [ebp + 8]
// 0044a483  8b0e                 mov ecx, dword ptr [esi]
// 0044a485  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044a488  83c404               add esp, 4
// 0044a48b  03ce                 add ecx, esi
// 0044a48d  8bd8                 mov ebx, eax
// 0044a48f  ff158c238000         call dword ptr [0x80238c]
// 0044a495  85c0                 test eax, eax
// 0044a497  7e22                 jle 0x44a4bb
// 0044a499  8b16                 mov edx, dword ptr [esi]
// 0044a49b  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044a49e  03ce                 add ecx, esi
// 0044a4a0  ff158c238000         call dword ptr [0x80238c]
// 0044a4a6  3bc3                 cmp eax, ebx
// 0044a4a8  7e11                 jle 0x44a4bb
// 0044a4aa  8b06                 mov eax, dword ptr [esi]
// 0044a4ac  8b4804               mov ecx, dword ptr [eax + 4]
// 0044a4af  03ce                 add ecx, esi
// 0044a4b1  ff158c238000         call dword ptr [0x80238c]
// 0044a4b7  8bf8                 mov edi, eax
// 0044a4b9  2bfb                 sub edi, ebx
// 0044a4bb  56                   push esi
// 0044a4bc  8d4dd8               lea ecx, [ebp - 0x28]
// 0044a4bf  e85cfeffff           call 0x44a320
// 0044a4c4  807ddc00             cmp byte ptr [ebp - 0x24], 0
// 0044a4c8  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0044a4cf  750c                 jne 0x44a4dd
// 0044a4d1  c745ec04000000       mov dword ptr [ebp - 0x14], 4
// 0044a4d8  e925010000           jmp 0x44a602
// 0044a4dd  8b0e                 mov ecx, dword ptr [esi]
// 0044a4df  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044a4e2  03ce                 add ecx, esi
// 0044a4e4  c645fc01             mov byte ptr [ebp - 4], 1
// 0044a4e8  ff1590238000         call dword ptr [0x802390]
// 0044a4ee  25c0010000           and eax, 0x1c0
// 0044a4f3  83f840               cmp eax, 0x40
// 0044a4f6  7450                 je 0x44a548
// 0044a4f8  85ff                 test edi, edi
// 0044a4fa  7e46                 jle 0x44a542
// 0044a4fc  8b16                 mov edx, dword ptr [esi]
// 0044a4fe  8b4204               mov eax, dword ptr [edx + 4]
// 0044a501  8a543030             mov dl, byte ptr [eax + esi + 0x30]
// 0044a505  8d0c30               lea ecx, [eax + esi]
// 0044a508  8855e8               mov byte ptr [ebp - 0x18], dl
// 0044a50b  ff15c4238000         call dword ptr [0x8023c4]
// 0044a511  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0044a514  51                   push ecx
// 0044a515  8bc8                 mov ecx, eax
// 0044a517  ff1594238000         call dword ptr [0x802394]
// 0044a51d  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0044a520  ff1598238000         call dword ptr [0x802398]
// 0044a526  8d55e4               lea edx, [ebp - 0x1c]
// 0044a529  8945e0               mov dword ptr [ebp - 0x20], eax
// 0044a52c  52                   push edx
// 0044a52d  8d45e0               lea eax, [ebp - 0x20]
// 0044a530  50                   push eax
// 0044a531  ff159c238000         call dword ptr [0x80239c]
// 0044a537  83c408               add esp, 8
// 0044a53a  84c0                 test al, al
// 0044a53c  7447                 je 0x44a585
// 0044a53e  834dec04             or dword ptr [ebp - 0x14], 4
// 0044a542  837dec00             cmp dword ptr [ebp - 0x14], 0
// 0044a546  7525                 jne 0x44a56d
// 0044a548  8b0e                 mov ecx, dword ptr [esi]
// 0044a54a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044a54d  03ce                 add ecx, esi
// 0044a54f  ff15c4238000         call dword ptr [0x8023c4]
// 0044a555  8b550c               mov edx, dword ptr [ebp + 0xc]
// 0044a558  53                   push ebx
// 0044a559  52                   push edx
// 0044a55a  8bc8                 mov ecx, eax
// 0044a55c  ff15a0238000         call dword ptr [0x8023a0]
// 0044a562  3bc3                 cmp eax, ebx
// 0044a564  742a                 je 0x44a590
// 0044a566  c745ec04000000       mov dword ptr [ebp - 0x14], 4
// 0044a56d  8b0e                 mov ecx, dword ptr [esi]
// 0044a56f  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044a572  6a00                 push 0
// 0044a574  03ce                 add ecx, esi
// 0044a576  ff15a4238000         call dword ptr [0x8023a4]
// 0044a57c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0044a583  eb7d                 jmp 0x44a602
// 0044a585  4f                   dec edi
// 0044a586  e96dffffff           jmp 0x44a4f8
// 0044a58b  eb03                 jmp 0x44a590
// 0044a58d  8d4900               lea ecx, [ecx]
// 0044a590  85ff                 test edi, edi
// 0044a592  7ed9                 jle 0x44a56d
// 0044a594  8b06                 mov eax, dword ptr [esi]
// 0044a596  8b4804               mov ecx, dword ptr [eax + 4]
// 0044a599  8a543130             mov dl, byte ptr [ecx + esi + 0x30]
// 0044a59d  03ce                 add ecx, esi
// 0044a59f  8855e0               mov byte ptr [ebp - 0x20], dl
// 0044a5a2  ff15c4238000         call dword ptr [0x8023c4]
// 0044a5a8  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 0044a5ab  51                   push ecx
// 0044a5ac  8bc8                 mov ecx, eax
// 0044a5ae  ff1594238000         call dword ptr [0x802394]
// 0044a5b4  8945e4               mov dword ptr [ebp - 0x1c], eax
// 0044a5b7  ff1598238000         call dword ptr [0x802398]
// 0044a5bd  8d55e4               lea edx, [ebp - 0x1c]
// 0044a5c0  8945e8               mov dword ptr [ebp - 0x18], eax
// 0044a5c3  52                   push edx
// 0044a5c4  8d45e8               lea eax, [ebp - 0x18]
// 0044a5c7  50                   push eax
// 0044a5c8  ff159c238000         call dword ptr [0x80239c]
// 0044a5ce  83c408               add esp, 8
// 0044a5d1  84c0                 test al, al
// 0044a5d3  7406                 je 0x44a5db
// 0044a5d5  834dec04             or dword ptr [ebp - 0x14], 4
// 0044a5d9  eb92                 jmp 0x44a56d
// 0044a5db  4f                   dec edi
// 0044a5dc  ebb2                 jmp 0x44a590

#pragma optimize("y", off)

namespace std {
    template<class C> struct char_traits;

    template<> struct char_traits<char> {
        static unsigned int (__cdecl *length)(const char*);
        static int (__cdecl *eof)();
        static bool (__cdecl *eq_int_type)(const int&, const int&);
    };

    struct ios_base {
        int width() const;
        __declspec(dllimport) int width(int);
        int flags() const;
    };

    template<class C, class T> struct basic_streambuf {
        int sputc(C);
        int sputn(const C*, int);
    };

    template<class C, class T> struct basic_ios : ios_base {
        char reserved[48];
        C fill_character;

        basic_streambuf<C, T>* rdbuf() const;
        __declspec(dllimport) void setstate(int, bool = false);
    };

    template<class C, class T> struct basic_ostream
        : virtual basic_ios<C, T> {
        struct sentry {
            basic_ostream* stream;
            bool ready;

            explicit sentry(basic_ostream&);
            ~sentry();
        };
    };
}

typedef std::char_traits<char> Traits;
typedef std::basic_streambuf<char, Traits> Buffer;
typedef std::basic_ios<char, Traits> IOS;
typedef std::basic_ostream<char, Traits> Stream;

extern int (__thiscall *import_width_get)(const std::ios_base*);
extern int (__thiscall *import_flags)(const std::ios_base*);
extern Buffer* (__thiscall *import_rdbuf)(const IOS*);
extern int (__thiscall *import_sputc)(Buffer*, char);
extern int (__thiscall *import_sputn)(Buffer*, const char*, int);

inline int std::ios_base::width() const
{
    return import_width_get(this);
}

inline int std::ios_base::flags() const
{
    return import_flags(this);
}

template<>
inline Buffer* std::basic_ios<char, Traits>::rdbuf() const
{
    return import_rdbuf(this);
}

template<>
inline int std::basic_streambuf<char, Traits>::sputc(char value)
{
    return import_sputc(this, value);
}

template<>
inline int std::basic_streambuf<char, Traits>::sputn(const char* text, int count)
{
    return import_sputn(this, text, count);
}

Stream& __cdecl insert(Stream& stream, const char* text)
{
    int state = 0;
    int length = Traits::length(text);
    int padding = 0;

    if (stream.width() > 0 && stream.width() > length)
        padding = stream.width() - length;

    Stream::sentry guard(stream);
    if (!guard.ready) {
        state = 4;
    } else {
        try {
            if ((stream.flags() & 0x1c0) != 0x40) {
                for (; padding > 0; --padding) {
                    char fill = stream.fill_character;
                    int result = stream.rdbuf()->sputc(fill);
                    int end = Traits::eof();
                    if (Traits::eq_int_type(end, result)) {
                        state |= 4;
                        break;
                    }
                }
            }

            if (state == 0) {
                if (stream.rdbuf()->sputn(text, length) != length) {
                    state = 4;
                } else {
                    for (; padding > 0; --padding) {
                        char fill = stream.fill_character;
                        int result = stream.rdbuf()->sputc(fill);
                        int end = Traits::eof();
                        if (Traits::eq_int_type(end, result)) {
                            state |= 4;
                            break;
                        }
                    }
                }
            }

            stream.width(0);
        } catch (...) {
            stream.setstate(4, true);
        }
    }

    stream.setstate(state);
    return stream;
}
}
