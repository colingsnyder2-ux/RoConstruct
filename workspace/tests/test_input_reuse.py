import json
import os
from pathlib import Path

import pytest

from roc import input_reuse, setup, libs, rebuild, rebuild_install, clients, integrator


def cached_tools(root):
    tools=root/'known & cached/tools'
    compiler=tools/'vc2008rtm/VC/bin/cl.exe'
    compiler.parent.mkdir(parents=True);compiler.write_bytes(b'fixture compiler')
    for path in ('libs/mfc-9.0-rtm/atlmfc/include/afxwin.h','libs/xtp-11.2.2/Source/XTToolkitPro.h',
                 'rbxgs/Client/App/include/native.h','openrbx/Client/native.h'):
        p=tools/path;p.parent.mkdir(parents=True,exist_ok=True);p.write_text('cached')
    return tools,compiler


def test_reuses_from_verified_compiler_without_shell_download_or_file_replacement(tmp_path,monkeypatch):
    cache,compiler=cached_tools(tmp_path)
    destination=tmp_path/'worker/tools'
    local=destination/'libs/keep-local/source.cpp';local.parent.mkdir(parents=True);local.write_text('agent changes')
    monkeypatch.delenv('ROC_REUSE_TOOLS',raising=False)
    first=input_reuse.attach(destination,[compiler],lambda _:None)
    assert first
    assert (destination/'libs/mfc-9.0-rtm/atlmfc/include/afxwin.h').read_text()=='cached'
    assert (destination/'rbxgs/Client/App/include/native.h').read_text()=='cached'
    assert (destination/'openrbx/Client/native.h').read_text()=='cached'
    assert local.read_text()=='agent changes'
    assert input_reuse.attach(destination,[destination/'vc2008rtm/VC/bin/cl.exe'],lambda _:None)==[]
    assert local.read_text()=='agent changes'


def test_existing_partial_tree_is_filled_only_at_missing_directory_boundaries(tmp_path,monkeypatch):
    cache,compiler=cached_tools(tmp_path)
    destination=tmp_path/'worker/tools'
    local=destination/'libs/mfc-9.0-rtm/custom.txt';local.parent.mkdir(parents=True);local.write_text('preserve')
    input_reuse.attach(destination,[compiler],lambda _:None)
    assert local.read_text()=='preserve'
    assert (local.parent/'atlmfc/include/afxwin.h').exists()


def test_configured_cache_and_broken_private_link_repair(tmp_path,monkeypatch):
    cache,compiler=cached_tools(tmp_path)
    destination=tmp_path/'worker/tools'
    config=destination.parent/'local/config/roconstruct-inputs.json';config.parent.mkdir(parents=True)
    config.write_text(json.dumps({'tools_roots':[str(cache)]}))
    monkeypatch.delenv('ROC_REUSE_TOOLS',raising=False)
    assert input_reuse.attach(destination,[],lambda _:None)
    broken=tmp_path/'broken-link';missing=tmp_path/'deleted-source';missing.mkdir()
    input_reuse.link_directory(missing,broken);missing.rmdir()
    assert input_reuse.ensure_link(cache,broken)
    assert (broken/'libs').exists()
    assert input_reuse.ensure_link(cache,broken) is False


def test_native_restart_uses_cached_headers_without_loading_linked_dependencies(tmp_path,monkeypatch):
    cache,compiler=cached_tools(tmp_path)
    root=tmp_path/'worker';work=root/'work/2008-06';work.mkdir(parents=True)
    (work/'functions.jsonl').write_text('{}');(work/'vtables.json').write_text('[{}]')
    headers=root/'rebuild/2008-06/native-headers';headers.mkdir(parents=True)
    (headers/'Frame.h').write_text('#include <XTToolkitPro.h>')
    monkeypatch.delenv('ROC_REUSE_TOOLS',raising=False)
    monkeypatch.setattr(rebuild,'ROOT',root);monkeypatch.setattr(libs,'LIBS',root/'tools/libs')
    monkeypatch.setattr(rebuild_install,'install',lambda *a:None)
    monkeypatch.setattr(clients,'load',lambda:{'2008-06':{}})
    monkeypatch.setattr(clients,'status',lambda *a:'ok')
    monkeypatch.setattr(setup,'compilers',lambda:{21022:str(compiler)})
    monkeypatch.setattr(libs,'winsdk_include',lambda:'existing SDK')
    def forbidden(*a,**kw):raise AssertionError('Recovery startup must not download or build linked dependencies')
    monkeypatch.setattr(libs,'fetch',forbidden);monkeypatch.setattr(libs,'bundle_fetch',forbidden)
    monkeypatch.setattr(setup,'download',forbidden);monkeypatch.setattr(setup,'install_compilers',forbidden)
    monkeypatch.setattr(rebuild,'load_module',forbidden);monkeypatch.setattr(rebuild,'build_module',forbidden)
    def toolchain(*a):
        assert (libs.LIBS/'mfc-9.0-rtm/atlmfc/include/afxwin.h').exists()
        return {k:'existing' for k in ('cl','link','lib','vc_include','sdk_include','sdk_lib','atlmfc_include')}
    monkeypatch.setattr(rebuild,'toolchain',toolchain)
    for _ in range(3):rebuild_install.prepare(log=lambda _:None,build_dependencies=False)


def test_resumed_workspace_restores_missing_input_links_preserving_source_and_proofs(tmp_path,monkeypatch):
    root=tmp_path/'checkout';folder=root/'local/integrators/private'
    (root/'clients/2008-06').mkdir(parents=True);(root/'tools/libs').mkdir(parents=True);(root/'src').mkdir()
    folder.mkdir(parents=True)
    native=folder/'candidate.cpp';native.write_text('uncommitted body')
    proof=folder/'receipt.json';proof.write_text('saved proof')
    monkeypatch.setattr(integrator,'ROOT',root)
    for _ in range(3):integrator.refresh_input_links(folder)
    assert (folder/'tools/libs').exists() and (folder/'clients/2008-06').exists()
    assert native.read_text()=='uncommitted body' and proof.read_text()=='saved proof'


def test_multiple_cache_roots_fill_missing_libraries_through_existing_cache_link(tmp_path,monkeypatch):
    first=tmp_path/'cache-one/tools';second=tmp_path/'cache-two/tools';destination=tmp_path/'worker/tools'
    (first/'libs/local-library').mkdir(parents=True);(first/'libs/local-library/keep.h').write_text('keep')
    (second/'libs/SDL-1.2.11/include').mkdir(parents=True);(second/'libs/SDL-1.2.11/include/SDL.h').write_text('cached SDL')
    monkeypatch.setenv('ROC_REUSE_TOOLS',os.pathsep.join(map(str,(first,second))))
    input_reuse.attach(destination,[],lambda _:None)
    assert (destination/'libs/SDL-1.2.11/include/SDL.h').read_text()=='cached SDL'
    assert (destination/'libs/local-library/keep.h').read_text()=='keep'
    assert input_reuse.attach(destination,[],lambda _:None)==[]


def test_first_private_workspace_shares_even_an_initially_empty_tool_cache(tmp_path,monkeypatch):
    for name in ('roc','research','rebuild/2008-06','clients'): (tmp_path/name).mkdir(parents=True,exist_ok=True)
    (tmp_path/'roc.py').write_text('# runtime')
    monkeypatch.setattr(integrator,'ROOT',tmp_path)
    private=integrator.workspace(log=lambda _:None)
    assert (private/'tools').resolve()==(tmp_path/'tools').resolve()
    (private/'tools/first-install').mkdir()
    assert (tmp_path/'tools/first-install').is_dir()
