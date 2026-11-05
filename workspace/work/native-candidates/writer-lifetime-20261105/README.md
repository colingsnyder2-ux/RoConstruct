# Inactive Doc writer dependency candidate

Native destination: work/workspace; original paths are rebuild/2008-06/native-classes/WorkspaceXmlWriter.cpp and rebuild/2008-06/native-headers/writer-2008/v8xml/XmlSerializer.h. These scoped copies do not replace canonical headers or executable providers.

Hypothesis: let the compiler generate the writer destructor, and use the existing std-noinline-string profile because original std::logic_error::what tail-calls imported basic_string::c_str. Without that import profile, byte-exact primary writer bodies still fail the transitive EH graph.

Compile once with native_check_runner.py run diagnostic.json. Reuse that run with analyze RUN --manifest proof.json --require-proof for constructor/destructor byte/data/direct-call checks. Audit both EH graphs on the same object. The caller remains nonexact (130 vs 112 bytes), so never select it or run the native-Doc diagnostic. Original caller EH state 1 remains unresolved. Runtime, provider closure and credit remain unproven.

No shared header/source was changed. Explicit empty destructor baseline is 83 vs 77 bytes; implicit destructor is 77 exact. Scoped auto_inline control did not repair caller inlining/state. Retain those rejected batches in work/integration-writer-lifetime-20261105.
