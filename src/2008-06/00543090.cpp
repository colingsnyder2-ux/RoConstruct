// from server: 100% by king_originala
struct VChunk;

char* __cdecl flagAddress(VChunk* p);

struct S {
    char pad[0x18];
    VChunk* pointer;
    unsigned int state;

    VChunk* acquire();
    char* getPointer();
    char* getSecondPointer();
    char* getThirdPointer();
    void initialize();
};

#pragma optimize("", off)
void S::initialize()
{
    pointer = acquire();
    *flagAddress(pointer) = 1;
    *reinterpret_cast<VChunk**>(getPointer()) = pointer;
    *reinterpret_cast<VChunk**>(getSecondPointer()) = pointer;
    *reinterpret_cast<VChunk**>(getThirdPointer()) = pointer;
    state = 0;
}
