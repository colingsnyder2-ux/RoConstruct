// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005746e0  unit: ChatEnter  size: 114 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005746e0
//
// 005746e0  56                   push esi
// 005746e1  8bf1                 mov esi, ecx
// 005746e3  8b8e34010000         mov ecx, dword ptr [esi + 0x134]
// 005746e9  57                   push edi
// 005746ea  8dbe34010000         lea edi, [esi + 0x134]
// 005746f0  85c9                 test ecx, ecx
// 005746f2  7407                 je 0x5746fb
// 005746f4  8b01                 mov eax, dword ptr [ecx]
// 005746f6  8b5040               mov edx, dword ptr [eax + 0x40]
// 005746f9  ffd2                 call edx
// 005746fb  8bcf                 mov ecx, edi
// 005746fd  e87e27eeff           call 0x456e80
// 00574702  b803000000           mov eax, 3
// 00574707  398644010000         cmp dword ptr [esi + 0x144], eax
// 0057470d  7515                 jne 0x574724
// 0057470f  8b442410             mov eax, dword ptr [esp + 0x10]
// 00574713  833804               cmp dword ptr [eax], 4
// 00574716  7524                 jne 0x57473c
// 00574718  c7864401000001000000 mov dword ptr [esi + 0x144], 1
// 00574722  eb0f                 jmp 0x574733
// 00574724  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00574728  833904               cmp dword ptr [ecx], 4
// 0057472b  750f                 jne 0x57473c
// 0057472d  898644010000         mov dword ptr [esi + 0x144], eax
// 00574733  8b16                 mov edx, dword ptr [esi]
// 00574735  8b4264               mov eax, dword ptr [edx + 0x64]
// 00574738  8bce                 mov ecx, esi
// 0057473a  ffd0                 call eax
// 0057473c  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00574740  5f                   pop edi
// 00574741  c7400400000000       mov dword ptr [eax + 4], 0
// 00574748  c70001000000         mov dword ptr [eax], 1
// 0057474e  5e                   pop esi
// 0057474f  c20800               ret 8

struct Result {
    int first;
    int second;
};

struct Event {
    int kind;
};

struct Object {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16x();
    virtual void release();
};

struct Holder {
    Object* object;
    void* control;
    void reset();
};

struct ChatEnter {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25x();
    virtual void update();

    char padding[0x8c];
    Holder holder;
    char padding2[8];
    int state;

    Result handle(const Event& event);
};

Result ChatEnter::handle(const Event& event)
{
    if (holder.object)
        holder.object->release();

    holder.reset();

    if (state == 3) {
        if (event.kind == 4) {
            state = 1;
            update();
        }
    } else {
        if (event.kind == 4) {
            state = 3;
            update();
        }
    }

    Result result;
    result.second = 0;
    result.first = 1;
    return result;
}
