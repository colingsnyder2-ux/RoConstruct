// from server: 100% by Yeetserama
// roc 2007-08 0046b250  unit: RBX::LDraw2Lua::LDrawCommand  size: 188 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046b250
//
// 0046b250  6aff                 push -1
// 0046b252  68783e7400           push 0x743e78
// 0046b257  64a100000000         mov eax, dword ptr fs:[0]
// 0046b25d  50                   push eax
// 0046b25e  51                   push ecx
// 0046b25f  56                   push esi
// 0046b260  57                   push edi
// 0046b261  a188518b00           mov eax, dword ptr [0x8b5188]
// 0046b266  33c4                 xor eax, esp
// 0046b268  50                   push eax
// 0046b269  8d442410             lea eax, [esp + 0x10]
// 0046b26d  64a300000000         mov dword ptr fs:[0], eax
// 0046b273  8bf9                 mov edi, ecx
// 0046b275  897c240c             mov dword ptr [esp + 0xc], edi
// 0046b279  8b742420             mov esi, dword ptr [esp + 0x20]
// 0046b27d  8937                 mov dword ptr [edi], esi
// 0046b27f  8b06                 mov eax, dword ptr [esi]
// 0046b281  8b4804               mov ecx, dword ptr [eax + 4]
// 0046b284  03ce                 add ecx, esi
// 0046b286  ff1508e67700         call dword ptr [0x77e608]
// 0046b28c  85c0                 test eax, eax
// 0046b28e  7417                 je 0x46b2a7
// 0046b290  8b07                 mov eax, dword ptr [edi]
// 0046b292  8b08                 mov ecx, dword ptr [eax]
// 0046b294  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046b297  03c8                 add ecx, eax
// 0046b299  ff1508e67700         call dword ptr [0x77e608]
// 0046b29f  8bc8                 mov ecx, eax
// 0046b2a1  ff15dce57700         call dword ptr [0x77e5dc]
// 0046b2a7  8b16                 mov edx, dword ptr [esi]
// 0046b2a9  8b4a04               mov ecx, dword ptr [edx + 4]
// 0046b2ac  03ce                 add ecx, esi
// 0046b2ae  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0046b2b6  ff15d0e57700         call dword ptr [0x77e5d0]
// 0046b2bc  84c0                 test al, al
// 0046b2be  7426                 je 0x46b2e6
// 0046b2c0  8b06                 mov eax, dword ptr [esi]
// 0046b2c2  8b4804               mov ecx, dword ptr [eax + 4]
// 0046b2c5  03ce                 add ecx, esi
// 0046b2c7  ff15d4e57700         call dword ptr [0x77e5d4]
// 0046b2cd  85c0                 test eax, eax
// 0046b2cf  7415                 je 0x46b2e6
// 0046b2d1  8b0e                 mov ecx, dword ptr [esi]
// 0046b2d3  8b4904               mov ecx, dword ptr [ecx + 4]
// 0046b2d6  03ce                 add ecx, esi
// 0046b2d8  ff15d4e57700         call dword ptr [0x77e5d4]
// 0046b2de  8bc8                 mov ecx, eax
// 0046b2e0  ff15fce57700         call dword ptr [0x77e5fc]
// 0046b2e6  8b16                 mov edx, dword ptr [esi]
// 0046b2e8  8b4a04               mov ecx, dword ptr [edx + 4]
// 0046b2eb  03ce                 add ecx, esi
// 0046b2ed  ff15d0e57700         call dword ptr [0x77e5d0]
// 0046b2f3  884704               mov byte ptr [edi + 4], al
// 0046b2f6  8bc7                 mov eax, edi
// 0046b2f8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0046b2fc  64890d00000000       mov dword ptr fs:[0], ecx
// 0046b303  59                   pop ecx
// 0046b304  5f                   pop edi
// 0046b305  5e                   pop esi
// 0046b306  83c410               add esp, 0x10
// 0046b309  c20400               ret 4
// copied from an identical function in another client (function ??0Sentry@ns_ROCX000000@@QAE@AAUStream@1@@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
struct Stream;
struct StreamBuffer;
struct BasicIOS;

extern StreamBuffer* (__thiscall* stream_rdbuf)(const BasicIOS*);
extern void (__thiscall* stream_lock)(StreamBuffer*);
extern bool (__thiscall* stream_good)(const BasicIOS*);
extern Stream* (__thiscall* stream_tie)(const BasicIOS*);
extern Stream& (__thiscall* stream_flush)(Stream*);

struct Stream
{
    int* table;
};

struct SentryBase
{
    Stream* stream;
    SentryBase(Stream& value);
    ~SentryBase();
};

struct Sentry : SentryBase
{
    bool ready;
    Sentry(Stream& value);
};

inline SentryBase::SentryBase(Stream& value)
{
    stream = &value;
    if (stream_rdbuf(reinterpret_cast<BasicIOS*>(
            reinterpret_cast<char*>(&value) + value.table[1])))
    {
        stream_lock(stream_rdbuf(reinterpret_cast<BasicIOS*>(
            reinterpret_cast<char*>(stream) + stream->table[1])));
    }
}

Sentry::Sentry(Stream& value) : SentryBase(value)
{
    if (stream_good(reinterpret_cast<BasicIOS*>(
            reinterpret_cast<char*>(&value) + value.table[1])) &&
        stream_tie(reinterpret_cast<BasicIOS*>(
            reinterpret_cast<char*>(&value) + value.table[1])))
    {
        stream_flush(stream_tie(reinterpret_cast<BasicIOS*>(
            reinterpret_cast<char*>(&value) + value.table[1])));
    }

    ready = stream_good(reinterpret_cast<BasicIOS*>(
        reinterpret_cast<char*>(&value) + value.table[1]));
}
}
