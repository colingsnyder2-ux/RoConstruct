// from server: 100% by colin
struct RakPeer {
    int sub_4BAB00(int, char*);
    int sub_4BAD70(int);
    int func_4BD610(int);
};

int RakPeer::func_4BD610(int a)
{
    char flag;
    int result = sub_4BAB00(a, &flag);
    if (flag == 0)
        return 0;
    sub_4BAD70(result);
    return result;
}
