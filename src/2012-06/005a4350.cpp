// from server: 44% by tester
// roc 2012-06 005a4350  unit: RBX::Network::InstancePacketCache::VCachedBitStream::?$sp_counted_impl_p  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005a4350

struct S {
    char pad0[4];
    int field4;
    char pad8[8];
    int field10;
    char pad14[4];
    int field18;
    int method(int);
};

extern "C" int __cdecl sub_42BCB0(int, int, int, int);
extern "C" int __cdecl sub_5A3900(int, int, int);
extern "C" int __cdecl sub_5CB270(int, int, int);
extern "C" int __cdecl sub_4D5990(int, int);
extern "C" int __cdecl sub_7A00F0(int);
extern "C" int __cdecl sub_5A4270(int);

int S::method(int arg)
{
    int local;
    int result;
    int *p;

    result = sub_42BCB0(0x00b5dba8, 0x00b5dc18, (int)&local, 0);
    if (result == 0x00b5dc18)
        result -= 4;
    result = *(int*)result;
    if (result != this->field18)
    {
        sub_5A3900((int)&local, (int)&this->field10, result);
        p = (int*)(this->field4 + (int)this);
        sub_5CB270((int)&this->field10, (int)&local, (int)p);
        sub_4D5990((int)&local, (int)&this->field10);
        sub_7A00F0((int)this);
        sub_5A4270((int)&local);
    }
    return arg;
}
