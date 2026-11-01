// from server: 100% by colin
// from server: 92% by king_originala
// roc 2008-06 0049f460  unit: RBX::Network::Client  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049f460
//
// 0049f460  6aff                 push -1
// 0049f462  68d96c7c00           push 0x7c6cd9
// 0049f467  64a100000000         mov eax, dword ptr fs:[0]
// 0049f46d  50                   push eax
// 0049f46e  64892500000000       mov dword ptr fs:[0], esp
// 0049f475  51                   push ecx
// 0049f476  8b442418             mov eax, dword ptr [esp + 0x18]
// 0049f47a  56                   push esi
// 0049f47b  8b7010               mov esi, dword ptr [eax + 0x10]
// 0049f47e  57                   push edi
// 0049f47f  8bf9                 mov edi, ecx
// 0049f481  8b17                 mov edx, dword ptr [edi]
// 0049f483  83ec1c               sub esp, 0x1c
// 0049f486  83c220               add edx, 0x20
// 0049f489  8bcc                 mov ecx, esp
// 0049f48b  8964243c             mov dword ptr [esp + 0x3c], esp
// 0049f48f  52                   push edx
// 0049f490  83c608               add esi, 8
// 0049f493  ff155c248000         call dword ptr [0x80245c]
// 0049f499  8b3f                 mov edi, dword ptr [edi]
// 0049f49b  8b471c               mov eax, dword ptr [edi + 0x1c]
// 0049f49e  50                   push eax
// 0049f49f  83ec1c               sub esp, 0x1c
// 0049f4a2  8bcc                 mov ecx, esp
// 0049f4a4  89642444             mov dword ptr [esp + 0x44], esp
// 0049f4a8  57                   push edi
// 0049f4a9  c744245400000000     mov dword ptr [esp + 0x54], 0
// 0049f4b1  ff155c248000         call dword ptr [0x80245c]
// 0049f4b7  8bce                 mov ecx, esi
// 0049f4b9  c7442450ffffffff     mov dword ptr [esp + 0x50], 0xffffffff
// 0049f4c1  e84afdffff           call 0x49f210
// 0049f4c6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0049f4ca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0049f4ce  5f                   pop edi
// 0049f4cf  64890d00000000       mov dword ptr fs:[0], ecx
// 0049f4d6  5e                   pop esi
// 0049f4d7  83c410               add esp, 0x10
// 0049f4da  c20800               ret 8

struct String;
typedef String* (__thiscall *StringCopy)(String*, const String&);
extern StringCopy copyString;

struct __declspec(dllimport) String
{
    char data[28];
    String(const String& other);
    ~String();
};

inline String::String(const String& other)
{
    copyString(this, other);
}

struct Worker
{
    void invoke(String first, int value, String second);
};

struct Argument
{
    char padding[16];
    char* worker;
};

struct Data
{
    String first;
    int value;
    String second;
};

struct Client
{
    Data* data;
    void* function(void* result, Argument* argument);
};

void* Client::function(void* result, Argument* argument)
{
    Worker* worker = reinterpret_cast<Worker*>(argument->worker + 8);
    worker->invoke(data->first, data->value, data->second);
    return result;
}
