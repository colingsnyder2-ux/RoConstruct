// from server: 92% by EspClaude
// from server: 90% by colin
// roc 2007-08 0045aa30  unit: RBX::VCamera::?$FactoryProduct::Creator  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045aa30
//
// 0045aa30  56                   push esi
// 0045aa31  8bf1                 mov esi, ecx
// 0045aa33  837e5802             cmp dword ptr [esi + 0x58], 2
// 0045aa37  7507                 jne 0x45aa40
// 0045aa39  e842feffff           call 0x45a880
// 0045aa3e  eb05                 jmp 0x45aa45
// 0045aa40  e8bbfdffff           call 0x45a800
// 0045aa45  84c0                 test al, al
// 0045aa47  751b                 jne 0x45aa64
// 0045aa49  8b4e68               mov ecx, dword ptr [esi + 0x68]
// 0045aa4c  85c9                 test ecx, ecx
// 0045aa4e  7414                 je 0x45aa64
// 0045aa50  83c654               add esi, 0x54
// 0045aa53  e86864ffff           call 0x450ec0
// 0045aa58  85c0                 test eax, eax
// 0045aa5a  7408                 je 0x45aa64
// 0045aa5c  56                   push esi
// 0045aa5d  8bc8                 mov ecx, eax
// 0045aa5f  e87c320d00           call 0x52dce0
// 0045aa64  5e                   pop esi
// 0045aa65  c3                   ret 

struct T {
    T* sub_450ec0();
    int sub_52dce0(void*);
};
struct Sub {
    char pad0[0x04];
    int mode;           // this+0x58
    char pad1[0x0C];
    T* handle;          // this+0x68
    void notify()
    {
        if (handle) {
            if (T* r = handle->sub_450ec0())
                r->sub_52dce0(this);
        }
    }
};
struct S {
    char pad[0x54];
    Sub sub;
    char sub_45a880();
    char sub_45a800();
    void f();
};

void S::f()
{
    char result;
    if (sub.mode == 2)
        result = this->sub_45a880();
    else
        result = this->sub_45a800();
    if (!result)
        sub.notify();
}
