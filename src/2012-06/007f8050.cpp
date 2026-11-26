// from server: 100% by Xemicl
// from server: 100% by Xemicl
// roc 2012-06 00481da0  unit: CRobloxDoc  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00481da0
//
// 00481da0  64a100000000         mov eax, dword ptr fs:[0]
// 00481da6  6aff                 push -1
// 00481da8  681b03aa00           push 0xaa031b
// 00481dad  50                   push eax
// 00481dae  64892500000000       mov dword ptr fs:[0], esp
// 00481db5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00481db9  56                   push esi
// 00481dba  57                   push edi
// 00481dbb  85c0                 test eax, eax
// 00481dbd  7562                 jne 0x481e21
// 00481dbf  8b442418             mov eax, dword ptr [esp + 0x18]
// 00481dc3  8b38                 mov edi, dword ptr [eax]
// 00481dc5  6a50                 push 0x50
// 00481dc7  e84e035000           call 0x98211a
// 00481dcc  8bf0                 mov esi, eax
// 00481dce  83c404               add esp, 4
// 00481dd1  89742420             mov dword ptr [esp + 0x20], esi
// 00481dd5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00481ddd  85f6                 test esi, esi
// 00481ddf  7427                 je 0x481e08
// 00481de1  8b0f                 mov ecx, dword ptr [edi]
// 00481de3  83c708               add edi, 8
// 00481de6  890e                 mov dword ptr [esi], ecx
// 00481de8  57                   push edi
// 00481de9  8d4e08               lea ecx, [esi + 8]
// 00481dec  e80fe7ffff           call 0x480500
// 00481df1  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00481df5  8932                 mov dword ptr [edx], esi
// 00481df7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481dfb  64890d00000000       mov dword ptr fs:[0], ecx
// 00481e02  5f                   pop edi
// 00481e03  5e                   pop esi
// 00481e04  83c40c               add esp, 0xc
// 00481e07  c3                   ret 
// 00481e08  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00481e0c  33f6                 xor esi, esi
// 00481e0e  8932                 mov dword ptr [edx], esi
// 00481e10  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481e14  64890d00000000       mov dword ptr fs:[0], ecx
// 00481e1b  5f                   pop edi
// 00481e1c  5e                   pop esi
// 00481e1d  83c40c               add esp, 0xc
// 00481e20  c3                   ret 
// 00481e21  83f801               cmp eax, 1
// 00481e24  7523                 jne 0x481e49
// 00481e26  8b442418             mov eax, dword ptr [esp + 0x18]
// 00481e2a  8b08                 mov ecx, dword ptr [eax]
// 00481e2c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00481e30  890a                 mov dword ptr [edx], ecx
// 00481e32  c70000000000         mov dword ptr [eax], 0
// 00481e38  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481e3c  64890d00000000       mov dword ptr fs:[0], ecx
// 00481e43  5f                   pop edi
// 00481e44  5e                   pop esi
// 00481e45  83c40c               add esp, 0xc
// 00481e48  c3                   ret 
// 00481e49  83f802               cmp eax, 2
// 00481e4c  7532                 jne 0x481e80
// 00481e4e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00481e52  8b37                 mov esi, dword ptr [edi]
// 00481e54  85f6                 test esi, esi
// 00481e56  7411                 je 0x481e69
// 00481e58  8d4e08               lea ecx, [esi + 8]
// 00481e5b  e830caffff           call 0x47e890
// 00481e60  56                   push esi
// 00481e61  e8ae025000           call 0x982114
// 00481e66  83c404               add esp, 4
// 00481e69  c70700000000         mov dword ptr [edi], 0
// 00481e6f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481e73  64890d00000000       mov dword ptr fs:[0], ecx
// 00481e7a  5f                   pop edi
// 00481e7b  5e                   pop esi
// 00481e7c  83c40c               add esp, 0xc
// 00481e7f  c3                   ret 
// 00481e80  83f803               cmp eax, 3
// 00481e83  7545                 jne 0x481eca
// 00481e85  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00481e89  8b0e                 mov ecx, dword ptr [esi]
// 00481e8b  6890ecd600           push 0xd6ec90
// 00481e90  ff15ec29b200         call dword ptr [0xb229ec]
// 00481e96  84c0                 test al, al
// 00481e98  7419                 je 0x481eb3
// 00481e9a  8b442418             mov eax, dword ptr [esp + 0x18]
// 00481e9e  8b08                 mov ecx, dword ptr [eax]
// 00481ea0  890e                 mov dword ptr [esi], ecx
// 00481ea2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481ea6  64890d00000000       mov dword ptr fs:[0], ecx
// 00481ead  5f                   pop edi
// 00481eae  5e                   pop esi
// 00481eaf  83c40c               add esp, 0xc
// 00481eb2  c3                   ret 
// 00481eb3  c70600000000         mov dword ptr [esi], 0
// 00481eb9  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481ebd  64890d00000000       mov dword ptr fs:[0], ecx
// 00481ec4  5f                   pop edi
// 00481ec5  5e                   pop esi
// 00481ec6  83c40c               add esp, 0xc
// 00481ec9  c3                   ret 
// 00481eca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00481ece  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481ed2  5f                   pop edi
// 00481ed3  c70090ecd600         mov dword ptr [eax], 0xd6ec90
// 00481ed9  c6400400             mov byte ptr [eax + 4], 0
// 00481edd  c6400500             mov byte ptr [eax + 5], 0
// 00481ee1  64890d00000000       mov dword ptr fs:[0], ecx
// 00481ee8  5e                   pop esi
// 00481ee9  83c40c               add esp, 0xc
// 00481eec  c3                   ret 

// from server: 99% by tajop
// roc 2012-06 00481da0  unit: CRobloxDoc  size: 333 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00481da0
//
// 00481da0  64a100000000         mov eax, dword ptr fs:[0]
// 00481da6  6aff                 push -1
// 00481da8  681b03aa00           push 0xaa031b
// 00481dad  50                   push eax
// 00481dae  64892500000000       mov dword ptr fs:[0], esp
// 00481db5  8b442418             mov eax, dword ptr [esp + 0x18]
// 00481db9  56                   push esi
// 00481dba  57                   push edi
// 00481dbb  85c0                 test eax, eax
// 00481dbd  7562                 jne 0x481e21
// 00481dbf  8b442418             mov eax, dword ptr [esp + 0x18]
// 00481dc3  8b38                 mov edi, dword ptr [eax]
// 00481dc5  6a50                 push 0x50
// 00481dc7  e84e035000           call 0x98211a
// 00481dcc  8bf0                 mov esi, eax
// 00481dce  83c404               add esp, 4
// 00481dd1  89742420             mov dword ptr [esp + 0x20], esi
// 00481dd5  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00481ddd  85f6                 test esi, esi
// 00481ddf  7427                 je 0x481e08
// 00481de1  8b0f                 mov ecx, dword ptr [edi]
// 00481de3  83c708               add edi, 8
// 00481de6  890e                 mov dword ptr [esi], ecx
// 00481de8  57                   push edi
// 00481de9  8d4e08               lea ecx, [esi + 8]
// 00481dec  e80fe7ffff           call 0x480500
// 00481df1  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00481df5  8932                 mov dword ptr [edx], esi
// 00481df7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481dfb  64890d00000000       mov dword ptr fs:[0], ecx
// 00481e02  5f                   pop edi
// 00481e03  5e                   pop esi
// 00481e04  83c40c               add esp, 0xc
// 00481e07  c3                   ret 
// 00481e08  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00481e0c  33f6                 xor esi, esi
// 00481e0e  8932                 mov dword ptr [edx], esi
// 00481e10  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481e14  64890d00000000       mov dword ptr fs:[0], ecx
// 00481e1b  5f                   pop edi
// 00481e1c  5e                   pop esi
// 00481e1d  83c40c               add esp, 0xc
// 00481e20  c3                   ret 
// 00481e21  83f801               cmp eax, 1
// 00481e24  7523                 jne 0x481e49
// 00481e26  8b442418             mov eax, dword ptr [esp + 0x18]
// 00481e2a  8b08                 mov ecx, dword ptr [eax]
// 00481e2c  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00481e30  890a                 mov dword ptr [edx], ecx
// 00481e32  c70000000000         mov dword ptr [eax], 0
// 00481e38  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481e3c  64890d00000000       mov dword ptr fs:[0], ecx
// 00481e43  5f                   pop edi
// 00481e44  5e                   pop esi
// 00481e45  83c40c               add esp, 0xc
// 00481e48  c3                   ret 
// 00481e49  83f802               cmp eax, 2
// 00481e4c  7532                 jne 0x481e80
// 00481e4e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00481e52  8b37                 mov esi, dword ptr [edi]
// 00481e54  85f6                 test esi, esi
// 00481e56  7411                 je 0x481e69
// 00481e58  8d4e08               lea ecx, [esi + 8]
// 00481e5b  e830caffff           call 0x47e890
// 00481e60  56                   push esi
// 00481e61  e8ae025000           call 0x982114
// 00481e66  83c404               add esp, 4
// 00481e69  c70700000000         mov dword ptr [edi], 0
// 00481e6f  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481e73  64890d00000000       mov dword ptr fs:[0], ecx
// 00481e7a  5f                   pop edi
// 00481e7b  5e                   pop esi
// 00481e7c  83c40c               add esp, 0xc
// 00481e7f  c3                   ret 
// 00481e80  83f803               cmp eax, 3
// 00481e83  7545                 jne 0x481eca
// 00481e85  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 00481e89  8b0e                 mov ecx, dword ptr [esi]
// 00481e8b  6890ecd600           push 0xd6ec90
// 00481e90  ff15ec29b200         call dword ptr [0xb229ec]
// 00481e96  84c0                 test al, al
// 00481e98  7419                 je 0x481eb3
// 00481e9a  8b442418             mov eax, dword ptr [esp + 0x18]
// 00481e9e  8b08                 mov ecx, dword ptr [eax]
// 00481ea0  890e                 mov dword ptr [esi], ecx
// 00481ea2  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481ea6  64890d00000000       mov dword ptr fs:[0], ecx
// 00481ead  5f                   pop edi
// 00481eae  5e                   pop esi
// 00481eaf  83c40c               add esp, 0xc
// 00481eb2  c3                   ret 
// 00481eb3  c70600000000         mov dword ptr [esi], 0
// 00481eb9  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481ebd  64890d00000000       mov dword ptr fs:[0], ecx
// 00481ec4  5f                   pop edi
// 00481ec5  5e                   pop esi
// 00481ec6  83c40c               add esp, 0xc
// 00481ec9  c3                   ret 
// 00481eca  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00481ece  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00481ed2  5f                   pop edi
// 00481ed3  c70090ecd600         mov dword ptr [eax], 0xd6ec90
// 00481ed9  c6400400             mov byte ptr [eax + 4], 0
// 00481edd  c6400500             mov byte ptr [eax + 5], 0
// 00481ee1  64890d00000000       mov dword ptr fs:[0], ecx
// 00481ee8  5e                   pop esi
// 00481ee9  83c40c               add esp, 0xc
// 00481eec  c3                   ret 

class type_info {
public:
    bool operator==(const type_info& rhs) const;
};

typedef bool (type_info::*type_info_eq_fn)(const type_info& rhs) const;
extern type_info_eq_fn imp_type_info_eq;

struct Inner {
    Inner(const Inner& o);
    ~Inner();
    int d[0x12];
};

struct Empty {};
// The functor's RTTI descriptor lives elsewhere in the image (a boost::bind_t<...> type);
// referencing it as an external object keeps this unit from defining a mismatching copy.
extern const type_info functor_typeid;

struct Functor {
    int fn;
    Empty e;
    Inner args;
};

union function_buffer {
    void* obj_ptr;
    struct {
        const type_info* type;
        bool const_qualified;
        bool volatile_qualified;
    } type;
};

enum functor_manager_operation_type {
    clone_functor_tag,
    move_functor_tag,
    destroy_functor_tag,
    check_functor_type_tag,
    get_functor_type_tag
};

struct functor_manager {
    static void manage(const function_buffer& in_buffer, function_buffer& out_buffer,
                       functor_manager_operation_type op);
};

void functor_manager::manage(const function_buffer& in_buffer, function_buffer& out_buffer,
                             functor_manager_operation_type op)
{
    if (op == clone_functor_tag) {
        const Functor* f = static_cast<const Functor*>(in_buffer.obj_ptr);
        Functor* new_f = new Functor(*f);
        out_buffer.obj_ptr = new_f;
    } else if (op == move_functor_tag) {
        out_buffer.obj_ptr = in_buffer.obj_ptr;
        const_cast<function_buffer&>(in_buffer).obj_ptr = 0;
    } else if (op == destroy_functor_tag) {
        Functor* f = static_cast<Functor*>(out_buffer.obj_ptr);
        delete f;
        out_buffer.obj_ptr = 0;
    } else if (op == check_functor_type_tag) {
        if (((*out_buffer.type.type).*imp_type_info_eq)(functor_typeid))
            out_buffer.obj_ptr = in_buffer.obj_ptr;
        else
            out_buffer.obj_ptr = 0;
    } else {
        out_buffer.type.type = &functor_typeid;
        out_buffer.type.const_qualified = false;
        out_buffer.type.volatile_qualified = false;
    }
}
