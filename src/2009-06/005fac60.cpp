// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class TaskScheduler {
public:
	static TaskScheduler& singleton();
	void setThreadShare(double v);
};
class TaskSchedulerSettings {
public:
	void setThreadShare(double v);
};
void TaskSchedulerSettings::setThreadShare(double v)
{
	TaskScheduler::singleton().setThreadShare(v);
}
}
