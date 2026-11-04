namespace RBX {
MouseCommand* createDefaultMouseCommand(Workspace*);
void Workspace::setDefaultMouseCommand() {
    stickyCommand.reset();
    currentCommand.reset(createDefaultMouseCommand(this));
}
}
