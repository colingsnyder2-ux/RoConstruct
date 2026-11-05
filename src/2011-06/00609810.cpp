// from server: 15% by atomic.potato
struct StopCommand
{
    StopCommand *GetObject();
    int IsStopped();
};

StopCommand *StopCommand::GetObject()
{
    return this;
}

int StopCommand::IsStopped()
{
    return GetObject()->GetObject()->IsStopped();
}
