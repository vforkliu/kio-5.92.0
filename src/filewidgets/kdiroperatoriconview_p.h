/*
    SPDX-FileCopyrightText: 2007 Peter Penz <peter.penz@gmx.at>
    SPDX-FileCopyrightText: 2019 Méven Car <meven.car@kdemail.net>

    SPDX-License-Identifier: LGPL-2.0-only
*/

#ifndef KDIROPERATORICONVIEW_P_H
#define KDIROPERATORICONVIEW_P_H

#include <QListView>

/**
 * Default icon view for KDirOperator using
 * custom view options.
 */
class KDirOperatorIconView : public QListView
{
    Q_OBJECT
public:
    KDirOperatorIconView(QWidget *parent = nullptr, QStyleOptionViewItem::Position decorationPosition = QStyleOptionViewItem::Position::Top);
    ~KDirOperatorIconView() override;
    void setDecorationPosition(QStyleOptionViewItem::Position decorationPosition);

protected:
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    void initViewItemOption(QStyleOptionViewItem *option) const override;
#else
    QStyleOptionViewItem viewOptions() const override;
#endif
    void dragEnterEvent(QDragEnterEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

protected
    Q_SLOT : void updateLayout();

private:
    QStyleOptionViewItem::Position decorationPosition;
};

#endif // KDIROPERATORICONVIEW_P_H
