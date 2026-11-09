// from server: 100% by colin
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
extern "C" int __cdecl helper(int, int);

int __cdecl sub_748f30(int a, int b, int c)
{
    int (*fn)(int, int) = *(int (**)(int, int))a;
    return fn(b, c);
}