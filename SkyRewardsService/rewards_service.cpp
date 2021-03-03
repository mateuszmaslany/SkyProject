#include "rewards_service.h"

#include "exceptions.h"

rewards_service::rewards_service
(
    std::shared_ptr<eligibility_service> const& eligibility_service
)
    :   eligibility_service_(eligibility_service)
{
    construct_rewards_map();
}

rewards_response rewards_service::check_for_rewards
(
    unsigned int account_number,
    QVector<channel_name> const& channels
)
{
    QVector<reward_name> rewards;
    eligibility_result eligibility;

    try
    {
        eligibility = eligibility_service_->is_eligible(account_number);
    }
    catch(technical_failure_exception&)
    {
        return rewards_response(rewards, true);
    }
    catch(invalid_account_number_exception&)
    {
        return rewards_response(rewards, false);
    }

    if(eligibility == eligibility_result::CUSTOMER_ELIGIBLE)
    {
        for(auto const& ch: channels)
        {
            if(rewards_map.contains(ch) && rewards_map[ch].has_value())
            {
                rewards.push_back(rewards_map[ch].value());
            }
        }
    }

    return rewards_response(rewards,true);
}

void rewards_service::construct_rewards_map()
{
    rewards_map[channel_name::SPORTS] = reward_name::CHAMPIONS_LEAGUE_FINAL_TICKET;
    rewards_map[channel_name::KIDS] = std::nullopt;
    rewards_map[channel_name::MUSIC] = reward_name::KARAOKE_PRO_MICROPHONE;
    rewards_map[channel_name::NEWS] = std::nullopt;
    rewards_map[channel_name::MOVIES] = reward_name::PIRATES_OF_THE_CARIBBEAN_COLLECTION;
}
