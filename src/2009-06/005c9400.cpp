// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace RBX {
struct Thread8 { int a, b; };
class TaskScheduler {
public:
	static TaskScheduler& singleton();
	char pad[0x178];
	std::vector<Thread8> threads;
	int threadCount() const { return (int)threads.size(); }
};
class TaskSchedulerSettings {
public:
	int getThreadCount() const;
};
int TaskSchedulerSettings::getThreadCount() const
{
	return TaskScheduler::singleton().threadCount();
}
}
