/*
    SPDX-FileCopyrightText: 2003 Malte Starostik <malte@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KPAC_PROXYSCOUT_H
#define KPAC_PROXYSCOUT_H

#include <KDEDModule>

#include <QDBusMessage>
#include <QMap>
#include <QUrl>

class QFileSystemWatcher;

#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QNetworkInformation>
#else
class QNetworkConfiguration;
class QNetworkConfigurationManager;
#endif

namespace KPAC
{
class Downloader;
class Script;

class ProxyScout : public KDEDModule
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "org.kde.KPAC.ProxyScout")
public:
    ProxyScout(QObject *parent, const QList<QVariant> &);
    ~ProxyScout() override;

public Q_SLOTS:
    Q_SCRIPTABLE QString proxyForUrl(const QString &checkUrl, const QDBusMessage &);
    Q_SCRIPTABLE QStringList proxiesForUrl(const QString &checkUrl, const QDBusMessage &);
    Q_SCRIPTABLE Q_NOREPLY void blackListProxy(const QString &proxy);
    Q_SCRIPTABLE Q_NOREPLY void reset();

private Q_SLOTS:
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    void disconnectNetwork(QNetworkInformation::Reachability newReachability);
#else
    void disconnectNetwork(const QNetworkConfiguration &config);
#endif

    void downloadResult(bool);
    void proxyScriptFileChanged(const QString &);

private:
    bool startDownload();
    QStringList handleRequest(const QUrl &url);

    QString m_componentName;
    Downloader *m_downloader;
    Script *m_script;

    struct QueuedRequest {
        QueuedRequest()
        {
        }
        QueuedRequest(const QDBusMessage &, const QUrl &, bool sendall = false);

        QDBusMessage transaction;
        QUrl url;
        bool sendAll;
    };
    typedef QList<QueuedRequest> RequestQueue;
    RequestQueue m_requestQueue;

    typedef QMap<QString, qint64> BlackList;
    BlackList m_blackList;
    qint64 m_suspendTime;
    QFileSystemWatcher *m_watcher;

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QNetworkConfigurationManager *m_networkConfig;
#endif
};
}

#endif // KPAC_PROXYSCOUT_H
