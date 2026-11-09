// from server: 39% by atomic.potato
struct S
{
    int Call(int);
    int* field;
};

int S::Call(int value)
{
    int result = Call(value);
    int* object = field;
    int (*function)(int, int) = (int (*)(int, int))(*(int**)object + 3);
    return function(*object, result);
}
