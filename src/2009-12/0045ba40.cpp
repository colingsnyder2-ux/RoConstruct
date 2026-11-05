// from server: 81% by atomic.potato
extern unsigned char byte_B7B811;
extern void __cdecl func_007F3E18(int, int, int);
extern void __cdecl func_00423960(int, int);

int func_0045BA40(int a, int b, int c)
{
    if (byte_B7B811 == 0) {
        func_007F3E18(a, b, c);
        return 0;
    }
    func_00423960(a, 4);
    return 0;
}
