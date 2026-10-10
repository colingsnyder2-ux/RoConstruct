import hashlib
import json

import pytest

from benchmarks.refine_archive import select


def candidate(root, arm, score, source):
    folder = root / arm / "2007-08"
    folder.mkdir(parents=True)
    path = folder / "00401000-direct.json"
    path.with_suffix(".cpp").write_text(source)
    path.write_text(json.dumps({"client": "2007-08", "addr": "00401000", "score": score,
                               "source_sha256": hashlib.sha256(source.encode()).hexdigest()}))
    return path


def test_selection_keeps_best_target_across_arms(tmp_path):
    candidate(tmp_path, "mass-a", 90, "int a() {}")
    candidate(tmp_path, "mass-b", 100, "int b() {}")
    rows = select(tmp_path, 85)
    assert len(rows) == 1
    assert rows[0][0]["score"] == 100
    assert rows[0][1] == "int b() {}"


def test_selection_rejects_modified_candidate(tmp_path):
    path = candidate(tmp_path, "mass-a", 100, "int a() {}")
    path.with_suffix(".cpp").write_text("changed")
    with pytest.raises(ValueError, match="hash mismatch"):
        select(tmp_path, 85)
