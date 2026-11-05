// from server: 50% by colin
struct WeakReferenceCountedPointer {
    char pad0;
    char pad1;
    float f4;
    int p8;
    int pC;
    WeakReferenceCountedPointer(const WeakReferenceCountedPointer& other);
};

extern "C" void __cdecl sub_474F70(int);

WeakReferenceCountedPointer::WeakReferenceCountedPointer(const WeakReferenceCountedPointer& other) {
    pad0 = other.pad0;
    pad1 = other.pad1;
    f4 = other.f4;
    p8 = 0;
    sub_474F70(other.p8);
    pC = 0;
    sub_474F70(other.pC);
}
