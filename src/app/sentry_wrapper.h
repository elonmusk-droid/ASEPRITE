// Aseprite
// Copyright (C) 2021  Igara Studio S.A.
//
// This program is distributed under the terms of
// the End-User License Agreement for Aseprite.

#ifndef APP_SENTRY_WRAPPER_H
#define APP_SENTRY_WRAPPER_H

#if !ENABLE_SENTRY
  #error ENABLE_SENTRY must be defined
#endif

#include "sentry.h"

#include <string>

namespace app {

class Sentry {
public:
  void init();
  ~Sentry();

  static void setUserID(const std::string& uuid);

  static bool requireConsent();
  static bool consentGiven();
  static void giveConsent();
  static void revokeConsent();

  // Returns true if there are some crash to report. Used to display
  // the "give consent" check box for first time.
  static bool areThereCrashesToReport();

private:
  void setupDirs(sentry_options_t* options);

  bool m_init = false;
  static std::string m_dbdir;
};

} // namespace app

#endif  // APP_SENTRY_WRAPPER_H
