#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <QVector>

#include "channel_name_enum.h"

class Customer
{
public:
    Customer(
        unsigned int account_number,
        QVector<channel_name> const& subscriptions);

    unsigned int get_account_number() const;

    QVector<channel_name> const& get_channel_subscriptions() const;

private:
    unsigned int const account_number_;
    QVector<channel_name> channel_subscriptions_;
};

#endif // CUSTOMER_H
