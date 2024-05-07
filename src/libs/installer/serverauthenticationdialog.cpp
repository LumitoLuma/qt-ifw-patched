/**************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt Installer Framework.
**
** $QT_BEGIN_LICENSE:GPL-EXCEPT$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
**************************************************************************/
#include "serverauthenticationdialog.h"

#include "downloadfiletask.h"
#include "ui_serverauthenticationdialog.h"

#include <QAuthenticator>

namespace QInstaller {

/*!
    \inmodule QtInstallerFramework
    \class QInstaller::ServerAuthenticationDialog
    \internal
*/

ServerAuthenticationDialog::ServerAuthenticationDialog(const QString &m, const FileTaskItem &item)
    : ui(new Ui::ServerAuthenticationDialog)
{
    ui->setupUi(this);
    ui->siteDescription->setText(m);
    setWindowFlags(windowFlags() &~Qt::WindowContextHelpButtonHint);

    const QAuthenticator auth = item.value(TaskRole::Authenticator).value<QAuthenticator>();
    ui->userEdit->setText(auth.user());
    ui->passwordEdit->setText(auth.password());
}

ServerAuthenticationDialog::~ServerAuthenticationDialog()
{
    delete ui;
}

QString ServerAuthenticationDialog::user() const
{
    return ui->userEdit->text();
}

QString ServerAuthenticationDialog::password() const
{
    return ui->passwordEdit->text();
}

} // namespace QInstaller
