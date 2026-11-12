// from server: 91% by EspClaude
// from server: 56% by colin
// roc 2007-08 0059aab0  unit: RBX::VCamera::?$FactoryProduct  size: 307 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0059aab0
//
// 0059aab0  81ecc4000000         sub esp, 0xc4
// 0059aab6  56                   push esi
// 0059aab7  57                   push edi
// 0059aab8  8bf1                 mov esi, ecx
// 0059aaba  c744240800000000     mov dword ptr [esp + 8], 0
// 0059aac2  e819f6ffff           call 0x59a0e0
// 0059aac7  83be9401000000       cmp dword ptr [esi + 0x194], 0
// 0059aace  7428                 je 0x59aaf8
// 0059aad0  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 0059aad6  83f804               cmp eax, 4
// 0059aad9  740a                 je 0x59aae5
// 0059aadb  83f801               cmp eax, 1
// 0059aade  7405                 je 0x59aae5
// 0059aae0  83f803               cmp eax, 3
// 0059aae3  7513                 jne 0x59aaf8
// 0059aae5  8d84249c000000       lea eax, [esp + 0x9c]
// 0059aaec  50                   push eax
// 0059aaed  8bce                 mov ecx, esi
// 0059aaef  e8dcfbffff           call 0x59a6d0
// 0059aaf4  8bf8                 mov edi, eax
// 0059aaf6  eb06                 jmp 0x59aafe
// 0059aaf8  8dbe2c010000         lea edi, [esi + 0x12c]
// 0059aafe  57                   push edi
// 0059aaff  8d4c2410             lea ecx, [esp + 0x10]
// 0059ab03  e8c8eaf6ff           call 0x5095d0
// 0059ab08  d94724               fld dword ptr [edi + 0x24]
// 0059ab0b  83be9401000000       cmp dword ptr [esi + 0x194], 0
// 0059ab12  d95c2430             fstp dword ptr [esp + 0x30]
// 0059ab16  d94728               fld dword ptr [edi + 0x28]
// 0059ab19  d95c2434             fstp dword ptr [esp + 0x34]
// 0059ab1d  d9472c               fld dword ptr [edi + 0x2c]
// 0059ab20  d95c2438             fstp dword ptr [esp + 0x38]
// 0059ab24  741d                 je 0x59ab43
// 0059ab26  8b868c010000         mov eax, dword ptr [esi + 0x18c]
// 0059ab2c  83f804               cmp eax, 4
// 0059ab2f  740a                 je 0x59ab3b
// 0059ab31  83f801               cmp eax, 1
// 0059ab34  7405                 je 0x59ab3b
// 0059ab36  83f803               cmp eax, 3
// 0059ab39  7508                 jne 0x59ab43
// 0059ab3b  d905c44c7a00         fld dword ptr [0x7a4cc4]
// 0059ab41  eb06                 jmp 0x59ab49
// 0059ab43  d905b4a87a00         fld dword ptr [0x7aa8b4]
// 0059ab49  8d4c246c             lea ecx, [esp + 0x6c]
// 0059ab4d  d95c2408             fstp dword ptr [esp + 8]
// 0059ab51  8dbee8000000         lea edi, [esi + 0xe8]
// 0059ab57  51                   push ecx
// 0059ab58  8bcf                 mov ecx, edi
// 0059ab5a  e881bff6ff           call 0x506ae0
// 0059ab5f  d9442408             fld dword ptr [esp + 8]
// 0059ab63  51                   push ecx
// 0059ab64  d91c24               fstp dword ptr [esp]
// 0059ab67  8d542410             lea edx, [esp + 0x10]
// 0059ab6b  52                   push edx
// 0059ab6c  8d442444             lea eax, [esp + 0x44]
// 0059ab70  50                   push eax
// 0059ab71  8d4c2478             lea ecx, [esp + 0x78]
// 0059ab75  e8f62ef8ff           call 0x51da70
// 0059ab7a  8d4c243c             lea ecx, [esp + 0x3c]
// 0059ab7e  51                   push ecx
// 0059ab7f  e8acff0000           call 0x5aab30
// 0059ab84  83c404               add esp, 4
// 0059ab87  84c0                 test al, al
// 0059ab89  740c                 je 0x59ab97
// 0059ab8b  8d54243c             lea edx, [esp + 0x3c]
// 0059ab8f  52                   push edx
// 0059ab90  8bcf                 mov ecx, edi
// 0059ab92  e879bff6ff           call 0x506b10
// 0059ab97  83be9001000000       cmp dword ptr [esi + 0x190], 0
// 0059ab9e  7426                 je 0x59abc6
// 0059aba0  d9057c837a00         fld dword ptr [0x7a837c]
// 0059aba6  83ec08               sub esp, 8
// 0059aba9  d9542404             fst dword ptr [esp + 4]
// 0059abad  8d442474             lea eax, [esp + 0x74]
// 0059abb1  d91c24               fstp dword ptr [esp]
// 0059abb4  50                   push eax
// 0059abb5  8d4c2448             lea ecx, [esp + 0x48]
// 0059abb9  51                   push ecx
// 0059abba  e831080100           call 0x5ab3f0
// 0059abbf  83c410               add esp, 0x10
// 0059abc2  84c0                 test al, al
// 0059abc4  7514                 jne 0x59abda
// 0059abc6  8bce                 mov ecx, esi
// 0059abc8  e8b3e8ffff           call 0x599480
// 0059abcd  85c0                 test eax, eax
// 0059abcf  7409                 je 0x59abda
// 0059abd1  8b10                 mov edx, dword ptr [eax]
// 0059abd3  8bc8                 mov ecx, eax
// 0059abd5  8b420c               mov eax, dword ptr [edx + 0xc]
// 0059abd8  ffd0                 call eax
// 0059abda  5f                   pop edi
// 0059abdb  5e                   pop esi
// 0059abdc  81c4c4000000         add esp, 0xc4
// 0059abe2  c3                   ret 

// Constants read from the exe: 0x7a4cc4 = 0.9f, 0x7aa8b4 = 0.4f, 0x7a837c = 0.01f.

struct Vector3 {
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Matrix3 {
    float elt[9];
    Matrix3(const Matrix3& o);                       // 0x5095d0 (thiscall)
};

struct CoordinateFrame {                             // 0x30 bytes
    Matrix3 rotation;
    Vector3 translation;                             // +0x24
    CoordinateFrame lerp(const CoordinateFrame& other, float alpha) const;   // 0x51da70
};

bool isValid(const CoordinateFrame& c);              // cdecl 0x5aab30
bool fuzzyEq(const CoordinateFrame& a, const CoordinateFrame& b, float posEps, float rotEps);  // cdecl 0x5ab3f0

struct Camera {                                      // at VCamera+0xe8
    CoordinateFrame getCoordinateFrame() const;      // 0x506ae0
    void setCoordinateFrame(const CoordinateFrame& c);  // 0x506b10
};

struct Listener {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void onCameraChanged();                  // +0x0c
};

struct VCamera {
    char pad0[0xe8];
    Camera camera;                                   // +0xe8
    char pad_e9[0x12c - 0xe9];
    CoordinateFrame cframe;                          // +0x12c
    char pad_15c[0x18c - 0x15c];
    int mode;                                        // +0x18c
    int notify;                                      // +0x190
    int enabled;                                     // +0x194

    void update();                                   // 0x59a0e0
    CoordinateFrame computeFocusFrame();             // 0x59a6d0
    Listener* getListener();                         // 0x599480
    bool isTracking() const {
        return enabled != 0 && (mode == 4 || mode == 1 || mode == 3);
    }
    void step();
};

void VCamera::step()
{
    float alpha = 0.0f;
    float* pAlpha = &alpha;
    update();
    CoordinateFrame goal = isTracking() ? computeFocusFrame() : cframe;
    *pAlpha = isTracking() ? 0.9f : 0.4f;
    CoordinateFrame current = camera.getCoordinateFrame();
    CoordinateFrame next = current.lerp(goal, alpha);
    if (isValid(next))
        camera.setCoordinateFrame(next);
    if (!notify || !fuzzyEq(next, current, 0.01f, 0.01f)) {
        Listener* l = getListener();
        if (l)
            l->onCameraChanged();
    }
}
