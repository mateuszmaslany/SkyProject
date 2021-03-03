#ifndef ELIGIBILITY_SERVICE_MOCK_H
#define ELIGIBILITY_SERVICE_MOCK_H

#include <gmock/gmock.h>

#include "..\SkyRewardsService\eligibility_service.h"

class eligibility_service_mock : public eligibility_service
{
public:
    virtual ~eligibility_service_mock() {}
    MOCK_CONST_METHOD1(is_eligible, eligibility_result(unsigned int));
};

#endif // ELIGIBILITY_SERVICE_MOCK_H
