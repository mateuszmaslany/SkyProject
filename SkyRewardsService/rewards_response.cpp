#include "rewards_response.h"

rewards_response::rewards_response
(
    QVector<reward_name> const& rewards,
    bool account_number_valid
)
:   rewards_(rewards),
    account_number_valid_(account_number_valid)
{
}

QVector<reward_name> const &rewards_response::get_rewards() const
{
    return rewards_;
}

bool rewards_response::is_account_number_valid() const
{
    return account_number_valid_;
}
