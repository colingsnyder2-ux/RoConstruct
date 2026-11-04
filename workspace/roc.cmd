@echo off
setlocal
cd /d "%~dp0"
title RoConstruct
rem The one Windows launcher. No arguments: menu. First run: installs itself.
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
if defined ROC_BOOTSTRAPPED exit /b 1
set "ROC_BOOTSTRAPPED=1"
if not "%~1"=="" set "ROC_NONINTERACTIVE=1"
call install.cmd
if errorlevel 1 exit /b 1
goto find_python
:python_ready
rem `roc update` only syncs Git source. Do not trigger the full installer first.
if /I "%~1"=="update" goto run
%PY% -c "import pefile, capstone" >nul 2>nul || (
  echo RoConstruct is not set up yet. Running first-time setup...
  if not "%~1"=="" set "ROC_NONINTERACTIVE=1"
  call install.cmd
  %PY% -c "import pefile, capstone" >nul 2>nul || exit /b 1
)
:run
%PY% roc.py %*
set ROC_EXIT_CODE=%errorlevel%
if "%~1"=="" pause
exit /b %ROC_EXIT_CODE%
