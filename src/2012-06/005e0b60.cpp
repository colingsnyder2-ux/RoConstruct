// from server: 51% by tester
namespace RBX {
    namespace Test {
        struct Memory {
            long initialBytes;
            Memory();
            long GetBytes();
        };
    }
}

extern "C" long __stdcall Memory_GetBytes(RBX::Test::Memory* memory);

RBX::Test::Memory::Memory() : initialBytes(0) {}

long RBX::Test::Memory::GetBytes() {
    return initialBytes;
}

extern "C" long __stdcall Memory_GetBytes(RBX::Test::Memory* memory) {
    return memory->GetBytes();
}
