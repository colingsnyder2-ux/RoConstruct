import hashlib
import json
from unittest.mock import patch

from roc import benchmark


def test_benchmark_archives_source_with_verification_metadata(tmp_path):
    source = 'extern "C" int func() { return 7; }'
    target = {"client": "test", "addr": "00401000", "size": 6}
    with patch("roc.match.target", return_value=(b"", [], target)), \
         patch("roc.match.disasm", return_value=""), \
         patch("roc.draft.facts_from_asm", return_value={}), \
         patch("roc.draft.target_data_facts", return_value={}), \
         patch("roc.draft.llm_rounds", return_value=(100, source)), \
         patch("roc.clients.load", return_value={"test": {"flags": "/O2"}}), \
         patch("roc.refsource.prompt_hints", return_value=[]), \
         patch("roc.providers.parse_model", return_value=("test", "model", {})), \
         patch("roc.metrics.record"):
        benchmark.run_local([target], ["test:model"], session="archive-test",
                            candidate_dir=tmp_path, log=lambda _: None)
    assert (tmp_path / "test/00401000-direct.cpp").read_text() == source
    metadata = json.loads((tmp_path / "test/00401000-direct.json").read_text())
    assert metadata["score"] == 100
    assert metadata["compiler_flags"] == "/O2"
    assert metadata["source_sha256"] == hashlib.sha256(source.encode()).hexdigest()


def test_failed_generation_does_not_archive_stale_source(tmp_path):
    target = {"client": "test", "addr": "00401000", "size": 6}
    with patch("roc.match.target", return_value=(b"", [], target)), \
         patch("roc.match.disasm", return_value=""), \
         patch("roc.draft.facts_from_asm", return_value={}), \
         patch("roc.draft.target_data_facts", return_value={}), \
         patch("roc.draft.llm_rounds", side_effect=RuntimeError("generation failed")), \
         patch("roc.clients.load", return_value={"test": {}}), \
         patch("roc.refsource.prompt_hints", return_value=[]), \
         patch("roc.providers.parse_model", return_value=("test", "model", {})), \
         patch("roc.metrics.record"):
        benchmark.run_local([target], ["test:model"], candidate_dir=tmp_path, log=lambda _: None)
    assert not list(tmp_path.iterdir())
