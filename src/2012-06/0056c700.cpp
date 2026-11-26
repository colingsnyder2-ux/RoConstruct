// from server: 100% by Xemicl
// roc 2012-06 0056c700  unit: RBX::Network::IdSerializer  size: 225 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0056c700
//
// 0056c700  55                   push ebp
// 0056c701  8bec                 mov ebp, esp
// 0056c703  64a100000000         mov eax, dword ptr fs:[0]
// 0056c709  6aff                 push -1
// 0056c70b  6862efaa00           push 0xaaef62
// 0056c710  50                   push eax
// 0056c711  64892500000000       mov dword ptr fs:[0], esp
// 0056c718  81ec8c000000         sub esp, 0x8c
// 0056c71e  53                   push ebx
// 0056c71f  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0056c722  56                   push esi
// 0056c723  57                   push edi
// 0056c724  8d45f0               lea eax, [ebp - 0x10]
// 0056c727  50                   push eax
// 0056c728  8bcb                 mov ecx, ebx
// 0056c72a  e8f1f8ffff           call 0x56c020
// 0056c72f  84c0                 test al, al
// 0056c731  752f                 jne 0x56c762
// 0056c733  68f051b700           push 0xb751f0
// 0056c738  8d4db8               lea ecx, [ebp - 0x48]
// 0056c73b  ff154826b200         call dword ptr [0xb22648]
// 0056c741  8d4db8               lea ecx, [ebp - 0x48]
// 0056c744  51                   push ecx
// 0056c745  8d4d90               lea ecx, [ebp - 0x70]
// 0056c748  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0056c74f  e84cf9e9ff           call 0x40c0a0
// 0056c754  686c80cd00           push 0xcd806c
// 0056c759  8d5590               lea edx, [ebp - 0x70]
// 0056c75c  52                   push edx
// 0056c75d  e8e2694100           call 0x983144
// 0056c762  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 0056c765  3d400d0300           cmp eax, 0x30d40
// 0056c76a  7635                 jbe 0x56c7a1
// 0056c76c  68c451b700           push 0xb751c4
// 0056c771  8d4dd4               lea ecx, [ebp - 0x2c]
// 0056c774  ff154826b200         call dword ptr [0xb22648]
// 0056c77a  8d45d4               lea eax, [ebp - 0x2c]
// 0056c77d  50                   push eax
// 0056c77e  8d8d68ffffff         lea ecx, [ebp - 0x98]
// 0056c784  c745fc01000000       mov dword ptr [ebp - 4], 1
// 0056c78b  e810f9e9ff           call 0x40c0a0
// 0056c790  686c80cd00           push 0xcd806c
// 0056c795  8d8d68ffffff         lea ecx, [ebp - 0x98]
// 0056c79b  51                   push ecx
// 0056c79c  e8a3694100           call 0x983144
// 0056c7a1  8d7001               lea esi, [eax + 1]
// 0056c7a4  8bc6                 mov eax, esi
// 0056c7a6  e8656b4100           call 0x983310
// 0056c7ab  8bfc                 mov edi, esp
// 0056c7ad  6a00                 push 0
// 0056c7af  53                   push ebx
// 0056c7b0  56                   push esi
// 0056c7b1  57                   push edi
// 0056c7b2  e8f9c50200           call 0x598db0
// 0056c7b7  8bc8                 mov ecx, eax
// 0056c7b9  e832c90200           call 0x5990f0
// 0056c7be  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0056c7c1  57                   push edi
// 0056c7c2  ff158c26b200         call dword ptr [0xb2268c]
// 0056c7c8  8bc3                 mov eax, ebx
// 0056c7ca  8da55cffffff         lea esp, [ebp - 0xa4]
// 0056c7d0  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0056c7d3  64890d00000000       mov dword ptr fs:[0], ecx
// 0056c7da  5f                   pop edi
// 0056c7db  5e                   pop esi
// 0056c7dc  5b                   pop ebx
// 0056c7dd  8be5                 mov esp, ebp
// 0056c7df  5d                   pop ebp
// 0056c7e0  c3                   ret 
// copied from an identical function in another client (function ?readString@ns_ROCX000000@@YAAAUStream@1@AAU21@AAUString@1@@Z)

namespace ns_ROCX000000 {
// from server: 100% by king_originala
// roc 2008-06 004a6610  unit: RBX::VHint::?$FactoryProduct::Creator  size: 229 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a6610
//
// 004a6610  55                   push ebp
// 004a6611  8bec                 mov ebp, esp
// 004a6613  64a100000000         mov eax, dword ptr fs:[0]
// 004a6619  6aff                 push -1
// 004a661b  68d27e7c00           push 0x7c7ed2
// 004a6620  50                   push eax
// 004a6621  64892500000000       mov dword ptr fs:[0], esp
// 004a6628  81ec8c000000         sub esp, 0x8c
// 004a662e  53                   push ebx
// 004a662f  8b5d08               mov ebx, dword ptr [ebp + 8]
// 004a6632  56                   push esi
// 004a6633  57                   push edi
// 004a6634  6a01                 push 1
// 004a6636  6a20                 push 0x20
// 004a6638  8d45f0               lea eax, [ebp - 0x10]
// 004a663b  50                   push eax
// 004a663c  8bcb                 mov ecx, ebx
// 004a663e  e8cdebffff           call 0x4a5210
// 004a6643  84c0                 test al, al
// 004a6645  752f                 jne 0x4a6676
// 004a6647  68803d8200           push 0x823d80
// 004a664c  8d4db8               lea ecx, [ebp - 0x48]
// 004a664f  ff1558248000         call dword ptr [0x802458]
// 004a6655  8d4db8               lea ecx, [ebp - 0x48]
// 004a6658  51                   push ecx
// 004a6659  8d4d90               lea ecx, [ebp - 0x70]
// 004a665c  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004a6663  e8e836f6ff           call 0x409d50
// 004a6668  68c81b8d00           push 0x8d1bc8
// 004a666d  8d5590               lea edx, [ebp - 0x70]
// 004a6670  52                   push edx
// 004a6671  e816af1f00           call 0x6a158c
// 004a6676  8b45f0               mov eax, dword ptr [ebp - 0x10]
// 004a6679  3d400d0300           cmp eax, 0x30d40
// 004a667e  7635                 jbe 0x4a66b5
// 004a6680  68543d8200           push 0x823d54
// 004a6685  8d4dd4               lea ecx, [ebp - 0x2c]
// 004a6688  ff1558248000         call dword ptr [0x802458]
// 004a668e  8d45d4               lea eax, [ebp - 0x2c]
// 004a6691  50                   push eax
// 004a6692  8d8d68ffffff         lea ecx, [ebp - 0x98]
// 004a6698  c745fc01000000       mov dword ptr [ebp - 4], 1
// 004a669f  e8ac36f6ff           call 0x409d50
// 004a66a4  68c81b8d00           push 0x8d1bc8
// 004a66a9  8d8d68ffffff         lea ecx, [ebp - 0x98]
// 004a66af  51                   push ecx
// 004a66b0  e8d7ae1f00           call 0x6a158c
// 004a66b5  8d7001               lea esi, [eax + 1]
// 004a66b8  8bc6                 mov eax, esi
// 004a66ba  e8a1ae1f00           call 0x6a1560
// 004a66bf  8bfc                 mov edi, esp
// 004a66c1  6a00                 push 0
// 004a66c3  53                   push ebx
// 004a66c4  56                   push esi
// 004a66c5  57                   push edi
// 004a66c6  e8653b0100           call 0x4ba230
// 004a66cb  8bc8                 mov ecx, eax
// 004a66cd  e87e3f0100           call 0x4ba650
// 004a66d2  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 004a66d5  57                   push edi
// 004a66d6  ff154c248000         call dword ptr [0x80244c]
// 004a66dc  8bc3                 mov eax, ebx
// 004a66de  8da55cffffff         lea esp, [ebp - 0xa4]
// 004a66e4  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004a66e7  64890d00000000       mov dword ptr fs:[0], ecx
// 004a66ee  5f                   pop edi
// 004a66ef  5e                   pop esi
// 004a66f0  5b                   pop ebx
// 004a66f1  8be5                 mov esp, ebp
// 004a66f3  5d                   pop ebp
// 004a66f4  c3                   ret 

extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

struct String;
extern String* (__thiscall* stringConstruct)(String*, const char*);
extern String& (__thiscall* stringAssign)(String*, const char*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
    String& operator=(const char*);
};

inline String::String(const char* text)
{
    stringConstruct(this, text);
}

inline String& String::operator=(const char* text)
{
    return stringAssign(this, text);
}

struct Stream {
    bool readBits(unsigned int*);
};

struct ReadError {
    char storage[40];
    ReadError(const String&);
    ReadError(const ReadError&);
    ~ReadError();
};

struct Reader {
    void read(char*, unsigned int, Stream*, bool);
};

Reader* __cdecl getReader();

Stream& __cdecl readString(Stream& stream, String& result)
{
    unsigned int length;
    if (!stream.readBits(&length))
        throw ReadError(String("BitStream >> std::string: failed to read length"));

    if (length > 200000)
        throw ReadError(String("BitStream >> std::string: Bad string length"));

    unsigned int capacity = length + 1;
    char* buffer = static_cast<char*>(_alloca(capacity));
    getReader()->read(buffer, capacity, &stream, false);
    result = buffer;
    return stream;
}
}
