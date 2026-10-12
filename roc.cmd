@echo off
setlocal
cd /d "%~dp0"
title RoConstruct
rem The one Windows launcher. No arguments: menu. First run: installs itself.
set PY=py -3.12
%PY% -c "import sys" >nul 2>nul || set PY=py
%PY% -c "import pefile, capstone" >nul 2>nul || (
  echo RoConstruct is not set up yet. Running first-time setup...
  call install.cmd
  %PY% -c "import pefile, capstone" >nul 2>nul || exit /b 1
)
%PY% roc.py %*
if "%~1"=="" pause
