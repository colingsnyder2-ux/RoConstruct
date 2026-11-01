// from server: 100% by king_originala
extern int global_value;
extern "C" int __stdcall helper(int, int, int, int);

int __stdcall function(int argument)
{
    return helper(global_value, 106, argument, 0);
}
