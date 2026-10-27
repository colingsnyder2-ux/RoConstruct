#include <cstddef>
extern "C" int dummy();
__declspec(naked) void asm_symbol() {
    __asm {
        public ?foo@Bar@@QAEHXZ
        ?foo@Bar@@QAEHXZ:
        xor eax, eax
        ret
    }
}
int main() { return 0; }
