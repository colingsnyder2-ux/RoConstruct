// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00459040  unit: ToggleIDEModeVerb  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00459040
//
// 00459040  56                   push esi
// 00459041  8bf1                 mov esi, ecx
// 00459043  e888f30a00           call 0x5083d0
// 00459048  dd4610               fld qword ptr [esi + 0x10]
// 0045904b  dc05b8908100         fadd qword ptr [0x8190b8]
// 00459051  5e                   pop esi
// 00459052  ded9                 fcompp 
// 00459054  dfe0                 fnstsw ax
// 00459056  f6c441               test ah, 0x41
// 00459059  7503                 jne 0x45905e
// 0045905b  32c0                 xor al, al
// 0045905d  c3                   ret 
// 0045905e  e8c3782400           call 0x6a0926
// 00459063  8b4004               mov eax, dword ptr [eax + 4]
// 00459066  8b4020               mov eax, dword ptr [eax + 0x20]
// 00459069  33c9                 xor ecx, ecx
// 0045906b  388805010000         cmp byte ptr [eax + 0x105], cl
// 00459071  0f94c1               sete cl
// 00459074  8ac1                 mov al, cl
// 00459076  c3                   ret 

extern double delay;
extern double __cdecl getTime();
struct State {
    char padding[0x109];
    unsigned char active;
};
struct Context {
    char padding[0x20];
    State* state;
};
struct Root {
    char padding[4];
    Context* context;
};
extern Root* __cdecl getRoot();
struct ToggleIDEModeVerb {
    char padding[0x10];
    double timestamp;
    bool isEnabled();
};
bool ToggleIDEModeVerb::isEnabled()
{
    double now = getTime();
    if (timestamp + delay > now)
        return false;
    State* s = getRoot()->context->state; return s->active == 0;
}
