/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 2001 Waldo Bastian <bastian@kde.org>

    SPDX-License-Identifier: LGPL-2.0-only
*/

#ifndef _KIO_HTTP_SLAVE_DEFAULTS_H
#define _KIO_HTTP_SLAVE_DEFAULTS_H

#include "global.h"

// CONNECTION
static constexpr int DEFAULT_KEEP_ALIVE_TIMEOUT = 60; // 60 seconds

// CACHE SETTINGS
static constexpr int DEFAULT_MAX_CACHE_SIZE = 50 * 1024; // 50 MB
static constexpr int DEFAULT_MAX_CACHE_AGE = 60 * 60 * 24 * 14; // 14 DAYS
static constexpr int DEFAULT_CACHE_EXPIRE = 3 * 60; // 3 MINS
static constexpr auto DEFAULT_CACHE_CONTROL = KIO::CC_Refresh; // Verify with remote

// DEFAULT USER AGENT KEY - ENABLES OS NAME
static const char DEFAULT_USER_AGENT_KEYS[] = "om"; // Show OS, Machine

// MAXIMUM AMOUNT OF DATA THAT CAN BE SAFELY SENT OVER IPC
static constexpr int MAX_IPC_SIZE = 1024 * 8;

// SOME DEFAULT HEADER VALUES
static const char DEFAULT_LANGUAGE_HEADER[] = "en";
static const char DEFAULT_MIME_TYPE[] = "text/html";
static const char DEFAULT_PARTIAL_CHARSET_HEADER[] = "utf-8, *;q=0.5";
static const char DEFAULT_ACCEPT_HEADER[] = "text/html, text/*;q=0.9, image/jpeg;q=0.9, image/png;q=0.9, image/*;q=0.9, */*;q=0.8";

#endif // KIO_HTTP_SLAVE_DEFAULTS_H
