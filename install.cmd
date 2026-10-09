@echo off
setlocal
cd /d "%~dp0"
title RoConstruct setup

rem RoConstruct needs Python 3.12. 3.13 removed msilib, which is how the old MSVC
rem compilers get unpacked. Everything else this script does is small: two pip
rem packages, the exact compiler bundles, the roconstruct:// link, then the site.
rem It installs no Ollama, no Docker, no model and no client: those are opt-in.

py -3.12 -c "import sys" >nul 2>nul
if errorlevel 1 (
  echo Python 3.12 not found. Installing it with winget...
  where winget >nul 2>nul || (
    echo winget is missing. Install "App Installer" from the Microsoft Store, or Python 3.12 from python.org, then run this again.
    pause & exit /b 1
  )
  winget install --id Python.Python.3.12 -e --scope user --accept-package-agreements --accept-source-agreements
  py -3.12 -c "import sys" >nul 2>nul || (
    echo.
    echo Python was installed. Close this window and double-click install.cmd again.
    pause & exit /b 0
  )
)

echo Checking Python packages (pefile, capstone)...
py -3.12 -m pip install --user -q --disable-pip-version-check pefile capstone || (
  echo pip failed. Check your internet connection and run this again.
  pause & exit /b 1
)

rem Compilers only. Safe to run twice: downloads resume, anything already installed
rem is left alone, and work/, src/ and settings are never written to.
py -3.12 roc.py install --yes
if errorlevel 1 (
  echo.
  echo Some downloads did not finish. Run install.cmd again: it picks up where it stopped.
  pause & exit /b 1
)

echo.
echo Registering roconstruct:// so the website can start the worker...
py -3.12 roc.py link install

echo.
echo Checking everything is in place...
py -3.12 roc.py doctor

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
pause