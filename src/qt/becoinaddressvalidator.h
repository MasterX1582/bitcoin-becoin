// Copyright (c) 2011-2014 The BeCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BECOIN_QT_BECOINADDRESSVALIDATOR_H
#define BECOIN_QT_BECOINADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BeCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BeCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** BeCoin address widget validator, checks for a valid becoin address.
 */
class BeCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BeCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // BECOIN_QT_BECOINADDRESSVALIDATOR_H
