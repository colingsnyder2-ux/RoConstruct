namespace RBX {
void Workspace::setNullMouseCommand() {
    stickyCommand.reset();
    setMouseCommand(0);
}
}
