// from server: 100% by colin
// roc 2007-08 00726c30  unit: boost::thread_resource_error  size: 13 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00726c30
//
// 00726c30  51                   push ecx
// 00726c31  a1f08f7e00           mov eax, dword ptr [0x7e8ff0]
// 00726c36  890424               mov dword ptr [esp], eax
// 00726c39  33c0                 xor eax, eax
// 00726c3b  59                   pop ecx
// 00726c3c  c3                   ret 

extern int g_7e8ff0;

struct boost_thread_resource_error {
    int f();
};

int boost_thread_resource_error::f()
{
    int tmp = g_7e8ff0;
    *(volatile int*)&tmp = tmp;
    return 0;
}
