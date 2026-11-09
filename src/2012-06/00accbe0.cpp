// from server: 70% by Intel
struct seg_00ac0000 {
    void f();
};

void seg_00ac0000::f()
{
    (*(char*)(reinterpret_cast<int>(this) - 0x5816fbb3))--;
}
