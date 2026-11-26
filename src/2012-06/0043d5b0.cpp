// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 00883790  unit: RBX::VFunctionalTest::?$FactoryProduct  size: 166 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00883790
//
// 00883790  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00883794  56                   push esi
// 00883795  85c0                 test eax, eax
// 00883797  752e                 jne 0x8837c7
// 00883799  8b442408             mov eax, dword ptr [esp + 8]
// 0088379d  8b30                 mov esi, dword ptr [eax]
// 0088379f  6a20                 push 0x20
// 008837a1  e874e90f00           call 0x98211a
// 008837a6  83c404               add esp, 4
// 008837a9  85c0                 test eax, eax
// 008837ab  7410                 je 0x8837bd
// 008837ad  56                   push esi
// 008837ae  8bc8                 mov ecx, eax
// 008837b0  e8cbf9ffff           call 0x883180
// 008837b5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008837b9  8901                 mov dword ptr [ecx], eax
// 008837bb  5e                   pop esi
// 008837bc  c3                   ret 
// 008837bd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008837c1  33c0                 xor eax, eax
// 008837c3  8901                 mov dword ptr [ecx], eax
// 008837c5  5e                   pop esi
// 008837c6  c3                   ret 
// 008837c7  83f801               cmp eax, 1
// 008837ca  7514                 jne 0x8837e0
// 008837cc  8b442408             mov eax, dword ptr [esp + 8]
// 008837d0  8b10                 mov edx, dword ptr [eax]
// 008837d2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008837d6  8911                 mov dword ptr [ecx], edx
// 008837d8  c70000000000         mov dword ptr [eax], 0
// 008837de  5e                   pop esi
// 008837df  c3                   ret 
// 008837e0  83f802               cmp eax, 2
// 008837e3  7519                 jne 0x8837fe
// 008837e5  8b74240c             mov esi, dword ptr [esp + 0xc]
// 008837e9  8b0e                 mov ecx, dword ptr [esi]
// 008837eb  85c9                 test ecx, ecx
// 008837ed  7407                 je 0x8837f6
// 008837ef  6a01                 push 1
// 008837f1  e8da92bbff           call 0x43cad0
// 008837f6  c70600000000         mov dword ptr [esi], 0
// 008837fc  5e                   pop esi
// 008837fd  c3                   ret 
// 008837fe  83f803               cmp eax, 3
// 00883801  751f                 jne 0x883822
// 00883803  8b74240c             mov esi, dword ptr [esp + 0xc]
// 00883807  8b0e                 mov ecx, dword ptr [esi]
// 00883809  68d883de00           push 0xde83d8
// 0088380e  ff15ec29b200         call dword ptr [0xb229ec]
// 00883814  84c0                 test al, al
// 00883816  74de                 je 0x8837f6
// 00883818  8b542408             mov edx, dword ptr [esp + 8]
// 0088381c  8b02                 mov eax, dword ptr [edx]
// 0088381e  8906                 mov dword ptr [esi], eax
// 00883820  5e                   pop esi
// 00883821  c3                   ret 
// 00883822  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00883826  c700d883de00         mov dword ptr [eax], 0xde83d8
// 0088382c  c6400400             mov byte ptr [eax + 4], 0
// 00883830  c6400500             mov byte ptr [eax + 5], 0
// 00883834  5e                   pop esi
// 00883835  c3                   ret 

struct type_info {
    __declspec(dllimport) bool operator==(const type_info&) const;
};

extern type_info type_info_00de83d8;

void* __cdecl operator new(unsigned int);
inline void* operator new(unsigned int, void* p) { return p; }

struct Functor {
    char storage[0x20];
    Functor(const Functor&);
    void* scalar_deleting_dtor(unsigned int);
};

union function_buffer {
    void* obj_ptr;
    struct {
        const type_info* type;
        bool const_qualified;
        bool volatile_qualified;
    } type;
};

void __cdecl functor_manager_manage(const function_buffer& in_buffer,
                                    function_buffer& out_buffer, int op)
{
    if (op == 0) {
        const Functor* f = (const Functor*)in_buffer.obj_ptr;
        void* mem = operator new(0x20);
        out_buffer.obj_ptr = mem ? new (mem) Functor(*f) : 0;
    } else if (op == 1) {
        out_buffer.obj_ptr = in_buffer.obj_ptr;
        const_cast<function_buffer&>(in_buffer).obj_ptr = 0;
    } else if (op == 2) {
        Functor* f = (Functor*)out_buffer.obj_ptr;
        if (f)
            f->scalar_deleting_dtor(1);
        out_buffer.obj_ptr = 0;
    } else if (op == 3) {
        if (*out_buffer.type.type == type_info_00de83d8)
            out_buffer.obj_ptr = in_buffer.obj_ptr;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &type_info_00de83d8;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
