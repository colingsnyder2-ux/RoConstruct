@echo off
setlocal
cd /d "%~dp0"
title RoConstruct setup

rem RoConstruct needs Python 3.12. 3.13 removed msilib, which is how the old MSVC
rem compilers get unpacked. Everything else this script does is small: two pip
rem packages, the exact compiler bundles, the roconstruct:// link, then the site.
rem It installs no Ollama, no Docker, no model and no client: those are opt-in.

:find_python
set "PY=python"
%PY% -c "import sys; sys.exit(sys.version_info[:2] != (3,12))" >nul 2>nul
if not errorlevel 1 goto python_ready
set "PY=py -3.12"
%PY% -c "import sys; sys.exit(sys.version_info[:2] != (3,12))" >nul 2>nul
if not errorlevel 1 goto python_ready
set PY="%LOCALAPPDATA%\Programs\Python\Python312\python.exe"
%PY% -c "import sys; sys.exit(sys.version_info[:2] != (3,12))" >nul 2>nul
if not errorlevel 1 goto python_ready
if defined ROC_PYTHON_INSTALL_ATTEMPTED goto python_failed
set "ROC_PYTHON_INSTALL_ATTEMPTED=1"
echo Python 3.12 not found. Installing it with winget...
where winget >nul 2>nul || goto python_failed
winget install --id Python.Python.3.12 -e --scope user --accept-package-agreements --accept-source-agreements
if errorlevel 1 goto python_failed
goto find_python
:python_failed
echo Python 3.12 could not be started. Python installation or launcher failed.
echo Install Python 3.12 from python.org or repair App Installer, then retry.
if not defined ROC_NONINTERACTIVE pause
exit /b 1
:python_ready

rem The update can rewrite this very file, and cmd reads a running .cmd by byte offset,
rem so after updating run the fresh copy and leave this one without reading any further.
rem A packaged native workflow may be newer than public Git. Keep its tested files.
if exist roconstruct-package.json goto packages
if not defined ROC_UPDATED (
  set ROC_UPDATED=1
  echo Checking for RoConstruct updates...
  %PY% roc.py update
  call "%~f0" %*
  exit /b
)

:packages
echo Checking Python packages (pefile, capstone)...
%PY% -m pip install --user -q --disable-pip-version-check pefile capstone || (
  echo pip failed. Check your internet connection and run this again.
  if not defined ROC_NONINTERACTIVE pause
  exit /b 1
)

rem Compilers only. Safe to run twice: downloads resume, anything already installed
rem is left alone, and work/, src/ and settings are never written to.
%PY% roc.py install --yes
if errorlevel 1 (
  echo.
  echo Some downloads did not finish. Run install.cmd again: it picks up where it stopped.
  if not defined ROC_NONINTERACTIVE pause
  exit /b 1
)

echo.
echo Registering roconstruct:// so the website can start the worker...
%PY% roc.py link install

echo.
echo Checking everything is in place...
%PY% roc.py doctor
if errorlevel 1 (
  echo Setup checks failed. Resolve the reported errors before continuing.
  if not defined ROC_NONINTERACTIVE pause
  exit /b 1
)

echo.
echo ------------------------------------------------------------------
echo  Setup complete. No Ollama, no Docker, no GPU required.
echo  RoConstruct is installed and ready.
echo.
echo  Next: click "Help out" on any client at
echo    https://colingsnyder2-ux.github.io/RoConstruct/index.html
echo  A console opens and asks: cloud or local model, which model,
echo  worker mode, how many workers, then start or edit the options.
echo.
echo  Same questions any time from this folder:
echo    py -3.12 roc.py launch
echo.
echo Something wrong? Run:  py -3.12 roc.py doctor
echo.
if not defined ROC_NONINTERACTIVE pause
