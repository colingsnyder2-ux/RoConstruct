// from server: 100% by EspClaude
// roc 2009-06 006ae570  unit: RBX::ContactConnector  size: 80 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006ae570
//
// 006ae570  83ec20               sub esp, 0x20
// 006ae573  833904               cmp dword ptr [ecx], 4
// 006ae576  7542                 jne 0x6ae5ba
// 006ae578  d9ee                 fldz 
// 006ae57a  8d0424               lea eax, [esp]
// 006ae57d  d91424               fst dword ptr [esp]
// 006ae580  50                   push eax
// 006ae581  d9542408             fst dword ptr [esp + 8]
// 006ae585  d954240c             fst dword ptr [esp + 0xc]
// 006ae589  d9542414             fst dword ptr [esp + 0x14]
// 006ae58d  d9542418             fst dword ptr [esp + 0x18]
// 006ae591  d95c241c             fstp dword ptr [esp + 0x1c]
// 006ae595  e886fd0100           call 0x6ce320
// 006ae59a  d90538768d00         fld dword ptr [0x8d7638]
// 006ae5a0  d85c240c             fcomp dword ptr [esp + 0xc]
// 006ae5a4  dfe0                 fnstsw ax
// 006ae5a6  f6c441               test ah, 0x41
// 006ae5a9  7509                 jne 0x6ae5b4
// 006ae5ab  b801000000           mov eax, 1
// 006ae5b0  83c420               add esp, 0x20
// 006ae5b3  c3                   ret 
// 006ae5b4  33c0                 xor eax, eax
// 006ae5b6  83c420               add esp, 0x20
// 006ae5b9  c3                   ret 
// 006ae5ba  b001                 mov al, 1
// 006ae5bc  83c420               add esp, 0x20
// 006ae5bf  c3                   ret 
// copied from an identical function in another client (function ?f@S@@QAE_NXZ)

// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Result {
    float x, y, z;
    float depth;
    float u, v, w;
    float extra;
};

extern const float threshold;

struct S {
    int kind;
    void evaluate(Result* result);
    bool f();
};

bool S::f()
{
    if (kind == 4) {
        Result result;
        result.x = 0.0f;
        result.y = 0.0f;
        result.z = 0.0f;
        result.u = 0.0f;
        result.v = 0.0f;
        result.w = 0.0f;
        evaluate(&result);
        return result.depth < threshold;
    }
    return true;
}