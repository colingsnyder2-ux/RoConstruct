// from server: 100% by king_originala
class Controller;

struct Primitive
{
    char data[0x170];
    void setController(Controller* controller);
};

struct PartInstance
{
    char data[0x228];
    Primitive primitive;
    bool dirty;

    void update();
    void updateModel();
    Controller* getController();
};

void PartInstance::update()
{
    updateModel();
    dirty = true;
    primitive.setController(getController());
}
