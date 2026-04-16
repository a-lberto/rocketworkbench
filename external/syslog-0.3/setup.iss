[Setup]
VersionInfoVersion={#version}
AppVersion={#version}
AppName=Syslog
AppVerName=Syslog {#version}
DefaultDirName={pf}\syslog
DefaultGroupName=syslog-win32
AllowNoIcons=yes
LicenseFile=COPYING
OutputDir=.
OutputBaseFilename=syslog-win32-{#version}
SolidCompression=yes
UsePreviousAppDir=no

[Files]
Source: "{#bindir}\libglib-2.0-0.dll";	DestDir: "{app}"
Source: "{#bindir}\iconv.dll";		DestDir: "{app}"
Source: "{#bindir}\intl.dll";		DestDir: "{app}"
Source: "{#bindir}\syslogd.exe";	DestDir: "{app}"
Source: "{#bindir}\logger.exe";		DestDir: "{app}"
Source: "{#bindir}\test.exe";		DestDir: "{app}"
Source: "{#bindir}\libsyslog-0.dll";	DestDir: "{app}"
Source: "AUTHORS";			DestDir: "{app}"
Source: "ChangeLog";			DestDir: "{app}"
Source: "NEWS";				DestDir: "{app}"
Source: "README";			DestDir: "{app}"
Source: "etc\syslog.conf";		DestDir: "{app}\etc"
Source: "doc\book\syslog-win32.html";	DestDir: "{app}"

[Icons]
Name: "{group}\Documentation"; Filename: "{app}\syslog-win32.html"
Name: "{group}\{cm:UninstallProgram,Syslog}"; Filename: "{uninstallexe}"

[Run]
Filename: "{app}\syslogd.exe"; Parameters: "--install"

[UninstallRun]
Filename: "{app}\syslogd.exe"; Parameters: "--remove"
