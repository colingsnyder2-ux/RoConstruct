// from server: 100% by nuck16
// from server: 99% by atomic.potato
// roc 2009-12 00552280  unit: Exposer  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00552280
//
// 00552280  8b01                 mov eax, dword ptr [ecx]
// 00552282  8b504c               mov edx, dword ptr [eax + 0x4c]
// 00552285  68b8e99b00           push 0x9be9b8
// 0055228a  ffd2                 call edx
// 0055228c  c3                   ret 

struct Exposer
{
    struct VTable
    {
        void *padding[19];
        void (__thiscall *f)(void *, const char *);
    };

    VTable *vtable;
    void f();
};

void Exposer::f()
{
    vtable->f(this, "S|R,Typ,Pckt#,Frm #,PktID,BitLn,Time     ,Local IP:Port   ,RemoteIP:Port,SPID,SPIN,SPCO,OI,Suffix\n");
}
