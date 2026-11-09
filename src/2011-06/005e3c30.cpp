// from server: 71% by atomic.potato
struct EnumDescriptor {
    int* field_4;
    int* field_8;
    
    void method_3C30(int arg_C, int arg_10, int arg_14);
};

extern "C" void __cdecl sub_422920(EnumDescriptor* thisptr, int, int, int);

void EnumDescriptor::method_3C30(int arg_C, int arg_10, int arg_14) {
    int* eax = field_4;
    int* ecx = field_8;
    int diff = ecx - eax;
    int esi;
    
    if ((diff & 0xFFFFFFFC) == 0) {
        esi = arg_10;
        esi -= reinterpret_cast<int>(eax);
        esi >>= 2;
    } else {
        esi = 0;
    }
    
    sub_422920(this, arg_10, 1, arg_14);
    
    int* result = field_4 + esi;
    *reinterpret_cast<int**>(arg_C) = result;
}
