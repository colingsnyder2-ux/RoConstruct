"""Tests for the cloud-first install: signed handoff, doctor, packages, idempotency.

Run directly (no pytest needed):  py -3.12 tests/test_install.py
"""
import json
import re
import sys
import tempfile
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))


class temp_root:
    """Point roc.setup at a throwaway tree so tests never touch real work."""

    def __enter__(self):
        self.dir = Path(tempfile.mkdtemp(prefix="roc-install-test-"))
        (self.dir / "work" / "2008-06").mkdir(parents=True)
        (self.dir / "src" / "2008-06").mkdir(parents=True)
        (self.dir / "work" / "2008-06" / "functions.jsonl").write_text("{}\n", encoding="utf-8")
        (self.dir / "src" / "2008-06" / "00000000.cpp").write_text("int f() { return 0; }\n", encoding="utf-8")
        (self.dir / "roconstruct-settings.json").write_text('{"user":"colin"}', encoding="utf-8")
        self.patches = [patch("roc.setup.ROOT", self.dir),
                        patch("roc.setup.TOOLS", self.dir / "tools"),
                        patch("roc.setup.DL", self.dir / "tools" / "dl"),
                        patch("roc.setup.STATE", self.dir / "tools" / "install-state.json")]
        for item in self.patches:
            item.start()
        return self.dir

    def __exit__(self, *error):
        for item in reversed(self.patches):
            item.stop()
        import shutil
        shutil.rmtree(self.dir, ignore_errors=True)


class temp_config:
    """Redirect the signed worker config and the settings file it writes."""

    def __enter__(self):
        import roc.handoff as handoff
        import roc.worker as worker
        self.dir = Path(tempfile.mkdtemp(prefix="roc-handoff-test-"))
        self.saved = (handoff.CONFIG, worker.SETTINGS)
        handoff.CONFIG = self.dir / "roconstruct-worker.json"
        worker.SETTINGS = self.dir / "roconstruct-settings.json"
        self.patches = [patch("roc.handoff.CONFIG", handoff.CONFIG),
                        patch("roc.worker.SETTINGS", worker.SETTINGS)]
        for item in self.patches:
            item.start()
        return handoff

    def __exit__(self, *error):
        for item in reversed(self.patches):
            item.stop()
        import shutil
        shutil.rmtree(self.dir, ignore_errors=True)
        return False


def test_bootstrap_installs_no_ollama_or_docker():
    """install() must never touch Ollama, Docker or a model, and must skip what it has."""
    from roc import setup
    with temp_root(), \
         patch("roc.setup.ensure_packages") as packages, \
         patch("roc.setup.compilers", return_value={21022: "cl.exe", 30729: "cl.exe", 50727: "cl.exe"}), \
         patch("roc.setup.FETCHERS") as fetchers, \
         patch("roc.setup.refresh_path"), \
         patch("roc.setup.register_link") as link, \
         patch("roc.setup.local_ai") as local_ai, \
         patch("roc.setup.extras") as extras, \
         patch("roc.setup.report", return_value=True):
        assert setup.install(ask=lambda _question: "y") is True
        assert packages.called and link.called
        assert not local_ai.called, "the default install must not install Ollama"
        assert not extras.called, "the default install must not install Docker"
        assert fetchers.__getitem__.call_count == 0, "compilers already present: no download"


def test_bootstrap_plans_only_missing_builds():
    from roc import setup
    with patch("roc.setup.compilers", return_value={30729: "cl.exe"}), \
         patch("roc.setup.has_module", return_value=True), \
         patch("roc.clients.load", return_value={
             "a": {"compiler_build": 30729, "compiler": "SP1"},
             "b": {"compiler_build": 50727, "compiler": "VS2005"},
             "c": {"compiler_build": 21022, "compiler": "RTM"}}):
        current = setup.plan()
    assert current["compilers"] == [21022, 50727], "only the missing builds are planned"
    assert current["download_mb"] == setup.BUNDLES[21022][0] + setup.BUNDLES[50727][0]
    assert current["minutes"] == setup.BUNDLES[21022][2] + setup.BUNDLES[50727][2]
    assert current["disk_mb"] > current["download_mb"], "unpacked size is bigger than the download"
    assert current["packages"] == []
    fetched = []
    with patch("roc.setup.compilers", return_value={30729: "cl.exe"}), \
         patch("roc.setup.FETCHERS", {50727: lambda: fetched.append(50727),
                                      21022: lambda: fetched.append(21022)}), \
         patch("roc.setup.compilers.cache_clear"), \
         patch("roc.setup.mark_done") as mark:
        setup.install_compilers(assume_yes=True)
    assert sorted(fetched) == [21022, 50727], "only the missing bundles are fetched"
    assert {call.args[0] for call in mark.call_args_list} == {"compiler-21022", "compiler-50727"}


def test_install_records_each_compiler_it_installed():
    """The state file is what makes the next run skip work, so it must be written."""
    from roc import setup
    with temp_root(), \
         patch("roc.setup.compilers", return_value={30729: "cl"}), \
         patch("roc.clients.load", return_value={"a": {"compiler_build": 50727,
                                                      "compiler": "VS2005"}}), \
         patch("roc.setup.FETCHERS", {50727: lambda: None}), \
         patch("roc.setup.compilers.cache_clear"):
        setup.install_compilers(assume_yes=True)
        saved = setup.state()
    assert saved["compiler-50727"]["done"] is True
    assert saved["compiler-50727"]["name"] == setup.NAMES[50727]
    assert "compiler-30729" not in saved, "a compiler that was already there is not recorded"


def test_bootstrap_never_refetches_a_present_compiler():
    from roc import setup
    have = {21022: "cl", 30729: "cl", 50727: "cl"}
    with patch("roc.setup.compilers", return_value=have), \
         patch("roc.setup.FETCHERS", {21022: _boom, 30729: _boom, 50727: _boom}), \
         patch("roc.setup.compilers.cache_clear"):
        assert setup.install_compilers(assume_yes=True) == []


def _boom():
    raise AssertionError("a compiler that is already installed must never be fetched again")


def test_bootstrap_keeps_work_settings_and_claims():
    """A re-install must not disturb work/, src/ or the settings file, file by file."""
    from roc import setup
    with temp_root() as root, \
         patch("roc.setup.ensure_packages"), \
         patch("roc.setup.compilers", return_value={21022: "cl", 30729: "cl", 50727: "cl"}), \
         patch("roc.setup.FETCHERS"), \
         patch("roc.setup.refresh_path"), \
         patch("roc.setup.register_link"), \
         patch("roc.setup.report", return_value=True):
        before = setup.snapshot(deep=True)
        assert before, "the throwaway tree must contain work to protect"
        assert setup.install(ask=lambda _question: "y") is True
        assert setup.changed_since(before, deep=True) == []
        assert (root / "work" / "2008-06" / "functions.jsonl").exists()
        assert (root / "roconstruct-settings.json").read_text(encoding="utf-8") == '{"user":"colin"}'


def test_local_ai_is_opt_in_and_asks_first():
    from roc import setup
    asked = []
    with patch("roc.setup.shutil.which", return_value="winget"), \
         patch("roc.setup.find_exe", return_value=None), \
         patch("roc.setup.refresh_path"), \
         patch("roc.setup.subprocess.run") as run:
        assert setup.local_ai(ask=lambda question: asked.append(question) or "n") is False
    assert asked, "Ollama is offered as a question, never installed silently"
    assert not run.called, "declining must not install anything"


def test_handoff_signature_round_trip_and_tamper():
    with temp_config() as handoff:
        url = handoff.link("colin", "2008-06", "https://server.example:443", cloud=True)
        assert url.startswith("roconstruct://work?") and "user=colin" in url
        handoff.save(user="colin", client="2008-06", server="https://server.example:443",
                     mode="cloud", cloud=True)
        saved = json.loads(handoff.CONFIG.read_text(encoding="utf-8"))
        assert handoff.verify(saved), "a config this machine signed must verify"
        assert handoff.load()["user"] == "colin"
        assert handoff.status()["state"] == "signed"
        saved["payload"]["cloud"] = False
        handoff.CONFIG.write_text(json.dumps(saved), encoding="utf-8")
        assert not handoff.verify(saved), "an edited config must not verify"
        assert handoff.load() == {}
        assert handoff.status()["state"] == "tampered"


def test_handoff_rejects_bad_links():
    with temp_config() as handoff:
        for url in ("roconstruct://work?client=2008-06&server=x",
                    "roconstruct://work?client=2008-06&server=x&user=bad%20name",
                    "roconstruct://work?client=../etc&server=x&user=colin",
                    "https://example.com/work?client=2008-06&server=x&user=colin"):
            try:
                handoff.from_url(url)
                assert False, "accepted a bad link: %s" % url
            except SystemExit:
                pass


def test_handoff_only_keeps_known_fields():
    with temp_config() as handoff:
        handoff.save(user="colin", client="2008-06", server="host:8765", mode="cloud",
                     cloud=True, workers="256", evil="--no-check")
        payload = handoff.load()
        assert "workers" not in payload and "evil" not in payload, "only the link vocabulary is stored"


def test_handoff_signature_depends_on_content():
    with temp_config() as handoff:
        first = handoff.sign({"user": "colin", "client": "2008-06"})
        same = handoff.sign({"client": "2008-06", "user": "colin"})
        other = handoff.sign({"user": "mallory", "client": "2008-06"})
        assert first == same, "the signature must not depend on key order"
        assert first != other, "a different payload must sign differently"


def test_cloud_worker_is_the_default_and_needs_no_gpu():
    from roc import worker
    with patch("roc.worker.cloud_default", return_value="deepseek:deepseek-flash"):
        model, allowed = worker.resolve_model({"mode": "cloud", "cloud": True})
    assert (model, allowed) == ("deepseek:deepseek-flash", True)
    with patch("roc.worker.cloud_default", return_value=None), \
         patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:14b"]):
        try:
            worker.resolve_model({"mode": "cloud", "cloud": False})
            assert False, "cloud ran without consent"
        except SystemExit as error:
            assert "consent" in str(error)
            assert "Use local model" in str(error)
    with patch("roc.worker.cloud_default", return_value=None), \
         patch("roc.draft.ollama_models", return_value=[]):
        try:
            worker.resolve_model({"mode": "cloud", "cloud": True})
            assert False, "ran with no model at all"
        except SystemExit as error:
            assert "roc provider setup" in str(error) and "roc local-ai" in str(error)
    with patch("roc.worker.cloud_default", return_value="deepseek:deepseek-flash"), \
         patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:14b"]):
        # Local mode must not silently pick the cloud model.
        model, allowed = worker.resolve_model({"mode": "local", "cloud": False,
                                               "model": "qwen2.5-coder:14b"})
    assert model == "qwen2.5-coder:14b" and allowed is False


def test_local_mode_asks_before_installing_ollama():
    """Local mode is the only path that may offer Ollama, and it asks first."""
    from roc import link
    with patch("roc.draft.pick_model", return_value=None), \
         patch("roc.link.ensure_model") as ensure, \
         patch("roc.link.choose_options", return_value=("qwen2.5-coder:14b", 4, 256, True, 1, 2048, "auto")):
        picked = link.choose_local({}, "qwen2.5-coder:14b")
    assert ensure.called, "no local model: Ollama is offered"
    assert picked[0] == "qwen2.5-coder:14b"


def test_cloud_path_never_offers_ollama():
    """With a cloud key present, the default path must not touch Ollama at all."""
    from roc import link, worker
    settings = {"model": "deepseek:deepseek-flash", "cloud_allowed": True}
    with patch("roc.providers.is_cloud", return_value=True), \
         patch("roc.providers.available", return_value=True), \
         patch("roc.worker.cloud_default", return_value="deepseek:deepseek-flash"), \
         patch("roc.draft.ollama_models", return_value=["qwen2.5-coder:14b"]), \
         patch("roc.link.ensure_model") as ensure:
        assert link.cloud_model(settings, True) == "deepseek:deepseek-flash"
        assert not ensure.called, "a cloud worker must not prompt for Ollama"
    try:
        link.cloud_model(settings, False)
        assert False, "a cloud model ran without consent"
    except SystemExit as error:
        assert "roc setup" in str(error)


def test_cloud_worker_sends_bounded_prompts():
    from roc import providers, worker
    assert worker.HANDOFF_CLOUD_REQUESTS <= 2000 and worker.HANDOFF_CLOUD_TOKENS <= 5000000
    budget = providers.CloudBudget(worker.HANDOFF_CLOUD_REQUESTS, worker.HANDOFF_CLOUD_TOKENS, 1.0)
    for _ in range(worker.HANDOFF_CLOUD_REQUESTS):
        budget.reserve(10, 0.0)
    try:
        budget.reserve(10, 0.0)
        assert False, "the request budget never stopped the worker"
    except providers.ProviderError as error:
        assert error.category == "cloud_budget"


def test_doctor_reports_problems_with_fixes():
    from roc import doctor
    rows = [doctor.check("python", "ok", "Python 3.12.10, pefile and capstone installed"),
            doctor.check("compilers", "fail", "missing VS2005 (460 MB to download)",
                         ["Run install.cmd again", "It resumes an interrupted download"]),
            doctor.check("clients", "ok", "8/8 client(s) verified"),
            doctor.check("identity", "ok", "user=colin server=host:8765"),
            doctor.check("cloud", "ok", "cloud model deepseek:deepseek-flash ready"),
            doctor.check("links", "ok", "roconstruct:// registered"),
            doctor.check("local-ai", "ok", "not installed (cloud models are the default)"),
            doctor.check("extras", "ok", "Docker/Rev.ng not installed")]
    names = [row["name"] for row in rows]
    with patch("roc.doctor.python_check", return_value=rows[0]), \
         patch("roc.doctor.compilers_check", return_value=rows[1]), \
         patch("roc.doctor.clients_check", return_value=rows[2]), \
         patch("roc.doctor.identity_check", return_value=rows[3]), \
         patch("roc.doctor.cloud_check", return_value=rows[4]), \
         patch("roc.doctor.link_check", return_value=rows[5]), \
         patch("roc.doctor.local_check", return_value=rows[6]), \
         patch("roc.doctor.extras_check", return_value=rows[7]):
        checks = doctor.all_checks(network=False)
    assert [row["name"] for row in checks] == names
    assert [row["name"] for row in doctor.failed(checks)] == ["compilers"]
    text = doctor.format_report(checks)
    assert "FAIL" in text and "fix: Run install.cmd again" in text
    assert "roc doctor" in text


def test_doctor_summary_names_the_model_a_launch_would_use():
    """The last line must match the saved config: cloud or local, never a surprise."""
    from roc import doctor
    rows = [doctor.check("python", "ok", "Python 3.12.10, pefile and capstone installed"),
            doctor.check("compilers", "ok", "all ready"),
            doctor.check("clients", "ok", "8/8 client(s) verified"),
            doctor.check("identity", "ok", "user=colin server=host:8765"),
            doctor.check("cloud", "ok", "deepseek:deepseek-flash ready"),
            doctor.check("links", "ok", "roconstruct:// registered"),
            doctor.check("local-ai", "ok", "not installed"),
            doctor.check("extras", "ok", "not installed")]
    payload = {"user": "colin", "client": "2008-06", "server": "host:8765",
               "mode": "cloud", "cloud": True, "model": "deepseek:deepseek-flash"}
    with patch("roc.handoff.load", return_value=payload), \
         patch("roc.providers.is_cloud", return_value=True), \
         patch("roc.worker.resolve_model", return_value=("deepseek:deepseek-flash", True)):
        text = doctor.format_report(rows)
    assert "A launch would use: deepseek:deepseek-flash" in text
    assert "bounded prompts leave this PC" in text
    assert "cloud worker is in place" not in text, "the summary must not assume cloud"
    # with no signed config at all it says nothing about the model
    with patch("roc.handoff.load", return_value=None):
        plain = doctor.format_report(rows)
    assert "A launch would use" not in plain
    assert "roc launch" in plain


def test_doctor_checks_run_offline():
    from roc import doctor
    python_row = doctor.python_check()
    assert "Python" in python_row["detail"] and python_row["state"] in ("ok", "fail")
    identity = doctor.identity_check()
    assert identity["name"] == "identity"
    if identity["state"] == "fail":
        assert any("roc setup" in step for step in identity["fix"])
    local = doctor.local_check()
    assert local["state"] in ("ok", "warn", "fail"), "local AI is never a hard failure"


def load_build():
    import importlib.util
    spec = importlib.util.spec_from_file_location("roc_packaging_build", ROOT / "packaging" / "build.py")
    build = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(build)
    return build


def test_packages_split_keeps_maintainer_modules_out():
    build = load_build()
    worker_modules = set(build.WORKER_MODULES)
    server_modules = set(build.SERVER_MODULES)
    assert server_modules == {"server", "discord", "progress", "dataset"}
    assert not (worker_modules & server_modules), "helper packages must not carry server code"
    for helper in ("worker", "link", "handoff", "doctor", "setup", "analyze", "draft", "providers"):
        assert helper in worker_modules, "%s must ship to helpers" % helper
    assert set(build.PACKAGES) == {"worker", "local-ai", "server"}
    for slug in ("worker", "local-ai"):
        assert set(build.PACKAGES[slug]["modules"]) == worker_modules
        assert "local-ai.cmd" not in build.PACKAGES[slug]["files"] or slug == "local-ai", \
            "only the Local AI package ships the Ollama launcher"
    assert "local-ai.cmd" in build.PACKAGES["local-ai"]["files"]
    assert "host.cmd" in build.PACKAGES["server"]["files"]


def test_packages_audit_rejects_a_missing_helper_module():
    build = load_build()
    server = dict(build.PACKAGES["server"])
    server["modules"] = [name for name in server["modules"] if name != "draft"]
    try:
        build.audit(ROOT, server)
        assert False, "a package missing a helper module must fail the build"
    except SystemExit as error:
        assert "draft" in str(error)


def test_packages_audit_allows_the_maintainer_modules():
    build = load_build()
    assert build.audit(ROOT, build.PACKAGES["worker"]) == ["dataset", "progress", "server"]
    assert build.audit(ROOT, build.PACKAGES["server"]) == []


def test_download_resumes_an_interrupted_transfer():
    """An interrupted download continues from the .part file instead of starting over."""
    import io
    from roc import setup
    with tempfile.TemporaryDirectory() as tmp:
        dest = Path(tmp) / "bundle.zip"
        part = dest.with_suffix(dest.suffix + ".part")
        part.write_bytes(b"first-half")
        asked = []

        class Response(io.BytesIO):
            status = 206
            headers = {"Content-Length": str(len(b"-second-half"))}

        def fake_urlopen(request, timeout=0):
            asked.append(request.headers.get("Range"))
            return Response(b"-second-half")

        with patch("roc.setup.urllib.request.urlopen", fake_urlopen), \
             patch("builtins.print"):
            assert setup.download("http://example/bundle.zip", dest) == dest
        assert asked == ["bytes=10-"], "the resume asked for the rest of the file"
        assert dest.read_bytes() == b"first-half-second-half"
        assert not part.exists(), "the .part file is renamed once the file is complete"

        # A complete file is never downloaded again.
        with patch("roc.setup.urllib.request.urlopen", side_effect=AssertionError("re-downloaded")):
            assert setup.download("http://example/bundle.zip", dest) == dest


def test_install_cmd_installs_only_packages_and_compilers():
    """The bootstrap script is the promise: no Ollama, no Docker, no model, no client."""
    script = (ROOT / "install.cmd").read_text(encoding="utf-8")
    flat = " ".join(script.split())
    # what it must do
    assert "py -3.12 -c \"import sys\"" in flat, "it must detect Python 3.12"
    assert "Python.Python.3.12" in flat, "a missing 3.12 is installed"
    assert "pip install --user -q --disable-pip-version-check pefile capstone" in flat
    assert "roc.py install" in flat, "the compiler bundles come from roc install"
    assert "roc.py link install" in flat, "roconstruct:// must be registered"
    assert "roc.py doctor" in flat
    # nothing launches by itself: the user starts the worker when they want to
    assert "roc.py launch" in flat, "the bootstrap must say how to start the worker"
    assert "start \"\" \"https" not in flat, "the installer must not open the browser on its own"
    assert "roc.py setup" not in flat, "the installer must not start the setup questions itself"
    # what it must never do
    for forbidden in ("Ollama.Ollama", "Docker.DockerDesktop", "ollama pull", "docker pull",
                      "client-fetch", "Docker.DockerDesktop.iso"):
        assert forbidden not in flat, "install.cmd must not install %s" % forbidden


def test_verified_client_is_never_downloaded_again():
    """A client already on disk and matching its hash is left alone."""
    from roc import clients, link, sources
    entry = {"exe": "Roblox.exe", "sha256": "abc"}
    with patch("roc.clients.load", return_value={"2008-06": entry}), \
         patch("roc.clients.status", return_value="ok"), \
         patch("roc.sources.fetch", side_effect=AssertionError("re-downloaded")) as fetch:
        link.wait_for_exe("2008-06", log=lambda *a: None)
    assert not fetch.called, "a verified client must not be fetched again"
    # ... but a missing or mismatched one is fetched, because byte matching needs it
    for status in ("missing", "hash mismatch"):
        with patch("roc.clients.load", return_value={"2008-06": entry}), \
             patch("roc.clients.status", return_value=status), \
             patch("roc.sources.load_sources", return_value={"drive": {"2008-06": {}}}), \
             patch("roc.sources.fetch") as fetch:
            link.wait_for_exe("2008-06", log=lambda *a: None)
        assert fetch.called, "%s must be downloaded for byte matching" % status


def test_reinstall_never_touches_the_server_so_leases_survive():
    """Claims live on the server: an install that calls it could disturb a running worker."""
    from roc import setup
    with temp_root(), \
         patch("roc.setup.ensure_packages"), \
         patch("roc.setup.compilers", return_value={21022: "cl", 30729: "cl", 50727: "cl"}), \
         patch("roc.setup.FETCHERS"), \
         patch("roc.setup.refresh_path"), \
         patch("roc.setup.register_link"), \
         patch("roc.setup.report", return_value=True), \
         patch("roc.worker.Api", side_effect=AssertionError("install called the server")) as api:
        setup.install(ask=lambda _question: "y")
    assert not api.called


def test_size_and_time_are_shown_before_anything_is_downloaded():
    from roc import setup
    order = []
    with temp_root(), \
         patch("roc.setup.print", side_effect=lambda *a, **k: order.append(str(a[0])) if a else None), \
         patch("roc.setup.report", return_value=True), \
         patch("roc.setup.register_link"), \
         patch("roc.setup.compilers", return_value={}), \
         patch("roc.setup.has_module", return_value=True), \
         patch("roc.setup.FETCHERS", {21022: lambda: order.append("downloaded"),
                                      30729: lambda: order.append("downloaded"),
                                      50727: lambda: order.append("downloaded")}), \
         patch("roc.setup.compilers.cache_clear"), \
         patch("roc.clients.load", return_value={"a": {"compiler_build": 30729,
                                                        "compiler": "VS2008 SP1"}}):
        setup.install(ask=lambda _question: "y")
    plan_line = next(i for i, line in enumerate(order) if "Total download" in line)
    first = next(i for i, line in enumerate(order) if line == "downloaded")
    assert plan_line < first, "the size/time estimate must come before any download"
    assert "MB" in order[plan_line] and "min" in order[plan_line]


def test_doctor_flags_a_client_hash_mismatch():
    from roc import doctor
    with patch("roc.clients.load", return_value={"2008-06": {"exe": "Roblox.exe", "sha256": "abc",
                                                            "compiler_build": 21022}}), \
         patch("roc.clients.status", return_value="hash mismatch"):
        row = doctor.clients_check()
    assert row["state"] in ("warn", "fail")
    assert "hash mismatch" in " ".join(row["fix"]).lower() or "purge" in " ".join(row["fix"]).lower()
    assert any("client-fetch" in step or "purge" in step for step in row["fix"])


def test_doctor_flags_a_python_that_cannot_unpack_compilers():
    from roc import doctor
    with patch("roc.setup.has_module", side_effect=lambda name: name != "msilib"):
        row = doctor.python_check()
    assert row["state"] == "fail"
    assert "msilib" in row["detail"]
    assert any("3.12" in step for step in row["fix"]), "the fix must name the version to use"


def test_doctor_flags_a_missing_python_package():
    from roc import doctor
    with patch("roc.setup.missing_packages", return_value=["capstone"]):
        row = doctor.python_check()
    assert row["state"] == "fail"
    assert any("pip install" in step and "capstone" in step for step in row["fix"])


def test_link_click_downloads_the_compiler_once_then_stops():
    """A link click fetches the compiler the client was built with, exactly once."""
    from roc import link
    url = ("roconstruct://work?user=colin&client=2008-06&server=host:8765")
    fetched = []
    entry = {"exe": "Roblox.exe", "sha256": "abc", "compiler_build": 21022, "compiler": "VS2008 RTM"}
    # cloud? yes, then Enter through the model / mode / workers / advanced menus
    def answers(prompt=""):
        if "cloud model" in prompt:
            return "y"
        return ""

    def click(compilers):
        with temp_config() as handoff, \
             patch("roc.clients.load", return_value={"2008-06": entry}), \
             patch("roc.clients.exe_path", return_value=Path("Roblox.exe")), \
             patch("roc.clients.status", return_value="ok"), \
             patch("roc.setup.compilers", return_value=compilers), \
             patch("roc.setup.FETCHERS", {21022: lambda: fetched.append(21022)}), \
             patch("roc.setup.compilers.cache_clear"), \
             patch("roc.link.wait_for_exe"), \
             patch("roc.analyze.analyze"), \
             patch("roc.worker.main_args", return_value="ran") as run_worker, \
             patch("roc.worker.save_settings"), \
             patch("roc.worker.load_settings", return_value={"user": "colin"}), \
             patch("roc.worker.keep_awake"), \
             patch("roc.providers.is_cloud", return_value=True), \
             patch("roc.providers.available", return_value=True), \
             patch("roc.worker.cloud_default", return_value="deepseek:deepseek-flash"), \
             patch("roc.draft.ollama_models", return_value=[]), \
             patch("roc.draft.pick_model", return_value="deepseek:deepseek-flash"), \
             patch("roc.optimizer.profile", return_value=None), \
             patch("builtins.input", answers):
            link.run(url)
        return run_worker.call_args

    first = click({})
    assert fetched == [21022], "the compiler for this client is fetched on first click"
    payload = first.args[0]
    assert payload["client"] == "2008-06" and payload["mode"] == "cloud" and payload["cloud"] is True

    second = click({21022: "cl"})
    assert fetched == [21022], "a second click must not download the compiler again"
    assert second.args[0]["user"] == "colin"


def test_local_mode_is_the_only_path_that_offers_ollama_and_docker():
    from roc import setup
    with temp_root(), \
         patch("roc.setup.shutil.which", return_value="winget"), \
         patch("roc.setup.find_exe", return_value="C:/ollama.exe"), \
         patch("roc.setup.ensure_ollama", return_value=["qwen2.5-coder:14b"]), \
         patch("roc.setup.extras") as extras:
        assert setup.local_ai(ask=lambda _q: "n") is True
    assert not extras.called, "Docker is a separate, later question"
    with temp_root(), \
         patch("roc.setup.shutil.which", return_value="winget"), \
         patch("roc.setup.find_exe", return_value="C:/ollama.exe"), \
         patch("roc.setup.ensure_ollama", return_value=["qwen2.5-coder:14b"]), \
         patch("roc.setup.extras") as extras:
        setup.local_ai(ask=lambda _q: "n", docker=True)
    assert extras.called, "--docker is the only way Docker is ever offered"


def test_doctor_reports_a_server_it_cannot_reach():
    from roc import doctor, worker
    saved = {"server": "https://gone.example", "token": None}
    with patch("roc.worker.load_settings", return_value=saved), \
         patch("roc.worker.Api") as api:
        api.return_value.call.side_effect = worker.ApiFailure("offline", "no route to host")
        state, detail, fix = doctor.server_check()
    assert state == "fail"
    assert "gone.example" in detail
    assert any("internet" in step for step in fix)
    with patch("roc.worker.load_settings", return_value=saved), \
         patch("roc.worker.Api") as api:
        api.return_value.call.return_value = {"clients": {"2008-06": {}, "2009-06": {}}}
        state, detail, _fix = doctor.server_check()
    assert state == "ok" and "2 client(s) published" in detail


def test_doctor_flags_a_compiler_that_is_missing():
    from roc import doctor
    with patch("roc.setup.compilers", return_value={}), \
         patch("roc.clients.load", return_value={"2008-06": {"compiler": "VS2008 RTM",
                                                            "compiler_build": 21022},
                                                 "2007-03": {"compiler": "VS2005",
                                                             "compiler_build": 50727}}):
        row = doctor.compilers_check()
    assert row["state"] == "fail"
    assert "VS2008 RTM" in row["detail"] and "VS2005" in row["detail"]
    assert "1400 MB" in row["detail"], "the cost of the fix is stated"
    assert any("roc install" in step for step in row["fix"])


def test_launch_command_detaches_into_its_own_console():
    with temp_config() as handoff, patch("roc.handoff.subprocess.Popen") as popen:
        try:
            handoff.start()
            assert False, "launching without a signed config must be refused"
        except SystemExit as error:
            assert "roc setup" in str(error)
        handoff.save(user="colin", client="2008-06", server="host:8765", mode="cloud", cloud=True)
        with patch("roc.handoff.os.name", "nt"):
            assert handoff.start() is True
    line = popen.call_args.args[0]
    assert "start \"RoConstruct worker\"" in line and line.rstrip().endswith("roc.cmd\" launch"), line


def test_launch_configures_in_the_terminal_when_nothing_is_saved():
    """`roc launch` must be usable on a fresh machine: it answers the questions
    here instead of telling you to go and run something else first."""
    import importlib.util
    spec = importlib.util.spec_from_file_location("roc_cli_launch_test", ROOT / "roc.py")
    cli = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cli)
    saved = []
    with temp_config() as handoff, \
         patch("roc.handoff.save", side_effect=lambda **kw: saved.append(kw) or kw), \
         patch("roc.handoff.load", side_effect=lambda **kw: (saved[-1] if saved else None)), \
         patch("builtins.input", side_effect=["colin", "1", ""]), \
         patch("roc.worker.site_server", return_value="host:8765"), \
         patch("roc.worker.USER_RE", re.compile(r"^[A-Za-z0-9_.-]{2,32}$")), \
         patch("roc.clients.load", return_value={"2008-06": {"compiler": "VS2008 RTM",
                                                             "compiler_build": 21022}}), \
         patch("roc.doctor.all_checks", return_value=[]), \
         patch("roc.setup.local_ai", return_value=True) as local_ai, \
         patch("roc.handoff.run_now", return_value="ran") as run:
        cli.main(["launch"])
    assert run.called, "the worker runs in this terminal once the questions are answered"
    assert local_ai.called, "local mode offers Ollama, and only local mode does"
    assert saved and saved[0]["user"] == "colin", saved
    assert saved[0]["client"] == "2008-06", saved
    # the default answer to "use a cloud model?" is now "no": consent is opt-in
    assert saved[0]["cloud"] is False, "cloud consent must not be assumed: %s" % saved[0]
    assert saved[0]["mode"] == "local", saved[0]


def test_launch_runs_in_this_terminal_when_cloud_is_chosen():
    """Answering yes to the cloud question must reach the cloud model, not a local one."""
    import importlib.util
    spec = importlib.util.spec_from_file_location("roc_cli_launch_cloud", ROOT / "roc.py")
    cli = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(cli)
    with temp_config() as handoff, \
         patch("roc.handoff.save", side_effect=lambda **kw: kw), \
         patch("roc.handoff.load", side_effect=lambda **kw: {"user": "colin", "client": "2008-06",
                                                             "server": "host:8765", "mode": "cloud",
                                                             "cloud": True}), \
         patch("builtins.input", side_effect=["colin", "1", "y"]), \
         patch("roc.worker.site_server", return_value="host:8765"), \
         patch("roc.worker.USER_RE", re.compile(r"^[A-Za-z0-9_.-]{2,32}$")), \
         patch("roc.clients.load", return_value={"2008-06": {"compiler": "VS2008 RTM",
                                                             "compiler_build": 21022}}), \
         patch("roc.setup.local_ai") as local_ai, \
         patch("roc.doctor.all_checks", return_value=[]), \
         patch("roc.handoff.run_now", return_value="ran") as run:
        cli.main(["launch"])
    assert not local_ai.called, "cloud was chosen, so Ollama must not be offered"
    assert run.called, "cloud consent means the worker runs right away, in this terminal"


def test_website_starts_the_worker_with_one_click():
    """The website keeps no dialog: every "Help out" is a roconstruct:// link.

    The protocol handler does the fetching, analysing and running, so a click on
    the page is the whole setup. The knobs stay available in `roc launch`.
    """
    page = (ROOT / "docs" / "index.html").read_text(encoding="utf-8")
    flat = " ".join(page.split())
    assert 'id="app"' in page, "the page needs its main container"
    # the links are built from the live client list and the published server
    assert 'href="roconstruct://work?${q}"' in page, "Help out must be a protocol link"
    assert "new URLSearchParams({client: name, server: progress.server})" in flat
    # the link decides nothing about the model: that is asked in the console
    assert 'mode: "cloud"' not in flat, "the link must not pre-pick the model path"
    assert 'cloud: "1"' not in flat, "the link must not pre-give cloud consent"
    assert "roc launch" in flat
    # ... and nothing that used to stand between the click and the worker
    for gone in ('<dialog', "id=\"setup\"", "showModal()", "location.href = url",
                 "localStorage", "su-user", "su-cloud"):
        assert gone not in page, "the setup prompt is back: %s" % gone


def test_a_website_link_asks_cloud_or_local_then_runs():
    """The link carries client+server only; the console picks the model path.

    Answering the cloud question yes must send the chosen options through to the
    worker; answering no must go down the local branch, where Ollama is offered.
    """
    from roc import link
    url = "roconstruct://work?client=2007-08&server=https%3A%2F%2Fcolinpc.tail2879d0.ts.net"
    parts = link.parse_full(url)
    assert parts == {"client": "2007-08", "server": "https://colinpc.tail2879d0.ts.net"}, parts

    def run_click(answer, settings, stub_local, stub_cloud):
        with temp_config() as handoff, \
             patch("roc.link.parse_full", return_value=parts), \
             patch("roc.link.wait_for_exe"), \
             patch("roc.worker.load_settings", return_value=settings), \
             patch("roc.worker.save_settings"), \
             patch("roc.clients.load", return_value={"2007-08": {"compiler_build": 21022,
                                                                 "compiler": "VS2008 RTM"}}), \
             patch("roc.setup.compilers", return_value={21022: "cl"}), \
             patch("roc.link.choose_options", side_effect=stub_cloud), \
             patch("roc.link.choose_local", side_effect=stub_local), \
             patch("roc.worker.keep_awake"), \
             patch("roc.worker.main_args", return_value="ran") as run, \
             patch("builtins.input", lambda prompt="": answer):
            link.run(url)
        return run

    def cloud_choices(settings):
        return "deepseek:deepseek-flash", 4, 256, True, 6, 4096, "auto"

    def local_choices(settings, wanted):
        raise AssertionError("cloud was chosen, so the local branch must not run")

    run = run_click("y", {"user": "colin", "known_servers": []}, local_choices, cloud_choices)
    assert run.called, "a click must reach the worker"
    payload, argv = run.call_args.args
    assert payload["client"] == "2007-08" and payload["cloud"] is True
    assert payload["mode"] == "cloud" and payload["model"] == "deepseek:deepseek-flash"
    assert argv == ["--workers", "6", "--rounds", "4", "--max-size", "256"]

    def cloud_refused(settings):
        raise AssertionError("the local branch must run when cloud is declined")

    def local_choices(settings, wanted):
        return "qwen2.5-coder:7b", 2, 96, False, 1, 2048, "auto"

    run = run_click("", {"user": "colin", "known_servers": []}, local_choices, cloud_refused)
    payload, argv = run.call_args.args
    assert payload["cloud"] is False and payload["mode"] == "local"
    assert payload["model"] == "qwen2.5-coder:7b"
    assert argv == ["--workers", "1", "--rounds", "2", "--max-size", "96", "--no-revng"]


def test_cloud_consent_is_asked_once_and_remembered():
    """Declining or agreeing must not re-ask on every click."""
    from roc import link
    url = "roconstruct://work?client=2007-08&server=host:8765"
    parts = link.parse_full(url)
    asked = []

    def choose_options(settings):
        return "deepseek:deepseek-flash", 4, 256, True, 1, 2048, "auto"

    with temp_config() as handoff, \
         patch("roc.link.parse_full", return_value=parts), \
         patch("roc.link.wait_for_exe"), \
         patch("roc.worker.load_settings",
               return_value={"user": "colin", "known_servers": [], "cloud_allowed": False}), \
         patch("roc.worker.save_settings") as saved, \
         patch("roc.clients.load", return_value={"2007-08": {"compiler_build": 21022,
                                                             "compiler": "VS2008 RTM"}}), \
         patch("roc.setup.compilers", return_value={21022: "cl"}), \
         patch("roc.link.choose_options", side_effect=choose_options), \
         patch("roc.worker.keep_awake"), \
         patch("roc.worker.main_args", return_value="ran"), \
         patch("builtins.input",
               lambda prompt="": asked.append(prompt) or ("y" if "cloud model" in prompt else "")):
        link.run(url)
    consent = [p for p in asked if "cloud model" in p]
    assert len(consent) == 1, "the cloud question must be asked exactly once: %s" % asked
    assert saved.call_args_list, "the answer must be remembered"
    assert any(kw.get("cloud_allowed") is True
               for _args, kw in saved.call_args_list), saved.call_args_list
    # second click: consent already recorded, no question
    asked.clear()
    with temp_config() as handoff, \
         patch("roc.link.parse_full", return_value=parts), \
         patch("roc.link.wait_for_exe"), \
         patch("roc.worker.load_settings",
               return_value={"user": "colin", "known_servers": [], "cloud_allowed": True}), \
         patch("roc.worker.save_settings"), \
         patch("roc.clients.load", return_value={"2007-08": {"compiler_build": 21022,
                                                             "compiler": "VS2008 RTM"}}), \
         patch("roc.setup.compilers", return_value={21022: "cl"}), \
         patch("roc.link.choose_options", side_effect=choose_options), \
         patch("roc.worker.keep_awake"), \
         patch("roc.worker.main_args", return_value="ran"), \
         patch("builtins.input", lambda prompt="": asked.append(prompt) or ""):
        link.run(url)
    assert not [p for p in asked if "cloud model" in p], \
        "consent is remembered, so the second click must not ask again"


if __name__ == "__main__":
    import inspect
    for name, fn in list(globals().items()):
        if name.startswith("test_"):
            if inspect.signature(fn).parameters:
                continue  # needs pytest fixtures; run under pytest
            fn()
            print("ok ", name)