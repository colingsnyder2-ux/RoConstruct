import json

from benchmarks.aggregate_search import aggregate
from benchmarks import mass_search


def test_aggregate_selects_best_arm(tmp_path):
    folder = tmp_path / "direct" / "C"
    folder.mkdir(parents=True)
    (folder / "1.json").write_text(json.dumps({"client": "C", "addr": "1", "score": 87,
                                                 "strategy": "direct", "session": "d"}))
    (folder / "1.cpp").write_text("int f(){}")
    folder = tmp_path / "structured" / "C"
    folder.mkdir(parents=True)
    (folder / "1.json").write_text(json.dumps({"client": "C", "addr": "1", "score": 100,
                                                 "strategy": "structured", "session": "s"}))
    (folder / "1.cpp").write_text("int f(){return 1;}")
    rows = aggregate(tmp_path)
    assert rows == [{"client": "C", "addr": "1", "best_score": 100,
                     "winner": {"score": 100, "strategy": "structured", "session": "s",
                                "source": str((tmp_path / "structured/C/1.cpp"))},
                     "trials": 2, "exact_trials": 1}]


def test_local_mass_runner_skips_cloud_preflight(monkeypatch):
    seen = []
    monkeypatch.setattr(mass_search.providers, "is_cloud", lambda model: False)
    monkeypatch.setattr(mass_search.providers, "generate", lambda *args, **kwargs: seen.append(1))
    assert not mass_search.providers.is_cloud("qwen2.5-coder:7b-instruct")
    assert seen == []
