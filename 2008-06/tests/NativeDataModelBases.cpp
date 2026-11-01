#include "../native-headers/v8tree/Service.h"
#include "../native-headers/v8tree/VerbContainer.h"
#include "../native-headers/v8tree/IDataState.h"
#include "util/Evaluator.h"

namespace RBX {
class RunService;
class RunTransition;
class DataModel;
extern const char* sDataModel;
// Layout probe only: DataModel's own members are intentionally not declared.
class DataModel : public DescribedNonCreatable<DataModel, ServiceProvider, &sDataModel>,
                  public VerbContainer, public IDataState, public Evaluator,
                  public Listener<RunService, RunTransition> {};
}
typedef char NativeDataModelBaseExtent[sizeof(RBX::DataModel) == 0x1fc ? 1 : -1];
