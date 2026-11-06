# Inactive Workspace XML writer lifetime candidate

Use only as an isolated recovery probe. This does not replace the canonical
WorkspaceXmlWriter.cpp or activate the native-Doc diagnostic.

The local v8xml/XmlSerializer.h retains the real writer members and its implicit
destructor. The existing std-noinline-string profile preserves the original
MSVCP90 c_str import used by std::logic_error::what. It changes no STL layout.
Pinned native-flags select that profile; the batch path is relative to
rebuild/2008-06, as required by native_check_runner.py.

Fresh proof: constructor98B and destructor77B are exact in the same object,
with byte/data checks, sizeof(TextXmlWriter)==0x28 and derived size0x4c.
Both lifetime EH graphs pass58 nodes, including the c_str import binding.
These are separate from whole reflection/class ABI, final linked ownership and
P5/P6/runtime proof.

CWorkspace::write remains NONEXACT: this coherent implicit-destructor profile
emits130B instead of112B. The older112B caller still has one wrong state byte.
Do not select it, patch that byte or combine inconsistent class definitions to
claim an exact swap. See the owner receipt for failed variants and hashes.
