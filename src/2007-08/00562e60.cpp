// from server: 100% by EspClaude
// from server: 54% by colin
// roc 2007-08 00562e60  unit: RBX::WatchCameraCommand  size: 178 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00562e60
//
// 00562e60  51                   push ecx
// 00562e61  56                   push esi
// 00562e62  57                   push edi
// 00562e63  8bf9                 mov edi, ecx
// 00562e65  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 00562e68  85c9                 test ecx, ecx
// 00562e6a  7409                 je 0x562e75
// 00562e6c  e86feaffff           call 0x5618e0
// 00562e71  8bf0                 mov esi, eax
// 00562e73  eb02                 jmp 0x562e77
// 00562e75  33f6                 xor esi, esi
// 00562e77  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 00562e7d  85c0                 test eax, eax
// 00562e7f  7431                 je 0x562eb2
// 00562e81  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 00562e87  2bc8                 sub ecx, eax
// 00562e89  c1f902               sar ecx, 2
// 00562e8c  7424                 je 0x562eb2
// 00562e8e  53                   push ebx
// 00562e8f  8bd8                 mov ebx, eax
// 00562e91  3b9efc000000         cmp ebx, dword ptr [esi + 0xfc]
// 00562e97  55                   push ebp
// 00562e98  8b2dd8e67700         mov ebp, dword ptr [0x77e6d8]
// 00562e9e  7608                 jbe 0x562ea8
// 00562ea0  ffd5                 call ebp
// 00562ea2  3b9efc000000         cmp ebx, dword ptr [esi + 0xfc]
// 00562ea8  7202                 jb 0x562eac
// 00562eaa  ffd5                 call ebp
// 00562eac  8b33                 mov esi, dword ptr [ebx]
// 00562eae  5d                   pop ebp
// 00562eaf  5b                   pop ebx
// 00562eb0  eb02                 jmp 0x562eb4
// 00562eb2  33f6                 xor esi, esi
// 00562eb4  8b470c               mov eax, dword ptr [edi + 0xc]
// 00562eb7  8b9028020000         mov edx, dword ptr [eax + 0x228]
// 00562ebd  8d8828020000         lea ecx, [eax + 0x228]
// 00562ec3  8b4204               mov eax, dword ptr [edx + 4]
// 00562ec6  6a02                 push 2
// 00562ec8  ffd0                 call eax
// 00562eca  8bc8                 mov ecx, eax
// 00562ecc  e8ef870300           call 0x59b6c0
// 00562ed1  8b470c               mov eax, dword ptr [edi + 0xc]
// 00562ed4  8b9028020000         mov edx, dword ptr [eax + 0x228]
// 00562eda  8d8828020000         lea ecx, [eax + 0x228]
// 00562ee0  8b4204               mov eax, dword ptr [edx + 4]
// 00562ee3  56                   push esi
// 00562ee4  ffd0                 call eax
// 00562ee6  8bc8                 mov ecx, eax
// 00562ee8  e813880300           call 0x59b700
// 00562eed  8b742410             mov esi, dword ptr [esp + 0x10]
// 00562ef1  6aff                 push -1
// 00562ef3  8bce                 mov ecx, esi
// 00562ef5  e8b6d9eaff           call 0x4108b0
// 00562efa  8b16                 mov edx, dword ptr [esi]
// 00562efc  8b4204               mov eax, dword ptr [edx + 4]
// 00562eff  6a01                 push 1
// 00562f01  8bce                 mov ecx, esi
// 00562f03  c74604ffffffff       mov dword ptr [esi + 4], 0xffffffff
// 00562f0a  ffd0                 call eax
// 00562f0c  5f                   pop edi
// 00562f0d  5e                   pop esi
// 00562f0e  59                   pop ecx
// 00562f0f  c20400               ret 4
#include <vector>

struct Item;

struct Source {
    char pad[0xf4];
    std::vector<int> items;
};

struct Getter {
    Source* get();
};

struct Sink {
    void m59b6c0();
    void m59b700();
};

struct Iface {
    virtual void v0();
    virtual Sink* v1(int);
};

struct Holder {
    char pad[0x228];
    Iface iface;
};

struct Arg {
    virtual void v0();
    virtual void v1(int);
    int f4;
    void m4108b0(int);
};

struct WatchCameraCommand {
    char pad[0x0c];
    Holder* field0c;
    char pad2[0x10];
    Getter* field20;
    void execute(Arg* arg);
};

void WatchCameraCommand::execute(Arg* arg)
{
    Source* s = field20 ? field20->get() : 0;
    int item = s->items.size() ? s->items.front() : 0;
    field0c->iface.v1(2)->m59b6c0();
    field0c->iface.v1(item)->m59b700();
    arg->m4108b0(-1);
    arg->f4 = -1;
    arg->v1(1);
}
