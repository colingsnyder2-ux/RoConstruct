// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class SimpleMutex { public: void Lock(); void Unlock(); char data[0x1c]; };
class C {
public:
    char pad0[0xc];
    unsigned int numberOfBitsUsed;
    char pad1[0x8];
    unsigned int value;
    char pad2[0x530];
    SimpleMutex mutex;
    void Get(unsigned int* a, unsigned int* b);
};
void C::Get(unsigned int* a, unsigned int* b)
{
    mutex.Lock();
    *a = value;
    *b = (numberOfBitsUsed + 7) >> 3;
    mutex.Unlock();
}
