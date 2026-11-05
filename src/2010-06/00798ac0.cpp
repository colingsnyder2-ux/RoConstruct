// from server: 90% by atomic.potato
// roc 2010-06 00798ac0  unit: RBX::Log  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00798ac0

extern "C" int __cdecl sub_8c3234(int, int, int, int);

struct RBX_Log {
};

int __cdecl f(int a) {
    int buf[4];
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    sub_8c3234(a, 0x100, 0, (int)buf);
    *(int*)buf[2] = buf[0];
    return 0;
}
