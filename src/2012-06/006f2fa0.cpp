// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 006f2e40  unit: RBX::CameraTiltUpCommand  size: 30 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f2e40
//
// 006f2e40  8b490c               mov ecx, dword ptr [ecx + 0xc]
// 006f2e43  8b8150010000         mov eax, dword ptr [ecx + 0x150]
// 006f2e49  8b5008               mov edx, dword ptr [eax + 8]
// 006f2e4c  81c150010000         add ecx, 0x150
// 006f2e52  ffd2                 call edx
// 006f2e54  6aff                 push -1
// 006f2e56  8bc8                 mov ecx, eax
// 006f2e58  e8c337f9ff           call 0x686620
// 006f2e5d  c3                   ret 

struct Result686620
{
    int method(int);
};

struct Sub;

struct SubVtable
{
    void* unknown0;
    void* unknown1;
    Result686620* (__thiscall *func8)(Sub*);
};

struct Sub
{
    SubVtable* vtbl;
};

struct Inner
{
    char pad[0x150];
    Sub sub;
};

struct CameraTiltUpCommand
{
    int f();
};

int CameraTiltUpCommand::f()
{
    Inner* inner = *(Inner**)((char*)this + 0xc);
    Result686620* result = inner->sub.vtbl->func8(&inner->sub);
    return result->method(-1);
}
