// from server: 100% by tester
extern int global_value;
extern "C" int __stdcall helper(int, int, int, int);

int __stdcall function(int argument)
{
    return helper(global_value, 116, argument, 0);
}
