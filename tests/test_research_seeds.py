from types import SimpleNamespace

import pytest

from roc import research


def test_seed_grid_includes_sourceless_code_and_skips_data_and_exacts(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    monkeypatch.setattr(research.match, "_functions", lambda client: {
        "open": dict(size=3108, kind="code"), "data": dict(size=4096, kind="data"),
        "exact": dict(size=4000, kind="code"), "near": dict(size=4000, kind="code")})
    (tmp_path / "seed.cpp").write_text("void recovered() {}")
    looked_up = []
    def current(client, addr):
        looked_up.append((client, addr))
        return dict(addr=addr, score=100 if addr=="exact" else 0, source=None)
    campaign = SimpleNamespace(api=SimpleNamespace(call=lambda *a, **kw: [
        dict(addr="near", score=95, source="best source")]), current=current)
    spec = dict(seed_sources={"2008-06": {a:"seed.cpp" for a in ["open", "data", "exact"]}},
                targets=dict(scores=[0,39], sizes=[3000,10000]))
    rows = research.grid_rows(campaign, spec, "2008-06")
    assert [(r["addr"],r["source"],r["score"]) for r in rows] == [("open","void recovered() {}",0)]
    assert looked_up == [("2008-06","open"),("2008-06","exact")]
    looked_up.clear()
    assert research.grid_rows(campaign, spec, "2009-06") == []
    assert looked_up == []


def test_seed_grid_rejects_paths_outside_workspace(tmp_path, monkeypatch):
    monkeypatch.setattr(research, "ROOT", tmp_path)
    monkeypatch.setattr(research.match, "_functions", lambda client: {"open":dict(size=4000,kind="code")})
    campaign = SimpleNamespace(api=SimpleNamespace(call=lambda *a, **kw: []),
                               current=lambda *a: dict(score=0))
    with pytest.raises(ValueError, match=r"workspace C\+\+ file"):
        research.grid_rows(campaign,dict(seed_sources={"2008-06":{"open":"../outside.cpp"}}),"2008-06")


def test_grid_never_mines_exact_sources_even_with_wide_score_filter(monkeypatch):
    monkeypatch.setattr(research.match,"_functions",lambda client:{"exact":dict(size=4000,kind="code")})
    assert research.select([dict(addr="exact",score=100,source="exact")],dict(scores=[0,100]))==[]


def test_partial_grid_keeps_only_best_candidate_and_preserves_it_on_resume(tmp_path, monkeypatch):
    history = []
    campaign = SimpleNamespace(root=tmp_path, previous=lambda stage:list(history),
                               record=lambda stage,row:history.append(row))
    sources = [("best",21022,"fast"),("loser",21022,"normal")]
    monkeypatch.setattr(research,"variants",lambda *a,**kw:iter(sources))
    monkeypatch.setattr(research.match,"check_text",lambda client,addr,source:(40 if source=="best" else 30,"face","diff",[]))
    row = dict(addr="004def80",score=0,source="starter")
    assert research.grid(campaign,"pilot",[row],keep_partials=True,log=lambda line:None) == []
    path=tmp_path/"candidates/pilot/2008-06/004def80.cpp"
    assert path.read_text() == "best"
    sources.append(("new loser",50727,"other"))
    research.grid(campaign,"pilot",[row],keep_partials=True,log=lambda line:None)
    assert path.read_text() == "best"
    assert len(history)==3


def test_default_grid_does_not_write_partial_candidate(tmp_path, monkeypatch):
    campaign=SimpleNamespace(previous=lambda stage:[],record=lambda *a:None)
    monkeypatch.setattr(research,"variants",lambda *a,**kw:iter([("partial",21022,"flags")]))
    monkeypatch.setattr(research.match,"check_text",lambda *a:(40,"face","diff",[]))
    assert research.grid(campaign,"pilot",[dict(addr="004def80",score=0,source="source")],log=lambda line:None)==[]
    assert list(tmp_path.iterdir())==[]


def test_partial_grid_does_not_preserve_a_regression_against_server_best(tmp_path, monkeypatch):
    campaign=SimpleNamespace(root=tmp_path,previous=lambda stage:[],record=lambda *a:None)
    monkeypatch.setattr(research,"variants",lambda *a,**kw:iter([("loser",21022,"flags")]))
    monkeypatch.setattr(research.match,"check_text",lambda *a:(40,"face","diff",[]))
    research.grid(campaign,"pilot",[dict(addr="004def80",score=54,source="starter")],
                  keep_partials=True,log=lambda line:None)
    assert list(tmp_path.iterdir())==[]
