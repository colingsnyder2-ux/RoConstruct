// from server: 100% by tester
namespace RBX {
class Controller;

class NullController
{
public:
    static Controller* getStaticNullController();
};

class Primitive
{
    char gap0[0xe8];
    Controller* controller;
public:
    void setController(Controller* _controller);
};

void Primitive::setController(Controller* _controller)
{
    if (!_controller)
        _controller = NullController::getStaticNullController();

    if (controller != _controller)
        controller = _controller;
}
}
