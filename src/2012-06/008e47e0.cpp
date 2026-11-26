// from server: 100% by Xemicl
// from server: 100% by atomic.potato
// roc 2012-06 008dfa90  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 40 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008dfa90
//
// 008dfa90  56                   push esi
// 008dfa91  8bf1                 mov esi, ecx
// 008dfa93  e848f3ffff           call 0x8dede0
// 008dfa98  85c0                 test eax, eax
// 008dfa9a  741a                 je 0x8dfab6
// 008dfa9c  8d642400             lea esp, [esp]
// 008dfaa0  6a00                 push 0
// 008dfaa2  6a00                 push 0
// 008dfaa4  8bc8                 mov ecx, eax
// 008dfaa6  e85547daff           call 0x684200
// 008dfaab  8bce                 mov ecx, esi
// 008dfaad  e82ef3ffff           call 0x8dede0
// 008dfab2  85c0                 test eax, eax
// 008dfab4  75ea                 jne 0x8dfaa0
// 008dfab6  5e                   pop esi
// 008dfab7  c3                   ret 

struct T_func_008dede0;

struct S_func_008dfa90
{
    T_func_008dede0* func_008dede0();
    void f();
};

struct T_func_008dede0
{
    void func_00684200(int, int);
};

void S_func_008dfa90::f()
{
    T_func_008dede0* p = func_008dede0();
    while (p != 0)
    {
        p->func_00684200(0, 0);
        p = func_008dede0();
    }
}
