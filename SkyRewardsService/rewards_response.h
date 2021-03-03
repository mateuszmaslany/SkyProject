#ifndef REWARDS_RESPONSE_H
#define REWARDS_RESPONSE_H

#include <QVector>

#include "reward_name_enum.h"

class rewards_response
{
public:
    rewards_response(
        QVector<reward_name> const& rewards,
        bool account_number_valid);

    QVector<reward_name> const& get_rewards() const;

    bool is_account_number_valid() const;

private:
    QVector<reward_name> const rewards_;
    bool account_number_valid_;
};

#endif // REWARDS_RESPONSE_H
