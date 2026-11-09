// from server: 100% by king_originala
#include <string>
#include <stdexcept>
// from server: 100% by king_originala
// roc 2008-06 005aeb80  unit: RBX::ScriptContext  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005aeb80
//
// 005aeb80  55                   push ebp
// 005aeb81  8bec                 mov ebp, esp
// 005aeb83  6aff                 push -1
// 005aeb85  6809357d00           push 0x7d3509
// 005aeb8a  64a100000000         mov eax, dword ptr fs:[0]
// 005aeb90  50                   push eax
// 005aeb91  64892500000000       mov dword ptr fs:[0], esp
// 005aeb98  83ec4c               sub esp, 0x4c
// 005aeb9b  53                   push ebx
// 005aeb9c  56                   push esi
// 005aeb9d  57                   push edi
// 005aeb9e  8965f0               mov dword ptr [ebp - 0x10], esp
// 005aeba1  8bf9                 mov edi, ecx
// 005aeba3  8b7508               mov esi, dword ptr [ebp + 8]
// 005aeba6  56                   push esi
// 005aeba7  c745fc01000000       mov dword ptr [ebp - 4], 1
// 005aebae  e85d300600           call 0x611c10
// 005aebb3  83c404               add esp, 4
// 005aebb6  56                   push esi
// 005aebb7  8d4d0c               lea ecx, [ebp + 0xc]
// 005aebba  8bd8                 mov ebx, eax
// 005aebbc  e8cf6ffeff           call 0x595b90
// 005aebc1  50                   push eax
// 005aebc2  56                   push esi
// 005aebc3  8bcf                 mov ecx, edi
// 005aebc5  e806f5ffff           call 0x5ae0d0
// 005aebca  83f802               cmp eax, 2
// 005aebcd  0f84b2000000         je 0x5aec85
// 005aebd3  56                   push esi
// 005aebd4  e837300600           call 0x611c10
// 005aebd9  8bf8                 mov edi, eax
// 005aebdb  b801000000           mov eax, 1
// 005aebe0  2bc3                 sub eax, ebx
// 005aebe2  83c404               add esp, 4
// 005aebe5  03f8                 add edi, eax
// 005aebe7  57                   push edi
// 005aebe8  56                   push esi
// 005aebe9  8d4d2c               lea ecx, [ebp + 0x2c]
// 005aebec  897dec               mov dword ptr [ebp - 0x14], edi
// 005aebef  c645fc02             mov byte ptr [ebp - 4], 2
// 005aebf3  e838c2ffff           call 0x5aae30
// 005aebf8  83c9ff               or ecx, 0xffffffff
// 005aebfb  2bcf                 sub ecx, edi
// 005aebfd  51                   push ecx
// 005aebfe  56                   push esi
// 005aebff  c745fc01000000       mov dword ptr [ebp - 4], 1
// 005aec06  e815300600           call 0x611c20
// 005aec0b  8b450c               mov eax, dword ptr [ebp + 0xc]
// 005aec0e  83c408               add esp, 8
// 005aec11  c645fc00             mov byte ptr [ebp - 4], 0
// 005aec15  85c0                 test eax, eax
// 005aec17  741b                 je 0x5aec34
// 005aec19  8b00                 mov eax, dword ptr [eax]
// 005aec1b  85c0                 test eax, eax
// 005aec1d  740e                 je 0x5aec2d
// 005aec1f  8d5514               lea edx, [ebp + 0x14]
// 005aec22  6a01                 push 1
// 005aec24  52                   push edx
// 005aec25  8bca                 mov ecx, edx
// 005aec27  51                   push ecx
// 005aec28  ffd0                 call eax
// 005aec2a  83c40c               add esp, 0xc
// 005aec2d  c7450c00000000       mov dword ptr [ebp + 0xc], 0
// 005aec34  8b452c               mov eax, dword ptr [ebp + 0x2c]
// 005aec37  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005aec3e  85c0                 test eax, eax
// 005aec40  7414                 je 0x5aec56
// 005aec42  8b00                 mov eax, dword ptr [eax]
// 005aec44  85c0                 test eax, eax
// 005aec46  740e                 je 0x5aec56
// 005aec48  8d5534               lea edx, [ebp + 0x34]
// 005aec4b  6a01                 push 1
// 005aec4d  52                   push edx
// 005aec4e  8bca                 mov ecx, edx
// 005aec50  51                   push ecx
// 005aec51  ffd0                 call eax
// 005aec53  83c40c               add esp, 0xc
// 005aec56  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005aec59  5f                   pop edi
// 005aec5a  5e                   pop esi
// 005aec5b  64890d00000000       mov dword ptr fs:[0], ecx
// 005aec62  5b                   pop ebx
// 005aec63  8be5                 mov esp, ebp
// 005aec65  5d                   pop ebp
// 005aec66  c24400               ret 0x44

struct State;

extern "C" int __cdecl lua_gettop(State*);
extern "C" const char* __cdecl lua_tostring(State*, int);
extern "C" void __cdecl lua_settop(State*, int);

typedef void (__cdecl *Manager)(void*, void*, int);

struct FunctionTable
{
    Manager manager;
    void (__cdecl *invoke)(void*, void*);
};

struct Loader
{
    FunctionTable* table;
    unsigned int unused;
    char storage[24];

    int operator()(State*);
    void clear();
    ~Loader();
};

struct Results
{
    FunctionTable* table;
    unsigned int unused;
    char storage[24];

    void operator()(State*, int);
    void clear();
    ~Results();
};

inline void Loader::clear()
{
    if (table)
    {
        Manager manager = table->manager;
        if (manager)
            manager(storage, storage, 1);
        table = 0;
    }
}

inline Loader::~Loader()
{
    clear();
}

inline void Results::clear()
{
    if (table)
    {
        Manager manager = table->manager;
        if (manager)
            manager(storage, storage, 1);
        table = 0;
    }
}

inline Results::~Results()
{
    clear();
}

struct ScriptContext
{
    int run(State*, int);
    void execute(State*, Loader, Results);
};

void ScriptContext::execute(State* state, Loader loader, Results results)
{
    int top = lua_gettop(state);
    if (run(state, loader(state)) != 2)
    {
        int count = lua_gettop(state);
        count += 1 - top;
        try
        {
            results(state, count);
        }
        catch (std::exception&)
        {
            lua_settop(state, -1 - count);
            throw;
        }
        lua_settop(state, -1 - count);
    }
    else
    {
        std::string error(lua_tostring(state, -1));
        lua_settop(state, 0);
        throw std::runtime_error(error);
    }
}
