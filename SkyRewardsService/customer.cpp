#include "customer.h"

Customer::Customer
(
    unsigned int account_number,
    const QVector<channel_name> &subscriptions
)
:   account_number_(account_number),
    channel_subscriptions_(subscriptions)
{
}

unsigned int Customer::get_account_number() const
{
    return account_number_;
}

const QVector<channel_name> &Customer::get_channel_subscriptions() const
{
    return channel_subscriptions_;
}
