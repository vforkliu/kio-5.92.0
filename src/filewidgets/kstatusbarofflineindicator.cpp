/*
    This file is part of the KDE project
    SPDX-FileCopyrightText: 2007 Will Stephenson <wstephenson@kde.org>

    SPDX-License-Identifier: LGPL-2.0-only WITH Qt-Commercial-exception-1.0
*/

#include "kstatusbarofflineindicator.h"

#if KIOFILEWIDGETS_BUILD_DEPRECATED_SINCE(5, 70)

#include <KIconLoader>
#include <KLocalizedString>
#include <QLabel>
#include <QVBoxLayout>

#include <QIcon>
#include <QNetworkConfigurationManager>

class KStatusBarOfflineIndicatorPrivate
{
public:
    // Silence deprecation warnings as there is no Qt 5 substitute for QNetworkConfigurationManager
    QT_WARNING_PUSH
    QT_WARNING_DISABLE_CLANG("-Wdeprecated-declarations")
    QT_WARNING_DISABLE_GCC("-Wdeprecated-declarations")
    explicit KStatusBarOfflineIndicatorPrivate(KStatusBarOfflineIndicator *parent)
        : q(parent)
        , networkConfiguration(new QNetworkConfigurationManager(parent))
    {
    }
    QT_WARNING_POP

    void initialize();
    void _k_networkStatusChanged(bool isOnline);

    KStatusBarOfflineIndicator *const q;
    // Silence deprecation warnings as there is no Qt 5 substitute for QNetworkConfigurationManager
    QT_WARNING_PUSH
    QT_WARNING_DISABLE_CLANG("-Wdeprecated-declarations")
    QT_WARNING_DISABLE_GCC("-Wdeprecated-declarations")
    QNetworkConfigurationManager *networkConfiguration;
    QT_WARNING_POP
};

KStatusBarOfflineIndicator::KStatusBarOfflineIndicator(QWidget *parent)
    : QWidget(parent)
    , d(new KStatusBarOfflineIndicatorPrivate(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(2, 2, 2, 2);
    QLabel *label = new QLabel(this);
    label->setPixmap(QIcon::fromTheme(QStringLiteral("network-disconnect")).pixmap(KIconLoader::SizeSmall));
    label->setToolTip(i18n("The desktop is offline"));
    layout->addWidget(label);
    d->initialize();
    // Silence deprecation warnings as there is no Qt 5 substitute for QNetworkConfigurationManager
    QT_WARNING_PUSH
    QT_WARNING_DISABLE_CLANG("-Wdeprecated-declarations")
    QT_WARNING_DISABLE_GCC("-Wdeprecated-declarations")
    connect(d->networkConfiguration, &QNetworkConfigurationManager::onlineStateChanged, this, [this](bool isOnline) {
        d->_k_networkStatusChanged(isOnline);
    });
    QT_WARNING_POP
}

KStatusBarOfflineIndicator::~KStatusBarOfflineIndicator() = default;

void KStatusBarOfflineIndicatorPrivate::initialize()
{
    _k_networkStatusChanged(networkConfiguration->isOnline());
}

void KStatusBarOfflineIndicatorPrivate::_k_networkStatusChanged(bool isOnline)
{
    if (isOnline) {
        q->hide();
    } else {
        q->show();
    }
}

#include "moc_kstatusbarofflineindicator.cpp"

#endif
