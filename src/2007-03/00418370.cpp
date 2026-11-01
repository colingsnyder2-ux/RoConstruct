// from server: 100% by tester
struct Marshaller
{
    void execute(int job);
};

void Marshaller::execute(int job)
{
    if (this)
    {
        void (Marshaller::*p)(int) = *(void (Marshaller::**)(int))this;
        p = *(void (Marshaller::**)(int))(*(int*)this + 4);
        (this->*p)(1);
    }
}
