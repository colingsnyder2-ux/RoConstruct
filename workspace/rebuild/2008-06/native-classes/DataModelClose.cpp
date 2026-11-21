// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::DataModel::closeDataModel 0057b800 (static, 496 B), a row of the DataModel unit (inactive).
// Identity: registry ?closeDataModel@DataModel@RBX@@SAXV?$shared_ptr@VDataModel@RBX@@@boost@@_N@Z; caller
// CWorkspace (closeDataModel(dataModel, true)). Shape after the donor tools/openrbx v8datamodel/DataModel.cpp
// closeDataModel(dataModel, joinRunThread) with the 2008 differences read from the target.
#include "v8datamodel/DataModel.h"
#include "v8datamodel/ChangeHistoryService.h"
#include "util/RunStateOwner.h"
#include "reflection/signal.h"

namespace RBX
{
	// INFERRED: Service.h only forward-declares the ServiceProvider Closing event; the target passes it as one
	// zeroed byte (mov byte [esp+0x38], 0; push) to Notifier<ServiceProvider, Closing>::raise 005768b0, so it is
	// an empty class (RTTI .?AV?$Notifier@VServiceProvider@RBX@@VClosing@2@@RBX@@ names it a class).
	class Closing
	{
	};

	// INFERRED: the DataModel unit's "Close" signal descriptor (dword 00974fc8, vtable 008300a4
	// SignalDesc<DataModel, void()>, initializer ??__Eevent_Closing@RBX@@YAXXZ 007f36a0); defined with the rest of
	// the DataModel reflection rows, referenced here.
	extern Reflection::SignalDesc<DataModel, void()> event_Closing;

	// 0057b800: under the first Lock (00411b40 / ~Lock 005773c0): ChangeHistoryService (find 00452a00, null-checked
	// provider) setEnabled(false) 0058c8b0, renderEnabled (+0x259) = false, runService (+0x20c/+0x210, shared_count
	// operator= 004025b0) requestStop 00554330 unconditionally. Then stop 00554460 when joinRunThread and runService.
	// Under the second Lock: raise Closing 005768b0 (ServiceProvider Notifier base +0x130), event_Closing fire
	// (findSignalInstance 0056b620 on SignalSource +0x14, signal0 operator() 004b5950), clearContents 00578ef0,
	// removeAllChildren 0055afd0, clearServices 00572db0.
	void DataModel::closeDataModel(boost::shared_ptr<DataModel> dataModel, bool joinRunThread)
	{
		boost::shared_ptr<RunService> runService;
		{
			DataModel::Lock lock(dataModel);

			if (ChangeHistoryService* changeHistory = ServiceProvider::find<ChangeHistoryService>(dataModel.get()))
				changeHistory->setEnabled(false);

			dataModel->renderEnabled = false;
			runService = dataModel->runService;
			runService->requestStop();
		}

		if (joinRunThread && runService)
			runService->stop();

		{
			DataModel::Lock lock(dataModel);

			// INFERRED: the donor calls the DataModel inline raiseClose() here (raise Closing, then fire event_Closing
			// on this); the target keeps that single this in esi for both, which the core DataModel.h (no raiseClose
			// declaration) is reproduced with through one local pointer.
			DataModel* model = dataModel.get();
			model->Notifier<ServiceProvider, Closing>::raise(Closing());
			event_Closing.fire(model);

			dataModel->clearContents();
			dataModel->removeAllChildren();
			dataModel->clearServices();
		}
	}
}
