// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /GS- /EHsc /MD
// roc-lib: ogre-1.4.5-dll roc_local_visitor_c83fbe91eb3a0edc.cpp

// Candidate translation unit (score above; library headers required).
#undef OGRE_NONCLIENT_BUILD
#include <OgreSceneManager.h>
using namespace Ogre;
class SceneMgrQueuedRenderableVisitor : public QueuedRenderableVisitor
		{
		protected:
			/// Pass that was actually used at the grouping level
			const Pass* mUsedPass;
		public:
			SceneMgrQueuedRenderableVisitor() 
				:transparentShadowCastersMode(false) {}
			~SceneMgrQueuedRenderableVisitor();
			void visit(const Renderable* r);
			bool visit(const Pass* p);
			void visit(const RenderablePass* rp);

			/// Target SM to send renderables to
			SceneManager* targetSceneMgr;
			/// Are we in transparent shadow caster mode?
			bool transparentShadowCastersMode;
			/// Automatic light handling?
			bool autoLights;
			/// Manual light list
			const LightList* manualLightList;

		};
SceneMgrQueuedRenderableVisitor::~SceneMgrQueuedRenderableVisitor() {}
