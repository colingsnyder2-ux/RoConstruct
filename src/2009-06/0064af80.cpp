// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class DataModel;
namespace TaskScheduler {
class Job {
public:
    Job(const char* name);
    virtual ~Job();
private:
    char pad[0x1c0 - 4];
};
}
class DataModelJob : public TaskScheduler::Job {
public:
    DataModelJob(const char* name, DataModel* dataModel, bool flag, int value);
    virtual ~DataModelJob();
private:
    DataModel* dataModel;
    int value;
    bool flag;
};
DataModelJob::DataModelJob(const char* name, DataModel* dataModel, bool flag, int value)
    : Job(name), dataModel(dataModel), value(value), flag(flag)
{
}
}
