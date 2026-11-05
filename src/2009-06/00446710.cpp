// from server: 100% by Yeetserama
// roc 2009-06 00446710  unit: CBrowserDocManager  size: 487 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00446710
//
// 00446710  55                   push ebp
// 00446711  8bec                 mov ebp, esp
// 00446713  6aff                 push -1
// 00446715  68a8078500           push 0x8507a8
// 0044671a  64a100000000         mov eax, dword ptr fs:[0]
// 00446720  50                   push eax
// 00446721  64892500000000       mov dword ptr fs:[0], esp
// 00446728  83ec1c               sub esp, 0x1c
// 0044672b  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0044672e  53                   push ebx
// 0044672f  56                   push esi
// 00446730  57                   push edi
// 00446731  8965f0               mov dword ptr [ebp - 0x10], esp
// 00446734  33ff                 xor edi, edi
// 00446736  50                   push eax
// 00446737  897dec               mov dword ptr [ebp - 0x14], edi
// 0044673a  ff15e4e38900         call dword ptr [0x89e3e4]
// 00446740  8b7508               mov esi, dword ptr [ebp + 8]
// 00446743  8b0e                 mov ecx, dword ptr [esi]
// 00446745  8b4904               mov ecx, dword ptr [ecx + 4]
// 00446748  83c404               add esp, 4
// 0044674b  03ce                 add ecx, esi
// 0044674d  8bd8                 mov ebx, eax
// 0044674f  ff15e8e38900         call dword ptr [0x89e3e8]
// 00446755  85c0                 test eax, eax
// 00446757  7e22                 jle 0x44677b
// 00446759  8b16                 mov edx, dword ptr [esi]
// 0044675b  8b4a04               mov ecx, dword ptr [edx + 4]
// 0044675e  03ce                 add ecx, esi
// 00446760  ff15e8e38900         call dword ptr [0x89e3e8]
// 00446766  3bc3                 cmp eax, ebx
// 00446768  7e11                 jle 0x44677b
// 0044676a  8b06                 mov eax, dword ptr [esi]
// 0044676c  8b4804               mov ecx, dword ptr [eax + 4]
// 0044676f  03ce                 add ecx, esi
// 00446771  ff15e8e38900         call dword ptr [0x89e3e8]
// 00446777  8bf8                 mov edi, eax
// 00446779  2bfb                 sub edi, ebx
// 0044677b  56                   push esi
// 0044677c  8d4dd8               lea ecx, [ebp - 0x28]
// 0044677f  e82cfeffff           call 0x4465b0
// 00446784  807ddc00             cmp byte ptr [ebp - 0x24], 0
// 00446788  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0044678f  750c                 jne 0x44679d
// 00446791  c745ec04000000       mov dword ptr [ebp - 0x14], 4
// 00446798  e925010000           jmp 0x4468c2
// 0044679d  8b0e                 mov ecx, dword ptr [esi]
// 0044679f  8b4904               mov ecx, dword ptr [ecx + 4]
// 004467a2  03ce                 add ecx, esi
// 004467a4  c645fc01             mov byte ptr [ebp - 4], 1
// 004467a8  ff15ece38900         call dword ptr [0x89e3ec]
// 004467ae  25c0010000           and eax, 0x1c0
// 004467b3  83f840               cmp eax, 0x40
// 004467b6  7450                 je 0x446808
// 004467b8  85ff                 test edi, edi
// 004467ba  7e46                 jle 0x446802
// 004467bc  8b16                 mov edx, dword ptr [esi]
// 004467be  8b4204               mov eax, dword ptr [edx + 4]
// 004467c1  8a543030             mov dl, byte ptr [eax + esi + 0x30]
// 004467c5  8d0c30               lea ecx, [eax + esi]
// 004467c8  8855e8               mov byte ptr [ebp - 0x18], dl
// 004467cb  ff1520e48900         call dword ptr [0x89e420]
// 004467d1  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 004467d4  51                   push ecx
// 004467d5  8bc8                 mov ecx, eax
// 004467d7  ff15f0e38900         call dword ptr [0x89e3f0]
// 004467dd  8945e4               mov dword ptr [ebp - 0x1c], eax
// 004467e0  ff15f4e38900         call dword ptr [0x89e3f4]
// 004467e6  8d55e4               lea edx, [ebp - 0x1c]
// 004467e9  8945e0               mov dword ptr [ebp - 0x20], eax
// 004467ec  52                   push edx
// 004467ed  8d45e0               lea eax, [ebp - 0x20]
// 004467f0  50                   push eax
// 004467f1  ff15f8e38900         call dword ptr [0x89e3f8]
// 004467f7  83c408               add esp, 8
// 004467fa  84c0                 test al, al
// 004467fc  7447                 je 0x446845
// 004467fe  834dec04             or dword ptr [ebp - 0x14], 4
// 00446802  837dec00             cmp dword ptr [ebp - 0x14], 0
// 00446806  7525                 jne 0x44682d
// 00446808  8b0e                 mov ecx, dword ptr [esi]
// 0044680a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0044680d  03ce                 add ecx, esi
// 0044680f  ff1520e48900         call dword ptr [0x89e420]
// 00446815  8b550c               mov edx, dword ptr [ebp + 0xc]
// 00446818  53                   push ebx
// 00446819  52                   push edx
// 0044681a  8bc8                 mov ecx, eax
// 0044681c  ff15fce38900         call dword ptr [0x89e3fc]
// 00446822  3bc3                 cmp eax, ebx
// 00446824  742a                 je 0x446850
// 00446826  c745ec04000000       mov dword ptr [ebp - 0x14], 4
// 0044682d  8b0e                 mov ecx, dword ptr [esi]
// 0044682f  8b4904               mov ecx, dword ptr [ecx + 4]
// 00446832  6a00                 push 0
// 00446834  03ce                 add ecx, esi
// 00446836  ff1500e48900         call dword ptr [0x89e400]
// 0044683c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00446843  eb7d                 jmp 0x4468c2
// 00446845  4f                   dec edi
// 00446846  e96dffffff           jmp 0x4467b8
// 0044684b  eb03                 jmp 0x446850
// 0044684d  8d4900               lea ecx, [ecx]
// 00446850  85ff                 test edi, edi
// 00446852  7ed9                 jle 0x44682d
// 00446854  8b06                 mov eax, dword ptr [esi]
// 00446856  8b4804               mov ecx, dword ptr [eax + 4]
// 00446859  8a543130             mov dl, byte ptr [ecx + esi + 0x30]
// 0044685d  03ce                 add ecx, esi
// 0044685f  8855e0               mov byte ptr [ebp - 0x20], dl
// 00446862  ff1520e48900         call dword ptr [0x89e420]
// 00446868  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 0044686b  51                   push ecx
// 0044686c  8bc8                 mov ecx, eax
// 0044686e  ff15f0e38900         call dword ptr [0x89e3f0]
// 00446874  8945e4               mov dword ptr [ebp - 0x1c], eax
// 00446877  ff15f4e38900         call dword ptr [0x89e3f4]
// 0044687d  8d55e4               lea edx, [ebp - 0x1c]
// 00446880  8945e8               mov dword ptr [ebp - 0x18], eax
// 00446883  52                   push edx
// 00446884  8d45e8               lea eax, [ebp - 0x18]
// 00446887  50                   push eax
// 00446888  ff15f8e38900         call dword ptr [0x89e3f8]
// 0044688e  83c408               add esp, 8
// 00446891  84c0                 test al, al
// 00446893  7406                 je 0x44689b
// 00446895  834dec04             or dword ptr [ebp - 0x14], 4
// 00446899  eb92                 jmp 0x44682d
// 0044689b  4f                   dec edi
// 0044689c  ebb2                 jmp 0x446850
// 0044689e  8b4508               mov eax, dword ptr [ebp + 8]
// 004468a1  8b10                 mov edx, dword ptr [eax]
// 004468a3  8b4a04               mov ecx, dword ptr [edx + 4]
// 004468a6  6a01                 push 1
// 004468a8  6a04                 push 4
// 004468aa  03c8                 add ecx, eax
// 004468ac  ff1504e48900         call dword ptr [0x89e404]
// 004468b2  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004468b9  b8bf684400           mov eax, 0x4468bf
// 004468be  c3                   ret 
// 004468bf  8b7508               mov esi, dword ptr [ebp + 8]
// 004468c2  8b0e                 mov ecx, dword ptr [esi]
// 004468c4  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 004468c7  8b4904               mov ecx, dword ptr [ecx + 4]
// 004468ca  6a00                 push 0
// 004468cc  50                   push eax
// 004468cd  03ce                 add ecx, esi
// 004468cf  ff1504e48900         call dword ptr [0x89e404]
// 004468d5  8d4dd8               lea ecx, [ebp - 0x28]
// 004468d8  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 004468df  e87cfdffff           call 0x446660
// 004468e4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004468e7  5f                   pop edi
// 004468e8  8bc6                 mov eax, esi
// 004468ea  5e                   pop esi
// 004468eb  64890d00000000       mov dword ptr fs:[0], ecx
// 004468f2  5b                   pop ebx
// 004468f3  8be5                 mov esp, ebp
// 004468f5  5d                   pop ebp
// 004468f6  c3                   ret 
// copied from an identical function in another client (function ?insert@ns_ROCX000000@@YAAAU?$basic_ostream@DU?$char_traits@D@std@ns_ROCX000000@@@std@1@AAU231@PBD@Z)

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
