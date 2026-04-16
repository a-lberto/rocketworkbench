if OS_WIN32

if DEBUG
AM_CFLAGS = -g
endif

lib_LTLIBRARIES = libsyslog.la
bin_PROGRAMS = logger

libsyslog_la_SOURCES = syslog-client.c
if RELOCATABLE
libsyslog_la_CPPFLAGS = -DSYSLOG_CONF_DIR=\".$(sysconfdir)\"
else
libsyslog_la_CPPFLAGS = -DSYSLOG_CONF_DIR=\"$(sysconfdir)\"
endif
libsyslog_la_CPPFLAGS += -I../include
libsyslog_la_LDFLAGS = -no-undefined
libsyslog_la_LIBADD = -lws2_32

logger_SOURCES = logger.c
logger_CPPFLAGS = -I../include
logger_LDFLAGS = -L.
logger_LDADD = -lsyslog

endif
