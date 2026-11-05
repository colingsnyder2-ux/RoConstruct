// from server: 100% by EspClaude
// roc-flags: /O1 /GS- /EHsc /MD
struct S
{
    S* GetValue();
    int f();
};

int S::f()
{
    S* p = this->GetValue();
    S* q = p ? *(S**)(*(char**)((char*)p + 0x118) + 0xe4) : 0;
    return q ? *(int*)((char*)q + 0x2c) : 0;
}
