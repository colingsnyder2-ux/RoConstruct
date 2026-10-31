// from server: 100% by EspClaude
// roc 2009-06 004ddb40  unit: RBX::Network::ConcurrentRakPeer::PacketJob  size: 332 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ddb40
//
// 004ddb40  64a100000000         mov eax, dword ptr fs:[0]
// 004ddb46  6aff                 push -1
// 004ddb48  68c5b88500           push 0x85b8c5
// 004ddb4d  50                   push eax
// 004ddb4e  64892500000000       mov dword ptr fs:[0], esp
// 004ddb55  81eca0000000         sub esp, 0xa0
// 004ddb5b  56                   push esi
// 004ddb5c  8bb424b4000000       mov esi, dword ptr [esp + 0xb4]
// 004ddb63  57                   push edi
// 004ddb64  8bbc24bc000000       mov edi, dword ptr [esp + 0xbc]
// 004ddb6b  8d4724               lea eax, [edi + 0x24]
// 004ddb6e  50                   push eax
// 004ddb6f  56                   push esi
// 004ddb70  e82bfcffff           call 0x4dd7a0
// 004ddb75  8d4c2413             lea ecx, [esp + 0x13]
// 004ddb79  51                   push ecx
// 004ddb7a  56                   push esi
// 004ddb7b  e8e0ebffff           call 0x4dc760
// 004ddb80  83c410               add esp, 0x10
// 004ddb83  807c240b00           cmp byte ptr [esp + 0xb], 0
// 004ddb88  7466                 je 0x4ddbf0
// 004ddb8a  6a01                 push 1
// 004ddb8c  6a06                 push 6
// 004ddb8e  8d542414             lea edx, [esp + 0x14]
// 004ddb92  52                   push edx
// 004ddb93  8bce                 mov ecx, esi
// 004ddb95  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004ddb9d  e8eebbffff           call 0x4d9790
// 004ddba2  84c0                 test al, al
// 004ddba4  7537                 jne 0x4ddbdd
// 004ddba6  684c678c00           push 0x8c674c
// 004ddbab  8d4c2424             lea ecx, [esp + 0x24]
// 004ddbaf  ff15b4e48900         call dword ptr [0x89e4b4]
// 004ddbb5  8d442420             lea eax, [esp + 0x20]
// 004ddbb9  50                   push eax
// 004ddbba  8d4c245c             lea ecx, [esp + 0x5c]
// 004ddbbe  c78424b400000000000000 mov dword ptr [esp + 0xb4], 0
// 004ddbc9  e842b8f2ff           call 0x409410
// 004ddbce  6850a79700           push 0x97a750
// 004ddbd3  8d4c245c             lea ecx, [esp + 0x5c]
// 004ddbd7  51                   push ecx
// 004ddbd8  e86dbe2300           call 0x719a4a
// 004ddbdd  8b54240c             mov edx, dword ptr [esp + 0xc]
// 004ddbe1  57                   push edi
// 004ddbe2  52                   push edx
// 004ddbe3  e838f11800           call 0x66cd20
// 004ddbe8  83c408               add esp, 8
// 004ddbeb  e983000000           jmp 0x4ddc73
// 004ddbf0  d9ee                 fldz 
// 004ddbf2  8d442418             lea eax, [esp + 0x18]
// 004ddbf6  50                   push eax
// 004ddbf7  d9542414             fst dword ptr [esp + 0x14]
// 004ddbfb  d9542418             fst dword ptr [esp + 0x18]
// 004ddbff  8d4c2418             lea ecx, [esp + 0x18]
// 004ddc03  51                   push ecx
// 004ddc04  d95c2420             fstp dword ptr [esp + 0x20]
// 004ddc08  d9e8                 fld1 
// 004ddc0a  8d542418             lea edx, [esp + 0x18]
// 004ddc0e  52                   push edx
// 004ddc0f  d95c2428             fstp dword ptr [esp + 0x28]
// 004ddc13  8d442428             lea eax, [esp + 0x28]
// 004ddc17  50                   push eax
// 004ddc18  8bce                 mov ecx, esi
// 004ddc1a  e831f2ffff           call 0x4dce50
// 004ddc1f  84c0                 test al, al
// 004ddc21  753d                 jne 0x4ddc60
// 004ddc23  6818678c00           push 0x8c6718
// 004ddc28  8d4c2440             lea ecx, [esp + 0x40]
// 004ddc2c  ff15b4e48900         call dword ptr [0x89e4b4]
// 004ddc32  8d4c243c             lea ecx, [esp + 0x3c]
// 004ddc36  51                   push ecx
// 004ddc37  8d8c2484000000       lea ecx, [esp + 0x84]
// 004ddc3e  c78424b400000001000000 mov dword ptr [esp + 0xb4], 1
// 004ddc49  e8c2b7f2ff           call 0x409410
// 004ddc4e  6850a79700           push 0x97a750
// 004ddc53  8d942484000000       lea edx, [esp + 0x84]
// 004ddc5a  52                   push edx
// 004ddc5b  e8eabd2300           call 0x719a4a
// 004ddc60  57                   push edi
// 004ddc61  8d4c2414             lea ecx, [esp + 0x14]
// 004ddc65  e8f6a21900           call 0x677f60
// 004ddc6a  57                   push edi
// 004ddc6b  e820051900           call 0x66e190
// 004ddc70  83c404               add esp, 4
// 004ddc73  8b8c24a8000000       mov ecx, dword ptr [esp + 0xa8]
// 004ddc7a  5f                   pop edi
// 004ddc7b  8bc6                 mov eax, esi
// 004ddc7d  5e                   pop esi
// 004ddc7e  64890d00000000       mov dword ptr fs:[0], ecx
// 004ddc85  81c4ac000000         add esp, 0xac
// 004ddc8b  c3                   ret 
// copied from an identical function in another client (function ?readFrame@ns_ROCX000066@@YAAAUStream@1@AAU21@AAUFrame@1@@Z)

namespace ns_ROCX000066 {
extern void (__thiscall *constructString)(void*, const char*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    __forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
    {
        constructString(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        void* data;
        int owned;
    public:
        virtual ~exception();
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string&);
        virtual ~runtime_error();
    };
}

struct Frame {
    float rotation[9];
    float position[3];
};

struct Quaternion {
    float x, y, z, w;
    void apply(Frame*);
};

struct Stream {
    bool readBits(void*, int, bool);
    bool readNormQuat(float&, float&, float&, float&);
};

extern Stream& __cdecl readPosition(Stream&, float*);
extern Stream& __cdecl readFlag(Stream&, bool&);
extern void __cdecl applyOrientation(int, Frame*);
extern void __cdecl finishFrame(Frame*);

Stream& __cdecl readFrame(Stream& stream, Frame& frame)
{
    readPosition(stream, frame.position);

    bool compressed;
    readFlag(stream, compressed);

    if (compressed) {
        int orientation = 0;
        if (!stream.readBits(&orientation, 6, true))
            throw std::runtime_error("BitStream >> CoordinateFrame orientId failed");
        applyOrientation(orientation, &frame);
    } else {
        Quaternion rotation;
        rotation.x = 0.0f;
        rotation.y = 0.0f;
        rotation.z = 0.0f;
        rotation.w = 1.0f;

        if (!stream.readNormQuat(rotation.w, rotation.x, rotation.y, rotation.z))
            throw std::runtime_error("BitStream >> CoordinateFrame ReadNormQuat failed");

        rotation.apply(&frame);
        finishFrame(&frame);
    }

    return stream;
}
}
