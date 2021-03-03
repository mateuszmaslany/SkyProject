#ifndef REWARDS_SERVICE_H
#define REWARDS_SERVICE_H

#include <memory>
#include <optional>
#include <QMap>

#include "eligibility_service.h"
#include "channel_name_enum.h"
#include "reward_name_enum.h"
#include "rewards_response.h"

class rewards_service
{
public:
    rewards_service(
        std::shared_ptr<eligibility_service> const& eligibility_service
    );

    rewards_response check_for_rewards(
        unsigned int account_number,
        QVector<channel_name> const& channels
    );

private:
    void construct_rewards_map();

    std::shared_ptr<eligibility_service> eligibility_service_;

    QMap<channel_name, std::optional<reward_name>> rewards_map;
};

#endif // REWARDS_SERVICE_H
