// from server: 100% by colin
// roc-flags: /O2 /GS- /EHsc /MD
extern void tail_fn(int);
void func_004f3380(void* p)
{
    if (p)
        tail_fn(*(int*)((char*)p - 4));
}
