// from server: 96% by atomic.potato
typedef unsigned long DWORD;

extern "C" void __cdecl SequenceBase(DWORD);

struct S
{
    DWORD value;
    S(DWORD);
};

S::S(DWORD value)
{
    this->value = value;
    SequenceBase(*(DWORD *)value + 4);
}
