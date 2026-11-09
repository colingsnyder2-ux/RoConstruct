// from server: 100% by colin
#include <set>
struct E { int v[8]; };
bool operator<(const E&, const E&);
typedef void (__thiscall *ElementRoutine)(void*);
extern ElementRoutine elementConstructor;
extern ElementRoutine elementDestructor;
void __stdcall constructArray(void*, unsigned int, unsigned int, ElementRoutine, ElementRoutine);
struct S : std::set<E> {
 char elements[0xE00];
 int flag;
 S();
};
S::S() {
 constructArray(elements,0x1C,0x80,elementConstructor,elementDestructor);
 flag=1;
}
