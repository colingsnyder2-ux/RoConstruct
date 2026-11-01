// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005f6450  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 390 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f6450
//
// 005f6450  83ec10               sub esp, 0x10
// 005f6453  53                   push ebx
// 005f6454  55                   push ebp
// 005f6455  56                   push esi
// 005f6456  57                   push edi
// 005f6457  8bf9                 mov edi, ecx
// 005f6459  8b07                 mov eax, dword ptr [edi]
// 005f645b  f6402401             test byte ptr [eax + 0x24], 1
// 005f645f  7512                 jne 0x5f6473
// 005f6461  83482401             or dword ptr [eax + 0x24], 1
// 005f6465  8b07                 mov eax, dword ptr [edi]
// 005f6467  8b4814               mov ecx, dword ptr [eax + 0x14]
// 005f646a  83c014               add eax, 0x14
// 005f646d  894808               mov dword ptr [eax + 8], ecx
// 005f6470  89480c               mov dword ptr [eax + 0xc], ecx
// 005f6473  8b07                 mov eax, dword ptr [edi]
// 005f6475  8b7024               mov esi, dword ptr [eax + 0x24]
// 005f6478  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005f647c  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 005f6480  c1ee02               shr esi, 2
// 005f6483  f7d6                 not esi
// 005f6485  83e601               and esi, 1
// 005f6488  894c2410             mov dword ptr [esp + 0x10], ecx
// 005f648c  03ca                 add ecx, edx
// 005f648e  8d6820               lea ebp, [eax + 0x20]
// 005f6491  83ce04               or esi, 4
// 005f6494  83c01c               add eax, 0x1c
// 005f6497  894c2418             mov dword ptr [esp + 0x18], ecx
// 005f649b  896c241c             mov dword ptr [esp + 0x1c], ebp
// 005f649f  89442414             mov dword ptr [esp + 0x14], eax
// 005f64a3  8b442414             mov eax, dword ptr [esp + 0x14]
// 005f64a7  8b00                 mov eax, dword ptr [eax]
// 005f64a9  8b4d00               mov ecx, dword ptr [ebp]
// 005f64ac  83fe04               cmp esi, 4
// 005f64af  0f94c3               sete bl
// 005f64b2  3bc1                 cmp eax, ecx
// 005f64b4  7504                 jne 0x5f64ba
// 005f64b6  84db                 test bl, bl
// 005f64b8  7470                 je 0x5f652a
// 005f64ba  8b542418             mov edx, dword ptr [esp + 0x18]
// 005f64be  8b2f                 mov ebp, dword ptr [edi]
// 005f64c0  52                   push edx
// 005f64c1  89442430             mov dword ptr [esp + 0x30], eax
// 005f64c5  8d442414             lea eax, [esp + 0x14]
// 005f64c9  50                   push eax
// 005f64ca  51                   push ecx
// 005f64cb  8d4c2438             lea ecx, [esp + 0x38]
// 005f64cf  51                   push ecx
// 005f64d0  8bcd                 mov ecx, ebp
// 005f64d2  e8b9750500           call 0x64da90
// 005f64d7  a128b28400           mov eax, dword ptr [0x84b228]
// 005f64dc  84db                 test bl, bl
// 005f64de  7505                 jne 0x5f64e5
// 005f64e0  a12cb28400           mov eax, dword ptr [0x84b22c]
// 005f64e5  50                   push eax
// 005f64e6  8bcd                 mov ecx, ebp
// 005f64e8  e833760500           call 0x64db20
// 005f64ed  6a01                 push 1
// 005f64ef  8d542414             lea edx, [esp + 0x14]
// 005f64f3  8bd8                 mov ebx, eax
// 005f64f5  52                   push edx
// 005f64f6  8d442434             lea eax, [esp + 0x34]
// 005f64fa  50                   push eax
// 005f64fb  8bcd                 mov ecx, ebp
// 005f64fd  e8be750500           call 0x64dac0
// 005f6502  53                   push ebx
// 005f6503  e8d8740500           call 0x64d9e0
// 005f6508  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 005f650c  8b542418             mov edx, dword ptr [esp + 0x18]
// 005f6510  83c404               add esp, 4
// 005f6513  3b1d10b28400         cmp ebx, dword ptr [0x84b210]
// 005f6519  890a                 mov dword ptr [edx], ecx
// 005f651b  0f94c0               sete al
// 005f651e  84c0                 test al, al
// 005f6520  0f8587000000         jne 0x5f65ad
// 005f6526  8b6c241c             mov ebp, dword ptr [esp + 0x1c]
// 005f652a  83fe06               cmp esi, 6
// 005f652d  750f                 jne 0x5f653e
// 005f652f  8b442414             mov eax, dword ptr [esp + 0x14]
// 005f6533  8b08                 mov ecx, dword ptr [eax]
// 005f6535  3b4d00               cmp ecx, dword ptr [ebp]
// 005f6538  0f8486000000         je 0x5f65c4
// 005f653e  8b542410             mov edx, dword ptr [esp + 0x10]
// 005f6542  3b542418             cmp edx, dword ptr [esp + 0x18]
// 005f6546  747c                 je 0x5f65c4
// 005f6548  83fe05               cmp esi, 5
// 005f654b  0f8552ffffff         jne 0x5f64a3
// 005f6551  8b07                 mov eax, dword ptr [edi]
// 005f6553  8b4818               mov ecx, dword ptr [eax + 0x18]
// 005f6556  8b4014               mov eax, dword ptr [eax + 0x14]
// 005f6559  8b742424             mov esi, dword ptr [esp + 0x24]
// 005f655d  51                   push ecx
// 005f655e  50                   push eax
// 005f655f  8bce                 mov ecx, esi
// 005f6561  ff1574238000         call dword ptr [0x802374]
// 005f6567  85c0                 test eax, eax
// 005f6569  7404                 je 0x5f656f
// 005f656b  8bc8                 mov ecx, eax
// 005f656d  eb08                 jmp 0x5f6577
// 005f656f  0fb64e3c             movzx ecx, byte ptr [esi + 0x3c]
// 005f6573  f7d9                 neg ecx
// 005f6575  1bc9                 sbb ecx, ecx
// 005f6577  8b07                 mov eax, dword ptr [edi]
// 005f6579  83f9ff               cmp ecx, -1
// 005f657c  750d                 jne 0x5f658b
// 005f657e  be04000000           mov esi, 4
// 005f6583  097024               or dword ptr [eax + 0x24], esi
// 005f6586  e918ffffff           jmp 0x5f64a3
// 005f658b  8b5014               mov edx, dword ptr [eax + 0x14]
// 005f658e  83c014               add eax, 0x14
// 005f6591  895008               mov dword ptr [eax + 8], edx
// 005f6594  03d1                 add edx, ecx
// 005f6596  89500c               mov dword ptr [eax + 0xc], edx
// 005f6599  8b07                 mov eax, dword ptr [edi]
// 005f659b  33d2                 xor edx, edx
// 005f659d  3b4818               cmp ecx, dword ptr [eax + 0x18]
// 005f65a0  0f95c2               setne dl
// 005f65a3  83c205               add edx, 5
// 005f65a6  8bf2                 mov esi, edx
// 005f65a8  e9f6feffff           jmp 0x5f64a3
// 005f65ad  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f65b1  2b442428             sub eax, dword ptr [esp + 0x28]
// 005f65b5  7515                 jne 0x5f65cc
// 005f65b7  5f                   pop edi
// 005f65b8  5e                   pop esi
// 005f65b9  5d                   pop ebp
// 005f65ba  83c8ff               or eax, 0xffffffff
// 005f65bd  5b                   pop ebx
// 005f65be  83c410               add esp, 0x10
// 005f65c1  c20c00               ret 0xc
// 005f65c4  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f65c8  2b442428             sub eax, dword ptr [esp + 0x28]
// 005f65cc  5f                   pop edi
// 005f65cd  5e                   pop esi
// 005f65ce  5d                   pop ebp
// 005f65cf  5b                   pop ebx
// 005f65d0  83c410               add esp, 0x10
// 005f65d3  c20c00               ret 0xc

namespace std {
template<class T> struct char_traits;
template<class T, class Traits> struct basic_streambuf {
    unsigned char padding[60];
    unsigned char eof;
};
}

extern int (__thiscall *sgetn)(
    std::basic_streambuf<char, std::char_traits<char> > *, char *, int);

extern int finish_mode;
extern int normal_mode;
extern int stream_end;
extern "C" void __cdecl check_status(int);

struct Buffer {
    char *data;
    int size;
    char *next;
    char *end;
};

struct State {
    void *state;
    unsigned char padding[16];
    Buffer buffer;
    unsigned int flags;

    void before(char **, char *, char **, char *);
    int inflate(int);
    void after(char **, char **, int);
};

struct S {
    State *state;
    int f(std::basic_streambuf<char, std::char_traits<char> > *, char *, int);
};

int S::f(std::basic_streambuf<char, std::char_traits<char> > *source,
         char *destination, int length)
{
    if (!(state->flags & 1)) {
        state->flags |= 1;
        Buffer &buffer = state->buffer;
        buffer.next = buffer.data;
        buffer.end = buffer.data;
    }

    int mode = ((~(state->flags >> 2)) & 1) | 4;
    char *output = destination;
    char *output_end = destination + length;
    char **end = &state->buffer.end;
    char **next = &state->buffer.next;

    for (;;) {
        bool finishing = mode == 4;

        if (*next != *end || finishing) {
            char *input = *next;
            State *current = state;
            current->before(&input, *end, &output, output_end);
            int result = current->inflate(finishing ? finish_mode : normal_mode);
            current->after(&input, &output, 1);
            check_status(result);
            bool done = result == stream_end;
            *next = input;

            if (done) {
                int count = output - destination;
                return count ? count : -1;
            }
        }

        if (mode == 6 && *next == *end)
            break;
        if (output == output_end)
            break;

        if (mode == 5) {
            int size = state->buffer.size;
            char *data = state->buffer.data;
            int result = sgetn(source, data, size);
            int count = result ? result : ((source->eof & 1) ? -1 : 0);

            if (count == -1) {
                mode = 4;
                state->flags |= mode;
            } else {
                Buffer &buffer = state->buffer;
                buffer.next = buffer.data;
                buffer.end = buffer.data + count;
                mode = 5 + (count != state->buffer.size);
            }
        }
    }

    return output - destination;
}
