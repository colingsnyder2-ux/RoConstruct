from roc import libs
from benchmarks.rtm_desktop_repair import desktop_files


def test_rtm_variants_use_rtm_source_and_headers():
    for name in ("mfc-9.0-rtm", "mfc-9.0-shared-rtm", "atl-9.0-rtm"):
        recipe = libs.RECIPES[name]
        assert recipe["src"] == "mfc-9.0-rtm" or recipe["src"].startswith("mfc-9.0-rtm/")
        assert not any(path.startswith("mfc-9.0/") for path in recipe["include"])
        assert recipe["builds"] == [21022]


def test_desktop_extraction_excludes_ce_duplicate_headers():
    desktop = {"path": r"Program Files\Microsoft Visual Studio 9.0\Vc7\atlmfc\include\afx.h"}
    ce = {"path": r"Program Files\Microsoft Visual Studio 9.0\Vc7\ce\atlmfc\include\afx.h"}
    binary = {"path": r"Program Files\Microsoft Visual Studio 9.0\Vc7\atlmfc\lib\mfc90.lib"}
    assert desktop_files([desktop, ce, binary]) == [desktop]
