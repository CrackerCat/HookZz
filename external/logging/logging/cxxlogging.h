#ifndef CXX_LOGGING_H
#define CXX_LOGGING_H

#include "logging.h"

class Logger {
public:
  static void LogFatal(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    printf("[!] FATAL: ");
    vprintf(fmt, args);
    va_end(args);
  }

private:
  static char *tag_;
  static char *file_;
  static int level_;
};

#endif
