// from server: 100% by tester
namespace RBX {
namespace RenderNew {
int __fastcall nextPowerOfTwo(int n)
{
    if (n < 2)
        return 2;
    int result = 1;
    while (result < n)
        result += result;
    return result;
}
}
}
