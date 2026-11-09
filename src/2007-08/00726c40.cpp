// from server: 100% by colin
// roc 2007-08 00726c40  unit: seg_00720000  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726c40
//
// 00726c40  68d06e7200           push 0x726ed0
// 00726c45  e8d9a0f0ff           call 0x630d23
// 00726c4a  83c404               add esp, 4
// 00726c4d  e84e010000           call 0x726da0
// 00726c52  33c0                 xor eax, eax
// 00726c54  c3                   ret 
// library boost-1.34.1 libs\thread\src\thread.cpp (function ?thread_resource_error@boost@@QAE@XZ)

extern "C" void __cdecl sub_630d23(const char* msg);
extern "C" void __cdecl sub_726da0();

struct thread_resource_error
{
    int init();
};

int thread_resource_error::init()
{
    sub_630d23((const char*)0x726ed0);
    sub_726da0();
    return 0;
}
