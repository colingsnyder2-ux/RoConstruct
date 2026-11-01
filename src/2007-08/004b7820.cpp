// from server: 81% by colin
struct Exposer {
    void* field0;
    char pad[8];
    int fieldC;
    int field10;
    char field14;
    void* method(int* arg);
};

void* Exposer::method(int* arg)
{
    if (this->field14 != 0 && *arg == this->field10)
    {
        return (char*)this->field0 + this->fieldC * 8 + 4;
    }
    int result = (int)this->method(arg);
    this->fieldC = result;
    this->field10 = *arg;
    this->field14 = 1;
    return (char*)this->field0 + result * 8 + 4;
}
